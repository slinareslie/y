#include <iostream>
#include <string>

using namespace std;

struct NodoAVL
{
    int dato;
    int fe; // Factor de Equilibrio
    NodoAVL *izquierda;
    NodoAVL *derecha;
};

void insertarAVL(NodoAVL *&raiz, int valor, int &cambioAltura);
void recorridoPreorden(NodoAVL *raiz);

int main()
{
    int opcion, valor, cambioAltura = 0;
    NodoAVL *raiz = nullptr;

    // Ejemplo predeterminado para probar las funciones
    insertarAVL(raiz, 50, cambioAltura);
    insertarAVL(raiz, 30, cambioAltura);
    insertarAVL(raiz, 70, cambioAltura);
    insertarAVL(raiz, 20, cambioAltura);
    insertarAVL(raiz, 40, cambioAltura);

    do
    {
        system("cls");
        cout << "\n\n\t\tMENU" << endl
             << endl;
        cout << "1. INSERTAR" << endl;
        cout << "2. RECORRIDO" << endl;
        cout << "3. SALIR" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "\nINGRESE EL DATO: ";
            cin >> valor;
            insertarAVL(raiz, valor, cambioAltura);
            cout << endl
                 << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            recorridoPreorden(raiz);
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
    } while (opcion != 3);

    return 0;
}

void insertarAVL(NodoAVL *&raiz, int valor, int &cambioAltura)
{
    if (raiz != nullptr)
    {
        if (valor < raiz->dato)
        {
            cout << "\nNODO: " << raiz->dato << endl;
            insertarAVL(raiz->izquierda, valor, cambioAltura);
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
                    raiz1 = raiz->izquierda;
                    if (raiz1->fe >= 0)
                    {
                        raiz2 = raiz1->derecha;
                        raiz->izquierda = raiz2->derecha;
                        raiz2->derecha = raiz;
                        raiz1->derecha = raiz2->izquierda;
                        raiz2->izquierda = raiz1;
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
                        raiz->izquierda = raiz1->derecha;
                        raiz1->derecha = raiz;
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
            if (valor > raiz->dato)
            {
                cout << "\nNODO: " << raiz->dato << endl;
                insertarAVL(raiz->derecha, valor, cambioAltura);
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
                        raiz1 = raiz->derecha;
                        if (raiz1->fe < 0)
                        {
                            raiz2 = raiz1->izquierda;
                            raiz->derecha = raiz2->izquierda;
                            raiz2->izquierda = raiz;
                            raiz1->izquierda = raiz2->derecha;
                            raiz2->derecha = raiz1;
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
                            raiz->derecha = raiz1->izquierda;
                            raiz1->izquierda = raiz;
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
                cout << "\nLA CLAVE YA EXISTE" << endl;
            }
        }
    }
    else
    {
        NodoAVL *nuevoNodo;
        nuevoNodo = new (NodoAVL);
        nuevoNodo->dato = valor;
        nuevoNodo->fe = 0;
        raiz = nuevoNodo;
        nuevoNodo->izquierda = nullptr;
        nuevoNodo->derecha = nullptr;
        cambioAltura = 1;
    }
}

void recorridoPreorden(NodoAVL *raiz)
{
    if (raiz != nullptr)
    {
        cout << raiz->dato << "\t";
        recorridoPreorden(raiz->izquierda);
        recorridoPreorden(raiz->derecha);
    }
}
