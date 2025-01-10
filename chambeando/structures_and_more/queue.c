#include <stdio.h>
#include <stdlib.h>

struct queueNode
{
  int data;
  struct queueNode * nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode * QueueNodePtr;

void enqueue(QueueNodePtr * tail, int value)
{
    QueueNodePtr newPtr = NULL;
    newPtr = (QueueNodePtr)malloc(sizeof(QueueNode));

    (*newPtr).data = value;
    (*newPtr).nextPtr = NULL;

    if(newPtr != NULL)
    {
        if((*tail) != NULL)
        {
           (*tail)->nextPtr = newPtr;
        }

        (*tail) = newPtr;

    }
}

void dequeue(QueueNodePtr * head, int value)
{
  QueueNodePtr temp = *head;
 
  if((*head) !=NULL)
  {
    (*head) = (*head)->nextPtr;

    if((*temp).data != value)
    {
       dequeue( head , value ); 
    }
  }

  free(temp);
}

void imprimir()
{

}

int main()
{
  QueueNodePtr cabeza = NULL;
  QueueNodePtr cola = NULL;

  if(cabeza  == NULL && cola != NULL)
  {
    cabeza = cola;
  }
  else
  {
    printf("queue empty\n");
  }

  return 0;
}
