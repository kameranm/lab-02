// Server side C/C++ program to demonstrate Socket programming 
// Here's some include statements that might be helpful for you
// Server side C/C++ program to demonstrate Socket programming 
// Here's some include statements that might be helpful for you
#include <string> 
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[]) 
{ 
	// check to see if user input is valid
	char socket_read_buffer[1024];
	
	// TODO: Fill out the server ip and port
	std::string server_ip = "0.0.48.57"; // 
	std::string server_port = "12345"; // whicher port I wanted above 8000

	int opt = 1;
	int client_fd = -1;

	// TODO: Create a TCP socket()

    client_fd = socket(AF_INET, SOCK_STREAM, 0); // from sample code on web linked

	// Enable reusing address and port
	if (setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
		return -1;
	}

	// Check if the client socket was set up properly
	if(client_fd == -1){
		printf("Error- Socket setup failed");
		return -1;
	}

	// Helping you out by pepping the struct for connecting to the server
	struct addrinfo hints;
	struct addrinfo *server_addr;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	getaddrinfo(server_ip.c_str(), server_port.c_str(), &hints, &server_addr);

	// TODO: Connect() to the server (hint: you'll need to use server_addr)
    if (connect(client_fd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) { // syntax from client link 
		printf("ERROR Connecting");
	}
    // TODO: Retreive user input
    printf("Please enter the message: "); // taken from client link
    bzero(socket_read_buffer,1024); 
    fgets(socket_read_buffer,1023,stdin);

    // TODO: Send() the user input to the server
    send(client_fd, socket_read_buffer, 1024, 0);
	
    // TODO: Recieve any messages from the server and print it here. Don't forget to make sure the string is null terminated!
	bzero(socket_read_buffer, 1024); // code also from client link 
    read(client_fd, socket_read_buffer, 1024);
    printf("Message from server: %s", socket_read_buffer);


    // TODO: Close() the socket
    close(client_fd);

	return 0; 
} 
