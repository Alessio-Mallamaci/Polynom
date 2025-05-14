// CLASSE DERIVATA DALLA FUNCTION OBJECT (Polimorfismo)

/*! @file CTrapezoidal.h
	@brief A class for numerical integration according to the trapezoidal rule
	@author Paolo Gastaldo

	Details.
*/ 

// GUARDIA: evita inclusioni multiple del file
#ifndef TRAPEZOIDAL_H
#define TRAPEZOIDAL_H

#include "CIntegral.h"  // Includo la classe base astratta da cui eredito

using namespace std;

// Classe Trapezoidal derivata da Integral (POLIMORFISMO)
class Trapezoidal : public Integral {

public:
    
	/// @name CONSTRUCTORS and DESTRUCTOR 
	/// @{
    Trapezoidal();                   	// Costruttore di default
    Trapezoidal(Polynomial* p);         // Costruttore con puntatore a Polynomial
    Trapezoidal(const Trapezoidal& p);  // Costruttore di copia
    ~Trapezoidal();                     // Distruttore
	/// @}
	
	/// @name OPERATORS 
	/// @{
	Trapezoidal& operator=(const Trapezoidal& p); // Operatore di assegnazione
    bool operator==(const Trapezoidal& p);        // Operatore di confronto (non implementato)
    /// @}
	
	// Implementazione del metodo virtuale GetIntegral tramite la regola del trapezio
    double GetIntegral(double inf, double sup, int intervals = 100);

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string);  // Messaggi di errore
    void WarningMessage(const char *string);// Messaggi di avviso
    void Dump();                            // Metodo per il debug
    /// @}

    
};

#endif