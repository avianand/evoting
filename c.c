#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include <sys/errno.h>
#define PORT 8080

//function in client program
//1. main_menu
//2. new_user
//3. existing_user
 
//interface
char stream[1000],stream1[1000];

int main()
{
    

   
    int sockfd=0; //scoket file descripter
    	/* our address */
    struct sockaddr_in address;
    struct sockaddr_in serv_addr;
    int sockoptval = 1;
    int valread;
    char buffer[1024]={0};
    char *hello = "This is the client's message."; //just for test purpose


    //a alerts user with sound

    

    //create socket in client side
    /*
        sockfd: socket descriptor, an integer
        domain: integer, communication domain e.g., AF_INET (IPv4 protocol) , AF_INET6 (IPv6 protocol)
        type: communication type
        SOCK_STREAM: TCP(reliable, connection oriented)
        protocol: Protocol value for Internet Protocol(IP), which is 0. This is the same number which appears on protocol field in the IP header of a packet.(man protocols for more details)
    */
    //check if socket is created or not
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        perror("\ncannot create socket\n");
        exit(EXIT_FAILURE);
    } 
    else
    {
        printf("sock created in client\n \a");
    }
    // struct sockaddr_in serv_addr;
    // /* Initialize sockaddr_in data structure */
    // serv_addr.sin_family = AF_INET;
    // serv_addr.sin_port = htons(5000); // port
    // serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* we use setsockopt to set SO_REUSEADDR. This allows us */
	/* to reuse the port immediately as soon as the service exits. */
	/* Some operating systems will not allow immediate reuse */
	/* on the chance that some packets may still be en route */
	/* to the port. */

	//setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &sockoptval, sizeof(int));
    
        /* set up our address */
        /* htons converts a short integer into the network representation */
        /* htonl converts a long integer into the network representation */
        /* INADDR_ANY is the special IP address 0.0.0.0 which binds the */
        /* transport endpoint to all IP addresses on the machine. */
    
        memset((char*)&serv_addr, 0, sizeof(serv_addr));  /* 0 out the structure */
        serv_addr.sin_family = AF_INET;   /* address family */
        serv_addr.sin_port = htons(PORT);
        serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    

    /* Attempt a connection */
       if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            printf("Error : Connect Failed \n");
            exit(EXIT_FAILURE);
        }
        
        //recv(sockfd, &server_response, sizeof(server_response),0);  
        send(sockfd , hello , strlen(hello) , 0 );
        printf("message sent from client side\n");
        valread = read( sockfd , buffer, 1024);
        printf("%s\n",buffer );
        
    
    return 0;
}
void main_menu()
{
    char choice;
    printf("Welcome to the E-Voting System\n");
    
    printf("Please choose from the following options: \n \b a. New User \t b. Existing User\n :"); 
    choice = getche();
    if(choice=a)
    {
        new_user(); 
    }
   else if(choice=b)
    {
       existing_user();
    }
    else
    {
        printf("\nError: Choose from the available options.\n")
    }
}

void new_user()
{
    
    
    //File handling
      FILE *filepointer1 = fopen("newuser.txt", "w"); //temp file
      if (fptr == NULL)
      {
          printf("Could not open file newuser.txt"); 
          return 0;
      }
      
      
        //interface  
            printf("\n Welcome to the new user registration portal. Please Enter the following Details. \n ");
            printf("\nFirst Name: ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s\t",stream);
            printf("\nLast Name: ");
                fgets(stream,50,stdin);  //flush the stream before continuing frwrd
                fprintf(filepointer1,"%s\n",stream);
            printf("\nDate of Birth: ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s\n",stream);
            printf("\nAddress: ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s\n",stream);
            printf("\nAadhaar Card number: ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s\n",stream);
            printf("Voter-ID number: ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s\n",stream);
            
            printf("\t Username: ");
            fprintf(filepointer1,"%s\t",stream);
            printf("\n\t Password: ");
            fprintf(filepointer1,"%s\n",stream);
        fclose(filepointer1);

        //send this file to server
        
        
}

void existing_user()
{
        FILE *filepointer3 = fopen("user.txt", "w"); //temp file
        //login
        char username[50],password[50];
            
            printf("\n Welcome back to the E-Voting portal. Please login to continue. \n ");
            printf("\t Username: ");
            scanf("%d",username);
            scanf("%d",password);
            fprintf(filepointer3,"%s\t",username);
            printf("\n\t Password: ");
            fprintf(filepointer3,"%s\n",password);
        
        fclose(filepointer3);

    //send this file to server

    //after receving authorization
    //fetch the details from the file (location)
    
    //open a new socket and send
    //strtok

}

  
