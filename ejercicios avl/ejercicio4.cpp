#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct AVL
{
    int dato;
    int factor_equilibrio;
    AVL *izquierda;
    AVL *derecha;
};

void insertar_avl(AVL *&raiz, int dato, int &cambio_en_raiz);
void eliminar_avl(AVL *&raiz, int dato, int &cambio_en_raiz, int &rotaciones);
void reestructurar_izquierda(AVL *&raiz, int &cambio_en_raiz, int &rotaciones);
void reestructurar_derecha(AVL *&raiz, int &cambio_en_raiz, int &rotaciones);
void borrar_nodo(AVL *&nodo, AVL *&padre, int &cambio_en_raiz, int &rotaciones);

void mostrar_menu();
void mostrar_preorden(AVL *raiz, int &contador);
void mostrar_inorden(AVL *&raiz, int &contador);

int main()
{
    int opcion, dato, cambio_en_raiz = 0, rotaciones, contador;
    AVL *raiz = NULL;
    srand(time(NULL));

    for (int i = 0; i < 49; i++)
    {
        dato = 1 + rand() % (1000 - 1);
        insertar_avl(raiz, dato, cambio_en_raiz);
    }

    do
    {
        system("cls");
        mostrar_menu();
        cout << "\n\t\tOPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "\nINGRESE EL DATO: ";
            cin >> dato;
            insertar_avl(raiz, dato, cambio_en_raiz);
            cout << endl
                 << endl;
            system("pause");
            break;

        case 2:
            contador = 0;
            system("cls");
            cout << "\n\tESTAS SON LAS CLAVES EXISTENTES: " << endl
                 << endl;
            mostrar_preorden(raiz, contador);
            cout << endl
                 << endl;
            rotaciones = 0;
            cout << "\nINGRESE EL DATO A ELIMINAR: ";
            cin >> dato;
            eliminar_avl(raiz, dato, cambio_en_raiz, rotaciones);
            cout << "\nEL NUMERO DE ROTACIONES EFECTUADAS AL ELIMINAR EL NODO " << dato << " ES: " << rotaciones;
            cout << endl
                 << endl;
            system("pause");
            break;

        case 3:
            contador = 0;
            system("cls");
            mostrar_preorden(raiz, contador);
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
    } while (opcion > 0 && opcion < 4);

    return 0;
}

