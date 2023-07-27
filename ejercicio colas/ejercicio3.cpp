#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Persona
{
    int edad;
    string nombre;
};

void agregarPersona(Persona *cola, int &inicio, int &fin, int max, Persona nuevaPersona);
void retirarPersona(Persona *cola, int &inicio, int &fin, Persona &personaEliminada);
void mostrarCola(Persona *cola, int inicio, int fin);

int main()
{
    Persona colaTotal[20], colaMayores[20], colaImpares[20], colaCoincidentes[20], nuevaPersona;
    int opcion, opcionMostrar, max = 19, inicioCola[4], finCola[4], centro;

    for (int i = 0; i < 4; i++)
    {
        inicioCola[i] = -1;
        finCola[i] = -1;
    }

    do
    {
        cout << "\n\t\t----------- MENU -----------" << endl;
        cout << "1. AGREGAR PERSONA" << endl;
        cout << "2. RETIRAR PERSONA" << endl;
        cout << "3. MOSTRAR" << endl;
        cout << "4. CERRAR PROGRAMA" << endl;
        cout << "\n\t\tOPCION: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            cout << "INGRESE EL NOMBRE DE LA PERSONA: ";
            cin.ignore();
            getline(cin, nuevaPersona.nombre);
            cout << "INGRESE LA EDAD DE LA PERSONA: ";
            cin >> nuevaPersona.edad;

            if (nuevaPersona.edad > 18)
            {
                agregarPersona(colaMayores, inicioCola[1], finCola[1], max, nuevaPersona);
            }
            if ((nuevaPersona.edad % 2) == 1)
            {
                agregarPersona(colaImpares, inicioCola[2], finCola[2], max, nuevaPersona);
            }

            centro = 0;
            for (int i = inicioCola[0]; i <= finCola[0]; i++)
            {
                if ((inicioCola[0] != -1) && (finCola[0] != -1))
                {
                    if (colaTotal[i].edad == nuevaPersona.edad)
                    {
                        int k = finCola[3];
                        for (int j = inicioCola[3]; j <= k; j++)
                        {
                            if ((inicioCola[3] != -1) && (finCola[3] != -1))
                            {
                                if (centro == 0)
                                {
                                    if ((colaCoincidentes[j].nombre == colaTotal[i].nombre) && (colaCoincidentes[j].edad == colaTotal[i].edad))
                                    {
                                        agregarPersona(colaCoincidentes, inicioCola[3], finCola[3], max, nuevaPersona);
                                        centro = 1;
                                    }
                                    else if (((colaCoincidentes[j].nombre != colaTotal[i].nombre) && (colaCoincidentes[j].edad != colaTotal[i].edad)) && ((nuevaPersona.nombre != colaCoincidentes[j].nombre) && (nuevaPersona.edad != colaCoincidentes[j].edad)))
                                    {
                                        agregarPersona(colaCoincidentes, inicioCola[3], finCola[3], max, colaTotal[i]);
                                        agregarPersona(colaCoincidentes, inicioCola[3], finCola[3], max, nuevaPersona);
                                        centro = 1;
                                    }
                                }
                            }
                            else
                            {
                                if (centro == 0)
                                {
                                    agregarPersona(colaCoincidentes, inicioCola[3], finCola[3], max, colaTotal[i]);
                                    agregarPersona(colaCoincidentes, inicioCola[3], finCola[3], max, nuevaPersona);
                                    centro = 1;
                                }
                            }
                        }
                    }
                }
            }
            agregarPersona(colaTotal, inicioCola[0], finCola[0], max, nuevaPersona);
            cout << endl;
            system("pause");
            break;

        case 2:
            if ((colaTotal[inicioCola[0]].nombre == colaMayores[inicioCola[1]].nombre) && (colaTotal[inicioCola[0]].edad == colaMayores[inicioCola[1]].edad))
            {
                retirarPersona(colaMayores, inicioCola[1], finCola[1], nuevaPersona);
            }
            if ((colaTotal[inicioCola[0]].nombre == colaImpares[inicioCola[2]].nombre) && (colaTotal[inicioCola[0]].edad == colaImpares[inicioCola[2]].edad))
            {
                retirarPersona(colaImpares, inicioCola[2], finCola[2], nuevaPersona);
            }
            if ((colaTotal[inicioCola[0]].nombre == colaCoincidentes[inicioCola[3]].nombre) && (colaTotal[inicioCola[0]].edad == colaCoincidentes[inicioCola[3]].edad))
            {
                retirarPersona(colaCoincidentes, inicioCola[3], finCola[3], nuevaPersona);
            }

            retirarPersona(colaTotal, inicioCola[0], finCola[0], nuevaPersona);
            cout << "\nSE ELIMINO A LA PERSONA: " << endl;
            cout << "NOMBRE: " << nuevaPersona.nombre << endl;
            cout << "EDAD: " << nuevaPersona.edad << endl;
            system("pause");
            break;

        case 3:
            cout << "\n\t\t----------- MENU -----------" << endl;
            cout << "1. MOSTRAR TODAS LAS PERSONAS" << endl;
            cout << "2. MOSTRAR PERSONAS MAYORES DE 18 ANIOS" << endl;
            cout << "3. MOSTRAR PERSONAS CON EDADES IMPARES" << endl;
            cout << "4. MOSTRAR PERSONAS CON EDADES COINCIDENTES" << endl;
            cout << "\n\t\tOPCION: ";
            cin >> opcionMostrar;
            switch (opcionMostrar)
            {
            case 1:
                mostrarCola(colaTotal, inicioCola[0], finCola[0]);
                system("pause");
                break;

            case 2:
                mostrarCola(colaMayores, inicioCola[1], finCola[1]);
                system("pause");
                break;

            case 3:
                mostrarCola(colaImpares, inicioCola[2], finCola[2]);
                system("pause");
                break;

            case 4:
                mostrarCola(colaCoincidentes, inicioCola[3], finCola[3]);
                system("pause");
                break;
            }
            break;

        case 4:
            cout << "----------- CERRANDO PROGRAMA -----------" << endl
                 << endl;
            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 4);

    return 0;
}

