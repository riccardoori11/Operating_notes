#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  int x = 100;

  int rc = fork();
  if (rc < 0) {

    fprintf(stderr, "error");
  }

  else if (rc == 0) {

    printf("%d \n", x);
  }

  else {
    x = 500;
    printf("%d \n", x);
  }

  return 0;
}
