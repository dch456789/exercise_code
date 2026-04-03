#ifndef LORENTZ_TRANSFORM
#define LORENTZ_TRANSFORM
double calculateGamma(double v,double c);           //洛伦兹因子，v为当前速度与光速的比，c为设定光速与当前光速的比
double calculate_x(double gamma,double velocity);   //x的洛伦兹变换，即x`
double calculate_t(double gamma,double velocity);   //t的洛伦兹变换，即t`
#endif