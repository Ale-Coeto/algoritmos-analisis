// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Domingo 3 de noviembre
// Clase para representar una línea y realizar operaciones con ella

#ifndef Line_h
#define Line_h
#include "libs.h"
#include "Point.h"
#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000



class Line {
    private:
        double a, b, c;

    public:
        Line();
        Line(double a, double b, double c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        Line(const Line& l) {
            this->a = l.a;
            this->b = l.b;
            this->c = l.c;
        }
        double getA() const {
            return a;
        }
        double getB() const {
            return b;
        }
        double getC() const {
            return c;
        }

        static Line pointsToLine(const Point &p1, const Point &p2) {
            double aux;
            if (fabs(p1.getX() - p2.getX()) < EPS) {  // Vertical line case
                return Line(1.0, 0.0, -p1.getX());
            } else {
                aux = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
                return Line(-aux, 1.0, (aux * p1.getX()) - p1.getY());
            }
        }

        static Line pointAndSlopeToLine(const Point &p, double m) {
            return Line(-m, 1, -(-m * p.getX() + p.getY()));
        }

        static bool areParallel(const Line &l1, const Line &l2) {
            return ((fabs(l1.getA() - l2.getA()) <= EPS) &&
            (fabs(l1.getB() - l2.getB()) <= EPS));
        }

        static bool areSameLine(const Line &l1, const Line &l2) {
            return (areParallel(l1, l2) &&
            (fabs(l1.getC() - l2.getC()) <= EPS) );
        }

        static bool segmentsIntersect(const Line &l1, const Line &l2, const Point &p1, const Point &p2, const Point &p3, const Point &p4) {
            Point* p = intersectsAt(l1, l2);

            if (p == NULL) {
                return false;
            }

            double x = p->getX();
            double y = p->getY();

            // Check if intersection is within boundaries
            if (x >= fmin(p1.getX(), p2.getX()) && x <= fmax(p1.getX(), p2.getX()) &&
            x >= fmin(p3.getX(), p4.getX()) && x <= fmax(p3.getX(), p4.getX()) &&
            y >= fmin(p1.getY(), p2.getY()) && y <= fmax(p1.getY(), p2.getY()) &&
            y >= fmin(p3.getY(), p4.getY()) && y <= fmax(p3.getY(), p4.getY())) {
                return true;
            }

            return false;

        }

        static Point* intersectsAt(const Line &l1, const Line &l2) {
           double x, y;
    
            if (areParallel(l1, l2)) {
                return nullptr;  // No intersection if lines are parallel
            }

            double denominator = (l1.getA() * l2.getB()) - (l2.getA() * l1.getB());
            
            x = ((l1.getB() * l2.getC()) - (l2.getB() * l1.getC())) / denominator;
            y = ((l2.getA() * l1.getC()) - (l1.getA() * l2.getC())) / denominator;
            
            return new Point(x, y); 
        }

        static double intersectionAngle(const Line &l1, const Line &l2) {
            return atan((l1.getA() * l2.getB() - l2.getA() * l1.getB()) / 
            (l1.getA() * l2.getA() + l1.getB() * l2.getB()));
        }

        static Point* closestPoint(const Point &p, const Line &l) {
            if (fabs(l.getB()) <= EPS) {
                return new Point(-l.getC(), p.getY());
            }
            if (fabs(l.getA()) <= EPS) {
                return new Point(p.getX(), -l.getC());
            }

            Line aux = pointAndSlopeToLine(p, 1 / l.getA());
            return intersectsAt(l, aux);
        }
};

#endif