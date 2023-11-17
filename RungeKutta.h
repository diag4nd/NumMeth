#ifndef RUNGEKUTTA_H
#define RUNGEKUTTA_H
#include "Euler.h"
class RungeKutta: public Euler
{
public:
	using Euler::Euler;
	std::vector<double> solve();
};

#endif // !RUNGEKUTTA_H

