#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        char *argv[] = {"ls", "-l", "-r", (char*)0};
        execv("/bin/ls", argv);
        printf("child process\n");
    }
    else if (pid > 0) {
        printf("parent process\n");
    }
    else {
        printf("fork failed\n");
    }
    return 0;
}
