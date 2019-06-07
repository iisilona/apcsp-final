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
 char extent[] = ".txt";
 char filename[200];
  
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

void access(char title[200])
{
  char extent[] = ".txt";
  char filename[200];
  char * accessing;
  
  strcpy(filename, title);
  strcat(filename, extent);
  
  int c;
  FILE * fyle;
  fyle = fopen(filename, "r");
  if (filename == NULL) 
    { 
        fprintf(stderr, "\nThat assignment doesn't exist. Sending you back...\n"); 
        exit (1); 
    }
  fyle = fgetc(fyle);
  while ((c = getc(fyle)) != EOF)
   {
     putchar(c);
   }
   fclose (fyle);
   exit;
}

int main ()
{
  char input[200];
  char request[200];
  char nameof[200]; //name of existing assignment//
  char name[200]; //initializes new assignment name//
  
  while (1)
  {
   printf("Welcome to your Pi Planner. To access your assignments, type 'Assignments'. To add a new assignment, type 'Add':\n");
     fgets(input, 200, stdin);
     sscanf(input,"%s", request);

      if(strcmp(request, "Add"))
      {
        printf("Ah, so you want to access an assignment? OK,  what's its name?: \n");
         fgets(input, 200, stdin);
         sscanf(input, "%s", name);
         access(nameof);
         break;
      }

      else if (strcmp(request, "Assignments"))
       {
          printf("Ah, so you want to create an assignment? OK, enter the assignment name: \n");
         fgets(input, 200, stdin);
         sscanf(input, "%s", nameof);
         create(name);
         break;
       }
      else 
       {
         printf("That wasn't a recognizable request. Please try again...\n");
       }
  }
}
