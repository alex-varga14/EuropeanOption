#ifndef SIMPLEBONDPRICING_HPP
#define SIMPLEBONDPRICING_HPP

#include <vector>

using namespade std;

// Logical grouping of functions and others
namespace Chapter3CPPBook
{
	typedef vector<double> Vector;
	
	double power(double d, long n);
	
	//	Future value of a sum of money invested today
	double FutureValue(double p, long nPeriods, double r);
	
	// with periods per year
	double FutureValue(double p, long nPeriods, double r, long m);
	
	//	Continuous compounding
	double FutureValueContinuous(double p, long nPeriods, double r);
	
	//	Future value of an ordinary annuity
	double OrdinaryAnnuity(double A, long nPeriods, double r);
	
	//	Present value
	double PV(double pn, long nPeriods, double r);
	
	//	Present value of a series of future values
	double PV(const Vector& prices, long nPeriods, double r);
	
	//	Present value of an ordinary annuity
	double PresentValueOrdinaryAnnuity(double A, long nPer, double r);
	
}

#endif