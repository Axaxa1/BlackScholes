#include "BlackScholesModel.h"
#include "MonteCarloPricer.h"
#include "European.h"
#include "Digital.h"
#include "Asian.h"
#include "Complex.h"

int main()
{
    double starting_price = 100.0;
    double risk_free_rate = 0.05;
    double volatility = 0.2;
    BlackScholesModel model = BlackScholesModel(starting_price, risk_free_rate, volatility); // Model to simulate prices
    
    int num_sims = 10000;
    int n_steps = 250; // Number of steps in the path generation process
    MonteCarloPricer optimizer = MonteCarloPricer(num_sims, n_steps); // Optimizer

    EuropeanCall eu_call = EuropeanCall(100.0, 1.0); // European Call
    optimizer.priceAndPrintClassic(model, eu_call);
    EuropeanPut eu_put = EuropeanPut(100.0, 1.0); // European Put
    optimizer.priceAndPrintClassic(model, eu_put);

    DigitalCall digital_call = DigitalCall(100.0, 1.0); // Digital Call
    optimizer.priceAndPrintClassic(model, digital_call);
    DigitalPut digital_put = DigitalPut(100.0, 1.0); // Digital Put
    optimizer.priceAndPrintClassic(model, digital_put);

    AsianArithmeticCall asian_arithmetic_call = AsianArithmeticCall(100.0, 1.0); // Asian Arithmetic Call
    optimizer.priceAndPrint(model, asian_arithmetic_call);
    AsianArithmeticPut asian_arithmetic_put = AsianArithmeticPut(100.0, 1.0); // Asian Arithmetic Put
    optimizer.priceAndPrint(model, asian_arithmetic_put);

    AsianGeometricCall asian_geometric_call = AsianGeometricCall(100.0, 1.0); // Asian Geometric Call
    optimizer.priceAndPrint(model, asian_geometric_call);
    AsianGeometricPut asian_geometric_put = AsianGeometricPut(100.0, 1.0); // Asian Geometric Put
    optimizer.priceAndPrint(model, asian_geometric_put);

    DoubleDigital double_digital = DoubleDigital(80.0, 120.0, 1.0); // Double Digital
    optimizer.priceAndPrintClassic(model, double_digital);

    BullSpread bull_spread = BullSpread(80.0, 120.0, 1.0); // Bullspread
    optimizer.priceAndPrintClassic(model, bull_spread);

    BearSpread bear_spread = BearSpread(80.0, 120.0, 1.0); // BearSpread
    optimizer.priceAndPrintClassic(model, bear_spread);

    Butterfly butterfly = Butterfly(80.0, 120.0, 1.0); //Butterfly
    optimizer.priceAndPrintClassic(model, butterfly);


    Complex custom_option = Complex("Customized option");
    /* The repartition of this customized option :
     - 1 Long European Call
     - 1 Long Asian Arithmetic Put
     - 3 Short Digital Call
     Total number of Options purchased: 50 000 */

    DigitalCall triple_digital_call(120, 1); // Create a triple digitalCall
    triple_digital_call.setMultiplier(3);
    
    custom_option += eu_call ; // Buy European Call
    custom_option += asian_arithmetic_put; // Buy Asian Arithmetic Put
    custom_option -= triple_digital_call; // Sell triple digital Call

    custom_option *= 50000.0; // Set the total number of options
    optimizer.priceAndPrint(model, custom_option);

    return 0;
}