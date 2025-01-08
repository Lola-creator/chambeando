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

void push(StackNodePtr *tail, int value)
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

void pop(StackNodePtr * tail, int value)
{
  StackNodePtr temp = *tail;
  (*tail) = (*tail)->nextPtr;

  if( (temp)->data!=value)
    {
    pop(tail, value);
    }
  free(temp);
}

void imprimir(StackNodePtr * tail)
{
  if((*tail) != NULL)
  {
    imprimir(&((*tail)->nextPtr));
    printf("%d  valor\n",(*tail)->data);
  }

}

int main()
{
  StackNodePtr cola = NULL;
  int valor = 0;
  char key = '1';

  while(key != '4')
  {
    puts("select option: ");
    key = getchar();
    while(getchar()!= '\n');

    switch(key)
    {
      case '1':
        puts("Push item: ");
        scanf("%d",&valor);
        push(&cola, valor);
        break;

      case '2':
        puts("Pop item: ");
        scanf("%d", &valor);
        pop(&cola, valor);
        break;

      case '3':
        puts("Imprimir \n");
        imprimir(&cola);
        break;

      case '4':
        puts("SALIR\n");
        break;

      default:
        puts("Number no valid\nagain\n");
        break;
    }

    while(getchar()!= '\n');

  }

  return 0;
}
