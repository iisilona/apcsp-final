#include <stdio.h>
#include <string.h>
struct planner
{
  char aname;
  char aclass;
  char adue;
  char adesc;
}alist[500];

void printit(struct planner *ptr)
{
  printf("%s", ptr->aclass);
  printf(" : %s\n", ptr->aname);
  printf("Due %s\n", ptr->adue);
  printf("%s", ptr->adesc);
}

void create
{
 FILE *plannerstorage;
 plannerstorage = fopen(const char *restrict __filename, const char *restrict __modes)
 if (plannerstorage == NULL) 
    { 
        fprintf(stderr, "\nError opening file. Sending you back...\n"); 
        exit (1); 
    } 
}

void access
{
}

int main ()
{
  char request;
  char assignments = "Assignments";
  char add = "add";
  
  while (1)
  {
   printf("Welcome to your Pi Planner. To access your assignments, type 'Assignments'. To add a new assignment, type 'Add':\n");
     fgets(input, 50, stdin);
     sscanf(input,"%s", request);
      if(strcmp(request, assignments)) == 0)
       access
       break;
      else if(strcmp(request, add)) == 0)
       create
       break;
      else printf("That wasn't a recognizable request. Please try again...\n")
  }
