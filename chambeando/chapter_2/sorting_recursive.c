#include <stdio.h>

void sorting(int * A, int j,int medida){
    int key =0,i=0;				

    if(j<medida)
		    sorting(A,j+1, medida);

		key = A[j];
    i = j-1;
		i = bucle(i,A,j);
		A[i+1] = key;								
}

int bucle(int l, int  *cadena, int j){
    if(l>0 && cadena[l]> cadena[j]){
				cadena[l+1] = cadena[l];
				return l = bucle(l-1, cadena, j);
		}	
		return 0;
}

int contar(int *U, int i){
		if(U[i] != '\0' || U[i] == EOF)
				return 1+contar(U,i+1);
		return 0;
}



int main(){
		int A[] = {3,7,2,8,44,4,8,3,20,0,0,0, '\0'};
		int inicio = contar(A,0);

    sorting(A, 1,inicio);

		for (int i =0;i<inicio;i++)
				printf("%d\n", A[i]);
		return 0;
}
