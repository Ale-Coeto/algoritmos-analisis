// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Domingo 3 de noviembre
// Clase para representar un segmento y realizar operaciones con el

#ifndef Segment_h
#define Segment_h

#include "Point.h"
#include "libs.h"

class Segment {
    private:
        Point p1, p2;
    public:
        Segment();
        Segment(const Point& p1, const Point& p2) {
            this->p1 = p1;
            this->p2 = p2;
        }
        Segment(const Segment&);
        Point getP1() const {
            return p1;
        }
        Point getP2() const {
            return p2;
        }
};

#endif