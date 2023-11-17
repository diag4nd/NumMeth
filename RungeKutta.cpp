#include "RungeKutta.h"
std::vector<double> RungeKutta::solve()
{
	//std::vector<double> u, v;
	u.insert(u.begin(), getU0());
	v.insert(v.begin(), getV0());

	double h = getH();
	double xl(0), xm(0), xr(0);
	double f10(0), f20(0), f30(0);
	double f11(0), f21(0), f31(0);
	double f12(0), f22(0), f32(0);
	double k01(0), k11(0), k21(0), k31(0);
	double k02(0), k12(0), k22(0), k32(0);

	for (int i(1); i <= getN(); i++)
	{
		xl = getXi(i - 1);
		xm = xl + h / 2;
		xr = xl + h;

		f10 = getF1(xl);
		f20 = getF2(xl);
		f30 = getF3(xl);
		f11 = getF1(xm);
		f21 = getF2(xm);
		f31 = getF3(xm);
		f12 = getF1(xr);
		f22 = getF2(xr);
		f32 = getF3(xr);

		k01 = h * v[i - 1];
		k11 = h * (v[i - 1] + k01 / 2);
		k21 = h * (v[i - 1] + k11 / 2);
		k31 = h * (v[i - 1] + k21 / 2);

		k02 = h * (-f10 * v[i - 1] - f20 * u[i - 1] + f30);
		k12 = h * (-f11 * (v[i - 1] + k02 / 2) - f21 * (u[i - 1] + k02 / 2) + f31);
		k22 = h * (-f11 * (v[i - 1] + k12 / 2) - f21 * (u[i - 1] + k12 / 2) + f31);
		k32 = h * (-f12 * (v[i - 1] + k22) - f22 * (u[i - 1] + k22) + f32);

		this->u.insert(u.begin() + i, u[i - 1] + (k01 + 2*k11 + 2*k21 + k31) / 6);
		this->v.insert(v.begin() + i, v[i - 1] + (k02 + 2*k12 + 2*k22 + k32) / 6);
	}
	return u;
}