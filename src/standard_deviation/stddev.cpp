/*********************************************************************************************************
 * Název projektu: IVS - Kalkulačka
 * Soubor: stddev.cpp
 * Datum: 22.04. 2020
 * Poslední změna: 22.04. 2020
 * Autoři: Kliš Michal (xklism00)
 *          Flek David (xflekd00)
 *          Široký Ondřej (xsirok09)
 *          Sladký Jan (xsladk09)
 * 
 * Popis: Výběrová směrodatná odchylka
 * 
 * *******************************************************************************************************/

/**
 * @file stddev.cpp
 * @author Kliš Michal (xklism00)
 * @author Flek David (xflekd00)
 * @author Široký Ondřej (xsirok09)
 * @author Sladký Jan (xsladk09)
 * 
 * @brief Výpočet výběrové směrodatné odchylky
 */

#include <iostream>
#include "../lib/Math.h"

using namespace std;
using namespace Math;

int main() {
    
    double sum = 0; 
    double sum_square = 0; 
    double x;
    int i = 0;
    while(cin >> x){   
        sum = Add(sum, x);
        sum_square = Add(sum_square, Power(x,2)); 
        i++;
    }
    double mean = Div(sum, i); 
    double brackets = Sub(sum_square, Mult(i,Power(mean,2)));  
    double fract = Div(1,Sub(i,1));
    double result = (GeneralRoot( Mult(fract,brackets), 2) );
    cout.precision(8);
    cout << result << endl;
    return 0;
}