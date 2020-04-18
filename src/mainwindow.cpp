#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lib/Math.h"

/*
 *
 */
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

/*
 *
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //nastaveni displejů
    ui->textBrowser->setText("");
    ui->lineEdit->setText(QString::number(outputVal));
    //inicializace číselníku
    QString butName;
    QPushButton *nmbrButtons[11];
    for(int i=0; i<11; i++)
    {
        if (i == 10)
        {
            QString butName = "ButtonDot";
            nmbrButtons[i]=MainWindow::findChild<QPushButton *>(butName);
            connect(nmbrButtons[i], SIGNAL(released()), this, SLOT(NmbrPress()));
        }
        QString butName = "Button" + QString::number(i);
        nmbrButtons[i]=MainWindow::findChild<QPushButton *>(butName);
        connect(nmbrButtons[i], SIGNAL(released()), this, SLOT(NmbrPress()));
    }

    //Inicializace funkci
    connect(ui->ButtonAdd, SIGNAL(released()), this, SLOT(OperationPress()));
    connect(ui->ButtonSub, SIGNAL(released()), this, SLOT(OperationPress()));
    connect(ui->ButtonDiv, SIGNAL(released()), this, SLOT(OperationPress()));
    connect(ui->ButtonMul, SIGNAL(released()), this, SLOT(OperationPress()));
    connect(ui->ButtonMod, SIGNAL(released()), this, SLOT(OperationPress()));
    connect(ui->ButtonSqrt, SIGNAL(released()), this, SLOT(OperationPress()));
    connect(ui->ButtonPow, SIGNAL(released()), this, SLOT(OperationPress()));
    connect(ui->ButtonFact, SIGNAL(released()), this, SLOT(FactPress()));
    connect(ui->ButtonEq, SIGNAL(released()), this, SLOT(EqualPress()));
    connect(ui->ButtonClear, SIGNAL(released()), this, SLOT(ClearPress()));
    connect(ui->ButtonBack, SIGNAL(released()), this, SLOT(BackPress()));

}

/*
 *
 */
void MainWindow::NmbrPress()
{
    QPushButton *buttonPress=(QPushButton *)sender();
    QString buttonVal = buttonPress->text();
    QString editText = ui->lineEdit->text();
    double newNumber = editText.toDouble();
    if((buttonVal == ".") && (dotPresed == false)) //pokud zmackne tecku a tecka jeste nebyla zmacknuta, tak toto:
    {
        dotPresed = true;

        editText = editText + buttonVal;
        newNumber = editText.toDouble();
        ui->lineEdit->setText(editText);
        if (opPressed == false) //pokud byl zadan operator, ukladej do druhe promenne
        {
            firstVal = newNumber;
        }
        else
        {
            secondVal = newNumber;
        }
    }
    else if (editText.toDouble() == 0)
    {
        ui->lineEdit->setText(buttonVal);
        editText = editText + buttonVal;
        newNumber = editText.toDouble();
        if (opPressed == false) //pokud byl zadan operator, ukladej do druhe promenne
        {
            firstVal = newNumber;
        }
        else
        {
            secondVal = newNumber;
        }
    }
    else if ((0 < buttonVal.toDouble()) && (buttonVal.toDouble() < 10))
    {
        editText = editText + buttonVal;
        newNumber = editText.toDouble();
        ui->lineEdit->setText(QString::number(newNumber, 'g', 16));
        if (opPressed == false) //pokud byl zadan operator, ukladej do druhe promenne
        {
            firstVal = newNumber;
        }
        else
        {
            secondVal = newNumber;
        }
    }
    ui->textBrowser->setText(QString::number(newNumber));

}

/*
 *
 */
void MainWindow::OperationPress()
{

}

/*
 *
 */
void MainWindow::FactPress()
{

}

/*
 *
 */
void MainWindow::EqualPress()
{

}

/*
 *
 */
void MainWindow::ClearPress()
{

}

/*
 *
 */
void MainWindow::BackPress()
{

}

/*
 *
 */

MainWindow::~MainWindow()
{
    delete ui;
}

