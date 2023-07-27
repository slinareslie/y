#include <iostream>

using namespace std;

struct nodo
{
    char inf;
    nodo *izq = nullptr, *der = nullptr;
};

void crear(nodo *&);
void preorden(const nodo *);
void inorden(const nodo *);
void postorden(const nodo *);
int contHojas(const nodo *, int &);
void mostrarHojas(const nodo *);
int contNodosInt(const nodo *, int &);
void mostrarNodosInt(const nodo *);

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    nodo *raiz = new nodo;
    int contH = 0, contNI = 0;

    crear(raiz);
    cout << "\n\nRecorrido preorden\n";
    preorden(raiz);

    cout << "\n\nRecorrido inorden\n";
    inorden(raiz);

    cout << "\n\nRecorrido postorden\n";
    postorden(raiz);

    cout << "\n\nTiene: " << contHojas(raiz, contH) << " hojas\n";
    cout << "\nLas hojas son:\n";
    mostrarHojas(raiz);

    cout << "\n\nTiene: " << contNodosInt(raiz, contNI) << " nodos internos\n";
    cout << "\nLos nodos internos son:\n";
    mostrarNodosInt(raiz);

    return 0;
}

void crear(nodo *&raiz)
{
    cout << "\nIngresa un caracter: ";
    cin >> raiz->inf;

    int opc;
    do
    {
        cout << "\nTiene izquierda?: \n\n1)Si\n2)N0\n\n";
        cin >> opc;
        if (opc != 1 && opc != 2)
            cout << "\nIngrese una respuesta valida";
    } while (opc != 1 && opc != 2);

    if (opc == 1)
    {
        raiz->izq = new nodo;
        crear(raiz->izq);
    }
    /*else
        raiz->izq = nullptr;*/

    do
    {
        cout << "\nTiene derecha?: \n\n1)Si\n2)N0\n\n";
        cin >> opc;
        if (opc != 1 && opc != 2)
            cout << "\nIngrese una respuesta valida";
    } while (opc != 1 && opc != 2);

    if (opc == 1)
    {
        raiz->der = new nodo;
        crear(raiz->der);
    }
    /*else
        raiz->der = nullptr;*/
}

void preorden(const nodo *raiz)
{
    if (raiz != nullptr)
    {
        cout << raiz->inf << " ";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}
void inorden(const nodo *raiz)
{
    if (raiz != nullptr)
    {
        inorden(raiz->izq);
        cout << raiz->inf << " ";
        inorden(raiz->der);
    }
}
void postorden(const nodo *raiz)
{
    if (raiz != nullptr)
    {
        postorden(raiz->izq);
        postorden(raiz->der);
        cout << raiz->inf << " ";
    }
}

int contHojas(const nodo *raiz, int &cont)
{
    if (raiz != nullptr)
    {
        if (raiz->izq == nullptr && raiz->der == nullptr)
        {
            cont++;
            return cont;
        }
        else
        {
            contHojas(raiz->izq, cont);
            contHojas(raiz->der, cont);
        }
    }
    else
        return cont;
}

void mostrarHojas(const nodo *raiz)
{
    if (raiz != nullptr)
    {
        if (raiz->izq == nullptr && raiz->der == nullptr)
            cout << raiz->inf << " ";
        else
        {
            mostrarHojas(raiz->der);
            mostrarHojas(raiz->izq);
        }
    }
}

int contNodosInt(const nodo *raiz, int &cont)
{
    if (raiz != nullptr)
    {
        if (raiz->izq != nullptr || raiz->der != nullptr)
        {
            cont++;
            contNodosInt(raiz->der, cont);
            contNodosInt(raiz->izq, cont);
            return cont;
        }
    }
}

void mostrarNodosInt(const nodo *raiz)
{
    if (raiz != nullptr)
    {
        if (raiz->izq != nullptr || raiz->der != nullptr)
        {
            cout << raiz->inf << " ";
            mostrarNodosInt(raiz->der);
            mostrarNodosInt(raiz->izq);
        }
    }
}