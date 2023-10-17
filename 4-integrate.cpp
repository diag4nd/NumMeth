#include <iostream>
#include <cmath>
#include <fstream>
#define A -1.0
#define B 1.0
#define N 100

long double func         (long double x);
long double midRectangle (int i, long double h);
long double trapezoid    (int i, long double h);
long double simpson      (int i, long double h);

int main()
{
    long double h = (B-A)/(N-1);
    long double rectSumm{0}, trapSumm{0}, simpSumm{0};
    for (int i=0; i<N; i++)
    {
      rectSumm += midRectangle(i, h);
      trapSumm += trapezoid (i, h);
      simpSumm += simpson(i, h);
    }
    
    std::cout << "Метод прямоугольников: "<< rectSumm << std::endl;
    std::cout << "Метод трапеций: "<< trapSumm << std::endl;
    std::cout << "Метод Симпсона: "<< simpSumm << std::endl;
    return 0;
}

long double func(long double x)
{
  return pow(x, 5)*sin(x);
}

long double midRectangle(int i, long double h)
{
  long double xi = A + h*i + h/2;
  return h*func(xi);
}

long double trapezoid(int i, long double h)
{
  long double xl = A + h*i;
  long double xr = xl + h;
  return h/2 * (func(xl) + func(xr));
}

long double simpson(int i, long double h)
{
  long double xl, xm, xr;
  
  if (i == N-2)
  {
    xl = A+h*(i-1);
  }
  else if (i == N-1)
  {
    xl = A+h*(i-2);
  }
  else
  {
    xl = A+i*h;
  }
  xm = xl + h;
  xr = xm + h;
  return h/6 * (func(xl) + 4*func(xm) + func(xr));
}