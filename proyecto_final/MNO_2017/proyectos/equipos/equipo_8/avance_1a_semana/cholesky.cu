
__global__ void choleskyParalelo(float *db, int num){
	int id=threadIdx.x + blockIdx.x*blockDim.x;
	int x=0;
	int inicio=0;
	int k=0, N=num;
	int id1=id+inicio, ids=id,id2;
	int N2 = N;
	int NN=0, KK=0;
	
	while(k < N){
		id1=id+inicio;
		//Checamos si es un elemnto de la diagonal
		if(id1 == inicio){
			db[id1] = sqrt(db[id1]);
		}else //si no es elemento de la diagonal, lo dividimos por el elemento diagonal de su columna
		{
			x=0;
			while(id1 <N2){
			
				while(x<1000)
					x++;
				__syncthreads();	
				db[id1] = db[id1]/db[inicio];
				
				id1 += gridDim.x * blockDim.x;
			__syncthreads();
			}
			//__syncthreads();//hacemos que todos los threads esperen a los que faltan
			
			
		}__syncthreads();
		//id=ids;
		inicio += (N-k); //Preparo el siguiente salto al siguiente elemento diagonal
		
		
		NN = N2; //Empiezo actaulizar valores de las columnas restantes a la actualizada
		KK = k+1;//cada columna posterior tiene 1 elemento menos a la anterior
		
		while(NN < (int)N*(N+1)/2){
			id2=id + NN; // saltamos a la siguiente columna
			while(id2 < NN + (N-KK)){
				db[id2] = db[id2] -db[id + KK]* db[KK];
				 
				id2 += gridDim.x * blockDim.x;
				__syncthreads();
			}
			//__syncthreads();
			
			NN += (N-KK);
			KK++;
		
		}
		//__syncthreads();
		k++; //pasamos a la siguiente columna
		N2 += (N-k); //Siguiente elemento diagonal
		__syncthreads();
		
	
	}	
	
}