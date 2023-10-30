#include <iostream>
#include <cmath>
#include <iomanip>
#define A 1
#define B 2.5
#define EPS 1e-14

double func(double x) { return  exp(pow(x, 3) - 2*x) - 2; };
double dfunc(double x) { return  (3*pow(x, 2) - 2)*exp(pow(x, 3) - 2 * x); };
double ddfunc(double x) { return  (6*x + pow((3 * pow(x, 2) - 2), 2))*exp(pow(x, 3) - 2 * x); };
typedef double(*function)(double x);

double getStartPosition(function f, function ddf, double xLeft, double xRight);
double newtonSolve(function f, function df, double xLeft, double xRight, double epsilon, double x0);

bool breakCheck1(double xnew, double xold, double epsilon1);
bool breakCheck2(function f, double xnew, double epsilon2);

int main()
{
    double x0 = getStartPosition(func, ddfunc, A, B);
    std::cout << std::setprecision(17) << "x0 = " << x0 << std::endl;
    std::cout << "e = " << EPS << std::endl << std::endl;
    double root = newtonSolve(func, dfunc, A, B, EPS, x0);
    std::cout << "x = " << root << std::endl;
}

bool breakCheck1(double xnew, double xold, double epsilon)
{
    std::cout << "x = " << xnew << std::endl;
    if (abs(xnew - xold) <= epsilon)
    {
        std::cout << "|x(n+1) - x(n)| <= e" << std::endl;
        return true;
    }
    std::cout << "|x(n+1) - x(n)| > e" << std::endl;
    return false;
}

bool breakCheck2(function f, double xnew, double epsilon)
{
    if (abs(f(xnew)) <= epsilon)
    {
        std::cout << "|f(x(n+1))| <= e" << std::endl << std::endl;
        return true;
    }
    std::cout << "|f(x(n+1))| > e" << std::endl << std::endl;
    return false;
}

double getStartPosition(function f, function ddf, double xLeft, double xRight)
{
    double x0(xLeft);
    if ((ddf(xLeft) != 0) and (f(xLeft) * ddf(xLeft) > 0)) { x0 = xLeft; }
    else if ((ddf(xRight) != 0) and (f(xRight) * ddf(xRight) > 0)) { x0 = xRight; }
    else { x0 = (xLeft + xRight) / 2; }
    return x0;
}

double newtonSolve(function f, function df, double xLeft, double xRight, double epsilon, double x0)
{
    double root(0), xnew(0), xold(x0);
    int iter(1);
    std::cout << "Iteration: " << iter << std::endl;
    xnew = xold - f(xold) / df(xold);
    bool a = breakCheck1(xnew, xold, epsilon);
    bool b = breakCheck2(func, xnew, epsilon);
    while (not(a or b))
    {
        iter++;
        std::cout << "Iteration: " << iter << std::endl;
        xold = xnew;
        xnew = xold - f(xold) / df(xold);
        a = breakCheck1(xnew, xold, epsilon);
        b = breakCheck2(func, xnew, epsilon);
        if (iter > 100)
        {
            std::cout << "Too many" << std::endl;
            break;
        }
    }
    root = xnew;
    return root;
}
