#include <iostream>
#include <string>

using namespace std;

struct NodoABB
{
    int dato;
    NodoABB *izquierda;
    NodoABB *derecha;
};

void insertar(NodoABB *&raiz, int dato);
void obtenerMayor(NodoABB *&raiz, int &mayor);
void obtenerMenor(NodoABB *&raiz, int &menor);
void preorden(NodoABB *raiz, int &contador);

int main()
{
    NodoABB *raiz = NULL;
    int opcion, dato, mayor, menor, contador;
    do
    {
        system("cls");
        cout << "\n\n\t\tMENÚ" << endl
             << endl;
        cout << "1. INSERTAR ELEMENTO" << endl;
        cout << "2. OBTENER PROMEDIO ENTRE CLAVE MAYOR Y MENOR" << endl;
        cout << "3. MOSTRAR RECORRIDO PREORDEN" << endl;
        cout << "4. SALIR" << endl;
        cout << "\n\t\tOPCIÓN: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "INGRESE EL DATO: ";
            cin >> dato;
            insertar(raiz, dato);
            cout << endl
                 << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            mayor = 0;
            obtenerMayor(raiz, mayor);
            menor = mayor;
            obtenerMenor(raiz, menor);
            cout << "\n\nEL PROMEDIO ENTRE LA CLAVE MENOR Y MAYOR ES: " << (mayor + menor) / 2 << endl
                 << endl;
            system("pause");
            break;

        case 3:
            contador = 0;
            system("cls");
            preorden(raiz, contador);
            cout << endl
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
    } while (opcion != 4);
    return 0;
}

void insertar(NodoABB *&raiz, int dato)
{
    NodoABB *nuevoNodo;
    if (raiz != NULL)
    {
        if (dato < raiz->dato)
        {
            insertar(raiz->izquierda, dato);
        }
        else if (dato > raiz->dato)
        {
            insertar(raiz->derecha, dato);
        }
        else
        {
            cout << "\n\n\tDATO REPETIDO" << endl;
        }
    }
    else
    {
        nuevoNodo = new NodoABB;
        nuevoNodo->dato = dato;
        nuevoNodo->izquierda = NULL;
        nuevoNodo->derecha = NULL;
        raiz = nuevoNodo;
    }
}

void obtenerMayor(NodoABB *&raiz, int &mayor)
{
    if (raiz != NULL)
    {
        if (raiz->dato > mayor)
        {
            mayor = raiz->dato;
        }
        obtenerMayor(raiz->izquierda, mayor);
        obtenerMayor(raiz->derecha, mayor);
    }
}

void obtenerMenor(NodoABB *&raiz, int &menor)
{
    if (raiz != NULL)
    {
        if (raiz->dato < menor)
        {
            menor = raiz->dato;
        }
        obtenerMenor(raiz->izquierda, menor);
        obtenerMenor(raiz->derecha, menor);
    }
}

void preorden(NodoABB *raiz, int &contador)
{
    if (raiz != NULL)
    {
        contador++;
        cout << "NODO " << contador << ": " << raiz->dato << "\t";
        preorden(raiz->izquierda, contador);
        preorden(raiz->derecha, contador);
    }
}
