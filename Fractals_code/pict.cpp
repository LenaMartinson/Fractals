#include <pict.h>

#include <math.h>
#include <iostream>
#include <algorithm>
#include <map>

Pict::Pict(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
}

Pict::~Pict()
{

}
QRectF Pict::boundingRect() const
{
    return QRectF(0, 0, 600, 600);
}

class complex {
private:
    double x, y;
public:
    complex(double a, double b) {
        x = a;
        y = b;
    }
    complex operator +(complex a) {
        return complex(a.x + x, a.y + y);
    }
    complex operator -(complex a) {
        return complex(a.x - x, a.y - y);
    }
    complex operator *(int a) {
        return complex(a * x, a * y);
    }
    complex operator /(complex a) {
        double b = (x * a.x + y * a.y) / (a.x * a.x + a.y * a.y);
        double c = (a.x * y - a.y * x) / (a.x * a.x + a.y * a.y);
        complex d = complex(b, c);
        return d;
    }
    complex operator /(int a) {
        return complex(x / a, y / a);
    }
    complex operator *(complex a) {
        return complex(a.x * x - a.y * y, a.x * y + a.y * x);
    }
    double mod() {
        return sqrt(x * x + y * y);
    }
};

int process(complex a) {
    complex b = complex(0, 0);
    complex z = a;
    int cnt = 0;
    complex c = complex(-0.0034, 0.67);
    double r = 2;
    //double r = (1 + sqrt(1 + 4 * a.mod()));
    while (cnt < 256 && z.mod() < r) {
        //z = z * z * z * z - z * z + z + a * a;
        z = z * z + c;
        //z = z * z + a;
        cnt++;
    }
    return cnt;
}


void Pict::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    double q1, q2;
    q1 = fabs(x1 - x0) / 600;
    q2 = fabs(y1 - y0) / 600;
    for (int i = 0; i < 600; i++) {
        for (int j = 0; j < 600; j++) {
            int a = process(complex(x0 + i * q1, y0 + j * q2));
            if (a == 256) {
                painter->setPen(QPen(Qt::black));
                painter->drawPoint(i, j);
            } else {
                painter->setPen(QColor(a * 10 % 256, 0, a * 10 % 256));
                //painter->setPen(QColor(a * a % 256, 0, a * a % 256));
                painter->drawPoint(i, j);
            }
        }
    }

    mas1 = q1;
    mas2 = q2;
    int Ksenia = 12;
}




