#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    pid_t pid, mypid;
    printf("A\n");
    pid = fork();    /* create a new child process */
    if (pid == -1) { /* check and handle error return value */
        fprintf(stderr, "fork failed!\n");
        exit(pid);
    }
    if (pid == 0) { /* the child process */
        mypid = getpid();
        printf("I'm the child! fork returned %d, my pid %d\n", pid, mypid);
    } else { /* the parent process */
        mypid = getpid();
        printf("I'm the parent! fork returned %d, my pid %d\n", pid, mypid);
    }
    printf("B:%d\n", mypid);

    return 0;
}
