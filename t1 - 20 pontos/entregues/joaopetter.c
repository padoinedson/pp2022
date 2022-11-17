#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tempo.h"
#include <math.h>


int  parte;
int num_thread = 13;

int ini[20];
char senha[40]= "!!!#(,4#";
time_t start, end;
int threadShare;

void *loop(void *arg);



pthread_mutex_t m;



void main(int argc, char *argv[]){
time(&start);

pthread_mutex_init(&m,NULL); 



threadShare = ceil(8/num_thread);


pthread_t pt[num_thread];
 ini[0]=0;
 int i;
 for (i = 0; i < num_thread; i++){
  int* a = malloc(sizeof(int));
  *a = i;
 pthread_create(pt+i, NULL, loop, a);
 //printf("\n.:thread %d criada para rodar a partir da posição = %d ", i, ini[i]);
ini[i+1] = ini[i] + parte;

 }
   for (i = 0; i < num_thread; i++){
 pthread_join(pt[i], NULL);
 printf("\n.:thread %d fechada ", i);

 }




}



void * loop(void *arg){
 
 int pos = *((int *)arg);

 	

  
  for (char v1 = 33; v1 < ((127/num_thread) * (pos +1)); v1++){ 

     for (char v2 = 33; v2 < ((127/num_thread) * (pos +1)); v2++){    

         for (char v3 = 33; v3 < ((127/num_thread) * (pos +1));v3++){

             for (char v4 = 33; v4 < ((127/num_thread) * (pos +1)); v4++){  

                  for (char v5 = 33; v5 < ((127/num_thread) * (pos +1)); v5++){  

                    for (char v6 = 33; v6 < ((127/num_thread) * (pos +1)); v6++){  

                      for (char v7 = 33; v7 < ((127/num_thread) * (pos +1)); v7++){  
                        
                        for (char v8 = 33; v8 < ((127/num_thread) * (pos +1)); v8++){  
                                  
          
          char linha[40]= "";     
          strncat(linha, &v1, 1);
          strncat(linha, &v2, 1);
          strncat(linha, &v3, 1);
          strncat(linha, &v4, 1);
          strncat(linha, &v5, 1);
          strncat(linha, &v6, 1);
          strncat(linha, &v7, 1);
          strncat(linha, &v8, 1);
          //printf("look at me ---> %d", pos);
            printf("%s\n", linha);

            
           int ok = strcmp  (senha, linha);
           
        
	     if (ok == 0){
        pthread_mutex_lock(&m);
		    printf("senha correta\n\n");
        printf("\n\n senha: %s \n\n",  linha);
        time(&end);
       double time_taken = end - start;

       printf("Tempo: %f \n\n", time_taken);

	     pthread_mutex_unlock(&m);
 
     exit(1);
    }else{
   
	//	printf("senha incorreta \n\n");
   }
   
                } 
               } 
              } 
             } 
           } 
          }        
        }
      }
    }

