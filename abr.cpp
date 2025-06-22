#include<iostream>
#include<string>
using namespace std;

struct ListaNombre {
	string nombre;
        ListaNombre* sig;
};

struct Nodo{
        


};

nodo* crearNodo(string nombre, int puntuacion) {
        Nodo* nuevo = new Nodo();
        nuevo->nombre = nombre;
        nuevo->puntuacion = puntuacion;
        nuevo->izq = nuevo->der = NULL;
        return nuevo;
}

nodo *insertar(nodo* raiz, string nombre, int puntuacion){
	if(raiz == NULL){
		return crearNodo(nombre, puntuacion);
	}
        if(puntuacion > raiz->puntuacion){
		raiz->der = insertar(raiz->der, nombre, puntuacion);
	}   else if (puntuacion < raiz->puntuacion) {
		raiz->izq = insertar(raiz->izq, nombre, puntuacion);
	}   else{
		raiz->puntuacion = puntuacion;
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
			cin>>valor;
			raiz=insertar(raiz,valor);
		}
	int resultado = segundoMayor(raiz);
	if(resultado!=1)
	{
		cout<<"El segundo elemento mas grande es: "<<resultado<<endl;
	}
	return 0;
}
