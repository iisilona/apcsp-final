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
  char input2[200];
  char input3[200];
  char input4[200];
  char input5[200];
  char input6[200];
  char input7[200];
  char request[200];
  char nameof[200]; //name of existing assignment//
  char name[200]; //initializes new assignment name//
  char extent[] = ".txt";
  char filename[200];
  char filename2[200];
  char buffer[BUFFER_SIZE];
  int totalRead = 0;

  while (1)
  {
   printf("Welcome to your Pi Planner. To access your assignments, type 'Assignments'. To add a new assignment, type 'Add':\n");
     fgets(input, 200, stdin);
     sscanf(input,"%s", request);

      if(strcmp(request, "Add"))
      {
        printf("Ah, so you want to access an assignment? OK,  what's its name?: \n");
         fgets(input2, 200, stdin);
         sscanf(input2, "%s", name);
         
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
         
         while(fread(&placehldr, sizeof(placehldr), 1, file))
         {
           printf("Assignment Name: %s\n", placehldr.aname);
           printf("Assignment Class: %s\n", placehldr.aclass);
           printf("Assignment Due Date: %s\n", placehldr.adue);
           printf("Assignment Description: %s\n", placehldr.adesc);
         }
         fclose (file);
         break;
        }
        
       else if (strcmp(request, "Assignments"))
       {
         printf("Ah, so you want to create an assignment? OK, give the file a title: \n");
         fgets(input3, 200, stdin);
         sscanf(input3, "%s", nameof);
         struct planner plans;

         printf("Enter the assignment name:\n");
         fgets(input4, 200, stdin);
         sscanf(input4,"%[^\n]%*c", plans.aname);

         printf("Enter the class for the assignment:\n");
         fgets(input5, 200, stdin);
         sscanf(input5,"%[^\n]%*c", plans.aclass);

         printf("Enter the due date:\n");
         fgets(input6, 200, stdin);
         sscanf(input6,"%[^\n]%*c", plans.adue);

         printf("Enter a description for the assignment:\n");
         fgets(input7, 400, stdin);
         sscanf(input7,"%[^\n]%*c", plans.adesc);

         FILE * fyle;

         strcpy(filename, nameof);
         strcat(filename, extent);
  
         fyle = fopen(filename, "w");
         fwrite(&plans, sizeof(plans), 1, fyle);

         if(fwrite != 0)  
         printf("Contents to file written successfully !\n"); 
         else 
         printf("Error writing file !\n"); 

         fclose (fyle); 
         break;
       }
 printf("That wasn't a recognizable request. Please try again...\n");
 }
}
