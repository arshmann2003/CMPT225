/***
 * 
 * Complete your methods for Triple here
 *
 */

#include "Triple.h"


Triple::Triple() : x(0), y(0), z(0) { };


Triple::Triple(double x, double y, double z) : x(x), y(y), z(z) { };

void Triple::setX(double x)
{
    this->x = x;
}

void Triple::setY(double y)
{
    this->y = y;
}

void Triple::setZ(double z)
{
    this->z = y;
}

double Triple::getX()
const{
    return x;
};

double Triple::getY()
const{
    return y;
};

double Triple::getZ()
const{
    return z;
};
