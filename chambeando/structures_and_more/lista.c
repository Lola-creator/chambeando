#include <stdio.h>
#include <stdlib.h>

struct listNode
{
    char data;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typdef ListNode * ListNodePtr; 

void insert(ListNodePtr * sPtr, char value)
{
    ListNodePtr newPtr = malloc(sizeof(ListNode));
    
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

void delete(ListNodePtr * sPtr, char value)
{
  

}

int main()
{
    ListNodePtr startPtr = NULL;
    char item = 'n';

    insert(&startPtr, item);

    return 0;
}