void agregarPersona(Persona *cola, int &inicio, int &fin, int max, Persona nuevaPersona)
{
    if (fin < max)
    {
        fin++;
        cola[fin].nombre = nuevaPersona.nombre;
        cola[fin].edad = nuevaPersona.edad;
        if (fin == 0)
        {
            inicio = 0;
        }
    }
    else
    {
        cout << "LA COLA SE ESTA DESBORDANDO" << endl;
    }
}

void retirarPersona(Persona *cola, int &inicio, int &fin, Persona &personaEliminada)
{
    if (inicio >= 0)
    {
        personaEliminada.nombre = cola[inicio].nombre;
        personaEliminada.edad = cola[inicio].edad;
        if (inicio == fin)
        {
            inicio = -1;
            fin = -1;
        }
        else
        {
            inicio = inicio + 1;
        }
    }
    else
    {
        personaEliminada.nombre = " ";
        personaEliminada.edad = 0;
        cout << "COLA VACIA" << endl;
    }
}

void mostrarCola(Persona *cola, int inicio, int fin)
{
    cout << "LA COLA ES: " << endl;

    cout << "--------------------------------------------" << endl;
    cout << setw(23) << "PERSONAS" << endl;
    cout << "--------------------------------------------" << endl;
    cout << setw(25) << "NOMBRE";
    cout << setw(10) << "EDAD" << endl;
    for (int i = inicio; i <= fin; i++)
    {
        if ((inicio != -1) && (fin != -1))
        {
            cout << setw(25) << cola[i].nombre;
            cout << setw(10) << cola[i].edad;
            cout << endl;
        }
    }
    cout << "\n--------------------------------------------" << endl;
}
