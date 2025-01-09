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
        (*tail);
    }
}

void dequeue(QueueNodePtr * head, int value)
{

}

void imprimir()
{

}

int main()
{
  QueueNodePtr cabeza = NULL;
  QueueNodePtr cola = NULL;



  return 0;
}
