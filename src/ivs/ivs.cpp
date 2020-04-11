#include "ivs.h"
#include "ui_ivs.h"

ivs::ivs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ivs)
{
    ui->setupUi(this);
}

ivs::~ivs()
{
    delete ui;
}
