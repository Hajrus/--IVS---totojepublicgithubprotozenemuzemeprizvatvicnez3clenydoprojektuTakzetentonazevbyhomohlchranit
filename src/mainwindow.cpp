#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lib/Math.h"
#include "ivs.h"
#include "operator.h"
#include <string>

/*
double firstVal = 0.0; //ukladani prvni promenne
double secondVal = 0.0; //ukladani druhe promenne
double outputVal = 0;

bool isPower = false;
bool isSqrt = false;
bool isMod = false;
bool isMul = false;
bool isAdd = false;
bool isSub = false;
bool isDiv = false;

bool dotPresed = false;
bool opPressed = false; //uchovovava info., zda byl stisknut jakykoliv operator
*/

IVS::Calculator *kalkulacka; //globalni promenna pro praci s daty kalkulacky

/*
 *
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    kalkulacka = new IVS::Calculator();
    //nastaveni displejů
    ui->lineEdit_2->setText("");
    //inicializace číselníku
    QString butName;
    QPushButton *nmbrButtons[11];
    for(int i=0; i<11; i++)
    {
        if (i == 10)
        {
            QString butName = "ButtonDot";
            nmbrButtons[i]=MainWindow::findChild<QPushButton *>(butName);
            connect(nmbrButtons[i], SIGNAL(released()), this, SLOT(ButtonPress()));
        }
        QString butName = "Button" + QString::number(i);
        nmbrButtons[i]=MainWindow::findChild<QPushButton *>(butName);
        connect(nmbrButtons[i], SIGNAL(released()), this, SLOT(ButtonPress()));
    }

    //Inicializace funkci
    connect(ui->ButtonAdd, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->ButtonSub, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->ButtonDiv, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->ButtonMul, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->ButtonMod, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->ButtonSqrt, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->ButtonPow, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->ButtonFact, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->ButtonEq, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->ButtonClear, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->ButtonDel, SIGNAL(released()), this, SLOT(ButtonPress()));

}

/*
 *
 */
void MainWindow::ButtonPress()
{
    QPushButton *buttonPress=(QPushButton *)sender();
    QString buttonVal = buttonPress->text();


    if (buttonVal == "0"){
        kalkulacka->Press(IVS::zero);
    }else if(buttonVal == "1"){
        kalkulacka->Press(IVS::one);
    }else if(buttonVal == "2"){
        kalkulacka->Press(IVS::two);
    }else if(buttonVal == "3"){
        kalkulacka->Press(IVS::three);
    }else if(buttonVal == "4"){
        kalkulacka->Press(IVS::four);
    }else if(buttonVal == "5"){
        kalkulacka->Press(IVS::five);
    }else if(buttonVal == "6"){
        kalkulacka->Press(IVS::six);
    }else if(buttonVal == "7"){
        kalkulacka->Press(IVS::seven);
    }else if(buttonVal == "8"){
        kalkulacka->Press(IVS::eight);
    }else if(buttonVal == "9"){
        kalkulacka->Press(IVS::nine);
    }else if(buttonVal == "."){
        kalkulacka->Press(IVS::dot);
    }else if(buttonVal == "π"){
        kalkulacka->Press(IVS::pi);
    }else if(buttonVal == "×"){
        kalkulacka->Press(IVS::multiply);
    }else if(buttonVal == "+"){
        kalkulacka->Press(IVS::plus);
    }else if(buttonVal == "-"){
        kalkulacka->Press(IVS::minus);
    }else if(buttonVal == "/"){
        kalkulacka->Press(IVS::divide);
    }else if(buttonVal == "="){
        kalkulacka->Press(IVS::equals);
    }else if(buttonVal == "^"){
        kalkulacka->Press(IVS::power);
    }else if(buttonVal == "√"){
        kalkulacka->Press(IVS::sqr);
    }else if(buttonVal == "mod"){
        kalkulacka->Press(IVS::mod);
    }else if(buttonVal == "!"){
        kalkulacka->Press(IVS::factorial);
    }else if(buttonVal == "C"){
        kalkulacka->Press(IVS::clear);
    }else if(buttonVal == "Del"){
        kalkulacka->Press(IVS::del);
    }

    //displej s historii
    std::string screenBuffer = kalkulacka->GetHistoryBuffer();
    QString qstr = QString::fromStdString(screenBuffer);
    ui->lineEdit_2->setText(qstr);
    //displej se vstupem
    screenBuffer = kalkulacka->GetScreenBuffer();
    qstr = QString::fromStdString(screenBuffer);
    ui->lineEdit->setText(qstr);

}


/*
 *
 */

MainWindow::~MainWindow()
{
    delete ui;
}

