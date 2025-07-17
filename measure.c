#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define N 1000000

int main(int argc, char *argv[]) {

  struct timeval start, end;

  gettimeofday(&start, NULL);
  for (int i = 0; i < N; i++) {

    read(0, NULL, 0);
  }

  gettimeofday(&end, NULL);

  int seconds = end.tv_sec - start.tv_sec;
  int u_sec = end.tv_usec - start.tv_usec;

  double total = (seconds * 1e6 + u_sec) / N;

  printf("Average time is %f microseconds \n", total);

  return 0;
}
