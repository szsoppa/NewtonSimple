#include "functions.h"

using namespace std;

/*******************************/
/*    LONG DOUBLE PRECISION    */
/*******************************/

long double f(int i, long double x[])
{
    switch(i)
    {
        case 0:
            return 2.0*(pow(x[0],2.0)) + x[1] + x[2];
            break;
        case 1:
            return (x[0]*x[1]) - x[2] + 2.0;
            break;
        case 2:
            return (x[0]-x[1])*x[2];
            break;
        default:
        break;
    }

    return 0;
}

long double df(int i, long double x[])
{
    switch(i)
    {
        case 0:
            return 4.0*x[0];
            break;
        case 1:
            return x[0];
            break;
        case 2:
            return x[0]-x[1];
            break;
        default:
        break;
    }

    return 0;
}

void Newtonsimple(const int &n, long double x[], const long double &omega,const long double &eps, const int &mit, int& it, int& st)
{
    int i;
    long double d,w;
    bool cond = false;
    long double *x1 = new long double[n];

    if( (n<1)||(mit<1) )
    {
        st = 1;
    }
    else
    {
        st = 0;
        it = 0;

        do
        {
            it++;

            if(it > mit)
            {
                st = 3;
                it--;
            }
            else
            {
                for(i=0; i<n; i++)
                {
                    d = df(i,x);

                    if(d==0)
                    {
                        st = 2;
                        break;
                    }
                    else
                    {
                        w = f(i,x);
                        x1[i] = x[i] - (omega*w)/d;
                    }
                }

                if( st==0 )
                {
                    cond = true;

                    for(i=0; i<n; i++)
                    {
                        if(std::abs(x[i]-x1[i])>=eps)
                        {
                            cond = false;
                            break;
                        }
                    }

                    for(i=0; i<n; i++)
                    {
                        x[i] = x1[i];
                        x1[i] = 0;
                    }
                }
            }
        }while( (st==0)&&(cond==false) );
    }

    delete []x1;
}


/*******************************/
/*     INTERVAL ARITHMETIC     */
/*******************************/

intervalarth::interval f_interval(int i, intervalarth::interval x[])
{
    intervalarth::interval two(2,2);
    switch(i)
    {
        case 0:
            return (two*(x[0]^2)) + x[1] + x[2];
            break;
        case 1:
            return (x[0]*x[1]) - x[2] + two;
            break;
        case 2:
            return (x[0]-x[1])*x[2];
            break;
        default:
            throw(SwitchException());
    }

    return intervalarth::interval(0,0);
}

intervalarth::interval df_interval(int i, intervalarth::interval x[])
{
    intervalarth::interval four(4,4);
    switch(i)
    {
        case 0:
            return four*x[0];
            break;
        case 1:
            return x[0];
            break;
        case 2:
            return x[0]-x[1];
            break;
        default:
            throw(SwitchException());
    }

    return intervalarth::interval(0,0);
}

void Newtonsimple_interval(const int &n, intervalarth::interval x[], const intervalarth::interval &omega,const intervalarth::interval &eps, const int &mit, int& it, int& st)
{
    int i;
    intervalarth::interval d,w;
    bool cond = false;
    intervalarth::interval *x1 = new intervalarth::interval[n];

    if( (n<1)||(mit<1) )
    {
        st = 1;
    }
    else
    {
        st = 0;
        it = 0;

        do
        {
            it++;

            if(it > mit)
            {
                st = 3;
                it--;
            }
            else
            {
                for(i=0; i<n; i++)
                {
                    d = df_interval(i,x);

                    if(d == intervalarth::interval(0,0) )
                    {
                        st = 2;
                        break;
                    }
                    else
                    {
                        w = f_interval(i,x);
                        x1[i] = x[i] - ((w*omega)/d);
                    }
                }

                if( st==0 )
                {
                    cond = true;

                    for(i=0; i<n; i++)
                    {
                        if(intervalarth::IntervalArithmetic::Abs(x[i]-x1[i]) >= eps)
                        {
                            cond = false;
                            break;
                        }
                    }

                    for(i=0; i<n; i++)
                    {
                        x[i] = x1[i];
                        x1[i] = intervalarth::interval(0,0);
                    }
                }
            }
        }while( (st==0)&&(cond==false) );
    }

    delete []x1;
}
