#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 1234

int main(int argc, char const *argv[])
{
    struct sockaddr_in serv_addr;

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    inet_pton(AF_INET, "193.196.38.206", &serv_addr.sin_addr);

    // connect to the server
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (0 == 0)
    {
        for (size_t i = 0; i < 512; i++)
        {
            for (size_t j = 0; j < 512; j++)
            {
                char message[50];
                sprintf(message, "PX %zu %zu 96E3A1ab\n", i, j);
                write(sock, message, strlen(message));
            }
        }
    }
}