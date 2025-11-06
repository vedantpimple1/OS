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

    // 2. Open FIFO for reading
    fd = open(fifo_path, O_RDONLY);

    // 3. Read data from FIFO
    read(fd, arr, sizeof(arr));

    printf("Received message: %s\n", arr);
    close(fd);
    return 0;
}

