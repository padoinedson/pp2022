# comentario -> para executar digite make 

all: compile
	
compile:
	clear
	@echo " "
	
	gcc -o 1   1thread_cria_threads.c			-lpthread
	gcc -o 11  1thread_cria_threads_var-global.c 		-lpthread

	gcc -o 2   2thread_incrementa_vetor.c 			-lpthread

	gcc -o 3   3thread_soma_vetor.c				-lpthread

	gcc -o 4   4thread-mutex.c				-lpthread
	gcc -o 41  4thread-mutex_erro.c				-lpthread

	gcc -o 5   5t1-thread-2arg.c          			-lpthread
	gcc -o 51  5t1-thread-criarNth.c      			-lpthread
#	gcc -o 5d 5t1-thread-criarNth_e_recebe_retorno_var_local.c -lpthread


	@echo "Compilaçao concluida"
	@echo " "

teste:
	gcc -o 1  1thread.c                  -lpthread
	
clean:
	rm -rf *.out
	rm -rf ?
	rm -rf ??

hoje:
	date

