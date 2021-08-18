#define _GNU_SOURCE // para usar getcpu -nad
#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main( int argc, char *argv[]) {
   char hostname[128];
   gethostname(hostname, sizeof(hostname));
   unsigned int cpu_num, node_num;
   getcpu(&cpu_num, &node_num);
   printf("Ejecutando en nodo %s, core %d, socket %d\n", hostname, cpu_num, node_num);
   return 0;
}
