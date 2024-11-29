#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    int process_id;
    int status;

    perror("Could not open data file");
    process_id = fork();

    if (process_id < 0) {
        perror("fork failed\n");
        return 1;
    }

    if (process_id == 0) {
        printf("this is from child process\n");
        execlp("/bin/ls", "ls", NULL);
        perror("execlp failed\n");
        return 1;
    } else {
        printf("this is from parent process\n");
        int pid = wait(&status);
        if (pid > 0) {
            if (WIFEXITED(status)) {
                printf("Child %d completed with exit status %d\n", pid, WEXITSTATUS(status));
            } else {
                printf("Child %d terminated abnormally\n", pid);
            }
        } else {
            perror("wait failed");
        }
    }
    printf("process ends %d\n", process_id);
    return 0;
}