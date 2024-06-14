#include <stdio.h>

int compare(int num, int *A, int inicio, int final){//final = leng
  int key = A[inicio];
  if(inicio != final){
    for(int i=inicio;i<final;i++)
      if(A[i]+ key == num)
        return 0;
      
    return compare(num,A,inicio+1,final);
  }
  return 1;
}

int main(){
  int longitud = 10;
  int cadena[longitud];
  int valor , i=0;
  
  scanf("%d", &valor);

  while(i!=longitud){
    scanf(" %d", &cadena[i]);
    i++;
  }

  if(compare(valor,cadena,0,longitud)==0)
    printf("SI HAY");
  else 
    printf("NO HAY");

return 0;}
