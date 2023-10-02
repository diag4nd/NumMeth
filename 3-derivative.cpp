#include <iostream>
#include <cmath>
#include <fstream>
#define N 100
#define A -1.5
#define B 1.5

long double func(long double x)
{
  return sin(x)/(2+x);
}

long double midDeriv(int i, long double* x, long double* f)
{
  long double h = x[1] - x[0];
  if (i == 0)
  {
    return (-3*f[i] + 4*f[i+1] - f[i+2]) / (2*h);
  }
  else if (i == N-1)
  {
    return (3*f[i] - 4*f[i-1] + f[i-2]) / (2*h);
  }
  return (f[i+1] - f[i-1]) / (2*h);
}

long double rDeriv(int i, long double* x, long double* f)
{
  long double h = x[1] - x[0];
  if (i == N-1)
  {
    return (f[i] - f[i-1]) / h;
  }
  return (f[i+1] - f[i]) / h;
}

long double midDerivDouble(int i, long double *x, long double *f)
{
  long double h = x[1] - x[0];
  if ( (i == 0) or (i == 1) )
  {
    return (15*f[i]/4 - 77*f[i+1]/6 + 107*f[i+2]/6 - 13*f[i+3] + 61*f[i+4]/12 - 5*f[i+5]/6) / (h*h);
  }
  else if ( (i == N-1) or (i == N-2) )
  {
    return (15*f[i]/4 - 77*f[i-1]/6 + 107*f[i-2]/6 - 13*f[i-3] + 61*f[i-4]/12 - 5*f[i-5]/6) / (h*h);
  }
  return (-f[i-2] + 16*f[i-1] - 30*f[i] + 16*f[i+1] - f[i+2]) / (12*h*h);
}

int main()
{
    long double h = (B-A)/(N-1);
    long double x[N], f[N], df[N];
    
    for (int i=0; i<N; i++)
    {
      x[i] = i*h;
      f[i] = func(x[i]);
    }
    
    std::ofstream out;
    out.open("midDeriv.txt");
    if (out.is_open())
    {
        for (int i=0; i<N; i++)
        {
          df[i] = midDeriv(i, x, f);
          std::cout << df[i] << std::endl;
          out << x[i] << '\t' << df[i] << std::endl;
        }  
    }
    out.close();
    std::cout << std::endl;
    
    out.open("rDeriv.txt");
    if (out.is_open())
    {
        for (int i=0; i<N; i++)
        {
          df[i] = rDeriv(i, x, f);
          std::cout << df[i] << std::endl;
          out << x[i] << '\t' << df[i] << std::endl;
        } 
    }
    out.close();
    std::cout << std::endl;
    
    out.open("midDerivDouble.txt");
    if (out.is_open())
    {
        for (int i=0; i<N; i++)
        {
          df[i] = midDerivDouble(i, x, f);
          std::cout << df[i] << std::endl;
          out << x[i] << '\t' << df[i] << std::endl;
        }  
    }
    out.close();
    std::cout << std::endl;
    
    return 0;
}