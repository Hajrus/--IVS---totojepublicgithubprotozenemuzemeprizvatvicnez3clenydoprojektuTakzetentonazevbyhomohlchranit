#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
/**
 * @file helpdialog.h
 * @author Kliš Michal (xklism00)
 * @author Flek David (xflekd00)
 * @author Široký Ondřej (xsirok09)
 * @author Sladký Jan (xsladk09)
 *
 * @brief Okno s nápovědou
 */
namespace Ui {
class helpdialog;
}

class helpdialog : public QDialog
{
    Q_OBJECT

public:
    explicit helpdialog(QWidget *parent = nullptr);
    ~helpdialog();

private:
    Ui::helpdialog *ui;
};

#endif // HELPDIALOG_H
