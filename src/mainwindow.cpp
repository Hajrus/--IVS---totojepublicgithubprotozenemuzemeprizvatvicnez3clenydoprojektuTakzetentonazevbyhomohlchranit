#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lib/Math.h"
#include "ivs.h"
#include "operator.h"
#include <string>


IVS::Calculator *kalkulacka; //globalni promenna pro praci s daty kalkulacky


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    kalkulacka = new IVS::Calculator();
    //nastaveni displejů
    ui->lineEdit_2->setText("");
    ui->lineEdit->setText("");
    //inicializace číselníku
    connect(ui->Button0, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->Button1, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->Button2, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->Button3, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->Button4, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->Button5, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->Button6, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->Button7, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->Button8, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->Button9, SIGNAL(released()), this, SLOT(ButtonPress()));
    connect(ui->ButtonDot, SIGNAL(released()), this, SLOT(ButtonPress()));
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


void MainWindow::ButtonPress()
{
    QPushButton *buttonPress=(QPushButton *)sender();
    QString buttonVal = buttonPress->text();

    //Zjisteni, ktere tlacitko byl zmacknuto,
    //nasledne zavolani prislusne funkce
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

    //update displeje s historii
    std::string screenBuffer = kalkulacka->GetHistoryBuffer();
    QString qstr = QString::fromStdString(screenBuffer);
    ui->lineEdit_2->setText(qstr);
    //update displeje se vstupem
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

