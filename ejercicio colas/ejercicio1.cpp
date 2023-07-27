#include <iostream>

using namespace std;

const int capacidad_maxima = 30;

void insertar_elemento(char *cola, char elemento, int &final, int capacidad, int &frente);
void eliminar_elemento(char *cola, int &frente, int &final);
int buscar_elemento(char *cola, int frente, int final, char elemento);

int main()
{
    int final = 5, frente = 0;
    char cola[capacidad_maxima] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char respuesta;

    cout << "Una cola por defecto va a contener 6 elementos (A, B, C, ...)" << endl;

    // Insertar los elementos: A, B y C
    cout << "Desea insertar los elementos 'A, B, C' en la cola?" << endl;
    cout << "SI (s) / NO (n): ";
    cin >> respuesta;
    if (respuesta == 's')
    {
        insertar_elemento(cola, 'A', final, capacidad_maxima, frente);
        insertar_elemento(cola, 'B', final, capacidad_maxima, frente);
        insertar_elemento(cola, 'C', final, capacidad_maxima, frente);
    }

    // Eliminar el elemento: A
    cout << "Desea eliminar el elemento 'A' de la cola?" << endl;
    cout << "SI (s) / NO (n): ";
    cin >> respuesta;
    if (respuesta == 's')
    {
        if (buscar_elemento(cola, frente, final, 'A') == 1)
        {
            eliminar_elemento(cola, frente, final);
        }
        else
        {
            cout << "El elemento 'A' no está en la cola." << endl;
            return 1;
        }
    }

    // Insertar los elementos: D, E y F
    cout << "Desea insertar los elementos 'D, E, F' en la cola?" << endl;
    cout << "SI (s) / NO (n): ";
    cin >> respuesta;
    if (respuesta == 's')
    {
        insertar_elemento(cola, 'D', final, capacidad_maxima, frente);
        insertar_elemento(cola, 'E', final, capacidad_maxima, frente);
        insertar_elemento(cola, 'F', final, capacidad_maxima, frente);
    }

    // Insertar el elemento: G
    cout << "Desea insertar el elemento 'G' en la cola?" << endl;
    cout << "SI (s) / NO (n): ";
    cin >> respuesta;
    if (respuesta == 's')
    {
        insertar_elemento(cola, 'G', final, capacidad_maxima, frente);
    }

    // Insertar el elemento: H
    cout << "Desea insertar el elemento 'H' en la cola?" << endl;
    cout << "SI (s) / NO (n): ";
    cin >> respuesta;
    if (respuesta == 's')
    {
        insertar_elemento(cola, 'H', final, capacidad_maxima, frente);
    }

    // Eliminar los elementos: B y C
    cout << "Desea eliminar los elementos 'B, C' de la cola?" << endl;
    cout << "SI (s) / NO (n): ";
    cin >> respuesta;
    if (respuesta == 's')
    {
        if (buscar_elemento(cola, frente, final, 'B') == 1)
        {
            eliminar_elemento(cola, frente, final);
        }
        else
        {
            cout << "El elemento 'B' no está en la cola." << endl;
            return 1;
        }

        if (buscar_elemento(cola, frente, final, 'C') == 1)
        {
            eliminar_elemento(cola, frente, final);
        }
        else
        {
            cout << "El elemento 'C' no está en la cola." << endl;
            return 1;
        }
    }

    // Mostrar elementos restantes en la cola
    cout << endl
         << "ELEMENTOS QUE QUEDARON EN LA COLA:" << endl;
    for (int i = frente; i <= final; i++)
    {
        cout << cola[i] << "\t";
    }
    cout << endl
         << "EN TOTAL QUEDAN " << final - frente + 1 << " ELEMENTOS EN LA COLA" << endl;
    if ((final - frente + 1) == 6)
    {
        cout << "LA COLA AUN TIENE 6 ELEMENTOS" << endl;
    }
    else
    {
        if ((final - frente + 1) < 6)
        {
            cout << "LA COLA HA DISMINUIDO " << 6 - (final - frente + 1) << " ELEMENTOS" << endl;
        }
        else
        {
            cout << "LA COLA HA AUMENTADO " << (final - frente + 1) - 6 << " ELEMENTOS" << endl;
        }
    }

    return 0;
}

void insertar_elemento(char *cola, char elemento, int &final, int capacidad, int &frente)
{
    if (final < capacidad - 1)
    {
        final++;
        cola[final] = elemento;
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

void eliminar_elemento(char *cola, int &frente, int &final)
{
    if (frente <= final)
    {
        if (frente == final)
        {
            frente = 0;
            final = -1;
        }
        else
        {
            frente = frente + 1;
        }
    }
    else
    {
        cout << "COLA VACIA" << endl;
    }
}

int buscar_elemento(char *cola, int frente, int final, char elemento)
{
    int resultado = 0;
    for (int i = frente; i <= final; i++)
    {
        if (cola[i] == elemento)
        {
            resultado = 1;
        }
    }
    return resultado;
}
