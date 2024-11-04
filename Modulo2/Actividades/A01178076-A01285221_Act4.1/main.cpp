// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Domingo 3 de noviembre
// Programa para recibir puntos de 2 segmentos y determinar si intersectan

#include "libs.h"
#include "Line.h"
#include "Point.h"

using namespace std;
typedef vector<int> vi;
#define pb push_back

/*
    Main
    Lee los puntos de 2 segmentos y determina si se intersectan,
    sigue leyendo mientras hayan líneas de input

    Complejidad temporal: O(1)
    Para cada caso de prueba, se realizan operaciones constantes
    Primero se crean las líneas (infinitas) con los puntos dados, 
    luego se determina si son paralelas o no, y si no lo son, se determina si intersectan.
    Finalmente, se checa si el punto de intersección está dentro de los segmentos dados

*/
int main() { 
    int x1,y1,x2,y2,x3,y3,x4,y4;
    char a;

    while (cin >> x1 >> a >> y1 >> x2 >> a >> y2 >> x3 >> a >> y3 >> x4 >> a >> y4) {
        Point points[4] = {Point(x1,y1), Point(x2,y2), Point(x3,y3), Point(x4,y4)};
        Line line1 = Line::pointsToLine(points[0], points[1]);
        Line line2 = Line::pointsToLine(points[2], points[3]);
        cout << (Line::segmentsIntersect(line1, line2, points[0], points[1], points[2], points[3]) ? "YES" : "NO") << endl;
        
        
    }
    return 0;
}