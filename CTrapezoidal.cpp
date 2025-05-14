
#include "CTrapezoidal.h" // Inclusione del file header associato

/*! @file CTrapezoidal.cpp
	@brief Implementation of the Trapezoidal class
	@author Paolo Gastaldo

	Details.
*/ 

// Costruttore di default: non inizializza nulla
Trapezoidal::Trapezoidal() {
    //Niente
}

// Metodo per assegnare un nuovo oggetto polinomio al puntatore dell'oggetto polinomio --> delega alla classe base Integral
Trapezoidal::Trapezoidal(Polynomial* p) : Integral(p) {
    // Costruttore delegato: chiama il costruttore della classe base --> quindi NO implementazione
}

// Costruttore di copia
Trapezoidal::Trapezoidal(const Trapezoidal& p){
	
	cout << "Trapezoidal - copy constructor" << endl;
    
	if (p.poly != NULL) {           // Se l'oggetto polinomio passato è NON nullo
        poly = new Polynomial;      // Alloco memoria per il nuovo oggetto Polynomial
        *poly = *(p.poly);          // Copio il contenuto dell'oggetto Polynomial
    } else 
        poly = NULL;                // Altrimenti lo inizializzo a NULL
}

// Distruttore
Trapezoidal::~Trapezoidal() {
    // Niente da fare qui: il distruttore della classe base gestisce già la memoria
}

// Operatore di assegnazione
Trapezoidal& Trapezoidal::operator=(const Trapezoidal& p) {
	
	if (poly != NULL) {     // Se il polinomio corrente esiste...
        delete poly;        // ...lo dealloco
        poly = NULL;
    }
	
	if (p.poly != NULL) {   // Se il polinomio di p non è nullo
        poly = new Polynomial;
        *poly = *(p.poly);  // Copia il contenuto
    }
	else 
		poly = NULL;
	
	return *this; 			// Restituisco l'oggetto corrente
	
}

/*
// Operatore di confronto (non implementato perchè non si sa se è utile)
bool Trapezoidal::operator==(const Trapezoidal& p) {
    // La funzione è dichiarata ma non implementata, serve solo per completezza di interfaccia
    
}*/


// Implementazione del metodo GetIntegral: usa la regola del trapezio
double Trapezoidal::GetIntegral(double inf, double sup, int intervals) {
    int i;
    double integ = 0.0;                          // Valore dell'integrale
    double stepsize = (sup - inf) / intervals;   // Ampiezza di ciascun intervallo
    double h = stepsize / 2.0;                   // Metà dell'intervallo, per il calcolo del trapezio
    double in1, in2;

    in1 = inf;
    for (i = 0; i < intervals; i++) {
        in2 = in1 + stepsize;
        // Applico la regola del trapezio: (base/2)*(f(a)+f(b))
        integ += h * (poly->GetValue(in1) + poly->GetValue(in2));
        in1 = in2; // Passo all'intervallo successivo
    }

    return integ; // Restituisco il risultato finale
}


/// @brief write an error message 
/// @param string message to be printed
// Metodo per stampare messaggi di errore
void Trapezoidal::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Trapezoidal --";
	cout << string << endl;
}

/// @brief write a warning message 
/// @param string message to be printed
// Metodo per stampare messaggi di warning
void Trapezoidal::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Trapezoidal --";
	cout << string << endl;

}

// Metodo di debug: stampa il tipo e il polinomio su cui lavora
void Trapezoidal::Dump() {
	
	cout << endl << " -- Trapezoidal --";
	cout << endl << " I use the trapezoidal rule to compute the integral of ";
	poly->Dump(); // Stampa il polinomio tramite il suo metodo Dump()

	return;
}


