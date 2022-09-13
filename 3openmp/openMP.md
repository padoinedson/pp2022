# Programação Paralela


## openMP Documentation 
https://www.openmp.org/



#openMP hands-on
https://www.openmp.org/wp-content/uploads/omp-hands-on-SC08.pdf




## Códigos Exemplos de openMP utilizados na disciplina.




### compilar programa em C 

> $ gcc  -o p p.c



### compilar programa em C com openmp

> $ gcc -o p   p.c   -fopenmp



### executar um programa

> $ export OMP_NUM_THREADS=4  
> $ ./p


### mapear threadsOpenMP nos cores  

> $ sudo apt install hwloc  
> $ hwloc-bind socket:0.pu:0-1  ./exe  


### bind threads alternating sockets  

> $ export OMP_NUM_THREADS=4  
> $ export GOMP_CPU_AFFINITY=0,8,1,9  
> $ ./exe  


### bind threads to cores respectively  

> $ export OMP_NUM_THREADS=4  
> $ export GOMP_CPU_AFFINITY=8-15  
> $ ./exe  

