
//A.c

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    char *arr[7];
    int n;
    int i;
    for (i = 1; i < argc; i++) {
        arr[i - 1] = argv[i];
    }
    arr[i - 1] = NULL;
    for (i = 0; i < argc - 1; i++) {
        printf("%s\t", arr[i]);
    }

    printf("\n");
    char *temp;
    
    int num_args = argc - 1; 
    for (int i = 0; i < num_args - 1; i++) {
        for (int j = 0; j < num_args - i - 1; j++) {
            if (atoi(arr[j]) > atoi(arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        printf("\nThis is child process\n");
        execv(arr[0], arr);
    } else {
        wait(&status);
        printf("\nThis is parent process\n");
        
        for (int i = 0; i < argc - 1; ++i) {
            printf("arr[%d]=%s\n", i, arr[i]);
        }
    }
}

//b.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Inside b.out:\n");
    
    for (int i = argc - 1; i >= 0; i--) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    
    return 0;
}


