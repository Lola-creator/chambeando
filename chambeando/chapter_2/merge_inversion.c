//n° inversiones = n° veces de alterar una variable = n° running time
#include <stdio.h>

int merge_sorting(int *A, int end, int middle, int begg){
  int m_f = middle - begg +1, m_s=end-middle;
  int first[m_f+1], second[m_s+1], i=0, a=0;
  int suma=0;
  
  first[m_f] = second[m_s] = '\0';
  
  
  for(;i<m_f;i++)
    first[i] = A[begg+i];

  for(;a<m_s;a++)
    second[a] = A[middle+1+a];

  for(i=0,a=0;begg<=end;begg++){
    if((first[i]<=second[a] && i<m_f)||a>=m_s){
      A[begg] = first[i];
      i++;
    }
    else{//second[a] <first[i] && a<m_s || i>=m_f
      A[begg] = second[a];
      if(a<m_s && i<m_f) suma++;
      a++;
    }   
  }
    return suma;
}

int merge(int *A, int final, int inicio){
  int medio = inicio+(final-inicio)/2;
  
  if(inicio<final){
    return merge(A, medio,inicio)+merge(A, final, medio+1)+ merge_sorting(A, final, medio, inicio);
  }
  return 0;

}

int main(){
  int num = 7;
  int cadena[] = {10,4,7,3,0,2,2}; //[num] = {elements} X
 
  printf("Inversiones en O nlg(n): %d\nCadena ordenada: ", merge(cadena, num-1, 0));
   
  for(int i=0;i<num;i++)
    printf("%d ", cadena[i]);

return 0;
}
