#include "math.h"
#include "sat3.cpp"


double f_rand(double f_min, double f_max)
{
    double f = (double)rand() / RAND_MAX;
    return f_min + f * (f_max - f_min);
}

double temp_0(double i, double t0, double tn, double n){
    return t0 - i * (t0 - tn)/n;
}

double temp_1(double i, double t0, double tn, double n){
    return t0 * pow(tn/ t0, i/(n+0.0));
}

double temp_2(double i, double t0, double tn, double n){
    double a = (t0 - tn)*(n+1)/n;
    double b = t0 - a;
    return a/(i+1) + b;
}

double temp_3(double i, double t0, double tn, double n){
    double a = log(t0-tn)/log(n);
    return t0 - pow(i, a);
}

double temp_4(double i, double t0, double tn, double n){
    return (t0-tn)/(1+pow(2.718281828459045,.3*(i-n/2)) + tn);
}
