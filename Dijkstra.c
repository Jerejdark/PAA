#include <limits.h>
#include <stdlib.h>
#include <String.h>
#include <stdio.h>
#include <stdbool.h>

#define V 5

struct no{
    char nome[20];
    int vrt;
};

int distanciaMin(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

int printar(int dist[], int n, struct no *cidade) {
    printf("Cidade: \n\n");
    for (int i = 0; i < V; i++)
        printf("%s; distancia de Sao Paulo: %d \n", cidade[i].nome, dist[i]);
}

void dijkstra(int graph[V][V], int src, struct no *cidade){
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = distanciaMin(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printar(dist, V, cidade);
}

int main(){
    struct no cidade[V];
    int i;

    for(i=0; i<V; i++){
        cidade[i].vrt = i;
        printf("Nome da cidade no vertice %d\n", i);
        fgets(cidade[i].nome,20,stdin);
        cidade[i].nome[strcspn(cidade[i].nome, "\n")] = 0;
    }
    printf("\n");

    //Matriz de adjacencia retirada do exercício.
    int graph[V][V] = { {0, 0, 2, 5, 0},
                        {7, 0, 0, 0, 0},
                        {0, 3, 0, 4, 0},
                        {0, 0, 0, 0, 6},
                        {4, 0, 0, 0, 0} };

    dijkstra(graph, 0, cidade);

    return 0;
}
