
#include "CIntegral.h"   // Inclusione del file header della classe

//Costruttore di default
Integral::Integral() {
	
	poly = NULL; // Inizializza il puntatore a NULL: nessun polinomio ancora assegnato
}

// Costruttore parametrico
Integral::Integral (Polynomial* p) {
	
	poly = new Polynomial; // Alloca dinamicamente un nuovo oggetto Polynomial
    *poly = *p;            // Copia il contenuto del polinomio passato per puntatore
}

// Distruttore
Integral::~Integral() {
    
	if (poly != NULL) {   // Se c’è memoria allocata...
        delete poly;      // ...libera la memoria associata al polinomio
        poly = NULL;      // Imposta il puntatore a NULL per evitare dangling pointer
    }
}

// Metodo per assegnare un nuovo oggetto polinomio al puntatore dell'oggetto polinomio
void Integral::SetPolynomial(Polynomial* p) {
    
	if (poly != NULL) {   // Se già presente, elimina il vecchio polinomio
        delete poly;
        poly = NULL;
    }

    poly = new Polynomial; // Alloca un nuovo oggetto Polynomial
    *poly = *p;            // Copia il contenuto dell’oggetto passato
}


/// @brief write an error message 
/// @param string message to be printed
// Metodo per stampare un messaggio di errore
void Integral::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Integral --";
	cout << string << endl;
}

/// @brief write a warning message 
/// @param string message to be printed
// Metodo per stampare un messaggio di warning
void Integral::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Integral --";
	cout << string << endl;
}

// Metodo di debug: stampa il polinomio su cui si può calcolare l'integrale
void Integral::Dump() {
	
	cout << endl << " -- Integral --";
	cout << endl << " I can compute the integral of ";
	poly->Dump(); 	// Chiama il metodo Dump del Polynomial

	return;			// (Facoltativo in funzioni void)
}