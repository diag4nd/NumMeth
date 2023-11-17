#ifndef ADAMSBASHFORTH_H
#define ADAMSBASHFORTH_H

#include "Euler.h"
class AdamsBashforth: public Euler
{
public:
	using Euler::Euler;
	std::vector<double> solve();
	void setStart(double u0, double u1, double u2, double v0, double v1, double v2);
};

#endif // !ADAMSBASHFORTH_H


