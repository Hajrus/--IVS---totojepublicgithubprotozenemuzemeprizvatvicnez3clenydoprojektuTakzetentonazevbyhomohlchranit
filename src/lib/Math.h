/*********************************************************************************************************
 * Název projektu: IVS - Kalkulačka
 * Soubor: Math.h
 * Datum: 24.03.2020
 * Poslední změna: 22.04. 2020
 * Autoři: Kliš Michal (xklism00)
 *          Flek David (xflekd00)
 *          Široký Ondřej (xsirok09)
 *          Sladký Jan (xsladk09)
 * 
 * Popis: Hlavičkový soubor matematocké knihovny
 * 
 * *******************************************************************************************************/

#ifndef MATH_LIB_H_
#define MATH_LIB_H_

/**
 * @file Math.h
 * @author Kliš Michal (xklism00)
 * @author Flek David (xflekd00)
 * @author Široký Ondřej (xsirok09)
 * @author Sladký Jan (xsladk09)
 * 
 * @brief Matematická knihovna
 */


/**
 * Jednoduchá matematická knihovna se základními operaceni
 * 
 * @brief Knihovna se základními matematickými operaceni
 */  
namespace Math
{
    /**
     * @brief Sčítání   
     * @param firstOperand První sčítanec
     * @param secondOperand Druhý sčítanec
     * @return Vrací výsledný součet sčítanců
     */
    double Add(double firstOperand, double secondOperand);

    /**
     * @brief Mínus
     * @param firstOperand Menšenec
     * @param secondOperand Menšitel
     * @return Vrací výsledný rozdíl
     */
    double Sub(double firstOperand, double secondOperand);
    
    /**
     * @brief Násobení
     * @param firstOperand První činitel
     * @param secondOperand Druhý činitel
     * @return Vrací výsledek násobení
     */
    double Mult(double firstOperand, double secondOperand);
    
    /**
     * @brief Dělení
     * @param numer Hodnota čitatele
     * @param denom Hodnota jmenovatele
     * @return Vrací výsledek dělení čitatele jmenovatelem
     */
    double Div(double numer, double denom);

    /**
     * @brief Faktorial
     * @param n Přirozené číslo
     * @return Vrací výsledek faktoriálu 
     */
    unsigned long long Factorial(unsigned int n);

    /**
     * @brief Mocnina
     * Mocnina - b^a -  a-tá mocnina b.
     * @param base Základ mocniny
     * @param exponent Exponent mocniny
     * @return Vrací výsledek mocniny
     */
    double Power(double base, unsigned int exponent);

    /**
     * @brief Obecná odmocnina
     * obecná odmocnina - n√x 
     * @param x n√x - číslo pod odmocninou
     * @param n n√x - číslo čím se odmocnuje
     * @return Vrací vysledek obecne odmocniny
     */
    double GeneralRoot(double x, double n);
    
    /**
     * @brief Operace modulo
     * Operace modulo - numer % denom
     * @param numer Hodnota čitatele
     * @param denom Hodnota jmenovatele
     * @return Vrací zbytek po deleni
     */
    int Mod(int numer, int denom);
};

#endif /* MATH_LIB_H_ */