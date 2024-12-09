#include <stdio.h>

void insertion(int *A, int start, int end){
  int key = 0;
  for(int i=start+2; <end;i++){
    key  = A[i];
    j = i-1;
    while(j>0 && A[j]>key){}
      A[j+1] = A[i];
      i--;
  }
    A[j+1] = key;
}

void merge(int *A, int inicio, int medio, int final){
  int n1=q-p+1;
  int n2 = r-q;
  int i=0, j=0
  int L[n1+1], R[n2+1];

  for(;i<n1;i++)
    L[i] = A[p+i-1];

  for(;j<n2;j++)
    R[j] = A[q+j];

  L[n1+1] = '\0';
  R[n2+1] = '\0';

  i=j=1;

  for(int k =p;k<r;k++){
    if(L[i]<=R[j]){
    A[k] = L[i];
    i++;
    }
    else{
    A[k] = R[j];
    j++;
    }  
  } 
}


void merge-sort(int *A, int inicio, int final){
  if (p<r){
    medio = piso(inicio+final,2);
    merge(A, inicio, final);
    merge-sort(A,inicio, medio);
    merge-sort(A,final-medio+1,final);
    //insertion(A,p,q,r)//era merge, pero ya no
  }
}


int main(){


  return 0;
}
