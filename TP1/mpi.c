#define _GNU_SOURCE // para usar sched_getcpu
#include <sched.h>
#include <stdio.h>
#include <mpi.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int numprocs, rank, namelen;
  char processor_name[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Get_processor_name(processor_name, &namelen);
  unsigned int cpu_num, node_num;
  cpu_num = sched_getcpu();
  if (cpu_num % 2 == 0)
    node_num = 0;
  else
    node_num = 1;
  printf("Hola desde el proceso %d en cpu %d, socket %d, nodo %s. Total de procesos: %d\n", rank, cpu_num, node_num, processor_name, numprocs);
  MPI_Finalize();
  return 0;
}
