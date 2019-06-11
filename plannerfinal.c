#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000

struct planner
{
  char aname[200];
  char aclass[200];
  char adue[200];
  char adesc[400];
};

int main ()
{
  char input[200];
  char request[200];
  char nameof[200]; //name of existing assignment//
  char name[200]; //initializes new assignment name//
  char extent[] = ".txt";
  char filename[200];
  char filename2[200];
  char buffer[BUFFER_SIZE];
  int totalRead = 0;
  char ch;

  while (1)
  {
   printf("Welcome to your Pi Planner. To access your assignments, type 'Assignments'. To add a new assignment, type 'Add'. To exit the program, type 'Exit':\n");
     fgets(input, 200, stdin);
     sscanf(input,"%s", request);

      if(strcmp(request, "Assignments") == 0)
      {
        printf("Ah, so you want to access an assignment? OK,  what's its name?: \n");
         fgets(input, 200, stdin);
         sscanf(input, "%s", name);
         
         strcpy(filename, name);
         strcat(filename, extent);
         struct planner placehldr;
         FILE * file;
         file = fopen(filename, "r");

        if(file == NULL)
           {
           printf("Unable to open file.\n");
           printf("Please check whether file exists and you have read privilege.\n");
           exit(EXIT_FAILURE);
           }

        printf("File opened successfully. Printing information... \n\n");
         
        while ((ch = fgetc(file)) != EOF)
        {
            printf("%c", ch);
        }
         fclose (file);
         break;
        }
        
       else if (strcmp(request, "Add") == 0)
       {
         printf("Ah, so you want to create an assignment? OK, give the file a title: \n");
         fgets(input, 200, stdin);
         sscanf(input, "%s", nameof);
         struct planner plans;
         char input[200];

         printf("Enter the assignment name:\n");
         fgets(input, 200, stdin);
         sscanf(input,"%[^\n]%*c", plans.aname);

         printf("Enter the class for the assignment:\n");
         fgets(input, 200, stdin);
         sscanf(input,"%[^\n]%*c", plans.aclass);

         printf("Enter the due date:\n");
         fgets(input, 200, stdin);
         sscanf(input,"%[^\n]%*c", plans.adue);

         printf("Enter a description for the assignment:\n");
         fgets(input, 400, stdin);
         sscanf(input,"%[^\n]%*c", plans.adesc);

         FILE * fyle;

         strcpy(filename, nameof);
         strcat(filename, extent);
         
         fyle = fopen(filename, "w");
        
         if(fyle == NULL)
          {
            printf("Error opening file. Please try again. \n");
            exit(EXIT_FAILURE);
          }
        
         fprintf(fyle,"Assignment Name: %s \n", plans.aname); 
         fprintf(fyle,"Assignment Class: %s \n", plans.aclass); 
         fprintf(fyle,"Assignment Due Date: %s \n", plans.adue);
         fprintf(fyle,"Assignment Description %s \n", plans.adesc);

         printf("Contents to file written successfully !\n"); 
        
         fclose (fyle); 
         break;
       }

        else if (strcmp(request, "Exit") == 0)
        {
        printf("Bye!\n");
        exit(0);
        }

 printf("That wasn't a recognizable request. Please try again...\n");
 }
}

