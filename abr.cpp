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

int buscar(Nodo* raiz, string nombre){
	if (raiz == NULL){
		return -1;
	}
	ListaNombre* actual = raiz->lista;
	while (actual != NULL){
		if(actual->nombre == nombre){
			return raiz->puntuacion;
		}
		actual = actual->sig;
	}
	int izq = buscar(raiz->izq, nombre);
	if(izq != -1){
		return izq;
	}
	return buscar(raiz->der, nombre);
}

void mostrarTopN(Nodo* raiz,int& contador, intN)
{
if(raiz==nullptr || contador >=N) return;

mostrarTopN(raiz->deer, contador, N);
if(contador<N)
{
cout<< contador + 1 << ".";
	ListaNombre* actual = raiz->lista;
	while(actual!=nullptr)
	{
		cout<<actua->nombre;
		if(actual->sig !=nullptr)
			cout<<",";
		actual=actual->sig;
	}
}

cout<<" - "<<raiz->puntuacion<<endl;
contador++;
}

int main()
{
	Nodo *raiz= nullptr;
	int opcion, N;
	string nombre;
	int puntuacion;

	do
		{
			cout << "\nSISTEMA DE RANKING - MENU\n";
			cout << "1. Insertar/Actualizar jugador\n";
			cout << "2. Buscar jugador\n";
			cout << "3. Mostrar top N jugadores\n";
			cout << "4. Salir\n";
			cout << "Seleccione una opcion: ";
			cin>>opcion;

			
		}

}
