# comentario -> para executar digite make 

all: compile
	
compile:
	clear

	gcc -o 3 3soma_vetor_var_global.c 		-lpthread
	gcc -o 4 4soma_vetor_var_global_mutex.c 	-lpthread
	gcc -o 5 5soma_vetor_var_local_mutex.c 		-lpthread


	@echo "Compilaçao concluida"

clean:
	rm -rf *.out
	rm -rf ?
	rm *.log
