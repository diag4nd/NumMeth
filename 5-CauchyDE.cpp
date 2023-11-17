#include <iostream>
#include "Euler.h"
#include "RungeKutta.h"
#include "AdamsBashforth.h"
#include <cmath>
#include <fstream>

double f1(double x) { return cosh(x); }

double f2(double x) { return sinh(x); }

double f3(double x) { return cosh(x) + x * sinh(x); }

double u0(double x) { return exp(-sinh(x)) + x; }

int main()
{
	double x0(1), y0(0), a(0), b(1), h1(0.05), h2(0.1);

	Euler eSode1(&f1, &f2, &f3, x0, y0, a, b, h1);
	std::vector<double> u11 = eSode1.solve();
	Euler eSode2(&f1, &f2, &f3, x0, y0, a, b, h2);
	std::vector<double> u12 = eSode2.solve();

	RungeKutta rkSode1(&f1, &f2, &f3, x0, y0, a, b, h1);
	std::vector<double> u21 = rkSode1.solve();
	std::vector<double> v21 = rkSode1.getV();
	RungeKutta rkSode2(&f1, &f2, &f3, x0, y0, a, b, h2);
	std::vector<double> u22 = rkSode2.solve();
	std::vector<double> v22 = rkSode2.getV();

	AdamsBashforth abSode1(&f1, &f2, &f3, x0, y0, a, b, h1);
	abSode1.setStart(u21[0], u21[1], u21[2], v21[0], v21[1], v21[2]);
	std::vector<double> u31 = abSode1.solve();
	AdamsBashforth abSode2(&f1, &f2, &f3, x0, y0, a, b, h2);
	abSode2.setStart(u22[0], u22[1], u22[2], v22[0], v22[1], v22[2]);
	std::vector<double> u32 = abSode2.solve();

	std::ofstream out11;
	std::ofstream out21;
	std::ofstream out31;
	std::ofstream out12;
	std::ofstream out22;
	std::ofstream out32;

	out11.open("euler1.txt");
	out21.open("rungekutta1.txt");
	out31.open("adamsbashforth1.txt");
	out12.open("euler2.txt");
	out22.open("rungekutta2.txt");
	out32.open("adamsbashforth2.txt");
	for (int i = 0; i <= eSode1.getN(); i++)
	{
		out11 << eSode1.getXi(i) << "\t" << u11[i] << "\n";
		out21 << rkSode1.getXi(i) << "\t" << u21[i] << "\n";
		out31 << abSode1.getXi(i) << "\t" << u31[i] << "\n";
	}
	for (int i = 0; i <= eSode2.getN(); i++)
	{
		out12 << eSode2.getXi(i) << "\t" << u12[i] << "\n";
		out22 << rkSode2.getXi(i) << "\t" << u22[i] << "\n";
		out32 << abSode2.getXi(i) << "\t" << u32[i] << "\n";
	}
	out11.close();
	out21.close();
	out31.close();
	out12.close();
	out22.close();
	out32.close();

	return 0;
}