/*
 * IntervalArithmetic.h
 *
 *  Created on: 20-11-2012
 *      Author: Tomasz Hoffmann and Andrzej Marciniak
 *
 *  Before you start use module, please install libraries:
 *  	- .boost ( http://www.boost.org/ )
 *  	- GNU MPFR ( http://www.mpfr.org/ )
 *
 *  Small changes for C++11 compatibility by Jakub Wozniak
 */

#ifndef INTERVALARITHMETIC_H_
#define INTERVALARITHMETIC_H_
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <fenv.h>
#include <stdlib.h>
#include <stdint.h>
#include <mpfr.h>
#include <boost/lexical_cast.hpp>
#include <quadmath.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <cmath>

namespace intervalarth
{

    class interval
    {
    public:
        long double a, b;

        interval();
        interval(const long double &x, const long double &y);

        interval operator +(const interval& x);
        interval operator -(const interval& x);
        interval operator *(const interval& x);
        interval operator ^(const int &x);
        interval operator /(const interval& x);
        bool operator >(const interval& x);
        bool operator <(const interval& x);
        bool operator ==(const interval& x);
        bool operator !=(const interval &x);
        bool operator >=(const interval& x);
        bool operator <=(const interval& x);
    };

    //set precision
    const int curr_precision = 80;

    // store the original rounding mode
    const int originalRounding = fegetround();
    const char DecimalSeparator = '.';

    class IntervalArithmetic
    {
    public:
        IntervalArithmetic();
        virtual ~IntervalArithmetic();
        static long double IntWidth(const interval& x);
        static interval IAdd(const interval &x, const interval& y);
        static interval ISub(const interval& x, const interval& y);
        static interval IMul(const interval& x, const interval& y);
        static interval IDiv(const interval& x, const interval& y);
        static long double DIntWidth(const interval& x);
        static interval Abs(const interval& x);
        static interval Projection(const interval& x);
        static interval Opposite(const interval& x);
        static interval Inverse(const interval& x);
        static interval DIAdd(const interval& x, const interval& y);
        static interval DISub(const interval& x, const interval& y);
        static interval DIMul(const interval& x, const interval& y);
        static interval DIDiv(const interval& x, const interval& y);
        static interval IntRead(const std::string& sa);
        static long double LeftRead(const std::string& sa);
        static long double RightRead(const std::string& sa);
        static interval ISin(const interval& x, int& st);
        static interval ICos(const interval& x, int& st);
        static interval IExp(const interval& x, int& st);
        static interval ISqr(const interval& x, int& st);
        static interval ISqr2();
        static interval ISqr3();
        static interval IPi();
        static void IEndsToStrings(const interval& i, std::string& left, std::string& right);
    };

} /* namespace interval */
#endif /* INTERVALARITHMETIC_H_ */
