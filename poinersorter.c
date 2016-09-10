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
	  
  for(i = 0; i < strlen(input); i++)
    {
      //if current character is not alphabetic, allocate memory for new component
      if((isalpha(input[i]) == 0 && i > 0) || input[i+1] == '\0')
      {
	
	//printf("Here:%d %c\n",i, input[i]);
       	component  = (char *)malloc(sizeof(char)*(i-1));
	if(component == NULL)
	  {
	    printf("Error: Unable to allocate 'component'\n");
	    return;
	  }
	else
	  {
	    //copy contents of input into component
	    memcpy(component, input, i);
	    printf("%s\n", component);
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

