#include <stdio.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork(); // Create a child process

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // This is the child process
        printf("Hello from the child process! PID: %d\n", getpid());
    } else {
        // This is the parent process
		sleep(1);
        printf("Hello from the parent process! PID: %d, Child PID: %d\n", getpid(), pid);
    }

    return 0;
}