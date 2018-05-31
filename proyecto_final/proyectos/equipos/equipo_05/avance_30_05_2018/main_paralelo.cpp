	/* 
 * File:   main.cpp
 * Author: francisco
 *
 * Created on Mayo 23, 2017, 7:22 PM
// */
//

#include <string>
#include "Activity.h"
#include "Graph.h"
#include "Station.h"

#include "GraphCreator.h"
#include "FileReader.h"
#include "AssemblyLine.h"
#include "Utilities.h"
#include "Heuristic.h"
#include "Simplifier.h"
#include "RestrictionGenerator.h"
#include "Model.h"
#include "DurationNode.h"
#include "DurationTree.h"
#include "strtk.hpp"
#include "Mixer.h"
#include "BinaryRestriction.h"
#include "VectorBR.h"
#include "BinaryMixer.h"
#include <cmath>
#include <chrono>
#include "stdafx.h"
#include <iostream>

#include <cuda.h>
#include <cuda_runtime.h>


/////////////////////////////////////////
// declaration, forward
/////////////////////////////////////////
//extern "C" int h_cont;

extern "C" bool 
runTest(int argc, const char **argv, unsigned long long int * h_cont, int numStations, unsigned int * h_temp, unsigned long long int  h_temp_size, unsigned int * h_rest, int h_rest_size, unsigned int * h_out);

using namespace std;
//using namespace std::chrono;

// checa is existe el archivo 
bool exist_test (const std::string& name){
    ifstream f(name.c_str());
    return f.good();
}

unsigned int hashmap_hash_int(unsigned long long int map_size, unsigned int key) {
	/* Robert Jenkins' 32 bit Mix Function */
	key += (key << 12);
	key ^= (key >> 22);
	key += (key << 4);
	key ^= (key >> 9);
	key += (key << 10);
	key ^= (key >> 2);
	key += (key << 7);
	key ^= (key >> 12);

	/* Knuth's Multiplicative Method */
	key = (key >> 3) * 2654435761;

	return key % map_size;
}

unsigned long long int MurmurHash2_pt1(unsigned long long int key, unsigned long long int seed)
{
	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.

	const unsigned int m = 0x5bd1e995;
	const int r = 24;

	key *= m;
	key ^= key >> r;
	key *= m;

	seed *= m;
	seed ^= key;

	return seed;
}

unsigned long long int MurmurHash2_pt2(unsigned long long int seed)
{
	const unsigned int m = 0x5bd1e995;
	seed ^= seed >> 13;
	seed *= m;
	seed ^= seed >> 15;

	return seed;
}


unsigned long long int fnv1(unsigned long long int key, unsigned long long int res) {
	const unsigned long long int prime = 16777619;
	res = res ^ key;
	res = res * prime;
	return res;
}





