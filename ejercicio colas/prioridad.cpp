#include <iostream>
#include <string>

using namespace std;

struct Persona
{
    string nombre;
    int codigo;
};

struct Nodo
{
    Persona info;
    int prioridad;
    Nodo *sig;
};

Nodo *insertar(Nodo *cola, Persona info, int prioridad);
Nodo *eliminar(Nodo *cola);
void mostrar(Nodo *cola);

int main()
{
    int opcion;
    Nodo *cola = nullptr;
    Persona info;
    int prioridad;

    do
    {
        system("cls");
        cout << "\n\n\t\tMENU" << endl;
        cout << "\n1. INSERTAR PERSONA" << endl;
        cout << "2. ELIMINAR PERSONA" << endl;
        cout << "3. MOSTRAR" << endl;
        cout << "4. SALIR" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "Ingrese el nombre de la persona: ";
            fflush(stdin);
            getline(cin, info.nombre);
            cout << "Ingrese el codigo de la persona: ";
            cin >> info.codigo;
            cout << "Ingrese la prioridad de la persona: ";
            cin >> prioridad;
            cola = insertar(cola, info, prioridad);
            cout << endl
                 << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            cola = eliminar(cola);
            cout << endl
                 << endl;
            system("pause");
            break;

        case 3:
            system("cls");
            mostrar(cola);
            cout << endl
                 << endl;
            system("pause");
            break;

        default:
            cout << "\nCERRANDO PROGRAMA" << endl;
            system("pause");
            system("cls");
            break;
        }

    } while (opcion > 0 && opcion < 4);

    return 0;
}

Nodo *insertar(Nodo *cola, Persona info, int prioridad)
{
    Nodo *q = new Nodo;
    q->info.codigo = info.codigo;
    q->info.nombre = info.nombre;
    q->prioridad = prioridad;
    q->sig = nullptr;

    if (cola == nullptr)
    {
        cola = q;
    }
    else
    {
        if (cola->prioridad > prioridad)
        {
            q->sig = cola;
            cola = q;
        }
        else
        {
            Nodo *r = cola;
            while (r->sig != nullptr && r->sig->prioridad <= prioridad)
            {
                r = r->sig;
            }
            q->sig = r->sig;
            r->sig = q;
        }
    }
    return cola;
}

Nodo *eliminar(Nodo *cola)
{
    if (cola != nullptr)
    {
        Nodo *q = cola;
        cola = cola->sig;
        delete q;
    }
    else
    {
        cout << "\nCOLA VACIA" << endl;
    }
    return cola;
}

void mostrar(Nodo *cola)
{
    Nodo *q = cola;
    int i = 1;
    cout << endl
         << endl;
    while (q != nullptr)
    {
        cout << "PERSONA " << i << endl;
        cout << "\tNOMBRE: " << q->info.nombre << endl;
        cout << "\tCODIGO: " << q->info.codigo << endl;
        cout << "\tPRIORIDAD: " << q->prioridad << endl;
        cout << endl;
        i++;
        q = q->sig;
    }
}
