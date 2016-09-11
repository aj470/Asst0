#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 1000

typedef enum {FALSE, TRUE} bool;

typedef struct _Node
{
  char * str;
  struct Node *next;
}Node;

typedef struct _LList
{
  Node *head;
  int listLength;
}LList;

void extractComponent (char* input)
{
  int i;
  char * component;    
  int pos = 0;
    
  for(i = 0; i < strlen(input)+1; i++)
    {
      //if current character is not alphabetic, allocate memory for new component
      if((isalpha(input[i]) == 0) || input[i] == '\0')
	{
	  component  = (char *)malloc(sizeof(char)*(1+i-pos));
	  if(component == NULL)
	    {
	      printf("Error: Unable to allocate 'component'\n");
	      return;
	    }
	  else
	    {
	      memcpy(component, &input[pos], (i-pos));
	      component[strlen(component)+1] = '\0';
	      if(component[0]!= '\0')
		{
		  printf("%s\n", component);
		}
	      pos = i + 1;
	      free(component);
	    }
	}
    }
}
  

int main(int argc, char *argv[])
{
  //check if user input data
  if(argc < 2)
    {
      printf("Error: Invalid input.\n");
      exit(0);
    }
  
  //call function to extract components from input
  int i;
  for(i = 1; i < argc; i++)
    {
      extractComponent(argv[i]);
    }

  return 0;
}
