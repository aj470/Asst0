#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct _Node
{
  char * str;
  struct _Node *next;
}Node;

typedef struct _LList
{
  struct _Node *head;
  int listLength;
}LList;

LList* createList()
{
  //allocate list poiner
  LList *lp = (LList*)malloc(sizeof(LList));
  if (lp == NULL) 
    {
      printf("ERR in 'createList': Malloc failed\n");
      return NULL;
    }

  lp->head = malloc(sizeof(Node));
  lp->head->str = '\0';
  lp->head->next = lp->head;
  lp->listLength = 0;

  return lp;
}

Node* createNode(char* add)
{
  Node* create = malloc(sizeof(Node));

  memcpy(create->str, add, sizeof(*add)); //*************SEG FAULTS HERE*************

  return create;
}

/*void sortComponent (char *component)
{
  
}*/

int main(int argc, char *argv[])
{
  //LList *listPtr = createList();

  char * data = (char*)malloc(sizeof(argv[1]));
  memcpy(data, argv[1], sizeof(*argv[1]));

  Node * output = createNode(data);

  printf("%s\n", output->str);
  
  return 0;
}
