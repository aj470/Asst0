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

void extractComponent (char* token)
{
  char input[strlen(token)+2];
  int j;
  input[0] = '"';
  for(j=0; j<strlen(token);j++)
    {
        input[j+1]= token[j];
     }
  input[strlen(token)+1]= '"';

  for(j=0; j<strlen(input);j++)
    {
      printf("%c \n", input[j]);
    }
  input[strlen(token)+1]= '"';
 
  int i; //for loop variable
  char * component;    //seperating a component from input
  int pos = 0; // tracks the poition count as we move through each character in input.
    
  for(i = 0; i < strlen(input)+1; i++) //for loop from starting to '\0' of the input.
    {
      //if current character is not alphabetic, allocate memory for new component
      if((isalpha(input[i]) == 0) || input[i] == '\0') //check to see if  input[i] is not not alpha or its last character in input.
	{
	  component  = (char *)malloc(sizeof(char)*(1+i-pos)); //allocate space for the i-pos, for example if "hello1world" then pos = 0 initally and when i=5, it will allocate for 5 space
	  if(component == NULL) //check if space is alocated or not
	    {
	      printf("Error: Unable to allocate 'component'\n");
	      return;
	    }
	  else // if allocated
	    {
	      memcpy(component, &input[pos], (i-pos)); //copy the character from input starting at pos till i-pos to component as that is our token.
	      component[strlen(component)+1] = '\0'; //add the null terminating character at end.
	      if(component[0]!= '\0') // if this wasn't the end then print the characters and continue
		{
		  printf("%s\n", component); // print the token
		}
	      pos = i + 1; // as the current place value in input was a deliminter so we will update current pos to i+1
	      free(component); // release the component
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
