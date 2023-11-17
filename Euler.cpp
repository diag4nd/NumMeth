#include "Euler.h"
double Euler::getA()
{
	return this->a;
}

double Euler::getB()
{
	return this->b;
}

double Euler::getH()
{
	return this->step;
}

int Euler::getN()
{
	return int((getB() - getA()) / getH());
}

double Euler::getF1(double x)
{
	return this->f1(x);
}

double Euler::getF2(double x)
{
	return this->f2(x);
}

double Euler::getF3(double x)
{
	return this->f3(x);
}

double Euler::getXi(int i)
{
	return getA() + i * getH();
}

double Euler::getU0()
{
	return this->u0;
}

double Euler::getV0()
{
	return this->v0;
}

std::vector<double> Euler::solve()
{
	//std::vector<double> u, v;
	u.insert(u.begin(), getU0());
	v.insert(v.begin(), getV0());
	double h = getH();
	double xl(0), f1(0), f2(0), f3(0);
	for (int i(1); i <= getN(); i++)
	{
		xl = getXi(i - 1);
		f1 = getF1(xl);
		f2 = getF2(xl);
		f3 = getF3(xl);
		u.insert(u.begin() + i, u[i - 1] + h * v[i - 1]);
		v.insert(v.begin() + i, v[i - 1] + h * (-f1 * v[i - 1] - f2 * u[i - 1] + f3));
	}
	return u;
}

std::vector<double> Euler::getV()
{
	return v;
}
