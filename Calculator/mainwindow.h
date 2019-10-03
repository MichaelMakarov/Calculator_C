#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "counter.h"
#include <QEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString separator = "\n";
    QString LastSymbol = "0";
    qint32 OpenBrackets, CloseBrackets;
    bool CalculateChecked = false;
    std::vector<QChar> symbols;
    QString ExprInput;

private slots:
    void digits_numbers();
    void simple_functions();
    void standard_functions();
    void on_pushButton_dot_clicked();
    void on_pushButton_backspace_clicked();
    void on_pushButton_AC_clicked();
    void on_pushButton_pi_clicked();
    void on_pushButton_sqr_clicked();
    void brackets();
    void on_pushButton_pow_clicked();
    void on_pushButton_log_clicked();
    void on_pushButton_coma_clicked();
    void on_pushButton_trigonometric_clicked();
    void on_pushButton_result_clicked();
    void refresh_display();

protected:
    void keyPressEvent(QKeyEvent * pe);

    bool isRightBracket(QChar const & c) {
        return c == ')';
    }
    bool isRightBracket(QString const & c) {
        return c == ")";
    }
    bool isLeftBracket(QChar const & c) {
        return c == '(';
    }
    bool isLeftBracket(QString const & c) {
        return c == "(";
    }
    bool isSimpleOperation(QChar const & c) {
        return (c == '+' || c == '-' || c == '/' || c == '*');
    }
    bool isFactorial(QChar const & c) {
        return c == '!';
    }
    bool isDot(QChar const & c) {
        return c == '.';
    }
};

#endif // MAINWINDOW_H
