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

int main()
{
	
}
