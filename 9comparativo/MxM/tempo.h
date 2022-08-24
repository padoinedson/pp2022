
#include <sys/time.h>
#include <string.h>

struct timeval t1, t2;
struct timezone tz1, tz2;

char MSGLOG[200];  // armazena o log no arquivo


void tempo1() {
   gettimeofday(&t1, &tz1);
}

void tempo2() {
   gettimeofday(&t2, &tz2);
}

void tempoFinal(const char *medida, char *nomeArquivo, char *msglog) {
   char tempo[50];
   long int micro = (((t2.tv_sec*1000000)+t2.tv_usec) - ((t1.tv_sec*1000000)+t1.tv_usec));
    if (strcmp(medida,"")==0)
       sprintf(tempo,"Tempo total= %.2f s\n", micro / 1000000.0);
    if (strcmp(medida,"micro segundos")==0)
       sprintf(tempo,"Tempo total= %ld us\n", micro);
    if (strcmp(medida,"mili segundos")==0)
       sprintf(tempo,"Tempo total= %.2f ms\n", micro / 1000.0);
    if (strcmp(medida,"segundos")==0)
       sprintf(tempo,"Tempo total= %.2f s\n", micro / 1000000.0);
    if (strcmp(medida,"minutos")==0)
       sprintf(tempo,"Tempo total= %.2f min\n", (micro / 1000000.0) / 60);
    if (strcmp(medida,"horas")==0)
       sprintf(tempo,"Tempo total= %.2f horas\n", ((micro / 1000000.0) / 60)) / 60;

    printf("\n...: %s\n",tempo);


}

