// BlackScholes.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "European.h"
#include "Digital.h"
#include "Asian.h"
#include "Complex.h"

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
    optimizer.priceAndPrintComplex(model, asian_arithmetic_call);
    optimizer.priceAndPrintComplex(model, asian_arithmetic_put);

    AsianGeometricCall asian_geometric_call = AsianGeometricCall(100.0, 1.0);
    AsianGeometricPut asian_geometric_put = AsianGeometricPut(110.0, 1.0);
    optimizer.priceAndPrintComplex(model, asian_geometric_call);
    optimizer.priceAndPrintComplex(model, asian_geometric_put);

    DoubleDigital double_digital = DoubleDigital(80.0, 120.0, 1);
    optimizer.priceAndPrintClassic(model, double_digital);

    BullSpread bull_spread = BullSpread(70.0, 140.0, 1);
    optimizer.priceAndPrintClassic(model, bull_spread);

    BearSpread bear_spread = BearSpread(80.0, 120.0, 1);
    optimizer.priceAndPrintClassic(model, bear_spread);

    Butterfly butterfly = Butterfly(80.0, 100.0, 1);
    optimizer.priceAndPrintClassic(model, butterfly);

    optimizer.priceAndPrint(model, call);
    optimizer.priceAndPrint(model, asian_arithmetic_call);

    Complex test = Complex("Test");
    test.buyOption(call);
    call.setMultiplier(-1);
    test.buyOption(call);
    test.setMultiplier(2);
    optimizer.priceAndPrint(model, test);

    BullSpread2 test2 = BullSpread2(70, 140, 1);
    optimizer.priceAndPrint(model, test2);

    return 0;

}
