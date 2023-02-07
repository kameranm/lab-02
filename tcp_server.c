/* A simple server in the internet domain using TCP
 * Answer the questions below in your writeup
 */

/* A simple server in the internet domain using TCP
 * Answer the questions below in your writeup
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
/* What is argc and *argv[]?
Argc is an integer that represents how many arguments are in the command line while *argv[] is simply the name of the program that is being executed.
     */
    int sockfd, newsockfd, portno;
    /* 2. What is a UNIX file descriptor and file descriptor table?
A UNIX file descriptor is essentially an input output stream that uses integer inputs that connect to the file descriptor table that are seen in the stream such as stdin, or stderr. Applications can change file descriptors to access the descriptor table and the object array. 
     */
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;
    /* 3. What is a struct? What's the structure of sockaddr_in?
    A struct is a type of data declaration that groups different variables into one place. The structure of sockaddr_in is used to store addresses for servers in internet connections. 
     */
    
    int n;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    /* 4. What are the input parameters and return value of socket()
The input parameters of socket() are the domain which is an integer used to specify the communication domain, the communication type (ex: Sock stream which has to do with TCP communication), and the protocol value for IP which will most of the time be 0 which signals it has gone through. If it is -1, it has an error. 
     */
    
    if (sockfd < 0) 
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");
    /* 5. What are the input parameters of bind() and listen()?
    The input parameters of bind() are the descriptor of a socket, the pointer used for the address of a socket, and the size of a socket address.
The input parameters of listen() are the socket descriptor returned by the socket function and the number of connections allowed. 
     */
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    while(1) {
        /* 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
While(1) is an infinite Loop which runs until there is a break so in terms of the serer, it is used to constantly receive data from the clients. If there are multiple connections to hande simultaneously, it may send the wrong return data packets to aclient and the timing would be slower. 
        */
        
	char buffer[256];
        newsockfd = accept(sockfd, 
                    (struct sockaddr *) &cli_addr, 
                    &clilen);
	/* 7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         * The command fork() can help handle multiple clients because it creates a child process that runs in sync with the parent process which runs concurrently with each other allowing for multiple clients at the same time without losing efficiency. 
         */
        
	if (newsockfd < 0) 
             error("ERROR on accept");
	bzero(buffer,256);
        
	n = read(newsockfd,buffer,255);
        if (n < 0) 
            error("ERROR reading from socket");
        printf("Here is the message: %s\n",buffer);
        n = write(newsockfd,"I got your message",18);
        if (n < 0) 
            error("ERROR writing to socket");
        close(newsockfd);
    }
    close(sockfd);
    return 0; 
}
  
/* This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
A system call is the way a computer makes a request for an action from the operating system where it is conducted such as bind() and listen().
