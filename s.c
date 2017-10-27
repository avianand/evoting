//server
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <sys/errno.h>

#define PORT 8080

//functions used in the server program 
// 1. Main
// 2. Handler
// 3. Login
// 4. new_user_register

/*#ifndef ERESTART
#define ERESTART EINTR
#endif
extern int errno; */
void dostuff(int);
void error(const char *msg)
{
    perror(msg);
    exit(1);
} /* function prototype */
int main()
{
    int server_fd, new_socket,valread;
    int pid; //sokcet descripter = server_fd
	/* port number */
    /* socket accepting the request */
    struct sockaddr_in my_addr;    /* address of this service */
    int addrlen = sizeof(my_addr);
   // socklen_t alen;       /* length of address structure */
    int sockoptval = 1;
    
    //file handling in server
    int filestream;

    filestream = fopen("userdata.txt","a+");   //a+	opens a text file in both reading and writing mode
    if(filestream==NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

   // char *hello="Cognnected to server. Welcome to E-Voting System.";

    //Check if socket is cerated or not
    if((server_fd=socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket not created server\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("socket created in server\n");
    }
    /* allow immediate reuse of the port 
    The setsockopt system call allows us to set special options on a socket. In this case, we use setsockopt to set SO_REUSEADDR. 
    This allows us to reuse the port immediately as soon as the service exits. 
    Some operating systems will not allow immediate reuse on the chance that some packets may still be en route to the port. 
    Allowing us to reuse the port immediately is a huge help when debugging requires us to start and restart the server over and over again.
    */
    // Forcefully attaching socket to the port 8080
	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &sockoptval, sizeof(sockoptval)))
    {
        perror("setsockopt ");
        exit(EXIT_FAILURE);
    }

    /* bind the socket to our source address */
    memset((char*)&my_addr, 0 , sizeof(my_addr)); /* 0 out the structure */
    
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY; /* INADDR_ANY is used when you don't need to bind a socket to a specific IP. When you use this value as the address when calling bind(), the socket accepts connections to all the IPs of the machine */
    my_addr.sin_port = htons( PORT );

    if (bind(server_fd, (struct sockaddr *)&my_addr, sizeof(my_addr)) < 0) 
    {
		perror("bind failed");
		exit(EXIT_FAILURE);
    }
    else{
        printf("Binded.");
    }
    
    /* set the socket for listening (queue backlog of 5) */
    if (listen(server_fd, 5) < 0) 
    {
		perror("listen failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("listening...\n");
    }
    /* loop, accepting connection requests */
     /*for (;;) 
    {
        while ((rqst = accept(server_fd, (struct sockaddr *)&my_addr, (socklen_t*)&addrlen)) < 0) 
        {
			/* we may break out of accept if the system call 
                        was interrupted. In this case, loop back and 
                        try again */
                      /* if ((errno != ECHILD) && (errno != ERESTART) && (errno != EINTR)) 
                        {
                                perror("accept failed");
                                exit(EXIT_FAILURE);
                        } 
        }
    } */
    
    while(1)
    {
        new_socket = accept(server_fd, (struct sockaddr *)&my_addr, (socklen_t*)&addrlen);
        if (new_socket <0)
        {
           perror("accept");
           exit(EXIT_FAILURE);
        }
        pid = fork();
        if (pid < 0)
            error("ERROR on fork");
        if (pid == 0)  {
            close(server_fd);
            dostuff(new_socket);
            exit(0);
        }
    }
   /* valread = read(new_socket , buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket, hello, sizeof(hello),0);
    printf("Hello message sent\n");
    */ 
    return 0;
    getchar()
    fclose(filestream);
}

void dostuff(int sock)
{
    int n;
    char buffer[1024];

    bzero(buffer, 1024);
    n = read(sock, buffer, 1024);

    if(n<0) error("error in reading from socket");
    printf(" message from client: %s\n", buffer);
    n=write(sock, "Message received",36);
    if(n<0) error("error writing to a socket");
}

//handler will handle all the incoming and outgoing comminication from and  into the server.
void handler(int a)
{
    if(a==1)
    {

    }
    else
    {
        
    }
}

//authorize login and send message back to client via handler
int login(char login[30], char pass[30]) 
{
    FILE *file;
    char user2[50], pass2[50], line[128];
    file = fopen("password.txt", "r");
    char array[128][128];

    if (file) 
    {
        
       while (fgets(line, sizeof line, file)
       {
        if((user2 = strtok(line, " \t") && (pass2 = strtok(NULL, " \t"))
        
            if ((strcmp(login, user2) == 0) && (strcmp(pass, pass2) == 0)) 
            {
                    printf("\n>>>User and password correct!<<<\n");
            }
            else 
            {
                    printf("\n>>>User or password incorrect!<<<\n");
                    getchar();
            }
        };
    }
    else printf("File was not found");
    fclose(file);
    return 0;
}

//update the registration details of new user
/*void new_user_register()
{
    
}
*/

