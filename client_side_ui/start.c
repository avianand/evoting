#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
char stream[1000],stream1[1000];
void new_user()
{
    
    
    //File handling
      FILE *filepointer1 = fopen("program.txt", "w"); //temp file
      if (filepointer1 == NULL)
      {
          printf("Could not open file newuser.txt"); 
      }
      
      
        //interface  
            printf("\n Welcome to the new user registration portal. Please Enter the following Details. \n ");
            printf(" ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s",stream);
            printf("Full Name: ");
                fgets(stream,50,stdin);  //flush the stream before continuing frwrd
                fprintf(filepointer1,"%s \r\n",stream);
            printf("\nDate of Birth: ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s \r\n",stream);
            printf("\nAddress: ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s \r\n",stream);
            printf("\nAadhaar Card number: ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s \r\n",stream);
            printf("Voter-ID number: ");
                fgets(stream,50,stdin);
                fprintf(filepointer1,"%s \r\n",stream);
            
            printf("\n Username: ");
		fgets(stream,20,stdin);
            fprintf(filepointer1,"%s \r\t",stream);
            printf("\nPassword: ");
		fgets(stream,20,stdin);
            fprintf(filepointer1,"%s",stream);
        fclose(filepointer1);

        //send this file to server
        
        
}

void existing_user()
{
        FILE *filepointer3 = fopen("program.txt", "w"); //temp file
        //login
        char username[50],password[50];
            
            printf("\n Welcome back to the E-Voting portal. Please login to continue. \n ");
            printf("\t Username: ");
            scanf("%s",username);
	    printf("\n\t Password: ");
            scanf("%s",password);
            fprintf(filepointer3,"%s\t",username);
            fprintf(filepointer3,"%s\n",password);
        
        fclose(filepointer3);

   
}

void encrypt()
{
	FILE *fp1, *fp2, *fp;
    char ch;
    int s;
     srand(time(0));
       s=rand();
     fp=fopen("pass.bin","wb");
	fprintf(fp, "%d\n", s);
    fp1 = fopen("program.txt","r");
    if(fp1 == NULL)
    {
        printf("Source File Could Not Be Found\n");
    }
    fp2 = fopen("program1.txt","w");
    if(fp2 == NULL)
    {
        printf("Target File Could Not Be Found\n");
    }
    while(1)
    {
        ch = fgetc(fp1);
        if(ch == EOF)
        {
            printf("\nEnd Of File\n");
            break;
        }
        else
        {
            ch = ch - s;
            fputc(ch, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp);
    printf("\n");
   //send this file to server

    //after receving authorization
    //fetch the details from the file (location)
    
    //open a new socket and send
    //strtok

}

int main()
{
    int choice;
    printf("Welcome to the E-Voting System\n");
    
    printf("Please choose from the following options: \n \b 1. New User \t 2. Existing User\n :"); 
    scanf("%d",&choice);
    switch (choice){
	case 1:
		new_user();
		encrypt();
		break;
	case 2:
		existing_user();
		encrypt();
		break;
	default:
		printf("enter valid choice");
		break;
}
return 0;
}


