/*
******************CODE COMPLIES*********************
*****************DIDN'T DEBUG YET*******************
*/
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

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
  
  create->str =(char *)malloc(sizeof(*add));
  memcpy(create->str, add, strlen(add)); 
  create->str[sizeof(create->str)+1] = '\0';

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
  
  while(!added && current != list->head)
    {
      if(strcmp(component, current->str) > 0)
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


int main(int argc, char *argv[])
{
  LList *listPtr = createList();
    
  Node * output = createNode(argv[1]);
  
  sortComponent(listPtr, output->str);

  printf("%s\n", output->str);
  
  return 0;
}
