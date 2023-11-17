#include "AdamsBashforth.h"
void AdamsBashforth::setStart(double u0, double u1, double u2, double v0, double v1, double v2)
{
	u.insert(u.begin(), u0);
	u.insert(u.begin() + 1, u1);
	u.insert(u.begin() + 2, u2);

	v.insert(v.begin(), v0);
	v.insert(v.begin() + 1, v1);
	v.insert(v.begin() + 2, v2);
}

std::vector<double> AdamsBashforth::solve()
{
	//std::vector<double> u, v;
	double h = getH();
	double xl(0), xm(0), xr(getA());
	double fr1(0), fm1(0), fl1(0);
	double fr2(0), fm2(0), fl2(0);

	/*
	u.insert(u.begin(), getU0());
	v.insert(v.begin(), getV0());

	
	fr1 = v[0];
	fr2 = -getF1(xr) * v[0] - getF2(xr) * u[0] + getF3(xr);

	u.insert(u.begin() + 1, u[0] + h*fr1);
	v.insert(v.begin() + 1, v[0] + h*fr2);

	xr = getXi(1);
	xm = getXi(0);

	fr1 = v[1];
	fm1 = v[0];
	fr2 = -getF1(xr) * v[1] - getF2(xr) * u[1] + getF3(xr);
	fm2 = -getF1(xm) * v[0] - getF2(xm) * u[0] + getF3(xm);

	u.insert(u.begin() + 2, u[1] + (h/2) * (3 * fr1 - fm1));
	v.insert(v.begin() + 2, v[1] + (h/2) * (3 * fr2 - fm2));
	*/
	for (int i(3); i <= getN(); i++)
	{
		xr = getXi(i - 1);
		xm = getXi(i - 2);;
		xl = getXi(i - 3);;

		fr1 = v[i - 1];
		fm1 = v[i - 2];
		fl1 = v[i - 3];
		fr2 = -getF1(xr) * v[i - 1] - getF2(xr) * u[i - 1] + getF3(xr);
		fm2 = -getF1(xm) * v[i - 2] - getF2(xm) * u[i - 2] + getF3(xm);
		fl2 = -getF1(xl) * v[i - 3] - getF2(xl) * u[i - 3] + getF3(xl);

		u.insert(u.begin() + i, u[i - 1] + (h / 12) * (23 * fr1 - 16 * fm1 + 5 * fl1));
		v.insert(v.begin() + i, v[i - 1] + (h / 12) * (23 * fr2 - 16 * fm2 + 5 * fl2));
	}
	return u;
}