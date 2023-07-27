#include <iostream>
using namespace std;

const int V = 5; // Número de nodos en el grafo

int nodoMinimaDistancia(int distancias[], bool visitado[])
{
    int minDistancia = INT_MAX;
    int nodoMinimo = -1;

    for (int v = 0; v < V; ++v)
    {
        if (!visitado[v] && distancias[v] < minDistancia)
        {
            minDistancia = distancias[v];
            nodoMinimo = v;
        }
    }

    return nodoMinimo;
}

void imprimirCamino(int padres[], int objetivo)
{
    if (padres[objetivo] == -1)
    {
        cout << objetivo << " ";
        return;
    }

    imprimirCamino(padres, padres[objetivo]);
    cout << objetivo << " ";
}

void dijkstra(int grafo[V][V], int pesos[V][V], int nodoInicio)
{
    int distancias[V];
    bool visitado[V];
    int padres[V];

    for (int i = 0; i < V; ++i)
    {
        distancias[i] = INT_MAX;
        visitado[i] = false;
        padres[i] = -1;
    }

    distancias[nodoInicio] = 0;

    for (int i = 0; i < V - 1; ++i)
    {
        int u = nodoMinimaDistancia(distancias, visitado);

        visitado[u] = true;

        for (int v = 0; v < V; ++v)
        {
            if (grafo[u][v] && !visitado[v] && distancias[u] + pesos[u][v] < distancias[v])
            {
                distancias[v] = distancias[u] + pesos[u][v];
                padres[v] = u;
            }
        }
    }

    for (int i = 0; i < V; ++i)
    {
        if (i != nodoInicio)
        {
            cout << "Camino mas corto desde " << nodoInicio << " hasta " << i << ": ";
            imprimirCamino(padres, i);
            cout << " | Distancia: " << distancias[i] << endl;
        }
    }
}

int main()
{
    int grafo[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}};

    int pesos[V][V] = {
        {0, 2, 4, 1, 0},
        {2, 0, 3, 0, 7},
        {4, 3, 0, 5, 0},
        {1, 0, 5, 0, 2},
        {0, 7, 0, 2, 0}};

    int nodoInicio = 0;

    /*
    cout << "Ingrese la matriz de adyacencia (0 o 1):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> grafo[i][j];
        }
    }

    cout << "Ingrese la matriz de pesos:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> pesos[i][j];
        }
    }

    int nodoInicio;
    cout << "Ingrese el nodo de inicio: ";
    cin >> nodoInicio;
    */

    dijkstra(grafo, pesos, nodoInicio);

    return 0;
}
