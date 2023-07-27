#include <iostream>
#include <string>

using namespace std;

struct NodoABB
{
    int dato;
    NodoABB *hijoIzquierdo;
    NodoABB *hijoDerecho;
};

void insertar(NodoABB *&raiz, int &contadorNodos, int dato);

int main()
{
    NodoABB *raiz = nullptr;
    int contadorNodos = 0;
    int opcion, dato;

    insertar(raiz, contadorNodos, 10);
    insertar(raiz, contadorNodos, 5);
    insertar(raiz, contadorNodos, 15);
    insertar(raiz, contadorNodos, 2);
    insertar(raiz, contadorNodos, 7);

    do
    {
        system("cls");
        cout << "\n\t\tMENU" << endl
             << endl;
        cout << "1. INSERTAR NUEVO NODO" << endl;
        cout << "2. CONTAR NUMERO DE NODOS" << endl;
        cout << "3. SALIR" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "INGRESE EL DATO: ";
            cin >> dato;
            insertar(raiz, contadorNodos, dato);
            cout << endl
                 << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "EL NUMERO TOTAL DE NODOS QUE TIENE EL ARBOL ES: " << contadorNodos << endl
                 << endl;
            system("pause");
            break;

        default:
            cout << "\n\t\tCERRANDO PROGRAMA" << endl
                 << endl;
            system("pause");
            system("cls");
            break;
        }
    } while (opcion != 3);

    return 0;
}

void insertar(NodoABB *&raiz, int &contadorNodos, int dato)
{
    if (raiz != nullptr)
    {
        if (dato < raiz->dato)
        {
            insertar(raiz->hijoIzquierdo, contadorNodos, dato);
        }
        else if (dato > raiz->dato)
        {
            insertar(raiz->hijoDerecho, contadorNodos, dato);
        }
        else
        {
            cout << "\n\n\tDATO REPETIDO" << endl;
        }
    }
    else
    {
        NodoABB *nuevoNodo = new NodoABB;
        nuevoNodo->dato = dato;
        nuevoNodo->hijoIzquierdo = nullptr;
        nuevoNodo->hijoDerecho = nullptr;
        raiz = nuevoNodo;
        contadorNodos++;
    }
}
