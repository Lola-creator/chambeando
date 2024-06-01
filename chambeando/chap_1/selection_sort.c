#include <stdio.h>

int main(){

    int cadena[] = {3,5,2,5,8,0,5,3,2,4,5,80, '\0'};
		int key = 0, valor =0 ;


		for(int i=0; i+1 != 11; i++){
		   key = i;
		   for(int a = i+1;a!= 11;a++)
				if(cadena[key] < cadena[a]){
				key = a;	}
		   if(key != i){
		   valor = cadena[i];
		   cadena[i] = cadena[key];
		   cadena[key] = valor;}
		}	

		for(int i=0;i != 11; i++)
				printf("%d\n", cadena[i]);

return 0;}
