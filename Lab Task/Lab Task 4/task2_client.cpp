// Client side implementation of UDP client-server model
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT 8080
#define MAXLINE 1024

using namespace std;
// Driver code
int main()
{

	cout << "------- Client Started -----------" << endl;
	int sockfd;
	char buffer[MAXLINE];
	// char *hello = "Hello from client";
	struct sockaddr_in servaddr;

	// Creating socket file descriptor
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	// memset(&servaddr, 0, sizeof(servaddr));

	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;

	int n;
	socklen_t len;

	while (true)
	{
		cout << "Enter The String To Send : ";
		string user_string;
		cin >> user_string;

		//sending string to server.
		sendto(sockfd, user_string.c_str(), strlen(user_string.c_str()),0, (const struct sockaddr *)&servaddr,sizeof(servaddr));

		if (user_string == "exit")
        {
            cout <<"Code Terminated."<<endl;
            break;
        }
		
		printf("\nMessage sent to server ..... \n");

		//receiving string from server.
		n = recvfrom(sockfd, (char *)buffer, MAXLINE,0, (struct sockaddr *)&servaddr,&len);
		buffer[n] = '\0';


		if (strcmp(buffer,"exit")==0)
        {
            cout <<"Code Terminated."<<endl;
            break;
        }
        
		cout << "Message From Server : " << buffer << endl;
		cout << "Number of Bytes Received : " << n << endl;

		cout <<endl<<endl;
	}

	close(sockfd);
	return 0;
}





