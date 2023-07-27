#include <iostream>
#include <string>

using namespace std;

struct ArbolBinario
{
    int valor;
    int altura;
    ArbolBinario *izquierda;
    ArbolBinario *derecha;
};

void insertar(ArbolBinario *&raiz, int altura, int dato);
int obtenerAlturaArbol(ArbolBinario *&raiz, int &altura);
int diferenciaAlturasRamas(ArbolBinario *&raiz);
void contarHojas(ArbolBinario *&raiz, int &hoja);
void contarNodosInteriores(ArbolBinario *&raiz, int &ni);

int main()
{
    ArbolBinario *raiz = nullptr;
    int altura = 0, hojas = 0, nodosInteriores = 0, opcion, dato;

    insertar(raiz, 0, 50);
    insertar(raiz, 0, 30);
    insertar(raiz, 0, 70);
    insertar(raiz, 0, 20);
    insertar(raiz, 0, 40);
    insertar(raiz, 0, 60);
    insertar(raiz, 0, 80);

    do
    {
        system("cls");
        cout << "\n\n\t\tMENU" << endl
             << endl;
        cout << "1. INSERTAR NODO" << endl;
        cout << "2. ALTURA DEL ARBOL" << endl;
        cout << "3. DIFERENCIA DE ALTURAS ENTRE RAMA IZQUIERDA Y DERECHA" << endl;
        cout << "4. CONTAR HOJAS" << endl;
        cout << "5. CONTAR NODOS INTERIORES" << endl;
        cout << "6. SALIR" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "INGRESE EL DATO: ";
            cin >> dato;
            insertar(raiz, 0, dato);
            cout << endl
                 << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "LA ALTURA DEL ARBOL ES: " << obtenerAlturaArbol(raiz, altura) << endl
                 << endl;
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "LA DIFERENCIA DE ALTURAS ENTRE LA RAMA IZQUIERDA Y LA RAMA DERECHA ES: " << diferenciaAlturasRamas(raiz) << endl
                 << endl;
            system("pause");
            break;

        case 4:
            system("cls");
            contarHojas(raiz, hojas);
            cout << "\nEL NUMERO TOTAL DE HOJAS DEL ARBOL ES: " << hojas << endl
                 << endl;
            system("pause");
            break;

        case 5:
            system("cls");
            contarNodosInteriores(raiz, nodosInteriores);
            cout << "\nEL NUMERO TOTAL DE NODOS INTERIORES DEL ARBOL ES: " << nodosInteriores << endl
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
    } while (opcion != 6);

    return 0;
}

void insertar(ArbolBinario *&raiz, int altura, int dato)
{
    if (raiz != nullptr)
    {
        if (dato < raiz->valor)
        {
            insertar(raiz->izquierda, raiz->altura, dato);
        }
        else if (dato > raiz->valor)
        {
            insertar(raiz->derecha, raiz->altura, dato);
        }
        else
        {
            cout << "\n\n\tDATO REPETIDO" << endl;
        }
    }
    else
    {
        ArbolBinario *nuevoNodo = new ArbolBinario;
        nuevoNodo->altura = altura + 1;
        nuevoNodo->valor = dato;
        nuevoNodo->izquierda = nullptr;
        nuevoNodo->derecha = nullptr;
        raiz = nuevoNodo;
    }
}

int obtenerAlturaArbol(ArbolBinario *&raiz, int &altura)
{
    if (raiz != nullptr)
    {
        if ((raiz->izquierda == nullptr) && (raiz->derecha == nullptr))
        {
            int alturaNodo = raiz->altura;
            if (alturaNodo > altura)
            {
                altura = alturaNodo;
            }
        }
        obtenerAlturaArbol(raiz->izquierda, altura);
        obtenerAlturaArbol(raiz->derecha, altura);
    }
    return altura;
}

int diferenciaAlturasRamas(ArbolBinario *&raiz)
{
    int alturaIzquierda = 0, alturaDerecha = 0;
    obtenerAlturaArbol(raiz->izquierda, alturaIzquierda);
    obtenerAlturaArbol(raiz->derecha, alturaDerecha);
    return alturaIzquierda - alturaDerecha;
}

void contarHojas(ArbolBinario *&raiz, int &hoja)
{
    if (raiz != nullptr)
    {
        if ((raiz->izquierda == nullptr) && (raiz->derecha == nullptr))
        {
            hoja++;
            cout << "LA HOJA NUMERO " << hoja << " ES: " << raiz->valor << endl;
        }
        contarHojas(raiz->izquierda, hoja);
        contarHojas(raiz->derecha, hoja);
    }
}

void contarNodosInteriores(ArbolBinario *&raiz, int &ni)
{
    if (raiz != nullptr)
    {
        if ((raiz->izquierda != nullptr) || (raiz->derecha != nullptr))
        {
            ni++;
            cout << "EL NODO INTERIOR NUMERO " << ni << " ES: " << raiz->valor << endl;
        }
        contarNodosInteriores(raiz->izquierda, ni);
        contarNodosInteriores(raiz->derecha, ni);
    }
}
