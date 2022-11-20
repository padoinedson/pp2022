

all: compile
	
compile:
	mpicc -o 1  1mpi_cria_processos.c 

	mpicc -o 2  2mpi_incrementa.c 
	mpicc -o 21 2mpi_soma.c

	mpicc -o 31 3mpi_incrementa_vetor.c 
	mpicc -o 32 3mpi_soma_vetor.c

	mpicc -o 41 4mpi_soma_e_multiplica.c
	mpicc -o 61 6mpi_recv_any_souce.c
	mpicc -o 71 7mpi_incrementa_DEBUG.c -D DEBUG


clean:
	rm ?
	rm ??
	rm -rf *.out


