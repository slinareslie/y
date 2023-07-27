#include <iostream>
#include <string>

using namespace std;

struct NodoAVL
{
    int dato;
    int fe;
    NodoAVL *izq;
    NodoAVL *der;
};

void insertarAVL(NodoAVL *&raiz, int dato, int &cambioAltura);
void eliminarAVL(NodoAVL *&raiz, int dato, int &cambioAltura);
void reestructurar1(NodoAVL *&raiz, int &cambioAltura);
void reestructurar2(NodoAVL *&raiz, int &cambioAltura);
void borrar(NodoAVL *&aux, NodoAVL *&otro, int &cambioAltura);
void buscarAVL(NodoAVL *raiz, int dato);
void preorden(NodoAVL *raiz);
void menu(NodoAVL *&raiz);

int main()
{
    NodoAVL *raiz = NULL;
    menu(raiz);

    return 0;
}

void menu(NodoAVL *&raiz)
{
    int opc, dato, cambioAltura = 0;

    // Ejemplo predeterminado: Insertamos algunos nodos automáticamente
    insertarAVL(raiz, 50, cambioAltura);
    insertarAVL(raiz, 30, cambioAltura);
    insertarAVL(raiz, 70, cambioAltura);
    insertarAVL(raiz, 20, cambioAltura);
    insertarAVL(raiz, 40, cambioAltura);
    insertarAVL(raiz, 60, cambioAltura);
    insertarAVL(raiz, 80, cambioAltura);

    do
    {
        system("cls");
        cout << "\n\t\t\tMENU";
        cout << "\n\t\t\t====";
        cout << "\n\n1. INSERTAR NUEVO DATO";
        cout << "\n\n2. ELIMINAR DATO";
        cout << "\n\n3. BUSCAR DATO";
        cout << "\n\n4. RECORRIDO PREORDEN";
        cout << "\n\n5. SALIR";

        cout << "\n\nOPCION:  ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("cls");
            cout << "\n\nINGRESE EL DATO A INSERTAR: ";
            cin >> dato;
            insertarAVL(raiz, dato, cambioAltura);
            cout << "\n\nSE HA INSERTADO EL DATO: " << dato << endl;
            cout << endl
                 << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "\n\nINGRESE EL DATO A ELIMINAR: ";
            cin >> dato;
            eliminarAVL(raiz, dato, cambioAltura);
            cout << "\n\nSE HA ELIMINADO EL DATO: " << dato << endl;
            cout << endl
                 << endl;
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "\n\nINGRESE EL DATO A BUSCAR: ";
            cin >> dato;
            buscarAVL(raiz, dato);
            cout << endl
                 << endl;
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "\n\nRECORRIDO PREORDEN:" << endl;
            preorden(raiz);
            cout << endl
                 << endl;
            system("pause");
            break;
        }
    } while (opc != 5);
}

void insertarAVL(NodoAVL *&raiz, int dato, int &cambioAltura)
{
    if (raiz != NULL)
    {
        if (dato < raiz->dato)
        {
            insertarAVL(raiz->izq, dato, cambioAltura);
            if (cambioAltura == 1)
            {
                switch (raiz->fe)
                {
                case 1:
                    raiz->fe = 0;
                    cambioAltura = 0;
                    break;
                case 0:
                    raiz->fe = -1;
                    break;
                case -1:
                    NodoAVL *raiz1, *raiz2;
                    raiz1 = raiz->izq;
                    if (raiz1->fe >= 0)
                    {
                        raiz2 = raiz1->der;
                        raiz->izq = raiz2->der;
                        raiz2->der = raiz;
                        raiz1->der = raiz2->izq;
                        raiz2->izq = raiz1;
                        if (raiz2->fe == -1)
                        {
                            raiz->fe = 1;
                        }
                        else
                        {
                            raiz->fe = 0;
                        }
                        if (raiz2->fe == 1)
                        {
                            raiz1->fe = -1;
                        }
                        else
                        {
                            raiz1->fe = 0;
                        }
                        raiz = raiz2;
                    }
                    else
                    {
                        raiz->izq = raiz1->der;
                        raiz1->der = raiz;
                        raiz->fe = 0;
                        raiz = raiz1;
                    }
                    raiz->fe = 0;
                    cambioAltura = 0;
                    break;
                }
            }
        }
        else
        {
            if (dato > raiz->dato)
            {
                insertarAVL(raiz->der, dato, cambioAltura);
                if (cambioAltura == 1)
                {
                    switch (raiz->fe)
                    {
                    case -1:
                        raiz->fe = 0;
                        cambioAltura = 0;
                        break;
                    case 0:
                        raiz->fe = 1;
                        break;
                    case 1:
                        NodoAVL *raiz1, *raiz2;
                        raiz1 = raiz->der;
                        if (raiz1->fe < 0)
                        {
                            raiz2 = raiz1->izq;
                            raiz->der = raiz2->izq;
                            raiz2->izq = raiz;
                            raiz1->izq = raiz2->der;
                            raiz2->der = raiz1;
                            if (raiz2->fe == 1)
                            {
                                raiz->fe = -1;
                            }
                            else
                            {
                                raiz->fe = 0;
                            }
                            if (raiz2->fe == -1)
                            {
                                raiz1->fe = 1;
                            }
                            else
                            {
                                raiz1->fe = 0;
                            }
                            raiz = raiz2;
                        }
                        else
                        {
                            raiz->der = raiz1->izq;
                            raiz1->izq = raiz;
                            raiz->fe = 0;
                            raiz = raiz1;
                        }
                        raiz->fe = 0;
                        cambioAltura = 0;
                        break;
                    }
                }
            }
            else
            {
                cout << "\nEL DATO YA EXISTE" << endl;
            }
        }
    }
    else
    {
        NodoAVL *nuevoNodo;
        nuevoNodo = new NodoAVL;
        nuevoNodo->dato = dato;
        nuevoNodo->fe = 0;
        raiz = nuevoNodo;
        nuevoNodo->izq = NULL;
        nuevoNodo->der = NULL;
        cambioAltura = 1;
    }
}

