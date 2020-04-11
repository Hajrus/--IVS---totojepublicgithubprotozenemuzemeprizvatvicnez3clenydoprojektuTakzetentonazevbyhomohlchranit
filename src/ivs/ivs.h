#ifndef IVS_H
#define IVS_H

#include <QMainWindow>

namespace Ui {
class ivs;
}

class ivs : public QMainWindow
{
    Q_OBJECT

public:
    explicit ivs(QWidget *parent = 0);
    ~ivs();

private:
    Ui::ivs *ui;
};

#endif // IVS_H
