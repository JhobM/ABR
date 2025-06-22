#include<iostream>
#include<string>
using namespace std;

struct ListaNombre {
	string nombre;
        ListaNombre* sig;
};

struct Nodo{
        int puntuacion;
        ListaNombre* lista;
        Nodo* izq;
        Nodo* der;
};
void insertarNombre(ListaNombre*& lista, string nombre){
	ListaNombre* actual = lista;
	while(actual !=NULL){
		if(actual->nombre == nombre){
			return;
		}
		actual = actual->sig;
	}

	ListaNombre* nuevo = new ListaNombre();
	nuevo->nombre = nombre;
	nuevo->sig = lista;
	lista = nuevo;
}

Nodo* crearNodo(string nombre, int puntuacion) {
        Nodo* nuevo = new Nodo();
        nuevo->puntuacion = puntuacion;
        nuevo->lista = NULL;
        nuevo->izq = nuevo->der = NULL;
	insertarNombre(nuevo->lista, nombre);
        return nuevo;
}

Nodo* insertar(Nodo* raiz, string nombre, int puntuacion)
{
    if(raiz==NULL)
        return crearNodo(nombre, puntuacion);

    if(puntuacion>raiz->puntuacion)
        raiz->der=insertar(raiz->der, nombre, puntuacion);
    else if(puntuacion<raiz->puntuacion)
        raiz->izq=insertar(raiz->izq, nombre, puntuacion);
    else
        insertarNombre(raiz->lista, nombre);

    return raiz;
}

Nodo* encontrarMaximo(Nodo* raiz)
{
    while(raiz->der!=NULL)
    {
        raiz=raiz->der;
    }
    return raiz;
}

Nodo* segundoMayor(Nodo* raiz)
{
    if(raiz==NULL || (raiz->izq==NULL && raiz->der==NULL))
    {
        cout<<"No existe un segundo elemento mayor.\n";
        return NULL;
    }

    Nodo* actual=raiz;
    Nodo* padre=NULL;

    while(actual->der!=NULL)
    {
        padre=actual;
        actual=actual->der;
    }

    if(actual->izq!=NULL)
    {
        return encontrarMaximo(actual->izq);
    }

    return padre;
}

int main()
{
	nodo *raiz=NULL;
	int n, puntuacion;
	string nombre;
	cout<<"¿Cuantos jugadores desea insertar?: ";
	cin>>n;

	for(int i=0;i<n;i++)
		{
			cout<<"Nombre del jugador: ";
			cin>>nombre;
			cout<<"Puntuación: ";
			cin>>puntuacion;
			raiz=insertar(raiz,nombre,puntuacion);
		}
	nodo *segundo=segundoMayor(raiz);
	if(segundo!=NULL)
	{
		cout<<"Segundo jugador con mayor puntuación: \n";
	int resultado = segundoMayor(raiz);
	if(resultado!=1)
	{
		cout<<"El segundo elemento mas grande es: "<<resultado<<endl;
	}
	return 0;
}
