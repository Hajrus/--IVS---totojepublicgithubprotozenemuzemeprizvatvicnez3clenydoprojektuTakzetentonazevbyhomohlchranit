#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
/**
 * @file maniwindow.h
 * @author Kliš Michal (xklism00)
 * @author Flek David (xflekd00)
 * @author Široký Ondřej (xsirok09)
 * @author Sladký Jan (xsladk09)
 *
 * @brief mainwindow třídní hlavičkový soubor - uvládání UI
 */

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * Třída MainWindow
 *
 * @brief Třída MainWindow - Řízení GUI
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow
     * Konstruktor
     * @param rodič
     * @return MainWindow
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief ~MainWindow
     * Destruktor
     */
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    /**
     * @brief AsciiToSqrt
     * Dostane string a vrátí QString s vloženým znakem "√", pokud byl zadán
     * @param String pro převedení
     * @return Převedený QString
     */
    QString AsciiToSqrt(std::string str);

private slots:
    /**
     * @brief ButtonPress
     * Zachytí stisknutí talčítka na kalkulačce
     */
    void ButtonPress();

};
#endif // MAINWINDOW_H
