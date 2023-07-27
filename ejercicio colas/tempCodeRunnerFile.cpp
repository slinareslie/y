#include <iostream>
#include <string>

using namespace std;

const int MAX_ELEMENTOS = 30;

void inicializarCola(string *cola, int &frente, int &final, string dato);
void insertarEnCola(string *cola, int &frente, string dato, int &final);
void eliminarDeCola(string *cola, int &frente, int &final, string &dato);
void mostrarCola(string *cola, int frente, int final);

int main()
{
    int frente = -1, final = -1, opcion;
    string cola[MAX_ELEMENTOS], dato;

    for (;;)
    {
        cout << "OPERACIONES CON COLA" << endl;
        cout << "1. CREAR" << endl;
        cout << "2. INSERTAR" << endl;
        cout << "3. ELIMINAR" << endl;
        cout << "4. MOSTRAR" << endl;
        cout << "5. SALIR" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            inicializarCola(cola, frente, final, dato);
            cout << endl;
            break;
        case 2:
            cout << "INGRESE UN DATO -> ";
            cin >> dato;
            insertarEnCola(cola, frente, dato, final);
            cout << endl;
            break;
        case 3:
            eliminarDeCola(cola, frente, final, dato);
            cout << "SE ELIMINO EL DATO -> " << dato << endl;
            break;
        case 4:
            mostrarCola(cola, frente, final);
            cout << endl;
            break;
        case 5:
            cout << "Fin del programa!!!" << endl;
            exit(0);
        }
        system("pause");
        system("cls");
    }

    return 0;
}

void inicializarCola(string *cola, int &frente, int &final, string dato)
{
    frente = 0;
    final = 0;
    cout << "INGRESE UN DATO -> ";
    cin >> dato;
    cola[frente] = dato;
}

void insertarEnCola(string *cola, int &frente, string dato, int &final)
{
    if (final < MAX_ELEMENTOS - 1)
    {
        final++;
        cola[final] = dato;
        if (final == 0)
        {
            frente = 0;
        }
    }
    else
    {
        cout << "LA COLA SE ESTA DESBORDANDO" << endl;
    }
}

void eliminarDeCola(string *cola, int &frente, int &final, string &dato)
{
    if (frente >= 0)
    {
        dato = cola[frente];
        if (frente == final)
        {
            frente = -1;
            final = -1;
        }
        else
        {
            frente++;
        }
    }
    else
    {
        dato = " ";
        cout << "COLA VACIA" << endl;
    }
}

void mostrarCola(string *cola, int frente, int final)
{
    cout << "LA COLA ES: " << endl;
    for (int i = frente; i <= final; i++)
    {
        if ((frente != -1) && (final != -1))
        {
            cout << cola[i] << "\t";
        }
    }
}
