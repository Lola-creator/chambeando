#include <stdio.h>
#include <stdlib.h>

struct listNode
{
    char data;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode * ListNodePtr; 

void insert(ListNodePtr * sPtr, char value)
{
    ListNodePtr newPtr = (ListNodePtr)malloc(sizeof(ListNode));
    
    if(newPtr != NULL)
    {
        (*newPtr).data = value;
        (*newPtr).nextPtr = NULL;
        
        ListNodePtr previousPtr = NULL; //previous + current  = puntero simple
        ListNodePtr currentPtr = *sPtr;//[unteros a puntero]
        
        //NULL --- P --- P --- P --- P --- NULL
        
        while(currentPtr != NULL && value>(*currentPtr).data)
        {
            previousPtr = currentPtr;
            currentPtr = (*currentPtr).nextPtr;
        }
        
        if(previousPtr == NULL)
        {
          (*newPtr).nextPtr =  (*sPtr);//nextPtr = NULL
          (*sPtr) = newPtr;//
        }
        else
        {
          (*previousPtr).nextPtr = (newPtr);
          (*newPtr).nextPtr = currentPtr;//asegurarnos x2 NULL
        }
    }
    else
    {
     printf("Memory no available\n");
    }
}

void borrar(ListNodePtr * sPtr, char hao)
{
  ListNodePtr previous = NULL;
  ListNodePtr currentPtr = (*sPtr);

  while((*currentPtr).data != hao && currentPtr != NULL)
  {
    previous = currentPtr;
    currentPtr = (*currentPtr).nextPtr;
  }

  if(currentPtr != NULL)
  {
    if(previous != NULL)
    {
      (*previous).nextPtr = (*currentPtr).nextPtr;
    }
    else
    {
      (*sPtr) = (*currentPtr).nextPtr;
    }

    free(currentPtr);
  }
  else
  {
    printf("NO deletion\n");
  }

}

void imprimir(ListNodePtr * sPtr)
{

  ListNodePtr currentPtr = (*sPtr);
  int i =1;

  while(currentPtr !=NULL)
  {
    printf("%d:   %c\n", i, (*currentPtr).data);
    currentPtr = (*currentPtr).nextPtr; 
    i++;
  }

}

int main()
{
    ListNodePtr startPtr = NULL;
    char item = 'n';
    char key = '1';

    while(key != '4')
    {
      puts("Select option: ");
      key = getchar();
      while(getchar() != '\n');

      switch(key)
      {
        case '1':
          puts("Insert item: ");
          item = getchar();
          while(getchar() != '\n');
          insert(&startPtr, item);
          break;

        case '2':
          puts("Delete item: ");
          item = getchar();
          while(getchar() != '\n');

          borrar(&startPtr, item);
          break;

        case '3':
          puts("Print\n");
          item = getchar();
          while(getchar() != '\n');

          imprimir(&startPtr);
          break;

        case'4':
          puts("end\n");
          
          break;

        default:
          puts("que pasa, solo es 1 - 2 - 3 - 4  no more\n");
          puts("again\n");
         
          break;
      } 

    }

   

    return 0;
}

