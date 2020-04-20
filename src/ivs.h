#ifndef IVS_H
#define IVS_H

#include <string>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

/**
 * @file ivs.h
 * @author Kliš Michal (xklism00)
 * @author Flek David (xflekd00)
 * @author Široký Ondřej (xsirok09)
 * @author Sladký Jan (xsladk09)
 * 
 * @brief Obsahuje namespace IVS, které obsahuje všechny třídy pro práci s projektem IVS.
 * GUI je zcela odděleno od funkcionality kalkulačky. GUI pouze volá funkce základního View Modelu.
 */

namespace IVS{
    /**
     * CalculatorButton je enum odlišující unikátně každou klávesu kalkulačky.
     * Při předávání informace o stisku klávesy se předává kód klávesy, právě z tohoto enum.
     */  
    typedef enum{
        //konstanty
        zero = 48,
        one = 49,
        two = 50,
        three = 51,
        four = 52,
        five = 53,
        six = 54,
        seven = 55,
        eight = 56,
        nine = 57,
        dot = 46,
        pi = 1,

        //operátory
        multiply = 42, 
        plus = 43, 
        minus = 45,
        divide = 47, 
        power = 94,
        mod = 37,
        factorial = 33,
        sqr = 2,

        //funkce
        equals = 61,
        clear = 99,
        del = 3

    } CalculatorButton;
    /**
     * CalculatorState definuje jednotlivé stavy kalkulačky, která funguje jako rádoby stavový automat.
     */
    typedef enum{
        Startup, InsertFirstOperand, OperatorAdded, InsertSecondOperand, Error
    } CalculatorState;

