#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct planner
{
  char aname;
  char aclass;
  char adue;
  char adesc;
};

void printit(struct planner *ptr)
{
  printf("%s", ptr->aclass);
  printf(" : %s\n", ptr->aname);
  printf("Due %s\n", ptr->adue);
  printf("%s", ptr->adesc);
}

void create(char* title)
{
  char * extent = ".txt";
  char filetitle = ((strlen(title))+(strlen(extent))+1);
  char filecontents;
  
 struct planner plans;
 char input [200];

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
 fgets(input, 200, stdin);
 sscanf(input,"%s", plans.adesc);

 FILE * fyle;
 snprintf(filetitle, sizeof(filetitle), "%s%s", title, extent );
 fyle = fopen(filetitle, "w");
 fwrite(&plans, sizeof(struct planner), 4, fyle);

 if(fwrite != 0)  
        printf("Contents to file written successfully !\n"); 
    else 
        printf("Error writing file !\n"); 

 fclose (fyle); 
}

void access(char* title)
{
  char * extent = ".txt";
  char filetitle = ((strlen(title))+(strlen(extent))+1);
  char filecontents;
  
  FILE * fyle;
  snprintf(filetitle, sizeof(filetitle), "%s%s", title, extent );
  fyle = fopen(filetitle, "r");
  if (title == NULL) 
    { 
        fprintf(stderr, "\nThat assignment doesn't exist. Sending you back...\n"); 
        exit (1); 
    }
  filecontents = fget(fyle);
  while (filecontents != EOF)
   {
     printf("%c", filecontents);
     filecontents = fgetc(fyle);
   fclose (fyle);
   }
}

int main ()
{
  char input[200];
  char request;
  char assignments = "Assignments";
  char add = "Add";
  char nameof; //name of existing assignment//
  char name; //initializes new assignment name//
  
  while (1)
  {
   printf("Welcome to your Pi Planner. To access your assignments, type 'Assignments'. To add a new assignment, type 'Add':\n");
     fgets(input, 50, stdin);
     sscanf(input,"%s", request);

      if((strcmp(request, assignments))==0)
      {
         printf("Ah, so you want to access an assignment? OK, enter the assignment name: \n");
         fgets(input, 50, stdin);
         sscanf(input, "%s", nameof);
         access(nameof);
         break;
      }

      else if((strcmp(request, add))==0)
       {
         printf("Ah, so you want to create an assignment? OK,  give the assignment a name: \n");
         fgets(input, 50, stdin);
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
