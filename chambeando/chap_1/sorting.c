#include <stdio.h>

int main(){
    int i =0, j=0, key =0;
	int cadena[] = {31,41,59,26,41,58}, length = 6;
	cadena[6] = '\0';
	i = length -2;
		
	for(;i>=0;i--){
		key = cadena[i];
		j = i+1;

		for(;j<length && cadena[j]>cadena[i];j++,i++){
				cadena[i] = cadena[j];	
				cadena[j] = key;

		}
		cadena[i] = key;
	}
	i = 0;
		while(cadena[i] != '\0'){
				printf("%d, %d\n", cadena[i],i);
				i++;}


return 0;}
