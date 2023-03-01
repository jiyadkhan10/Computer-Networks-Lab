// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
using namespace std;

#define PORT 8080
#define MAXLINE 1024

// Driver code
int main()
{
    cout << "-------- Server Started ----------" << endl;
    int sockfd;
    char buffer[MAXLINE];
    // char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // memset(&servaddr, 0, sizeof(servaddr));
    // memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int n;
    socklen_t len;

    len = sizeof(cliaddr); // len is value/resuslt

    while (true)
    {

        n = recvfrom(sockfd, (char *)buffer, sizeof(buffer),0, (struct sockaddr *)&cliaddr,&len);
        buffer[n] = '\0';

        if (strcmp(buffer, "exit") == 0)
        {
            cout << "Code Terminated." << endl;
            break;
        }

        cout << "\nClient Sent : " << buffer << endl;
        cout << "Total Bytes Received : " << n << endl;

        cout << "\n\nEnter The String To Send : ";
        string client_string;
        cin >> client_string;

        sendto(sockfd, client_string.c_str(), strlen(client_string.c_str()),0, (const struct sockaddr *)&cliaddr,len);

        if (client_string =="exit")
        {
            cout << "Code Terminated." << endl;
            break;
        }

    }

    return 0;
}
