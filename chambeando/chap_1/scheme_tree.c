#include <stdio.h>
#include <stdlib.h>

struct node {
    int centro;
    struct node * izquierda;
    struct node * derecha;
};
//1 = NULL, luego !=NULL ALLOCATED
struct node * crear(struct node *nudo, int n_valor){//crear y darle valor NUDO
    if((nudo = (struct node*)malloc(sizeof(struct node))) == NULL)
        return NULL;
    
    (*nudo).izquierda = NULL;
    (*nudo).derecha = NULL;
    (*nudo).centro = n_valor;
    return nudo;
}

void middle(struct node * nudo, int valor){//organizar arbol
    if((*nudo).centro > valor){
        if((*nudo).izquierda != NULL)
            middle((*nudo).izquierda, valor);
        (*nudo).izquierda = crear((*nudo).izquierda, valor);
    }
    else if((*nudo).centro < valor){
        if((*nudo).derecha != NULL)
            middle((*nudo).derecha,valor);
        (*nudo).derecha = crear((*nudo).derecha, valor);
    }
    else
        return;
}

void liberar(struct node * nudo){//liberar memoria
    if((*nudo).izquierda!= NULL)
        liberar((*nudo).izquierda);
    if((*nudo).derecha != NULL)
        liberar((*nudo).derecha);
    free(nudo);
}

int main(){
    struct node * valor = NULL;
    int *num= NULL, c = 1, max= 0, i =0;
    printf("max: ");
    scanf("%d", &max);

    if((num = (int *)malloc(max*sizeof(int)))== NULL)//memoria 1node //main node
        return 1;
        
    while(i<max){//guardar valores
        scanf("%d", &c);
        num[i] = c;
        i++;
    }
    
    if((valor = crear(valor, num[0])) == NULL)//memoria 1node //main node
        return 1;

    for(i =0;i<max;i++)//arbol
        middle(valor, num[i]);

    liberar(valor);
    free(num);
    //probando probando, luego borrar
    
    return 0;
}