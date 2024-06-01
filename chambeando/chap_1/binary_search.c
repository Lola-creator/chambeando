#include <stdio.h>
#include <stdlib.h>

int techo (float  num){
	int valor = num-(int)num;
		if(valor!=0)
			return (int)num+1;	
	return num;

}

int binary(int *A, int valor, int inicio, int final){
	int medio = techo((final-inicio)/2) + inicio;

	if (valor==A[medio]) return medio;
	else if(valor<A[medio]) final=medio;
	else /**/ inicio= medio;
								
	if(inicio!=final) medio =binary(A,valor, inicio,final);
	else medio = -1;

	return medio;

}
int main(){
	int num =0, inicio =0, tam;
	
	int * cadena;
	printf("valor: ");
	scanf("%d",&num);

	printf("tam: ");
	scanf("%d", &tam);

	if((cadena = (int*)malloc(tam*sizeof(int))) == NULL)
		return 1;

	for(int i=0;i<tam; i++)
		scanf("%d", &cadena[i]);

	printf("indice %d", binary(cadena, num, inicio, tam-1 ));
	free(cadena);

	return 0;
}
