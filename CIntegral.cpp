#include "CIntegral.h"

Integral::Integral() {
	poly = NULL;
}

Integral::Integral(Polynomial* p) {
	
	poly = new Polynomial;
	*poly = *p;
	
}

Integral::~Integral() {
    
	if (poly != NULL) {
		delete poly;
		poly = NULL;
	}
}

void Integral::SetPolynomial(Polynomial* p) {
	
	if (poly != NULL) {
		delete poly;
		poly = NULL;
	}
	poly = new Polynomial;
	*poly = *p;
	
}


/// @brief write an error message 
/// @param string message to be printed
void Integral::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Integral --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Integral::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Integral --";
	cout << string << endl;

}

void Integral::Dump() {
	
	cout << endl << " -- Integral --";
	cout << endl << " I can compute the integral of ";
	poly->Dump();

	return;
}