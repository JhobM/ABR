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
		raiz->izq = insertar(raiz->izq, valor);
	}   else if (valor > raiz->dato) {
		raiz->der = insertar(raiz->der, valor);
	}   else{
		cout<< "El valor ya existe y no puede estar duplicado.. \n";
	}
	return raiz;
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
		return NULL;
	}

	nodo* actual=raiz;
	nodo* padre=NULL;

	while(actual->der!= NULL)
	{
		padre = actual;
		actual=actual->der;
	}

	if (actual->izq!= NULL) 
	{
		nodo* temp =encontrarMaximo(actual->izq);
		return temp->dato;
	}

	return padre->dato;
}

int main()
{
	nodo *raiz=NULL;
	int n, valor;
	cout<<"¿Cuantos valores desea insertaar?: ";
	cin>>n;

	for(int i=0;i<n;i++)
		{
			cout<<"Ingrese valor: ";
			cin>>valor
}