void insertar_avl(AVL *&raiz, int dato, int &cambio_en_raiz)
{
    if (raiz != NULL)
    {
        if (dato < raiz->dato)
        {
            insertar_avl(raiz->izquierda, dato, cambio_en_raiz);
            if (cambio_en_raiz == 1)
            {
                switch (raiz->factor_equilibrio)
                {
                case 1:
                    raiz->factor_equilibrio = 0;
                    cambio_en_raiz = 0;
                    break;
                case 0:
                    raiz->factor_equilibrio = -1;
                    break;
                case -1:
                    AVL *raiz1, *raiz2;
                    raiz1 = raiz->izquierda;
                    if (raiz1->factor_equilibrio >= 0)
                    {
                        raiz2 = raiz1->derecha;
                        raiz->izquierda = raiz2->derecha;
                        raiz2->derecha = raiz;
                        raiz1->derecha = raiz2->izquierda;
                        raiz2->izquierda = raiz1;
                        if (raiz2->factor_equilibrio == -1)
                        {
                            raiz->factor_equilibrio = 1;
                        }
                        else
                        {
                            raiz->factor_equilibrio = 0;
                        }
                        if (raiz2->factor_equilibrio == 1)
                        {
                            raiz1->factor_equilibrio = -1;
                        }
                        else
                        {
                            raiz1->factor_equilibrio = 0;
                        }
                        raiz = raiz2;
                    }
                    else
                    {
                        raiz->izquierda = raiz1->derecha;
                        raiz1->derecha = raiz;
                        raiz->factor_equilibrio = 0;
                        raiz = raiz1;
                    }
                    raiz->factor_equilibrio = 0;
                    cambio_en_raiz = 0;
                    break;
                }
            }
        }
        else
        {
            if (dato > raiz->dato)
            {
                insertar_avl(raiz->derecha, dato, cambio_en_raiz);
                if (cambio_en_raiz == 1)
                {
                    switch (raiz->factor_equilibrio)
                    {
                    case -1:
                        raiz->factor_equilibrio = 0;
                        cambio_en_raiz = 0;
                        break;
                    case 0:
                        raiz->factor_equilibrio = 1;
                        break;
                    case 1:
                        AVL *raiz1, *raiz2;
                        raiz1 = raiz->derecha;
                        if (raiz1->factor_equilibrio < 0)
                        {
                            raiz2 = raiz1->izquierda;
                            raiz->derecha = raiz2->izquierda;
                            raiz2->izquierda = raiz;
                            raiz1->izquierda = raiz2->derecha;
                            raiz2->derecha = raiz1;
                            if (raiz2->factor_equilibrio == 1)
                            {
                                raiz->factor_equilibrio = -1;
                            }
                            else
                            {
                                raiz->factor_equilibrio = 0;
                            }
                            if (raiz2->factor_equilibrio == -1)
                            {
                                raiz1->factor_equilibrio = 1;
                            }
                            else
                            {
                                raiz1->factor_equilibrio = 0;
                            }
                            raiz2->factor_equilibrio = 0;
                            raiz = raiz2;
                        }
                        else
                        {
                            raiz->derecha = raiz1->izquierda;
                            raiz1->izquierda = raiz;
                            raiz->factor_equilibrio = 0;
                            raiz = raiz1;
                        }
                        raiz->factor_equilibrio = 0;
                        cambio_en_raiz = 0;
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
        AVL *nuevo_nodo;
        nuevo_nodo = new AVL;
        nuevo_nodo->dato = dato;
        nuevo_nodo->factor_equilibrio = 0;
        raiz = nuevo_nodo;
        nuevo_nodo->izquierda = NULL;
        nuevo_nodo->derecha = NULL;
        cambio_en_raiz = 1;
    }
}

void eliminar_avl(AVL *&raiz, int dato, int &cambio_en_raiz, int &rotaciones)
{
    if (raiz != NULL)
    {
        if (dato < raiz->dato)
        {
            eliminar_avl(raiz->izquierda, dato, cambio_en_raiz, rotaciones);
            reestructurar_izquierda(raiz, cambio_en_raiz, rotaciones);
        }
        else
        {
            if (dato > raiz->dato)
            {
                eliminar_avl(raiz->derecha, dato, cambio_en_raiz, rotaciones);
                reestructurar_derecha(raiz, cambio_en_raiz, rotaciones);
            }
            else
            {
                AVL *nodo_a_borrar;
                nodo_a_borrar = raiz;
                if (nodo_a_borrar->derecha == NULL)
                {
                    raiz = nodo_a_borrar->izquierda;
                    cambio_en_raiz = 1;
                }
                else
                {
                    if (nodo_a_borrar->izquierda == NULL)
                    {
                        raiz = nodo_a_borrar->derecha;
                        cambio_en_raiz = 1;
                    }
                    else
                    {
                        borrar_nodo(nodo_a_borrar->izquierda, nodo_a_borrar, cambio_en_raiz, rotaciones);
                        reestructurar_izquierda(raiz, cambio_en_raiz, rotaciones);
                        delete (nodo_a_borrar);
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

void reestructurar_izquierda(AVL *&raiz, int &cambio_en_raiz, int &rotaciones)
{
    if (cambio_en_raiz == 1)
    {
        switch (raiz->factor_equilibrio)
        {
        case -1:
            raiz->factor_equilibrio = 0;
            break;
        case 0:
            raiz->factor_equilibrio = 1;
            cambio_en_raiz = 0;
            break;
        case 1:
            AVL *raiz1, *raiz2;
            raiz1 = raiz->derecha;
            rotaciones++;
            if (raiz1->factor_equilibrio >= 0)
            {
                raiz->derecha = raiz1->izquierda;
                raiz1->izquierda = raiz;
                switch (raiz1->factor_equilibrio)
                {
                case 0:
                    raiz->factor_equilibrio = 1;
                    raiz1->factor_equilibrio = -1;
                    cambio_en_raiz = 0;
                    break;
                case 1:
                    raiz->factor_equilibrio = 0;
                    raiz1->factor_equilibrio = 0;
                    break;
                }
                raiz = raiz1;
            }
            else
            {
                raiz2 = raiz1->izquierda;
                raiz->derecha = raiz2->izquierda;
                raiz2->izquierda = raiz;
                raiz1->izquierda = raiz2->derecha;
                raiz2->derecha = raiz1;
                if (raiz2->factor_equilibrio == 1)
                {
                    raiz->factor_equilibrio = -1;
                }
                else
                {
                    raiz->factor_equilibrio = 0;
                }
                if (raiz2->factor_equilibrio == -1)
                {
                    raiz1->factor_equilibrio = 1;
                }
                else
                {
                    raiz1->factor_equilibrio = 0;
                }
                raiz2->factor_equilibrio = 0;
                raiz = raiz2;
            }
            break;
        }
    }
}

void reestructurar_derecha(AVL *&raiz, int &cambio_en_raiz, int &rotaciones)
{
    if (cambio_en_raiz == 1)
    {
        switch (raiz->factor_equilibrio)
        {
        case 1:
            raiz->factor_equilibrio = 0;
            break;
        case 0:
            raiz->factor_equilibrio = 1;
            cambio_en_raiz = 0;
            break;
        case -1:
            AVL *raiz1, *raiz2;
            raiz1 = raiz->izquierda;
            rotaciones++;
            if (raiz1->factor_equilibrio <= 0)
            {
                raiz->izquierda = raiz1->derecha;
                raiz1->derecha = raiz;
                switch (raiz1->factor_equilibrio)
                {
                case 0:
                    raiz->factor_equilibrio = -1;
                    raiz1->factor_equilibrio = 1;
                    cambio_en_raiz = 0;
                    break;
                case -1:
                    raiz->factor_equilibrio = 0;
                    raiz1->factor_equilibrio = 0;
                    break;
                }
                raiz = raiz1;
            }
            else
            {
                raiz2 = raiz1->derecha;
                raiz->izquierda = raiz2->derecha;
                raiz2->derecha = raiz;
                raiz1->derecha = raiz2->izquierda;
                raiz2->izquierda = raiz1;
                if (raiz2->factor_equilibrio == -1)
                {
                    raiz->factor_equilibrio = 1;
                }
                else
                {
                    raiz->factor_equilibrio = 0;
                }
                if (raiz2->factor_equilibrio == 1)
                {
                    raiz1->factor_equilibrio = -1;
                }
                else
                {
                    raiz1->factor_equilibrio = 0;
                }
                raiz2->factor_equilibrio = 0;
                raiz = raiz2;
            }
            break;
        }
    }
}

void borrar_nodo(AVL *&nodo, AVL *&padre, int &cambio_en_raiz, int &rotaciones)
{
    if (nodo->derecha != NULL)
    {
        borrar_nodo(nodo->derecha, padre, cambio_en_raiz, rotaciones);
        reestructurar_derecha(nodo, cambio_en_raiz, rotaciones);
    }
    else
    {
        padre->dato = nodo->dato;
        padre = nodo;
        nodo = nodo->izquierda;
        cambio_en_raiz = 1;
    }
}

void mostrar_menu()
{
    cout << "\n\n\t\tMENU" << endl
         << endl;
    cout << "1. INSERTAR" << endl;
    cout << "2. ELIMINAR" << endl;
    cout << "3. RECORRIDO" << endl;
    cout << "4. SALIR" << endl;
}

void mostrar_preorden(AVL *raiz, int &contador)
{
    if (raiz != NULL)
    {
        contador++;
        if ((contador % 10) == 0)
        {
            cout << "NODO " << contador << ": " << raiz->dato << "\n";
        }
        else
        {
            cout << "NODO " << contador << ": " << raiz->dato << "\t";
        }
        mostrar_preorden(raiz->izquierda, contador);
        mostrar_preorden(raiz->derecha, contador);
    }
}

void mostrar_inorden(AVL *&raiz, int &contador)
{
    if (raiz != NULL)
    {
        mostrar_inorden(raiz->izquierda, contador);
        contador++;
        if ((contador % 10) == 0)
        {
            cout << "NODO " << contador << ": " << raiz->dato << "\n";
        }
        else
        {
            cout << "NODO " << contador << ": " << raiz->dato << "\t";
        }
        mostrar_inorden(raiz->derecha, contador);
    }
}
