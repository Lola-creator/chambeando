#include <stdio.h>
#include <stdlib.h>

struct stackNode
{
  int data;
  struct stackNode * nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode * StackNodePtr;

int isEmpty(StackNodePtr topPtr)
{
    return topPtr == NULL;
}

void pop(StackNodePtr *tail, int value)
{
    StackNodePtr newPtr = NULL;

    newPtr = (StackNodePtr)malloc(sizeof(StackNode));
    (*newPtr).data = value;
    (*newPtr).nextPtr = NULL;

    if(newPtr != NULL)
    {
      if(!isEmpty(*tail))
      {
         (*newPtr).nextPtr = (*tail);
      }

      (*tail) = newPtr;
      
    }
    else
    {
      printf("error when storing data\n");
    }

}

int main()
{
  
  return 0;
}
