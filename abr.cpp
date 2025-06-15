#include<iostream>
using namespace std;

struct nodo {
	int dato;
	nodo *izq;
	nodo *der;
};

nodo *nuevonodo(int valor) {
        nodo *Nodo = new nodo();
        Nodo->dato = valor;
        Nodo->izq = NULL;
        Nodo->der = NULL;
        return Nodo;
}

nodo *insertar(nodo* raiz, int valor){
	if(raiz == NULL){
		return nuevonodo (valor);
	}
        if(valor < raiz->dato){
		raiz->izq = insertar
	}   

nodo* encontrarMaximo(nodo* raiz)
{
	while(raiz->der != NULL)
	{
		raiz=raiz->der;
	}
	return raiz;
}

int segundoMayor(nodo* raiz)
{
	if(raiz==NULL || (raiz->izq==NULL && raiz->der==NULL))
	{
		cout<<"No existe un segundo elemento mayor \n";
		return -1;
	}

	nodo
}

int main()
{
	
}
