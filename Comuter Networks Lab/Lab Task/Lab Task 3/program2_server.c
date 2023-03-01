#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {

	char server_message[256] = "Hi, Yes you have reached the server!";
	char buf[200];
	
	int number1, number2;
	char operator;
	
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
	
	int first_number = recv(client_socket, &number1, sizeof(number1), 0);
    	printf("First number From The Client: %s \n", number1) ;

 

    	int second_number = recv(client_socket, &number2, sizeof(number2), 0);
    	printf("Second number From The Client: %s \n", number2);
    	
    	int operater = recv(client_socket, &operator, sizeof(operator), 0);
    	printf("Operator From The Client: %c \n", operator);
	
	// send the message
	/*recv(client_socket, &buf, sizeof(buf), 0);
	printf("\n %s \n", buf);
	send(client_socket, buf, sizeof(buf), 0);*/
	
	//performing operations.
    	int result;
	
    	if(op == '+')
    	{
        	result = number1 + number2;
        
    	}
    	
    	else if(op == '-')
    	{
        	result = number1 - number2;
        
    	}
    	
    	else if(op == '*')
    	{
        	result = number1 * number2;
        
    	}
    	
    	else if(op == '/')
    	{
        	result = number1 / number2;
    	}
    	
    	printf("Result from the Server: %s \n", result);

	// close the socket
	close(server_socket);
	
	return 0;
}
