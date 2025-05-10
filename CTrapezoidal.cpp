#include "CTrapezoidal.h"
/*! @file CTrapezoidal.cpp
	@brief Implementation of the Trapezoidal class
	@author Paolo Gastaldo

	Details.
*/ 


Trapezoidal::Trapezoidal() {
}

Trapezoidal::Trapezoidal(Polynomial* p):Integral(p) {
	
}

Trapezoidal::Trapezoidal(const Trapezoidal& p){
	
	cout << "Trapezoidal - copy constructor" << endl; 
	if (p.poly != NULL) {
		poly = new Polynomial;
		*poly = *(p.poly);
	}
	else 
		poly = NULL;
}

Trapezoidal::~Trapezoidal() {
}

Trapezoidal& Trapezoidal::operator=(const Trapezoidal& p) {
	
	if (poly != NULL) {
		delete poly;
		poly = NULL;
	}
	
	if (p.poly != NULL) {
		poly = new Polynomial;
		*poly = *(p.poly);
	}
	else 
		poly = NULL;
	
	return *this;
	
}

bool Trapezoidal::operator==(const Trapezoidal& p){ /*NON si sa se è utile*/}

double Trapezoidal::GetIntegral(double inf, double sup, int intervals) {
	
	int i;

	double integ = 0.;
	double stepsize = (sup - inf)/(double)intervals;
	double h = stepsize/2.;
	double in1,in2;
	
	in1 = inf;
	for (i=0; i<intervals; i++) {
		in2 = in1 + stepsize;
		integ += h*(poly->GetValue(in1)+poly->GetValue(in2));
		in1 = in2;
	}
	
	return integ;
	
}


/// @brief write an error message 
/// @param string message to be printed
void Trapezoidal::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Trapezoidal --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Trapezoidal::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Trapezoidal --";
	cout << string << endl;

}

void Trapezoidal::Dump() {
	
	cout << endl << " -- Trapezoidal --";
	cout << endl << " I use the trapezoidal rule to compute the integral of ";
	poly->Dump();

	return;
}


