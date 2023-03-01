#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {

	char server_message[256] = "Hi, Yes you have reached the server!";
	char buf[200];
	// create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	
	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 5);
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	
	// sending 5 times to client
	
	int i = 0; 
	
    	while (i <= 5)
    	{
    		
    		// Recieving string from client
		recv(client_socket, &buf, sizeof(buf), 0);
		
		printf("Recieved string from client: %s \n", buf);

		//reversing the string.
		string str(buf);
		string reverse_string = string(str.rbegin(), str.rend());
		
		printf("Reversed string:  %s \n", reverse_string);
    		cout << "\nReversed string sent back to client." << endl;
    		printf("\nReversed string sent back to client.");
    
        	// Sending the reverse string to the server
        	send(client_socket, rev.c_str(), sizeof(buf), 0);
        	
        	i++;
    	}
	
	// send the message
	/*recv(client_socket, &buf, sizeof(buf), 0);
	printf("\n %s \n", buf);
	send(client_socket, server_message, sizeof(server_message), 0);*/

	// close the socket
	close(server_socket);
	
	return 0;
}
