/* 
 * File:   main_secuencia.cpp
 * Author: francisco
 *
 * Created on Mayo 30, 7:22 PM
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
#include "Mixer.h"
#include "BinaryRestriction.h"
#include "VectorBR.h"
#include "BinaryMixer.h"
#include <cmath>
#include <chrono>
#include "stdafx.h"
#include <iostream>

//#include <cuda.h>
//#include <cuda_runtime.h>


/////////////////////////////////////////
// declaration, forward
/////////////////////////////////////////
//extern "C" int h_cont;

extern "C" bool 
runTest(int argc, const char **argv, unsigned long long int * h_cont, int numStations, unsigned int * h_temp, unsigned long long int  h_temp_size, unsigned int * h_rest, int h_rest_size, unsigned int * h_out);

using namespace std;
//using namespace std::chrono;

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




bool executeBool(){
      
    cout << "READING FILE..." << endl;
 
    //string filename = "/home/paco/Desktop/inner_desktop/Proy_BLP/balanceolinea/Data_BL/Problem_Set/BOWMAN8.IN2";
    //Estaciones a verificar: 3 y 5
    //string filename = "/home/paco/Desktop/inner_desktop/Proy_BLP/balanceolinea/Data_BL/Problem_Set/JACKSON.IN2";
    //Estaciones a verificar: 3,4 y 5
    //string filename = "/home/paco/Desktop/inner_desktop/Proy_BLP/balanceolinea/Data_BL/Problem_Set/JAESCHKE.IN2";
    //Estaciones a verificar: 3,4,5 y 6 
    //string filename = "/home/paco/Desktop/inner_desktop/Proy_BLP/balanceolinea/Data_BL/Problem_Set/MANSOOR.IN2";
    //Estaciones a verificar: 3 y 4
    //string filename = "/home/paco/Desktop/inner_desktop/Proy_BLP/balanceolinea/Data_BL/Problem_Set/MERTENS.IN2";
    //Estaciones a verificar: 3 y 5
    //string filename = "/home/paco/Desktop/inner_desktop/Proy_BLP/balanceolinea/Data_BL/Problem_Set/LASCURAIN.IN2";
    
    //Estaciones a verificar: 
    //string filename = "/home/paco/Desktop/inner_desktop/Proy_BLP/balanceolinea/Data_BL/Problem_Set/MITCHELL.IN2";
    
    //Estaciones a verificar: 
    //string filename = "/home/ubuntu/balanceolinea/Data_BL/Problem_Set/JACKSON.IN2";
    string filename = "/home/ubuntu/balanceolinea/Proy_BLP/balanceolinea/Data_BL/Problem_Set/LASCURAIN.IN2";
    
    
    
    //Checa si el archivo existe.
    bool exist = exist_test(filename);
    cout << "File existence: " << exist << endl;
    

    //Create Tables
    //1. ForwardTimes, BackwardTimes
    //2. Precedence Table

    //Crea un objeto graph creator
    GraphCreator gc;

    //Instanciamos el grafo de producción, este lee input e instancia, actividades,
    //duraciónes y relaciones de precedencia.
    Graph * graph = gc.createGraph(filename);
    
    //Imprime la matriz con las relaciones de adjacencia/precendencia.
    graph->printGraph();
    
    //Si los hay, esta parte imprime si se tuvieron que generar
    // tanto un inicio como un final artificial del grafo de producción.

    cout << "--------------------------------------------------------------------------------------------------" << endl;      
    cout << "\n" << "Artificial Destination: " << graph->artificialDestination << endl;
    cout << "Artificial Origin: " << graph->artificialOrigin << "\n " << endl;
    
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "Max common divisor: ";
    int gdc = graph->ActivityDurationsGDC();
    cout << gdc <<  endl;
    
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "Duración Total: " << graph->getTotalDuration() << endl;
    
    
    //Se determina el número de estaciones deseadas para el balanceo. 
    int numberStations = 4;
     
   
    //Se instancia la linea de producción.
    AssemblyLine * al = new AssemblyLine(numberStations);
    
    //Se obtiene el tiempo de ciclo ideal.
    double heuristic = graph->getTotalDuration()/numberStations;
    heuristic = ceil(heuristic);
    cout << "Tiempo de ciclo ideal: " << heuristic << endl;
     
    
    //Bandera para el ciclo de balanceo.
    //De no encontrar solución, incrementa el ciclo ideal en la magnitud del máximo común divisor.
    bool finish = false;
    
    //Ciclo de balanceo.
    while(!finish){
        
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n"<< endl;
    cout << "Tiempo de Balanceo: " << heuristic << endl;
    cout << "\n\n"<< endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    
    
    // Simplificador de restricciones, recibe la matriz de restricciones
    // de precedencia, el tiempo de ciclo ideal y el numero de 
    // estaciones.
    Simplifier s(graph,heuristic,numberStations);
    
    //Calcula los tiempos hacia adelante, hacia atrás,
    //establece las estaciones candidatas a partir de este análisis.
    AllCandidateStations * cand= s.simplify();
    
    //Checamos si es posible (todas las actividades tienen candidatos en estaciones)
    //si no lo es, itera aumentandole al tiempo de ciclo ideal.
    if(cand->isFeasible())
    {
          
        // Binary Search for a lower limit
        //Busqueda binaria por un limite menor y superior. el superior siendo el tiempo de ciclo ideal.
        //El inferior es el tiempo de ciclo ideal inicial.
        //Esta parte busca tiempos de ciclos factibles entre 
        
        double lowerLimit, upperLimit, middleValue;
        lowerLimit= graph->getTotalDuration()/numberStations;
        lowerLimit= round(lowerLimit,true);
        //El limite superior es el tiempo de ciclo ideal.
        upperLimit=heuristic;

        double minValue,maxValue;

        minValue=lowerLimit;
        maxValue=heuristic;

        // Step 3: Finished getting lower bound

        printf("el min value es %f\n", minValue);
        printf("el max value es %f\n", maxValue);

        //definimos nuestro tiempo de ciclo ideal. 
        s.setHeuristic(heuristic);
        //simplificamos restricciones.Calculando intersecciones de estaciones,
        //para cada actividad calculando tiempos hacia adelante y hacia atrás.
        cand= s.simplify();

        // Step 4: Finished simplifying model
    		
        //Imprimimos los tiempos hacia adelante y hacia atrás.
        cout << "Activity Information Table" << endl;
        graph->printActivityColletion();
        
        // Estaciones posibles para cada actividad.
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        cout << "Candidate stations for each activity: " << endl;
        cand->print();
        
        //Genera las restricciones del modelo. 
        //Recibe las cota inferior y superior del tiempo de ciclo ideal. 
        //Recide el arreglo de allCandidateStations cand, que contiene las estaciones
        //candidatas de cada estacion.
        //Recibe el grafo de activdiades.
        //Recibe la línea de ensamble, que contiene las estaciones.
        //genera las restricciones de unicidad.
        RestrictionGenerator * r = new RestrictionGenerator(minValue,maxValue,cand,graph,al);
        
        //obtén el módelo con restriccioens de unicidad.
        Model * model= r->getModel();
        
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        cout << "------RESTRICCIONES----- \n\n" << endl;
        
        model->print();
        
        //La tabla universo es la matriz de estaciones versus 
        //actividades. 1 significa posible asignación.
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
        
         cout << "\n\n ------RESTRICCIONES PRECEDENCIA BOOLEANAS----- \n\n" << endl;
        vector<string> rPrecedence;
        
        
        int origin, staOrigin;
        
        int dest, staDestination;
        int j = numberStations-1; //indica estaciones, inicia en cero.
        int jDest = 0;
        bool flag = false;  //bandera para cuando la activiad si puede estar en esa estación.
        
        for(int i=0; i<arrPrecedence.size();i++){
            
            origin = arrPrecedence.at(i)->getOrigin();
            dest = arrPrecedence.at(i)->getDestination();
                
            //Mientras j (numero estaciones sea positivo.)
            while(j>0){
                
                
                //Checa si la actividad origin puede estar en estación j
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
                            cout << "NEGACION DEST: " << temp2 << endl;
                            
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
                flag=false;   //se pone la bandera en falso.

            }
            j = numberStations-1;
            
        }
        
        cout << "\n\n ------RESTRICTIONS UNICITY BOOLEANAS----- \n\n" << endl;
        
        
        
        
        vector<string> rUnicity = model->getUnicityRestrictions();
        
        string toString;
        int stationUnicity;
        for(int ii=0; ii< cand->getNumberActivities(); ii++){
            if(cand->getCandStationsForActivity(ii)->hasOnlyOneCandidate()){
                    string UnicityConstr;
                    toString = invHashAux(ii); // de numero a letra
                    UnicityConstr.append(toString);
                    UnicityConstr.append(cand->getCandStationsForActivity(ii)->getCandidatesExtra());
                    rUnicity.push_back(UnicityConstr);
                
            }
        }
        
        
        
        for(int i = 0; i< rUnicity.size() ;i++){
                cout << rUnicity.at(i) << endl;
        }
        
        //cand tiene el numero de actividades de ahi puedo generar la ultima restriccion
        // number of stations numberStations
               
        
        cout << "\n\n ------RESTRICTIONS DURACION BOOLEANAS----- \n" << endl;
        
        int numRecDuration = model->getNumberEquations();
        
        

        vector<Equation *> equations = model->getVectorEquations();

        vector<vector<DurationNode>> groupDN;
        
        // Para cada restriccion de duración
        for(int w=0; w<numRecDuration ; w++){
            
            vector<DurationNode> arr;
            int y= 0;
            Variable * aux;
            //heuristica es el tiempo de ciclo ideal
            int balanceDuration = heuristic - equations[w]->getConstantValue();

            //itera sobre las variables de cada ecuación.
            while(y<equations[w]->getNumVariables()){
                
                aux = equations[w]->getVariable(y);
                // get duration da duractioon, despues i3, y la constante
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
            
            // tomas los nodos base
            arr = groupDN[i];
            
            //esta vacio
            if(arr.size() != 0){

                // ordenas nodos base conforme a su constante.
                groupDN[i] = MergeSort(arr);

                //saco cuantos tengo
                int numDNs= groupDN[i].size();
                //cout << "\n \n";

                for(int j =0; j<numDNs ; j++){
                    
                    // le pone un id a cada nodo.
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

        
        //Vector de duración.
        vector<string> vectorRest ;
        vector<string> * vectorR = &vectorRest;
        
        cout << groupDN.size() << endl;
        //Para cada restriccion
        for(int j =0; j<groupDN.size(); j++){
            
            vector<DurationNode> * vectorDN = &groupDN[j];
            if(vectorDN->size() != 0){
                    DurationTree * tree = new DurationTree(vectorDN, vectorR, groupDN[j][0].getBalanceDuration());
                    tree->buildTree();
            }

            
        }   
        
        
        cout << "Restricciones Generadas:" << vectorR->size() << endl;
        
        //
        //for(int i = 0; i < vectorR->size() ; i++){
        //    //cout << vectorR->at(i) << endl;
        //}
        
        //Sacas el umero de restricciones de duracion
        cout << "Negacion de Restricciones Generadas:" << vectorR->size() << endl;
        
        for(int i = 0; i < vectorR->size() ; i++){
            string negC = constraintNeg(vectorR->at(i), tablaUniverso, numberStations);
            vectorR->at(i) = negC;
            
            //restricción negada.
            cout << vectorR->at(i) << endl;
        }
        
        
        cout << "Integracion Booleana" << endl;
        
        
        /// un mezclador para restricciones binarias.
        BinaryMixer bMixer;

    	//TIME
    	std::chrono::high_resolution_clock::time_point t1;
    	std::chrono::high_resolution_clock::time_point t2;
    	auto duration = 0;

    	//Inicia Tiempo 
    	t1 = std::chrono::high_resolution_clock::now();
        
        //Primera restriccion de duracion entra al mixer. El mixer es donde se van a realizar las operaciones tipo AND.
        string resultadoMixer = vectorR->at(0);
        
        // VectorBr es una clase, auxRtoB es la instancia
        VectorBR auxRtoB(numberStations, vectorR->at(0));
        //Tomamos la primera restriccion binaria de dutación, que sea temp,
        // con ella iniciaremos el for.
        vector<BinaryRestriction> temp = auxRtoB.Br;
        
        cout << "size of temporal,binary restriccion" << endl;
        cout << temp.size() << endl; 
        
        
        cout << "\n Primera Restriccion: " << resultadoMixer << endl;
        
        
        string tempM;
        int contador= 0;
        //sumas duracion, precendencia y unicidad.
        int totalRestrictions = vectorR->size() + rPrecedence.size() + rUnicity.size();
        
        cout << "Total Restricciones: " << totalRestrictions;

        //cout << "\n\n ------RESTRICCIONES PRECEDENCIA BOOLEANAS----- \n\n" << endl;


        vector<VectorBR> rbPrecedence;
        
        //Binarias
        vector<VectorBR> rbDuracion;
            
        //Binarias
        vector<VectorBR> rbUnicity;

        
        //Para cada restriccion
        for(int i = 0; i < rPrecedence.size() ; i++){
    		
            //convertir las restricciones a conjunte de restricciones binarias
            VectorBR auxRtoB(numberStations, rPrecedence.at(i));
            rbPrecedence.push_back(auxRtoB);
            
            temp = bMixer.mix(temp,rbPrecedence.at(i).Br);
            cout << "Iteracion " << contador << "/" << totalRestrictions << endl;
            contador++;


        }
        
        
        //Reperims la operación para las de duración.
        for(int i = 1; i < vectorR->size(); i++){
            //convertir las restricciones duracion a conjunte de restricciones binarias
            VectorBR auxRtoB(numberStations, vectorR->at(i));
            rbDuracion.push_back(auxRtoB);
            temp = bMixer.mix(temp,rbDuracion.at(i-1).Br);
            cout << "Iteracion " << contador << "/" << totalRestrictions << endl;
            contador++;

        }

        


        //Repites para las de unicidad.
        for(int i = 0; i < rUnicity.size() ; i++){
            //convertir las restricciones a conjunte de restricciones binarias
            VectorBR auxRtoB(numberStations, rUnicity.at(i));
            rbUnicity.push_back(auxRtoB);
            temp = bMixer.mix(temp,rbUnicity.at(i).Br);
             cout << "Iteracion " << contador << "/" << totalRestrictions << endl;
            contador++;
           
        }
        

        
        
        
            //imprimir numero de restricciones
        cout << "Numero de restricciones de Duracion: " << vectorR->size() << endl;
        cout << "Numero de restricciones Binarias de Duracion: " << rbDuracion.size() << endl;

        //imprimir numero de restricciones
        cout << "Numero de restricciones de Precedencia: " << rPrecedence.size() << endl;
        cout << "Numero de restricciones Binarias de Precedencia: " << rbPrecedence.size() << endl;

        //imprimir numero de restricciones
        cout << "Numero de restricciones de Unicity: " << rUnicity.size() << endl;
        cout << "Numero de restricciones Binarias de Unicity: " << rbUnicity.size() << endl;
        

        //Notese que cada tabla es una solución en este punto.
        cout << "numero de tablas: " << temp.size() << endl;
        for(int k =0;k<temp.size();k++){
            cout << "Solucion " << k << endl;
            temp.at(k).print();
        }
        
        
        
        if(temp.size()!=0){
            finish = true;

    		//Tiempo Fin
    		t2 = std::chrono::high_resolution_clock::now();
    		duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    		cout << "Tiempo: " << duration << endl;


        }
    
    }
    else
    {
        cout << "No hay solucion, no es feasible hubo almenos una actividad imposible de asignar" << endl;
    }
    
    heuristic = heuristic + gdc;
 
    } // iteracion de tiempo de balanceo


    // PRUEBAS

    
    return true;

}

 




int main(int argc, const char **argv) {

	cout << "Hello world\n";

	bool flag = executeBool();

    // mediante enter el usuario indica que termine el programa.
	cin.get();

	return 0;

}


    



