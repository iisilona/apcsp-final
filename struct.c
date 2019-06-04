#include <stdio.h>
#include <string.h>
struct planner
{
  char aname;
  char aclass;
  char adue;
  char adesc;
}alist[500];

void printas(struct planner *ptr)
{
  printf("%s", ptr->aclass);
  printf(" : %s\n", ptr->aname);
  printf("Due %s\n", ptr->adue);
  printf("%s", ptr->adesc);
}

