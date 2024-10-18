// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Miércoles 16 de Octubre
// Programa para probar el algoritmo Welsh y Powell para colorear grafos

#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define pb push_back

/*
    Algoritmo welsh y powell para colorear un grafo sin que vertices adjacentes
    tengan el mismo color y minimizando la cantidad de colores usados
    Params: graph (vector de adjacencias)
    Returns: colores (vector de los colores asignados a cada vértice)

    Complejidad temporal: O(n^2), donde n es la cantidad de nodos
*/
vi welsh_powell(vector<vi> & graph) {

    vector<ii> grados(graph.size());
    vi colors(graph.size(), -1);
    int color = 0;

    // Definir grado (cant de edges)
    // Complejidad temporal: O(n), donde n es la cantidad de nodos
    for (int i = 0; i < graph.size(); i++) {
        grados[i] = {graph[i].size(), i};
    }
    
    // Ordenar por grado 
    // Complejidad temporal: O(nlog(n)), donde n es la cantidad de nodos
    sort(grados.begin(), grados.end(), greater<ii>());

    // Para cada vértice, colorear los vértices que no sean adjacentes y no han sido coloreados
    // Complejidad temporal: O(n), donde n es la cantidad de nodos
    for (int i = 0; i < grados.size(); i++) {
        ii front = grados[i];
        vector<bool> available(graph.size(), true);

        if (colors[front.second] == -1) {
            colors[front.second] = color;

            // Marcar nodos adjacentes como no disponibles
            // Complejidad temporal: O(m), donde m es la cantidad de arcos del vértice
            for (auto x : graph[front.second]) {
                available[x] = false;
            }

            // Buscar los vértices que puedan ser del mismo color (no coloreados y disponibles)
            // Complejidad temporal: O(n), donde n es la cantidad de nodos
            for (int j = i+1; j < grados.size(); j++) {
                ii curr = grados[j];
                if (colors[curr.second] == -1 && available[curr.second]) {
                    colors[curr.second] = color;
                    break;
                    // Método alternativo para reducir la cantidad de colores usados, pero aumenta la complejidad
                    // Complejidad temporal: O(m), donde m es la cantidad de arcos del vértice
                    // for (auto x : graph[curr.second]) {
                    //     available[x] = false;
                    // }
                }
            }

            color++;
        }
    }

    return colors;


}

/*
    Main
    Lee matriz de adjacencia e imprime los colores asignados
    después de correr el algoritmo Welsh y Powell
*/
int main() { 
    int n,a;
    cin >> n;
    vector<vi> graph(n);

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            cin >> a;
            if (a) {
                graph[i].pb(j);
            }
        }
    }

    for (auto x : graph) {
        for (auto i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    vi colors = welsh_powell(graph);

    for (int i = 0; i < colors.size(); i++) {
        cout << "Node: " << i << ", Assigned Color: " << colors[i] << endl;
    }


    return 0;
}