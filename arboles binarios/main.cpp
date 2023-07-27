#include <iostream>
#include <string>

using namespace std;

struct Estudiante
{
    int codigo;
    string nombre;
    float notas[2];
    float promedio;
};

struct ArbolBinario
{
    Estudiante info;
    ArbolBinario *izquierda;
    ArbolBinario *derecha;
};

void buscar_arbol(ArbolBinario *raiz, Estudiante dato);
void insertar_arbol(ArbolBinario *&raiz, Estudiante clave);
void eliminar_arbol(ArbolBinario *&raiz, Estudiante clave);

void menu(ArbolBinario *p);

int main()
{
    ArbolBinario *raiz = NULL;

    // Ejemplo predeterminado
    Estudiante estudiante1 = {1001, "Juan Perez", {90.5, 85.0}, 87.75};
    Estudiante estudiante2 = {1002, "Maria Lopez", {80.0, 95.0}, 87.5};
    Estudiante estudiante3 = {1003, "Carlos Gomez", {70.0, 75.5}, 72.75};

    insertar_arbol(raiz, estudiante1);
    insertar_arbol(raiz, estudiante2);
    insertar_arbol(raiz, estudiante3);

    menu(raiz);

    return 0;
}

void menu(ArbolBinario *raiz)
{
    int opc, opc1;
    Estudiante estudiante;
    do
    {
        system("cls");
        cout << "\n\t\t\tM E N U";
        cout << "\n\t\t\t=======";
        cout << "\n\n1. INSERTAR";
        cout << "\n\n2. ELIMINAR";
        cout << "\n\n3. BUSCAR";
        cout << "\n\n4. SALIR";

        cout << "\n\n\t\t\tOPCION:  ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            system("cls");
            cout << "\n\t\t\tM E N U";
            cout << "\n\t\t\t=======";
            cout << "\n\n1. INSERTAR DE LA PRIMERA FORMA";
            cout << "\n\n2. INSERTAR DE LA SEGUNDA FORMA";
            cout << "\n\n\t\t\tOPCION:  ";
            cin >> opc1;
            system("cls");
            cout << "\n\nINGRESE EL CODIGO DEL ESTUDIANTE: ";
            cin >> estudiante.codigo;
            cout << "\n\nINGRESE EL NOMBRE DEL ESTUDIANTE: ";
            fflush(stdin);
            getline(cin, estudiante.nombre);
            cout << "\n\nINGRESE LA PRIMERA NOTA DEL ESTUDIANTE: ";
            cin >> estudiante.notas[0];
            cout << "\n\nINGRESE LA SEGUNDA NOTA DEL ESTUDIANTE: ";
            cin >> estudiante.notas[1];
            estudiante.promedio = (estudiante.notas[0] + estudiante.notas[1]) / 2;
            switch (opc1)
            {
            case 1:
                insertar_arbol(raiz, estudiante);
                cout << endl;
                system("pause");
                break;

            case 2:
                insertar_arbol(raiz, estudiante);
                cout << endl;
                system("pause");
                break;
            }
            break;

        case 2:
            system("cls");
            cout << "\n\nINGRESE EL CODIGO DEL ESTUDIANTE A ELIMINAR: ";
            cin >> estudiante.codigo;
            eliminar_arbol(raiz, estudiante);
            cout << endl
                 << endl;
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "\n\t\t\tM E N U";
            cout << "\n\t\t\t=======";
            cout << "\n\n1. BUSCAR DE LA PRIMERA FORMA";
            cout << "\n\n2. BUSCAR DE LA SEGUNDA FORMA";
            cout << "\n\n\t\t\tOPCION:  ";
            cin >> opc1;
            system("cls");
            cout << "\n\nINGRESE EL CODIGO DEL ESTUDIANTE A BUSCAR: ";
            cin >> estudiante.codigo;
            switch (opc1)
            {
            case 1:
                buscar_arbol(raiz, estudiante);
                cout << endl;
                system("pause");
                break;

            case 2:
                buscar_arbol(raiz, estudiante);
                cout << endl;
                system("pause");
                break;
            }
            break;
        }
    } while (opc > 0 && opc < 4);
}

void buscar_arbol(ArbolBinario *raiz, Estudiante dato)
{
    if (raiz != NULL)
    {
        if (dato.codigo < raiz->info.codigo)
        {
            buscar_arbol(raiz->izquierda, dato);
        }
        else if (dato.codigo > raiz->info.codigo)
        {
            buscar_arbol(raiz->derecha, dato);
        }
        else
        {
            cout << "\nEL ESTUDIANTE ES LOCALIZADO" << endl
                 << endl;
            cout << "CODIGO: " << raiz->info.codigo << endl;
            cout << "NOMBRE: " << raiz->info.nombre << endl;
            cout << "NOTA 1: " << raiz->info.notas[0] << endl;
            cout << "NOTA 2: " << raiz->info.notas[1] << endl;
            cout << "PROMEDIO: " << raiz->info.promedio << endl;
        }
    }
    else
    {
        cout << "\nEL ESTUDIANTE NO EXISTE" << endl;
    }
}

void insertar_arbol(ArbolBinario *&raiz, Estudiante clave)
{
    if (raiz == NULL)
    {
        ArbolBinario *q = new ArbolBinario;
        q->info = clave;
        q->izquierda = NULL;
        q->derecha = NULL;
        raiz = q;
    }
    else if (clave.codigo < raiz->info.codigo)
    {
        insertar_arbol(raiz->izquierda, clave);
    }
    else if (clave.codigo > raiz->info.codigo)
    {
        insertar_arbol(raiz->derecha, clave);
    }
    else
    {
        cout << "\nEL ESTUDIANTE YA EXISTE" << endl;
    }
}

void eliminar_arbol(ArbolBinario *&raiz, Estudiante clave)
{
    if (raiz != NULL)
    {
        if (clave.codigo < raiz->info.codigo)
        {
            eliminar_arbol(raiz->izquierda, clave);
        }
        else if (clave.codigo > raiz->info.codigo)
        {
            eliminar_arbol(raiz->derecha, clave);
        }
        else
        {
            ArbolBinario *q = raiz;
            if (q->derecha == NULL)
            {
                raiz = q->izquierda;
            }
            else if (q->izquierda == NULL)
            {
                raiz = q->derecha;
            }
            else
            {
                ArbolBinario *aux, *aux1;
                aux = q->izquierda;
                int cen = 0;
                while (aux->derecha != NULL)
                {
                    aux1 = aux;
                    aux = aux->derecha;
                    cen = 1;
                }
                raiz->info = aux->info;
                q = aux;
                if (cen == 0)
                {
                    raiz->izquierda = aux->izquierda;
                }
                else
                {
                    aux1->derecha = aux->izquierda;
                }
            }
            delete (q);
        }
    }
    else
    {
        cout << "\nEL ESTUDIANTE NO EXISTE" << endl;
    }
}
