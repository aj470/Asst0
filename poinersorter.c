#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
  char * str;
  struct _Node *next;
  struct _Node *prev;
}Node;

typedef struct _LList
{
  struct _Node *head;
  int listLength;
}LList;

LList* createList()
{
  //allocate list poiner
  LList *lp = (LList*)malloc(sizeof(struct _LList));
  if (lp == NULL) 
    {
      printf("ERR in 'createList': Malloc failed\n");
      return NULL;
    }

  lp->head = malloc(sizeof(Node));
  lp->head->str = '\0';
  lp->head->next = lp->head;
  lp->head->prev = lp->head;
  lp->listLength = 0;

  return lp;
}

Node* createNode(char* add)
{
  Node* create = malloc(sizeof(Node));
  if(create == NULL)
    {
      return NULL;
    }

 
  create->str =(char *)malloc(strlen(add)+1);
  memcpy(create->str, add, strlen(add)); 
  create->str[strlen(create->str)+1] = '\0';
  //  printf("%s\n", create->str);
  create->next = NULL;
  create->prev = NULL;
  
  return create;
}

void sortComponent (LList *list, char *component)
{
  typedef enum {FALSE, TRUE} bool;
  bool added = FALSE; //flag to check if item to be inserted is uniqueness
  Node *current; //pointer to traverse list when inserting new items
  current = list->head->next; //set pointet to start of list 
  int i;
  char *token;
  while(!added && current != list->head)
    {
      token = (char *)malloc(sizeof(char)*strlen(component));
      for(i=0;i<strlen(component);i++)
	{
	  token[i] = tolower(component[i]);
	}
      if(strcmp(token,current->str) < 0)
	{
	  break;
	}
      current = current->next;
    }
  
  Node *add = createNode(component);
  add->prev = current->prev;
  current->prev->next = add;
  add->next = current;
  current->prev = add;
}


void extractComponent (LList* list , char* token)
{
  char input[strlen(token)+2];
  int j;
  input[0] = '"';
  for(j=0; j<strlen(token);j++)
    {
      input[j+1]= token[j];
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
		  sortComponent(list, component);
		     
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
  LList *listPtr = createList();
  
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
      extractComponent(listPtr, argv[i]);
    }
  
  Node * traverse;
  traverse = listPtr->head->next;

  while(traverse != listPtr->head)
    {
      //      printf("%s\n", traverse->str);
      free(traverse->str);
      traverse = traverse -> next;
    }
  free(traverse);
  free(listPtr);
    
  return 0;
}
