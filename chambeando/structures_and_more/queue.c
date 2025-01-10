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

void imprimir(QueueNodePtr *head)
{ 
    if((*head) != NULL)
    {
      printf("valor: %d \n", (*head)->data);
      imprimir(&((*head)->nextPtr) );
    }
    else
    {
      printf("QUEUE EMPTY");
    }
}

int main()
{
  QueueNodePtr cabeza = NULL;
  QueueNodePtr cola = NULL;

  int valor = 0;
  char key = '1';
  int flag = 0;

  while(key != '4')
  {
    puts("select option: ");
    key = getchar();
    while(getchar()!= '\n');

    switch(key)
    {
      case '1':
        puts("Enqueue item: ");
        scanf("%d",&valor);
        enqueue(&cola, valor);
        break;

      case '2':
        if(flag)
        {
        puts("Dequeue item: ");
        scanf("%d", &valor);
        dequeue(&cabeza, valor);
        break;
        }
        else
        {
          puts("CANNOT DEQUEUE, QUEUE EMPTY\n");
          break;
        }
      case '3':
        puts("Imprimir \n\n");
        imprimir(&cabeza);
        break;

      case '4':
        puts("SALIR\n");
        break;

      default:
        puts("Number no valid\nagain\n");
        break;
    }

    while(getchar()!= '\n');

    if((cabeza)  == NULL && (cola) != NULL)
    {
     (cabeza) = (cola);
     flag =1;
    }

  }

  return 0;
}
