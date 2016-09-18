#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//struct for nodes that will be added to list
typedef struct _Node
{
  char * str; //holds string stored in list
  struct _Node *next; //pointer to next node
  struct _Node *prev; //pointer to previous node
}Node;

//struct for list to hold sorted words
typedef struct _LList
{
  struct _Node *head; //holds address of list head
  int listLength; //holds number of nodes in list
}LList;

LList* createList()
{
  //allocate list poiner
  LList *lp = (LList*)malloc(sizeof(struct _LList));
  //if returns NULL, memory was not allocated
  if (lp == NULL) 
    {
      printf("ERR in 'createList': Malloc failed\n");
      return NULL;
    }

  lp->head = malloc(sizeof(Node));//allocate memory and store as address of list head
  lp->head->str = '\0'; //initialize str component to null terminator
  lp->head->next = lp->head; //set address of next
  lp->head->prev = lp->head; //set addres of prev
  lp->listLength = 0;

  return lp; //return list pointer
}

Node* createNode(char* add)
{
  //allocate memory for node being created
  Node* create = malloc(sizeof(Node));
  //if malloc returns NULL, memory was not allocated
  if(create == NULL)
    {
      return NULL;
    }

  
  create->str =(char *)malloc(strlen(add)+1); //allocate memory for str member
  memcpy(create->str, add, strlen(add)); //copy string argument into struct
  create->str[strlen(create->str)+1] = '\0'; //null terminate the string
  create->next = NULL; //intialize next
  create->prev = NULL; //initialize prev
  
  return create; //return created node
}

void sortComponent (LList *list, char *component)
{
  Node *current; //pointer to traverse list when inserting new items
  current = list->head->next; //set pointet to start of list 
  int i; //for loop iterator
  char *token;
  char *word;
  //loop goes through list until it finds head of list
  while(current != list->head)
    {
      token = (char *)malloc(sizeof(char)*strlen(component));
      word = (char *)malloc(sizeof(char)*strlen(current->str));
      //convert each character from component into lower case and store in token 
      for(i=0;i<strlen(component);i++)
	{
	  token[i] = tolower(component[i]);
	}
      //convert each existing token in list into lower case and store in word for later comparision.
      for(i=0;i<strlen(current->str); i++)
	{
	  word[i] = tolower(current->str[i]);
	}
      //if token comes before current break from loop
      if(strcmp(token,word) < 0)
	{
	  break;
	}
      //else continue through list
      current = current->next;
    }
  
  Node *add = createNode(component); //function call to create node
  //attach new node to list
  add->prev = current->prev;
  current->prev->next = add;
  add->next = current;
  current->prev = add;

}


void extractComponent (LList* list , char* input)
{
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
	      printf("ERR: Unable to allocate 'component'\n");
	      return;
	    }
	  else // if allocated
	    {
	      memcpy(component, &input[pos], (i-pos)); //copy the character from input starting at pos till i-pos to component as that is our token.
	      component[strlen(component)+1] = '\0'; //add the null terminating character at end.
	      if(component[0]!= '\0') // if this wasn't the end then print the characters and continue
		{
		  sortComponent(list, component);
		}
	      pos = i + 1; // as the current place value in input was a deliminter so we will update current pos to i+1
	      free(component); // release the component
	    }
	}
    }
}

int main(int argc, char *argv[])
{
  //create list to hold sorted components
  LList *listPtr = createList();
  
  //  printf("%s\n%s\n%s", listPtr->head->str, listPtr->head->next->str, listPtr->head->prev->str);
  //check if user input data
  if(argc < 2)
    {
      printf("ERR: Invalid input.\n");
      exit(0);
    }

  //call function to extract components from input
  int i;
  for(i = 1; i < argc; i++)
    {
	  //check if current str is empty 
      if(strlen(argv[i]) == 0)
	{
	  printf("ERR: Empty string in argument %d\n", i);
	  continue;
	}
      extractComponent(listPtr, argv[i]);
    }
  //create a head node to go through list for freeing memory
  Node * traverse;
  traverse = listPtr->head->next;

  //loop print nodes and free memory that was allocated
  while(traverse != listPtr->head)
    {
      printf("%s\n", traverse->str);
      free(traverse->str);
      traverse = traverse -> next;
    }
  free(traverse);
  free(listPtr);
    
  return 0;
}
