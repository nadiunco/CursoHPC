#define _GNU_SOURCE // para usar getcpu
#include <omp.h>
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>

int main( int argc, char *argv[]) {
   char hostname[128];
   gethostname(hostname, sizeof(hostname));

   char* s = getenv("OMP_NUM_THREADS");
   printf("OMP_NUM_THREADS: %s\n",(s!=NULL)? s : "sin definir");

   #pragma omp parallel
   {
      unsigned int cpu_num, node_num;
      getcpu(&cpu_num, &node_num);
      printf("El hilo %3d ejecuta en el core %3d, socket %d, del nodo %s\n", omp_get_thread_num(), cpu_num, node_num, hostname);
   }
   return 0;
}
