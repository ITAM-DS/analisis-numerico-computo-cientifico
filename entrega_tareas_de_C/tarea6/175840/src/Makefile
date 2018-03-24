CC=gcc
CFLAGS=-Wall
CLIBS=-lblas

compila_dgemv: 
	$(CC) $(CFLAGS) dgemv_mult_mat_vec.c definiciones.h funciones.c -o programa_dgemv.out $(CLIBS)

compila_dger: 
	$(CC) $(CFLAGS) dger_mult_mat_vec.c definiciones.h funciones.c -o programa_der.out $(CLIBS)	

compila_dgemm: 
	$(CC) $(CFLAGS) dgemm_mult_mat.c definiciones.h funciones.c -o programa_dgemm.out $(CLIBS)		

compila_dgemm_trick: 
	$(CC) $(CFLAGS) dgemm_mult_mat.c definiciones_trick.h funciones.c -o programa_dgemm_trick.out $(CLIBS)	

compila_dsymm: 
	$(CC) $(CFLAGS) dsymm_mat_mat.c definiciones.h funciones.c -o programa_dsymm.out $(CLIBS)		
			
ejecuta_dgemv: compila_dgemv
	./programa_dgemv.out 3 2 A.txt v.txt

ejecuta_dgemv_1: compila_dgemv
	./programa_dgemv.out 20 5 A1.txt v1.txt	

ejecuta_dger: compila_dger
	./programa_der.out 3 2 A.txt v.txt w.txt

ejecuta_dgemm: compila_dgemm
	./programa_dgemm.out 3 2 2 3 AA.txt B.txt

ejecuta_dgemm_1: compila_dgemm
	./programa_dgemm.out 10 10 10 10 AA1.txt BB1.txt	

ejecuta_dgemm_trick: compila_dgemm_trick 
	./programa_dgemm_trick.out 3 2 2 3 AA.txt B.txt

ejecuta_dgemm_trick_1: compila_dgemm_trick 
	./programa_dgemm_trick.out 10 10 10 10 AA1.txt BB1.txt	

ejecuta_dsymm: compila_dsymm
	./programa_dsymm.out 5 5 A_sym.txt B_sym.txt C_sym.txt

clean:
	-rm -f *.out
