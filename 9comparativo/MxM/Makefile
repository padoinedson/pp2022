
all: compile

compile:
	clear 
	gcc  	-o s 	 1_mult_matriz_sequencial.c 
	gcc  	-o t 	 2_thread_mult_matriz.c -lpthread
	gcc  	-o o 	 3_openmp_mult_matriz.c -fopenmp
#	mpicc 	-o m 	 4_mpi_mult_matriz.c
#	nvcc 	-o c 	 5_cuda_mult_matriz.cu

	@echo "Compilaçao concluida"

flag:
	clear 
	gcc  	-o s 	-O3 1_mult_matriz_sequencial.c 
	gcc  	-o t 	-O3 2_thread_mult_matriz.c -lpthread
	gcc  	-o o 	-O3 3_openmp_mult_matriz.c -fopenmp
#	mpicc 	-o m 	-O3 4_mpi_mult_matriz.c
#	nvcc 	-o c 	-03 5_cuda_mult_matriz.cu

	@echo "Compilaçao concluida"

clean:
	rm -rf ?