bool parallelExe(int argc, const char **argv){
	
    cout << "TEST" << endl;
    
    cout << "READING FILE..." << endl;
 
    //Verify file existence
    
    //Data_BL/BOWMAN8.IN2";
    //Estaciones a verificar: 3 y 5
    //Data_BL/JACKSON.IN2";
    //Estaciones a verificar: 3,4 y 5
    //Data_BL/JAESCHKE.IN2";
    //Estaciones a verificar: 3,4,5 y 6 
    //Data_BL/MANSOOR.IN2";
    //Estaciones a verificar: 3 y 4
    //Data_BL/MERTENS.IN2";
    //Estaciones a verificar: 3 y 5
    //Data_BL/LASCURAIN.IN2";
    //Estaciones a verificar: 4
    //Data_BL/MITCHELL.IN2";
    
    //Read from file
	//string filename = "C:\\Users\\FERNYBOY\\Desktop\\Data_BL\\JAESCHKE.IN2";
    string filename = "/home/ubuntu/balanceolinea/Data_BL/Problem_Set/LASCURAIN.IN2";
    bool exist = exist_test(filename);
    cout << "File existence: " << exist << endl;
    

    //Create Tables
    //1. ForwardTimes, BackwardTimes
    //2. Precedence Table
    GraphCreator gc;
    Graph * graph = gc.createGraph(filename);
    graph->printGraph();
    cout << "--------------------------------------------------------------------------------------------------" << endl;      
    cout << "\n" << "Artificial Destination: " << graph->artificialDestination << endl;
    cout << "Artificial Origin: " << graph->artificialOrigin << "\n " << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "Max common divisor: ";
    int gdc = graph->ActivityDurationsGDC();
    cout << gdc <<  endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "Graph Total Duration: " << graph->getTotalDuration() << endl;
    
    
    // Determine NUMBER OF STATIONS for the desired BALANCING.
    //Esto será especificado en el comando.
    int numberStations = 4;
   
    //Linea de produccion
    AssemblyLine * al = new AssemblyLine(numberStations);
    Heuristic * op=new Heuristic(graph,al);
    op->solve();
    double heuristic=op->getHeuristic();
    cout << "Heuristic Balancing Time: " << heuristic << endl;
    
    //Change the value of heuristic for the ideal balancing time. The program iterates upwards in variations of the size of the 'Max common divisor'
    heuristic = graph->getTotalDuration()/numberStations;
    heuristic = ceil(heuristic);
    cout << "Ideal Balancing Time: " << heuristic << endl;
    
    
    //Program starts here...

    /////////////////////////////////////
	////BALANCING TIME ITERATION LOOP////
	/////////////////////////////////////

    //finish: Flag for Balancing iteration loop
    bool finish = false;

    while(!finish){

    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n\nBalancing Time: \n\n\n" << heuristic << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    
    // Create Simplifier for model
    Simplifier s(graph,heuristic,numberStations);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//START: Need better comments
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //esta bandera me va a ayudar a determinar si hay alguna interseccion vacia
    // al momento de asignar actividades a estaciones.
    // significa que no es possible este balanceo y tengo que iterar

    AllCandidateStations * cand= s.simplify();

    if(cand->isFeasible())
    {
          
    // Binary Search for a lower limit
    // Determine which is the objective of this segment of code that simplifies the model
    
    double lowerLimit, upperLimit, middleValue;
    lowerLimit= graph->getTotalDuration()/numberStations;
    lowerLimit= round(lowerLimit,true);
    upperLimit=heuristic;

    double minValue,maxValue;


    minValue=lowerLimit;
    maxValue=heuristic;

    // Step 3: Finished getting lower bound

    s.setHeuristic(heuristic);
    cand= s.simplify();

    // Step 4: Finished simplifying model
		
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//END: Need better comments
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    cout << "Activity Information Table" << endl;
    graph->printActivityColletion();
    
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "Candidate stations for each activity: " << endl;
    cand->print();
    
    //Generate Model and Restrictions for Model
    RestrictionGenerator * r = new RestrictionGenerator(minValue,maxValue,cand,graph,al);
    Model * model= r->getModel();
    
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "------RESTRICCIONES----- \n\n" << endl;
    
    model->print();
    
    cout << "\n ------TABLA UNIVERSO----- \n" << endl;
    int** tablaUniverso = cand->generateTable();
    
    // "precedenceR" es un arreglo de objetos (PrecedenceRestrictions) que vamos a usar para extraer las ecuaciones booleanas
    // de las restricciones que si son validas, es decir que generan una restriccion.
    vector<PrecedenceRestriction *> arrPrecedence = model->getPrecedenceRestrictions();
    
    // Generar restricciones de precedencia negadas
        /*
         * 1. Un metodo que extraiga de la restriccion la combiancion de letras que no se puede
         * 2. Determinar la negacion de esta expression
         * 3. Crear un arreglo de string
         * 4. Guardar las restricciones generadas en este arreglo de strings
         */
    
    /*
     * La idea va a ser recorrer la tabla del universo de variables en la columna de origen hacia abajo y para cada uno de los renglones
     * Verificar que no exista un valor possible anterior en estacion para el actual.
     * 
     
     */
    
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 //PRECEDENCE CONSTRAINT GENERATION
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     cout << "\n\n ------RESTRICCIONES PRECEDENCIA BOOLEANAS----- \n\n" << endl;
    //formato correcto
    vector<string> rPrecedence;
    
    int origin, staOrigin;
    int dest, staDestination;
    int j = numberStations-1;
    int jDest = 0;
    bool flag = false;
    
    for(int i=0; i<arrPrecedence.size();i++){
        
        origin = arrPrecedence.at(i)->getOrigin();
        dest = arrPrecedence.at(i)->getDestination();
        
        cout << "ERROR EN PRECEDENCIA" << endl;
        cout << "Origen: " << origin << endl;
        cout << "Destino: " << dest << endl;
        
        while(j>0){
            //[estacion][actividad]
            if(tablaUniverso[j][origin]==1){
                staOrigin=j;
                flag = true;
            }
            
            
            while(flag && jDest<numberStations){
            //[estacion][actividad]
            if(tablaUniverso[jDest][dest]==1){
                if(j>jDest){
                    cout << "j: " << j << endl;
                    cout << "JDest: " << jDest << endl;
                    
                    staDestination=jDest;
                    string temp = ""; 
                    string temp1 = getNegation(origin, staOrigin,tablaUniverso, numberStations);
                    cout << "NEGACION ORIGIN: " << temp1 << endl;
                    string temp2 = getNegation(dest, staDestination,tablaUniverso, numberStations);
                    cout << "NEGACION DEST: " << temp2 <<endl;
                    
                    temp += temp1;
                    temp += ",";
                    temp += temp2;
                    cout << temp << endl;
                    // agregar a arreglo de restricciones de Precedencia
                    rPrecedence.push_back(temp);

                }
            }
            jDest++;
            }
            jDest = 0;
            j--;
            flag=false;

        }
        j = numberStations-1;
        
    }

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//UNICITY CONSTRAINT GENERATION
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    cout << "\n\n ------RESTRICTIONS UNICITY BOOLEANAS----- \n\n" << endl;
    
    vector<string> rUnicity = model->getUnicityRestrictions();
    
    string toString;
    int stationUnicity;
    for(int ii=0; ii< cand->getNumberActivities(); ii++){
        if(cand->getCandStationsForActivity(ii)->hasOnlyOneCandidate()){
                string UnicityConstr;
                toString = invHashAux(ii);
                UnicityConstr.append(toString);
                UnicityConstr.append(cand->getCandStationsForActivity(ii)->getCandidatesExtra());
                rUnicity.push_back(UnicityConstr);
            
        }
    }

    for(int i = 0; i< rUnicity.size() ;i++){
            cout << rUnicity.at(i) << endl;
    }
    
    // cand tiene el numero de actividades de ahi puedo generar la ultima restriccion
    // number of stations numberStations
    

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//DURATION CONSTRAINT GENERATION
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    cout << "\n\n ------RESTRICTIONS DURACION BOOLEANAS----- \n" << endl;
    
    int numRecDuration = model->getNumberEquations();
    vector<Equation *> equations = model->getVectorEquations();
    vector<vector<DurationNode>> groupDN;
    
    for(int w=0; w<numRecDuration ; w++){
        vector<DurationNode> arr;
        int y= 0;
        Variable * aux;
        int balanceDuration = heuristic - equations[w]->getConstantValue();

        while(y<equations[w]->getNumVariables()){
            aux = equations[w]->getVariable(y);
            DurationNode * DN = new DurationNode( aux->getDuration(),aux->getActSta(), balanceDuration);  
            //Add Duration Node to Vector
            arr.push_back(*DN);
            y = y+1;
        }
        
        //Add Vector of Duration Nodes to array of restrictions.
        groupDN.push_back(arr);
    }
    
    // Verificar la creacion de los nodos de duracion.
    int size = groupDN.size();
    vector<DurationNode> arr;
    
    for(int i =0; i<size ; i++){      
        arr = groupDN[i];
        
        //esta vacio
        if(arr.size() != 0){
            groupDN[i] = MergeSort(arr);
            int numDNs= groupDN[i].size();
            //cout << "\n \n";

            for(int j =0; j<numDNs ; j++){
                groupDN[i][j].setId(j);
                // Imprimir los nodos ordenados.
                /*
                cout << "Nodo " << j << endl;
                cout<< "Duracion: " << groupDN[i][j].getDuration() << endl;
                cout<< "Restriction: " << groupDN[i][j].getRestriction() << endl;
                cout<< "Id: " << groupDN[i][j].getId() <<endl;
                cout<< "BalanceDuration: " << groupDN[i][j].getBalanceDuration() <<endl;
                cout << "\n";
                */
            }
        }

    }

    
    vector<string> vectorRest ;
    vector<string> * vectorR = &vectorRest;
    
    cout << groupDN.size() << endl;
    for(int j =0; j<groupDN.size(); j++){
        vector<DurationNode> * vectorDN = &groupDN[j];
        if(vectorDN->size() != 0){
                DurationTree * tree = new DurationTree(vectorDN, vectorR, groupDN[j][0].getBalanceDuration());
                tree->buildTree();
        }

        
    }
  
    // NUMBER OF DURATION RESTRICTIONS GENERATED
    cout << "Restricciones Generadas:" << vectorR->size() << endl;
    
    
    
    cout << "Negacion de Restricciones Generadas:" << vectorR->size() << endl;
    
    for(int i = 0; i < vectorR->size() ; i++){
        string negC = constraintNeg(vectorR->at(i), tablaUniverso, numberStations);
        vectorR->at(i) = negC;
        //cout << vectorR->at(i) << endl;
    }
    
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//CONSTRAINT BINARY INTEGRATION IN PARALLEL
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//PARALLEL CALL FUNCTION: runtest()


	cout << "Integracion Booleana" << endl;

	cout << "AQUI MUERO!!!!" << endl;

    //BinaryMixer bMixer;
    //Mixer * mixer = new Mixer();

	//////////////////////////////
	/////Variable Declaration/////
	//////////////////////////////


	const unsigned long long int sol_vector_size = 4294967295;  ///Tamaño máximo de tablas 
	const unsigned long long int rest_vector_size = 10000; // Tamaño máximo de vector d restricciones.

        cout << "Sigo vivo 2222 ??" << endl;

 
    //En la GPU no puedo guardar en el mismo temp resultados/
    // estas trabajando sober un arreglo y puede sr que guardes algo sobre un casilla que no hayas utilizado (asi operan threads)
    // y pierdes información
	unsigned int ARR1[rest_vector_size]; 
	unsigned int * ptr1 = new unsigned int[rest_vector_size];
    unsigned int * ptr3 = ARR1;


	unsigned int * ptr2 = new unsigned int[sol_vector_size];
	unsigned int * ptr4 = new unsigned int[sol_vector_size];
	
        cout << "Sigo vivo 2.555555??" << endl;
 
	//inicializar en ceros
    // El tercer argumeno es el espacio en bits que quiers usar e bits.
	memset(ptr1, 0, rest_vector_size * sizeof(int));
        cout << "Sigo vivo 2.2555555??" << endl;

	memset(ptr3, 0, rest_vector_size * sizeof(int));
	cout << "Sigo vivo 2.3555555??" << endl;

    memset(ptr4, 0, sol_vector_size * sizeof(int));
    cout << "Sigo vivo 2.4555555??" << endl;
    memset(ptr2, 0, sol_vector_size * sizeof(int));

	cout << "Sigo vivo 3333??" << endl;

    //In order to keep track how many elements there are in certain array
	//Number of occupied space in the array
	//Esto es para controlar el tamaǹo de los vectores, Y RECORRERLOS HASTA DONDE ESTAN LLENOS. 
    int S1_size = 0;
	int S2_size = 0;
	int ARR1_size = 0;
	unsigned long long int NoDup_size = 0;

        cout << "Sigo vivo 44444??" << endl;

	//AUXILIAR Counters
	unsigned long long int  jj = 0;
	unsigned long long int solution_cont = 0;
	unsigned long long int cont_GPU = 0;
	unsigned long long int * ptr_cont;
	ptr_cont = &cont_GPU;

	//HASH TABLE
	string hash_key;
	string null_hash_key;
	for (int i = 0; i < numberStations; i++) {
		null_hash_key.append("0");
	}
	std::map<string, bool> mapTable;
	mapTable[null_hash_key] = true;


	/////////////////////////////////////////////////////
	////////////////HASHMAP//////////////////////////////
	/////////////////////////////////////////////////////


	//TIME
	std::chrono::high_resolution_clock::time_point t1;
	std::chrono::high_resolution_clock::time_point t2;
	auto duration = 0;

	// S1: Array that will store the temporal solutions.
	// S2: Array that will store the temporal solution
	// ARR1: Array that will store the new constraint that will be merged with the temporal solution.

	// Transform and save 1st constrain in S1.

    //Esto es similar al primer temp.
	cout << vectorR->at(0) << endl;
	S1_size = StrRestr2BinVector(numberStations, vectorR->at(0), ptr1); //E.sta linearizao
	cout << "Size Temp:  \n" << S1_size/numberStations << endl; // Size es el numero de tablas de temp.

	printArrayPointer(ptr1, S1_size, numberStations);

	// Transform and save 2nd constrain in ARR1.
	cout << vectorR->at(1) << endl;
	ARR1_size = StrRestr2BinVector(numberStations, vectorR->at(1), ptr3);
	cout << "Size Restriction: \n" << ARR1_size / numberStations << endl; //sacas el numero de tablas.. 

	printArrayPointer(ptr3, ARR1_size, numberStations);

	//Inicia Tiempo 
	t1 = std::chrono::high_resolution_clock::now();
	
	//////////////////////////////////////
	/////S invoca a run Test para que, este, a su vez invoque al kernel./////
	//////////////////////////////////////

	runTest(argc, (const char **)argv, ptr_cont ,numberStations, ptr1, S1_size, ptr3, ARR1_size, ptr2);
	printArrayPointer(ptr2, (S1_size*ARR1_size) / numberStations, numberStations);

	solution_cont = 0;
		while (jj < (*ptr_cont)*numberStations) {

			cout << "hashing status:  " << jj << "/" << ((*ptr_cont)*numberStations) << endl;
			
			for (int kk = 0; kk < numberStations; kk++) {
				hash_key.append(std::to_string(*(ptr2 + jj + kk)));
			}
			//cout << "hash_key " << jj / numberStations << " : " << hash_key << endl;

			if (!mapTable[hash_key]) {
				mapTable[hash_key] = true;

				for (int kk = 0; kk < numberStations; kk++) {
					*(ptr4 + solution_cont + kk) = *(ptr2 + jj + kk);
				}
				solution_cont += numberStations;
			}
			jj += numberStations;
			hash_key = "";
		}
	NoDup_size = solution_cont;
	

	cout << "Tamano TEMP (únicas, pues es despues de hash): " << NoDup_size << endl;
	
	
	int contador= 1;
	int totalRestrictions = vectorR->size() + rPrecedence.size() + rUnicity.size()-1;

	cout << "size P: " << rPrecedence.size() << endl;
	cout << "size D: " << vectorR->size() << endl;
	cout << "size U: " << rUnicity.size() << endl;
	
		///////////////////////////////////////////
		/////PRECEDENT RESTRICTION INTEGRATION/////
		///////////////////////////////////////////

	int cont_mix = 0;
	//for(int i = 0; i < rPrecedence.size() ; i++){
	while (cont_mix < rPrecedence.size() && NoDup_size>0) {
		//Reset values of ARR1 to zero.
		memset(ARR1, 0, sizeof(ARR1));

		*ptr_cont = 0;
		//Transform String::Constraint into Array[int]::Constraint
		ARR1_size = StrRestr2BinVector(numberStations, rPrecedence.at(cont_mix), ptr3);
		cout << "-----------------------------------------------------" << endl;
		cout << "RESTRICCION" << endl;
		cout << "-----------------------------------------------------" << endl;
		//Parallel Execution
		//cout << "elements en temp: " << NoDup_size << " \t Elements in REST: " << ARR1_size << endl;
		//cout << "Elements in solutions vector: " << (NoDup_size*ARR1_size) / numberStations;

		runTest(argc, (const char **)argv, ptr_cont, numberStations, ptr4, solution_cont, ptr3, ARR1_size, ptr2);

		solution_cont = 0;
		jj = 0;
		mapTable.clear();
		mapTable[null_hash_key] = true;
		cout << "elementos para hash: " << *ptr_cont << endl;
		while (jj < (*ptr_cont)*numberStations) {

			//if (jj % 10000000 == 0) {
				//cout << "hashing status:  " << jj << "/" << ((*ptr_cont)*numberStations) << endl;
			//}

			for (int kk = 0; kk < numberStations; kk++) {
				hash_key.append(std::to_string(*(ptr2 + jj + kk)));
			}
			//cout << "hash_key " << jj / numberStations << " : " << hash_key << endl;

			if (!mapTable[hash_key]) {
				mapTable[hash_key] = true;

				for (int kk = 0; kk < numberStations; kk++) {
					*(ptr4 + solution_cont + kk) = *(ptr2 + jj + kk);
				}
				solution_cont += numberStations;
			}
			jj += numberStations;
			hash_key = "";
		}
		NoDup_size = solution_cont;
		cout << "-----------------------------------------------------" << endl;
		cout << "SOLUTION" << endl;
		cout << "Number of solutions: " << NoDup_size / numberStations << endl;
		//printArrayPointer(ptr4, (NoDup_size), numberStations);



		cout << "-----------------------------------------------------" << endl;
		contador++;
		cout << "Iteracion " << contador << "/" << totalRestrictions << endl;

		cont_mix++;
	}

		///////////////////////////////////////////////
		/////////Integración sobre las restricciones de duración/////
		///////////////////////////////////////////////

		cont_mix = 2;

		
		while(cont_mix < vectorR->size() && NoDup_size>0){
			//Transform String::Constraint into Array[int]::Constraint
			//Reset values of ARR1 to zero.
			memset(ARR1, 0, sizeof(ARR1));
			*ptr_cont = 0;
			ARR1_size = StrRestr2BinVector(numberStations, vectorR->at(cont_mix), ptr3);
			cout << "-----------------------------------------------------" << endl;
			cout << "RESTRICCION" << endl;
			//printArrayPointer(ptr3, ARR1_size, numberStations);
			cout << "-----------------------------------------------------" << endl;
			//Parallel Execution
			//cout << "elements en temp: " << NoDup_size << " \t Elements in REST: " << ARR1_size << endl;
			runTest(argc, (const char **)argv,ptr_cont, numberStations, ptr4, solution_cont, ptr3, ARR1_size, ptr2);

			solution_cont = 0;
			jj = 0;
			mapTable.clear();
			mapTable[null_hash_key] = true;
			cout << "elementos para hash: " << *ptr_cont << endl;
			while (jj < ((*ptr_cont)*numberStations)) {
				for (int kk = 0; kk < numberStations; kk++) {
					hash_key.append(std::to_string(*(ptr2 + jj + kk)));
				}


				

				if (!mapTable[hash_key]) {
					mapTable[hash_key] = true;

					for (int kk = 0; kk < numberStations; kk++) {
						*(ptr4 + solution_cont + kk) = *(ptr2 + jj + kk);
					}
					solution_cont += numberStations;
				}
				jj += numberStations;
				hash_key = "";
			}
			NoDup_size = solution_cont;
			cout << "-----------------------------------------------------" << endl;
			cout << "SOLUTION" << endl;
			cout << "Number of solutions: " << NoDup_size/numberStations << endl;
			//printArrayPointer(ptr4, (NoDup_size), numberStations);
			cout << "-----------------------------------------------------" << endl;
			contador++;
			cout << "Iteracion " << contador << "/" << totalRestrictions << endl;

			cont_mix++;
		}



	////	/////////////////////////////////////////
	////	/////Integración de resricciones de unicidad./////
	////	/////////////////////////////////////////

		cont_mix =  0;

		//for (int i = 0; i < rUnicity.size(); i++) {
		while(cont_mix < rUnicity.size() && NoDup_size>0){
			//Transform String::Constraint into Array[int]::Constraint
			//Reset values of ARR1 to zero.
			memset(ARR1, 0, sizeof(ARR1));

			*ptr_cont = 0;
			ARR1_size = StrRestr2BinVector(numberStations, rUnicity.at(cont_mix), ptr3);
			cout << "-----------------------------------------------------" << endl;
			cout << "RESTRICCION" << endl;
			cout << "-----------------------------------------------------" << endl;
			//Parallel Execution
			//cout << "elements en temp: " << NoDup_size << " \t Elements in REST: " << ARR1_size << endl;
			runTest(argc, (const char **)argv, ptr_cont,numberStations, ptr4, solution_cont, ptr3, ARR1_size, ptr2);

			solution_cont = 0;
			jj = 0;
			mapTable.clear();
			mapTable[null_hash_key] = true;
			while (jj < (*ptr_cont)* numberStations) {
				for (int kk = 0; kk < numberStations; kk++) {
					hash_key.append(std::to_string(*(ptr2 + jj + kk)));
				}

				if (!mapTable[hash_key]) {
					mapTable[hash_key] = true;

					for (int kk = 0; kk < numberStations; kk++) {
						*(ptr4 + solution_cont + kk) = *(ptr2 + jj + kk);
					}
					solution_cont += numberStations;
				}
				jj += numberStations;
				hash_key = "";
			}
			NoDup_size = solution_cont;
			cout << "-----------------------------------------------------" << endl;
			cout << "SOLUTION" << endl;
			cout << "Number of solutions: " << NoDup_size/numberStations << endl;
			cout << "-----------------------------------------------------" << endl;
			contador++;
			cout << "Iteracion " << contador << "/" << totalRestrictions << endl;

			cont_mix++;
		}



		//If que controle cuando acabo
		if ((NoDup_size / numberStations) != 0) {

			//Tiempo Fin
			t2 = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			cout << "Tiempo: " << duration << endl;

			finish = true;

			cout << "-----------------------------------------------------" << endl;
			cout << "SOLUTION" << endl;
			cout << "Tiempo: " << duration << endl;
			cout << "Number of constraints:  " <<  totalRestrictions << endl;
			cout << "Number of solutions: " << NoDup_size / numberStations << endl;
			cout << "\nBalancing Time: " << heuristic << "\n\n" << endl;
			printArrayPointer(ptr4, (NoDup_size), numberStations);
			cout << "-----------------------------------------------------" << endl;


		}
		else {
			heuristic = heuristic + gdc;
			free(ptr2);
                        //free(ptr4);
		}
		

    } //if cand is feasible
    else
    {
        cout << "No hay solucion." << endl;
		heuristic = heuristic + gdc;
    }
    
    } // iteracion de tiempo de balanceo while


    
    return true;

}



int main(int argc, const char **argv) {


	bool flag = parallelExe(argc, (const char **)argv);
    
    cout << "Termino: " << flag << endl;


	cin.get();

	return 0;

}


    



