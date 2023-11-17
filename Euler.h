#ifndef EULER_H
#define EULER_H
#include <vector>

class Euler
{
protected:
	typedef double(*func)(double x);
	func f1, f2, f3;
	double u0, v0;
	double a, b;
	double step;
	std::vector<double> u{}, v{};

public:
	Euler(func f, func g, func k, double x0, double y0, double l, double r, double h):
		f1(f), f2(g), f3(k),
		u0(x0), v0(y0), 
		a(l), b(r),
		step(h)
	{}
	double getA();
	double getB();
	double getH();
	int getN();
	double getF1(double x);
	double getF2(double x);
	double getF3(double x);
	double getXi(int i);
	double getU0();
	double getV0();
	std::vector<double> solve();
	std::vector<double> getV();
};

#endif // !EULER_H


