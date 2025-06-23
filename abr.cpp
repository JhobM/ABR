#include <iostream>
#include <string>
using namespace std;
//Estructura para la lista enlazada de nombres asociados a un puntaje
struct ListaNombre
{
    string nombre;
    ListaNombre* sig; //Siguiente jugador en la lista
};
//Estructura del nodo del árbol binario
struct Nodo
{
    int puntuacion;            //Puntaje
    ListaNombre* lista;        //Lista de jugadores con ese puntaje
    Nodo* izq;                 //Subárbol izquierdo (menor puntuación)
    Nodo* der;                 //Subárbol derecho (mayor puntuación)
};
//Inserta un nombre en la lista si no está repetido
void insertarNombre(ListaNombre*& lista, string nombre)
{
    ListaNombre* actual=lista;
    while(actual!=NULL)
    {
        if(actual->nombre==nombre)
        {
            return; //Ya está en la lista
        }
        actual=actual->sig;
    }
    //Insertar al inicio
    ListaNombre* nuevo=new ListaNombre();
    nuevo->nombre=nombre;
    nuevo->sig=lista;
    lista=nuevo;
}
//Crea un nuevo nodo con la puntuación y el nombre
Nodo* crearNodo(string nombre, int puntuacion)
{
    Nodo* nuevo=new Nodo();
    nuevo->puntuacion=puntuacion;
    nuevo->lista=NULL;
    nuevo->izq=nuevo->der=NULL;
    insertarNombre(nuevo->lista, nombre); //Insertar nombre en su lista
    return nuevo;
}

//Inserta un jugador en el árbol
Nodo* insertar(Nodo* raiz, string nombre, int puntuacion)
{
    if(raiz==NULL)
    {
        return crearNodo(nombre, puntuacion);
    }

    if(puntuacion>raiz->puntuacion)
    {
        raiz->der=insertar(raiz->der, nombre, puntuacion);
    }
    else if(puntuacion<raiz->puntuacion)
    {
        raiz->izq=insertar(raiz->izq, nombre, puntuacion);
    }
    else
    {
        insertarNombre(raiz->lista, nombre);
    }

    return raiz;
}
//Busca un jugador por nombre y devuelve su puntuación
int buscar(Nodo* raiz, string nombre)
{
    if(raiz==NULL)
    {
        return -1; //No encontrado
    }
    ListaNombre* actual=raiz->lista;
    while(actual!=NULL)
    {
        if(actual->nombre==nombre)
        {
            return raiz->puntuacion;
        }
        actual=actual->sig;
    }
    int izq=buscar(raiz->izq, nombre);
    if(izq!=-1)
    {
        return izq;
    }
    return buscar(raiz->der, nombre);
}

//Muestra los N primeros jugadores con mayor puntuación
void mostrarTopN(Nodo* raiz, int& contador, int N)
{
    if(raiz==NULL || contador>=N)
    {
        return;
    }
    mostrarTopN(raiz->der, contador, N); //Recorrido inorden invertido
    if(contador<N)
    {
        cout<<contador+1<<". ";
        ListaNombre* actual=raiz->lista;
        while(actual!=NULL)
        {
            cout<<actual->nombre;
            if(actual->sig!=NULL)
            {
                cout<<", ";
            }
            actual=actual->sig;
        }
        cout<<" - "<<raiz->puntuacion<<"\n";
        contador++;
    }
    mostrarTopN(raiz->izq, contador, N);
}

//Encuentra el nodo con la mayor puntuación
Nodo* encontrarMaximo(Nodo* raiz)
{
    while(raiz->der!=NULL)
    {
        raiz=raiz->der;
    }
    return raiz;
}

//Encuentra el nodo con la segunda mayor puntuación
Nodo* encontrarSegundoMayor(Nodo* raiz)
{
    if(raiz==NULL || (raiz->izq==NULL && raiz->der==NULL))
    {
        return NULL; //No hay suficientes jugadores
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

// Muestra el segundo jugador con mayor puntuación (pueden ser varios con mismo puntaje)
void mostrarSegundoMayor(Nodo* raiz)
{
    Nodo* segundo=encontrarSegundoMayor(raiz);
    if(segundo!=NULL)
    {
        cout<<"Segundo mayor puntaje: "<<segundo->puntuacion<<" - ";
        ListaNombre* actual=segundo->lista;
        while(actual!=NULL)
        {
            cout<<actual->nombre;
            if(actual->sig!=NULL)
            {
                cout<<", ";
            }
            actual=actual->sig;
        }
        cout<<"\n";
    }
    else
    {
        cout<<"No hay suficientes jugadores para determinar el segundo mayor.\n";
    }
}

// Función principal
int main()
{
    Nodo* raiz=NULL;
    int opcion, N;
    string nombre;
    int puntuacion;
    do
    {
        cout<<"\nSISTEMA DE RANKING - MENU\n";
        cout<<"1. Insertar/Actualizar jugador\n";
        cout<<"2. Buscar jugador\n";
        cout<<"3. Mostrar top N jugadores\n";
        cout<<"4. Mostrar segundo jugador con mayor puntuación\n";
        cout<<"5. Salir\n";
        // Validar opción
        do
        {
            cout<<"Seleccione una opcion: ";
            cin>>opcion;
            if(opcion<1 || opcion>5)
            {
                cout<<"Opcion invalida...\n";
            }
        } while(opcion<1 || opcion>5);
        switch(opcion)
        {
            case 1:
                cout<<"Nombre del jugador: ";
                cin>>nombre;
                cout<<"Puntuación: ";
                cin>>puntuacion;
                raiz=insertar(raiz, nombre, puntuacion);
                break;
            case 2:
                cout<<"Nombre del jugador a buscar: ";
                cin>>nombre;
                puntuacion=buscar(raiz, nombre);
                if(puntuacion!=-1)
                {
                    cout<<"Puntuación de "<<nombre<<": "<<puntuacion<<"\n";
                }
                else
                {
                    cout<<"Jugador no encontrado.\n";
                }
                break;
            case 3:
                cout<<"¿Cuántos jugadores mostrar?: ";
                cin>>N;
                {
                    int contador=0;
                    mostrarTopN(raiz, contador, N);
                }
                break;
            case 4:
                mostrarSegundoMayor(raiz);
                break;
            case 5:
                cout<<"Saliendo...\n";
                break;
        }
    } while(opcion!=5);
    return 0;
}
