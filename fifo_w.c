#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char *fifo_path = "/tmp/myfifo";
    char arr[100];

    // 1. Create FIFO file if not exists
    mkfifo(fifo_path, 0666);

    // 2. Open FIFO for writing
    fd = open(fifo_path, O_WRONLY);

    printf("Enter message to send: ");
    fgets(arr, sizeof(arr), stdin);

    // 3. Write message into FIFO
    write(fd, arr, sizeof(arr));

    close(fd);
    return 0;
}

