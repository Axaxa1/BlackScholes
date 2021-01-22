// BlackScholes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "European.h"
#include "Digital.h"
#include "Asian.h"
#include <typeinfo>

int main()
{
    BlackScholesModel model = BlackScholesModel(100, 0.05, 0.02); // Model to simulate prices
    MonteCarloPricer optimizer = MonteCarloPricer(1000); // Optimizer 

    EuropeanCall call = EuropeanCall(100.0, 1.0); // European Call option
    EuropeanPut put = EuropeanPut(110.0, 1.0); // European put
    optimizer.priceAndPrintClassic(model, call);
    optimizer.priceAndPrintClassic(model, put);

    DigitalCall digi_call = DigitalCall(100.0, 1.0);
    DigitalPut digi_put = DigitalPut(100.0, 1.0);
    optimizer.priceAndPrintClassic(model, digi_call);
    optimizer.priceAndPrintClassic(model, digi_put);

    AsianArithmeticCall asian_arithmetic_call = AsianArithmeticCall(100.0, 1.0);
    AsianArithmeticPut asian_arithmetic_put = AsianArithmeticPut(110.0, 1.0);
    optimizer.priceAndPrintAsian(model, asian_arithmetic_call);
    optimizer.priceAndPrintAsian(model, asian_arithmetic_put);

    AsianGeometricCall asian_geometric_call = AsianGeometricCall(100.0, 1.0);
    AsianGeometricPut asian_geometric_put = AsianGeometricPut(110.0, 1.0);
    optimizer.priceAndPrintAsian(model, asian_geometric_call);
    optimizer.priceAndPrintAsian(model, asian_geometric_put);

    return 0;

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
