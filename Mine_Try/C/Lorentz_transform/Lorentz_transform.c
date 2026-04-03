#include <stdio.h>
#include <math.h>

#include "Lorentz_transform.h"
double calculateGamma(double v,double c)
{
    double gamma;
    gamma = 1/sqrt(1-pow((v/c),2));
    return gamma;
}
double calculate_x(double gamma,double velocity)
{
    return (1 - velocity)*gamma;
}
double calculate_t(double gamma,double velocity)
{
    return (1-pow(velocity,2))*gamma;
}
