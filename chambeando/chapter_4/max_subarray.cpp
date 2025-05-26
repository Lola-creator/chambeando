
#include <iostream>
#include <climits>


int *general[41] = {};
int contador = 0;

int *max_subarray(int *A, int low, int high);
int * find_crossing(int *A, int low, int mid, int high);

void chau()
{
    for(int i = 0; i < (contador+1) && general[i] != nullptr; i++)
    {
        delete[] general[i];
    }
}

int main()
{
    int hola[6] = {-13,-3,-25,-20,-1,-16};//int hola[20] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7,1,1,1,1};
    int * buffer = max_subarray(hola, 0,5);//indice
    std::cout<<*(buffer)<<" "<<*(buffer+1)<<" "<<*(buffer+2);
    
    chau();
    return 0;
}


int * find_crossing(int *A, int low, int mid, int high)
{
    int left_sum = INT_MIN, sum = 0, max_left = INT_MIN;
    int * liberar = new int [3];
    
    for(int *nodo =  A+mid;nodo>=(A+low);nodo--)
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
    
    for(int *nodo =  A+mid+1;nodo<=(A+high);nodo++)
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
    general[contador++] = liberar;


    return liberar;
}

int *max_subarray(int *A, int low, int high)
{
    int *right  = nullptr, *left = nullptr, *cross = nullptr;

    if(high == low)
    {
        int *ayuda = new int[3];
        ayuda[0] = low;
        ayuda[1] = high;
        ayuda[2] = A[low];

        general[contador++] = ayuda;
        return ayuda;
    }
    else
    {
        int mid = (low+high)/2;
        //left
        left= max_subarray(A, low, mid);
        //right
        right= max_subarray(A, mid+1, high);
        //middle
        cross = find_crossing(A,low, mid, high);

        if(left[2]>=right[2] && left[2]>=cross[2])
            return left;
        else if(right[2]>=left[2] && right[2]>=cross[2])
            return right;
        else
            return cross;
    }
    
}