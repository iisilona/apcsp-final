#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct planner
{
  char aname[200];
  char aclass[200];
  char adue[200];
  char adesc[400];
};

void create(char title[200])
{
 char * extent = ".txt";
 char * filename;
  
 struct planner plans;
 char input[200];

 printf("Enter the assignment name:\n");
 fgets(input, 200, stdin);
 sscanf(input,"%s", plans.aname);

 printf("Enter the class for the assignment:\n");
 fgets(input, 200, stdin);
 sscanf(input,"%s", plans.aclass);

 printf("Enter the due date:\n");
 fgets(input, 200, stdin);
 sscanf(input,"%s", plans.adue);

 printf("Enter a description for the assignment:\n");
 fgets(input, 400, stdin);
 sscanf(input,"%s", plans.adesc);

 FILE * fyle;

 strcpy(filename, title);
 strcat(filename, extent);
  
 fyle = fopen(filename, "w");
 fwrite(&plans, sizeof(struct planner), 4, fyle);

 if(fwrite != 0)  
        printf("Contents to file written successfully !\n"); 
    else 
        printf("Error writing file !\n"); 

 fclose (fyle); 
}

void access(char * title)
{
  char * extent = ".txt";
  char * filename;
  char * accessing;
  
  strcpy(filename, title);
  strcat(filename, extent);
  
  FILE * fyle;
  fyle = fopen(filename, "r");
  if (title == NULL) 
    { 
        fprintf(stderr, "\nThat assignment doesn't exist. Sending you back...\n"); 
        exit (1); 
    }

  accessing = fgetc(fyle);
  while (accessing != EOF)
   {
     printf("%s", accessing);
     accessing = fgetc(fyle);
   }
   fclose (fyle);
}

int main ()
{
  char input[200];
  char request[200];
  char assignments[] = "Assignments";
  char add[] = "Add";
  char nameof[200]; //name of existing assignment//
  char name[200]; //initializes new assignment name//
  
  while (1)
  {
   printf("Welcome to your Pi Planner. To access your assignments, type 'Assignments'. To add a new assignment, type 'Add':\n");
     fgets(input, 200, stdin);
     sscanf(input,"%s", request);

      if(strcmp(request, add))
      {
         printf("Ah, so you want to access an assignment? OK, enter the assignment name: \n");
         fgets(input, 200, stdin);
         sscanf(input, "%s", nameof);
         access(nameof);
         break;
      }

      else if(strcmp(request, assignments))
       {
         printf("Ah, so you want to create an assignment? OK,  give the assignment a name: \n");
         fgets(input, 200, stdin);
         sscanf(input, "%s", name);
         create(name);
         break;
       }
      else 
       {
         printf("That wasn't a recognizable request. Please try again...\n");
       }
  }
}
