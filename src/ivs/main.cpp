#include "ivs.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ivs w;
    w.show();

    return a.exec();
}
