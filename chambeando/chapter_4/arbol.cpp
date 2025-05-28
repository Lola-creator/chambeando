#include <iostream>

class Nodo
{
    public:
    int valor;
    class Nodo *Right;
    class Nodo *Left;

    Nodo(int v)
    {
        valor = v;
        Right = nullptr;
        Left = nullptr;
    }
};

class Arbol
{
    public:

    class Nodo * Root;
    Arbol()
    {//redundandte pero anyway
        Root = nullptr;
    }
//el nodo raiz de todo se asume que ya esta lleno de algo 
    void insertar(class Nodo *&nodo, int number)
    {
        if(nodo == nullptr )
        {
            crear(nodo, number);
            return;
        }

        if((nodo->valor) > number)
        {
            insertar(nodo->Left,number);
        }
        else if((nodo->valor) < number)
        {
            insertar(nodo->Right,number);
        }

    }

    void insertar(int numero)
    {
        insertar(Root, numero);
    }
    void crear(class Nodo * &lugar, int numero)
    {
        lugar = new Nodo(numero);
    }

    void liberar(class Nodo *Hola)
    {
        class Nodo * buffer = Hola;
        if(buffer !=nullptr)
        {
            liberar(buffer->Left);
            liberar((*buffer).Right);
            delete buffer;
        }
    }

    ~Arbol()
    {
        liberar(Root);
    }
    
};


int main()
{
    Arbol arbolito;

    arbolito.insertar(10);
    arbolito.insertar(5);
    arbolito.insertar(15);
    arbolito.insertar(3);
    arbolito.insertar(8);

    
    return 0;
}