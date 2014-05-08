#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <tgmath.h>

#include "switchexception.h"
#include "intervalarithmetic.h"



// Real Arithmetic
void Newtonsimple(const int &n, long double x[], const long double &omega,const long double &eps, const int &mit, int& it, int& st);
long double f(int i, long double x[]);
long double df(int i, long double x[]);


// Interval Arithmetic
void Newtonsimple_interval(const int &n, intervalarth::interval x[], const intervalarth::interval &omega,const intervalarth::interval &eps, const int &mit, int& it, int& st);
intervalarth::interval f_interval(int i, intervalarth::interval x[]);
intervalarth::interval df_interval(int i, intervalarth::interval x[]);

#endif // FUNCTIONS_H
