// Oscar Arreola (A01178076) y Alejandra Coeto (A01285221)
// Última modificación: Domingo 3 de noviembre
// Clase para representar un punto y realizar operaciones con el

#ifndef Point_h
#define Point_h

class Point {
    private:
        double x, y;

    public:
        Point();
        Point(double x, double y) {
            this->x = x;
            this->y = y;
        }

        Point(const Point&);
        double getX() const {
            return x;
        }
        double getY() const {
            return y;
        }

        
        static double dist(const Point &p1, const Point &p2) {
            double diffx = p1.getX() - p2.getX();
            double diffy = p1.getY() - p2.getY();
            return sqrt((diffx * diffx) + (diffy * diffy));
        }

        static Point rotate(const Point &p, double theta) {
            double rad = theta * M_PI / 180.0; // Convert degrees to radians
            return Point(p.getX() * cos(rad) - p.getY() * sin(rad),
            p.getX() * sin(rad) + p.getY() * cos(rad));
        }

};

#endif