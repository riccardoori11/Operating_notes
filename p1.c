#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  printf("Hello pid: %d \n", (int)getpid());

  int rc = fork();

  if (rc == 0) {

    printf("Child: %d \n", (int)getpid());

    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("p1.c");
    myargs[2] = NULL;

    execvp(myargs[0], myargs);
    printf("execvp has failed");

  }

  else if (rc < 0) {

    fprintf(stderr, "fork has failed \n");
    exit(1);
  }

  else {
    int rc_wait = wait(NULL);
    printf("parent of %d (rc_wait: %d) (pid:%d)\n", rc, rc_wait, (int)getpid());
  }

  return 0;
}
