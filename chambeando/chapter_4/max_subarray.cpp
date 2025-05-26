
#include <iostream>


int * max_subarray(int *A, int low, int mid, int high)
{
    int left_sum = 0, sum = 0, max_left = 0;
    int * liberar = new int [3];
    
    for(int *nodo =  A+mid;nodo>(A+low);nodo--)
    {
        sum += *nodo;
        if(sum>left_sum)
        {
            left_sum = sum;
            max_left = nodo-A;
        }
    }
    
    int right_sum = 0, max_right = 0;
    sum = 0;
    
    for(int *nodo =  A+mid+1;nodo<(A+mid+high);nodo++)
    {
        sum += *nodo;
        if(sum>right_sum)
        {
            right_sum = sum;
            max_right = nodo-A;
        }
    }
    
    liberar[0] = max_left;
    liberar[1] = max_right;
    liberar[2] = left_sum+right_sum;
    return liberar;
}

int main()
{
    int hola[20] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7,1,1,1,1};
    int * buffer = max_subarray(hola, 2, 9,15);//indice
    std::cout<<*(buffer);

    return 0;
}