// Client side implementation of UDP client-server model
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT	 8080
#define MAXLINE 1024



using namespace std;
// Driver code
int main() {

	cout <<"------- Client Started -----------"<<endl;
	int sockfd;
	char buffer[MAXLINE];
	//char *hello = "Hello from client";
	struct sockaddr_in	 servaddr;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	//memset(&servaddr, 0, sizeof(servaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = inet_addr("172.16.15.47");
	int i = 0;
	while(i < 5)
	{	
	int n;
	socklen_t len;
	
		cout <<"\nPlease Enter the Number : ";
		cin.getline(buffer,MAXLINE);


		sendto(sockfd, buffer, sizeof(buffer),0, (const struct sockaddr *) 	&servaddr,sizeof(servaddr));
		cout <<"The Number sent to server is : "<<buffer<<endl;
		i++;
	}
	
	
	

	close(sockfd);
	return 0;
}