    /**
     * Třída pro vyjímky kalkulačky.
     */
    class CalculatorException{
        public:
            /**
             * @brief konstruktor vyjímky
             * @param message Zpráva, kterou má vyjímka dále předat
             */
            CalculatorException(std::string message);
            /**
             * @brief Vypíše opsah vyjímky na standartní chybový výstup
             * Vypíše chybu na standartní chybový výstup
             * @param message Zpráva, kterou má vyjímka dále předat
             */
            void Print();
        private:
            /**
             * @brief Obsahuje text vyjímky
             * Text vyjímky předaný v konstruktoru vyjímky.
             */
            std::string message;
    };
    /**
     * @brief Absrtakce operandu kalkulačky
     * Třída obsahuje všechny funkce pro práci a funkci abstrakce operandu v kalkulačce.
     * Abstrakce v sobě ukládá jak operand ve formátu string, tak ve formátu double.
     * Maximální hodnota operandu je rovna maximální hodnotě doublu.
     */
    class Operand{
        public:
            /**
             * @brief Konstruktor bez parametru
             * Konstruktor bez parametru se téměř nikdy nepoužívá, není ani definován. Použíjte konstruktory s parametrem.
             */
            Operand();
            /**
             * @brief Vytvoří a zinicializuje operand ze stringu,
             * Vytvoří abstranci operandu ze stringu. Automaticky překonvertuje string na double
             * @param sOp string zadaného operandu
             */
            Operand(std::string sOp);
            /**
             * @brief Vytvoří a zinicializuje operand z doublu,
             * Vytvoří abstranci operandu z doublu. Automaticky překonvertuje string na double
             * @param op hodnota zadaného operandu v doublu
             */
            Operand(double op);
            /**
             * @brief Navrátí operand ve formátu string
             * Navrací operand ve formátu string.
             * @return operand ve formátu string
             */
            std::string ToString();
            /**
             * @brief Navrátí operand ve formátu double
             * Navrací operand ve formátu double.
             * @return operand ve formátu double
             */
            double ToDouble();
            /**
             * @brief Přidá znak na konec operandu
             * Znak musí být validní, v případě nevalidity znaku vyhodí vyjímku (viz. validChar).
             * @param c Znak v kódování CalculatorButton, určený pro přidání.
             */
            void Append(CalculatorButton c);
            /**
             * @brief Umaže koncový znak u operandu
             * Umaže poslední znak z aktuálního operandu
             */
            void Erase();
        private:
            /**
             * Hodnota operandu v double, při změně hodnoty ve stringu se změní i hodnota v doublu.
             */
            double _doubleValue;
            /**
             * Hodnota operandu ve stringu, při změně hodnoty v doublu se změní i hodnota ve stringu.
             */
            std::string _stringValue;
            /**
             * @brief Otestuje jestli zadaný string odpovídá validnímu operandu
             * Otestuje jestli se zadaný string skládá z povolených znaků. V případě opaku vyhodí vyjímku.
             * @param input string určený ke kontrole.
             * @return navrátí true pokud je validní, jinak false.
             */
            bool validStr(std::string input);
            /**
             * @brief Otestuje, zdali je znak validní
             * Vyhodí exception, pokud znak není validní
             * @param c string určený ke kontrole.
             * @return navrátí true pokud je validní, jinak false.
             */
            bool validChar(CalculatorButton c);
            /**
             * @brief Převede double na string
             * Překonvertuje double na string
             * @param val double hodnota určená k převodu.
             * @return navrátí požadované číslo ve stringu.
             */
            std::string DoubleToStr(double val);
    };
    /**
     * @brief Rodičovská třída operátoru
     * Operator je třída, od které dědí jednotlivé operátory, jako například Plus, Minus atd.
     * Do kalkulačky lze jednoduše přidat další Operátory
     */
    class Operator{
        public:
            /**
             * @brief Defaultiní konstruktor operátoru
             * Konstruktor Operátoru, není nutné používat
             */
            explicit Operator();
            /**
             * @brief Konstruktor pro operátor s dvěmi operandy
             * Každý matematický operátor potřebuje operátory pro svou funkci (minimálně jeden).
             * Pro vytvoření nového operátoru je třeba zdědit a definovat funkci execute, která navrací výsledek daného operátoru.
             * Více matematických funkcí naleznete v operator.h
             * @param o1 odkaz na první operand předaný operátoru
             * @param o1 odkaz na druhý operand předaný operátoru
             */
            explicit Operator(Operand* o1, Operand* o2);
            /**
             * @brief Konstruktor pro operátor s jedním operandem
             * Každý matematický operátor potřebuje operátory pro svou funkci (minimálně jeden).
             * Pro vytvoření nového operátoru je třeba zdědit a definovat funkci execute, která navrací výsledek daného operátoru.
             * Více matematických funkcí naleznete v operator.h
             * @param o1 odkaz na první operand předaný operátoru
             */
            explicit Operator(Operand* o1);
            /**
             * Destruktor každého operandu.
             */
            virtual ~Operator();
            /**
             * @brief Navrátí výsledek operace
             * Navrátí výsledek operace po zavolání execute
             * @return navrátí ukazatel na operand s hodnout výpočtu dané operace
             */
            Operand* GetResult();  
        protected:
            /**
             * Hodnota výsledku operace
             */
            Operand* _result;
            /**
             * První operand
             */
            Operand* _o1;
            /**
             * Druhý operand, je nevyužit u operací s jen jedním operandem.
             */
            Operand* _o2;

    };
    /**
     * @brief Třída reprezentující kalkulačku
     * Třída obsahující funkce kalkulačky. Kalkulačka je simulována uvnitř paměti.
     */
    class Calculator{
        public:
            /**
             * @brief Konstruktor kalkulačky
             * konstruktor kalkulačky. Při vytvoření nové kalkulačky je třeba uchovat někde v paměti programu odkaz ke kalkulačce a poté přes něj k ní přistupovat.
             */
            Calculator();
            /**
             * @brief Funkce volaná pro simulování stisku klávesy
             * Při stisku klávesy v gui se předá informace o stisku klávesy pomocí funkce press. Kód příslušné klávesy je definovaný v CalculatorButton.
             * Při stisku klávesy se zjišťuje aktuální stav kalkulačky a chová se jako rádoby stavový automat.
             * @param button Identifikátor stisknuté klávesy
             */
            void Press(CalculatorButton button);
            /**
             * @brief Navrátí aktuální screen buffer kalkulačky
             * Kalkulačka ukládá buffer obrazovky usebe v paměti. Pro zobrazení v gui je třeba překreslovat tento buffer. Žádná jiná logika se v GUI neřeší.
             * @return navrátí screen buffer ve formátu std::string
             */
            std::string GetScreenBuffer();
            /**
             * @brief Navrátí aktuální history buffer kalkulačky
             * History buffer je řetězec postupu výpočtu kalkulačky.
             * @return navrátí history buffer ve formátu std::string
             */
            std::string GetHistoryBuffer();
        private:
            /**
             * Aktuální stav stavového automatu
             */
            CalculatorState _state;
            /**
             * Obsahuje data o displeji kalkulačky
             */
            std::string  _screenBuffer;
            /**
             * Obsahuje zobrazovaná data displeje kalkulačky pro historii.
             */
            std::string  _historyBuffer;
            /**
             * Aktuálně zvolený operátor
             */
            CalculatorButton _actualOperator;
            /**
             * První operand
             */
            Operand* _o1;
            /**
             * Druhý operand
             */
            Operand* _o2;
            /**
             * @brief Otestuje jestli je tlačítko konstanta
             * Otestování konstany
             * @return navrátí true pokud je, jinak false
             */
            bool isConstant(CalculatorButton button);
            /**
             * @brief Otestuje jestli je tlačítko operátor
             * Otestování operátoru
             * @return navrátí true pokud je, jinak false
             */
            bool isOperator(CalculatorButton button);
            /**
             * @brief Otestuje jestli je tlačítko funkce
             * Otestování funkce
             * @return navrátí true pokud je, jinak false
             */
            bool isFunction(CalculatorButton button);
            /**
             * @brief Vyčistí paměť kalkulačky
             * Vyčistí paměť kalkulačky
             */
            void clear();
            /**
             * @brief Vykoná operaci
             * Výsledek zvolené operace je uložen do prvního operandu
             */
            void execute();
            /**
             * Překreslí buffery.
             */
            void redrawBuffers();
    };
};

#endif