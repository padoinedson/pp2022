
all: 1 2 3 4 6 7 8 9
	
1:
	gcc -o 1a 	1openmp_cria_threads.c 					-fopenmp
	gcc -o 1b 	1openmp_cria_threads_single.c 			-fopenmp
	gcc -o 1c 	1openmp_cria_threads_varshared.c 			-fopenmp
	gcc -o 1d 	1openmp_cria_threads_varprivate.c 			-fopenmp
	gcc -o 1e 	1openmp_cria_threads_varfirstprivate.c 		-fopenmp

2:
	gcc -o 2a 	2openmp_parallel_for.c			-fopenmp
	gcc -o 2b 	2openmp_parallel_for_incrementa_vetor.c			-fopenmp
	gcc -o 2c 	2openmp_parallel_for_schedule.c  		-fopenmp
	gcc -o 2d 	2openmp_parallel_for_schedule_nowait.c  	-fopenmp	
	gcc -o 2e 	2openmp_parallel_for_schedule_collapse.c   	-fopenmp
3:
	gcc -o 3a 	3openmp_soma_vetor_parallel_for_reduction.c 		-fopenmp
	gcc -o 3b 	3openmp_reduction.c 			-fopenmp
	gcc -o 3c 	3openmp_reduction2.c 			-fopenmp
4:
	gcc -o 4a 	4openmp_mutex_critical.c 	  	  	-fopenmp
	gcc -o 4b 	4openmp_mutex_critical_erro.c 	  	  	-fopenmp

6:
	gcc -o 6a 	6openmp_time.c 				-fopenmp
	gcc -o 6b 	6openmp_master_slave_barrier.c 	-fopenmp

7:
	gcc -o 7a 	7openmp_section.c 	  	  		-fopenmp

8:
	gcc -o 8a 	8openmp_task.c 	  	  		-fopenmp

9:
	gcc -o 9a 	9openmp_get_set_num_threads.c 	-fopenmp
	gcc -o 9a 	9openmp_single.c 	-fopenmp

clean:
	rm ??