void eliminarAVL(NodoAVL *&raiz, int dato, int &cambioAltura)
{
    if (raiz != NULL)
    {
        if (dato < raiz->dato)
        {
            eliminarAVL(raiz->izq, dato, cambioAltura);
            reestructurar1(raiz, cambioAltura);
        }
        else
        {
            if (dato > raiz->dato)
            {
                eliminarAVL(raiz->der, dato, cambioAltura);
                reestructurar2(raiz, cambioAltura);
            }
            else
            {
                NodoAVL *nodoEliminar;
                nodoEliminar = raiz;
                if (nodoEliminar->der == NULL)
                {
                    raiz = nodoEliminar->izq;
                    cambioAltura = 1;
                }
                else
                {
                    if (nodoEliminar->izq == NULL)
                    {
                        raiz = nodoEliminar->der;
                        cambioAltura = 1;
                    }
                    else
                    {
                        borrar(nodoEliminar->izq, nodoEliminar, cambioAltura);
                        reestructurar1(raiz, cambioAltura);
                        delete (nodoEliminar);
                    }
                }
            }
        }
    }
    else
    {
        cout << "\nEL DATO NO EXISTE" << endl;
    }
}

void reestructurar1(NodoAVL *&raiz, int &cambioAltura)
{
    if (cambioAltura == 1)
    {
        switch (raiz->fe)
        {
        case -1:
            raiz->fe = 0;
            break;
        case 0:
            raiz->fe = 1;
            cambioAltura = 0;
            break;
        case 1:
            NodoAVL *raiz1, *raiz2;
            raiz1 = raiz->der;
            if (raiz1->fe >= 0)
            {
                raiz->der = raiz1->izq;
                raiz1->izq = raiz;
                switch (raiz1->fe)
                {
                case 0:
                    raiz->fe = 1;
                    raiz1->fe = -1;
                    cambioAltura = 0;
                    break;
                case 1:
                    raiz->fe = 0;
                    raiz1->fe = 0;
                    break;
                }
                raiz = raiz1;
            }
            else
            {
                raiz2 = raiz1->izq;
                raiz->der = raiz2->izq;
                raiz2->izq = raiz;
                raiz1->izq = raiz2->der;
                raiz2->der = raiz1;
                if (raiz2->fe == 1)
                {
                    raiz->fe = -1;
                }
                else
                {
                    raiz->fe = 0;
                }
                if (raiz2->fe == -1)
                {
                    raiz1->fe = 1;
                }
                else
                {
                    raiz1->fe = 0;
                }
                raiz2->fe = 0;
                raiz = raiz2;
            }
            break;
        }
    }
}

void reestructurar2(NodoAVL *&raiz, int &cambioAltura)
{
    if (cambioAltura == 1)
    {
        switch (raiz->fe)
        {
        case 1:
            raiz->fe = 0;
            break;
        case 0:
            raiz->fe = 1;
            cambioAltura = 0;
            break;
        case -1:
            NodoAVL *raiz1, *raiz2;
            raiz1 = raiz->izq;
            if (raiz1->fe <= 0)
            {
                raiz->izq = raiz1->der;
                raiz1->der = raiz;
                switch (raiz1->fe)
                {
                case 0:
                    raiz->fe = -1;
                    raiz1->fe = 1;
                    cambioAltura = 0;
                    break;
                case -1:
                    raiz->fe = 0;
                    raiz1->fe = 0;
                    break;
                }
                raiz = raiz1;
            }
            else
            {
                raiz2 = raiz1->der;
                raiz->izq = raiz2->der;
                raiz2->der = raiz;
                raiz1->der = raiz2->izq;
                raiz2->izq = raiz1;
                if (raiz2->fe == -1)
                {
                    raiz->fe = 1;
                }
                else
                {
                    raiz->fe = 0;
                }
                if (raiz2->fe == 1)
                {
                    raiz1->fe = -1;
                }
                else
                {
                    raiz1->fe = 0;
                }
                raiz2->fe = 0;
                raiz = raiz2;
            }
            break;
        }
    }
}

void borrar(NodoAVL *&aux, NodoAVL *&otro, int &cambioAltura)
{
    if (aux->der != NULL)
    {
        borrar(aux->der, otro, cambioAltura);
        reestructurar2(aux, cambioAltura);
    }
    else
    {
        otro->dato = aux->dato;
        otro = aux;
        aux = aux->izq;
        cambioAltura = 1;
    }
}

void buscarAVL(NodoAVL *raiz, int dato)
{
    if (raiz != NULL)
    {
        if (dato < raiz->dato)
        {
            if (raiz->izq != NULL)
            {
                buscarAVL(raiz->izq, dato);
            }
            else
            {
                cout << "\nEL DATO NO EXISTE" << endl;
            }
        }
        else
        {
            if (dato > raiz->dato)
            {
                if (raiz->der != NULL)
                {
                    buscarAVL(raiz->der, dato);
                }
                else
                {
                    cout << "\nEL DATO NO EXISTE" << endl;
                }
            }
            else
            {
                cout << "\nEL DATO ES LOCALIZADO" << endl
                     << endl;
                cout << "\nDATO: " << raiz->dato << endl;
            }
        }
    }
    else
    {
        cout << "\nEL DATO NO EXISTE" << endl;
    }
}

void preorden(NodoAVL *raiz)
{
    if (raiz != NULL)
    {
        cout << raiz->dato << "\t";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}
