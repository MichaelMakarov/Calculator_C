#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include "additionalfunctions.h"
#include "QDebug"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OpenBrackets = 0;
    CloseBrackets = 0;
    //setup the correct symbols
    ui->pushButton_sqrt->setText(QString::fromUtf8("\u221A"));
    ui->pushButton_pi->setText(QString::fromUtf8("\u03c0"));
    ui->pushButton_arcsin->setVisible(false);
    ui->pushButton_arccos->setVisible(false);
    ui->pushButton_arctg->setVisible(false);
    ui->pushButton_sinh->setVisible(false);
    ui->pushButton_cosh->setVisible(false);
    ui->pushButton_th->setVisible(false);

    // connection with refreshing a display
    connect(ui->pushButton_zero, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_one, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_two, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_three, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_four, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_five, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_six, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_seven, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_eight, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_nine, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_backspace, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_lg, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_sqr, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_tenpower, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_tg, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_sinh, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_cosh, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_th, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_arcsin, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_arccos, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_arctg, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_leftbracket, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_rightbracket, SIGNAL(clicked()), this, SLOT(refresh_display()));
    connect(ui->pushButton_factorial, SIGNAL(clicked()), this, SLOT(refresh_display()));

    // connection with displaying digits function
    connect(ui->pushButton_zero, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_one, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_two, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_three, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_four, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_five, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_six, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_seven, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_eight, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_nine, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    // connection with displaying simple functions
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(simple_functions()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(simple_functions()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(simple_functions()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(simple_functions()));
    connect(ui->pushButton_factorial, SIGNAL(clicked()), this, SLOT(simple_functions()));

    // connection with displaying standard functions
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_lg, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_tenpower, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_tg, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_arcsin, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_arccos, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_arctg, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_sinh, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_cosh, SIGNAL(clicked()), this, SLOT(standard_functions()));
    connect(ui->pushButton_th, SIGNAL(clicked()), this, SLOT(standard_functions()));

    // connection with displaying brackets
    connect(ui->pushButton_rightbracket, SIGNAL(clicked()), this, SLOT(brackets()));
    connect(ui->pushButton_leftbracket, SIGNAL(clicked()), this, SLOT(brackets()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// displays digits
void MainWindow::digits_numbers() {
    QPushButton *button_sender = (QPushButton *) sender();
    if (ui->display->text()[ui->display->text().length() - 1] ==
            ui->pushButton_pi->text()[ui->pushButton_pi->text().length() - 1] ||
            isRightBracket(ui->display->text()[ui->display->text().length() - 1])) {
        ui->display->setText(ui->display->text() + "*" + button_sender->text());
        separator = "*";
    } else if (ui->display->text() == "0")
        ui->display->setText(button_sender->text());
    else
        ui->display->setText(ui->display->text() + button_sender->text());
}

// displays dot
void MainWindow::on_pushButton_dot_clicked()
{
    if (ui->display->text().split(separator).last().length() == 0) {
        ui->display->setText(ui->display->text() + "0.");
    } else if (!ui->display->text().split(separator).last().contains('.')) {
        ui->display->setText(ui->display->text() + ".");
    }

}

// changes signum of the expression
void MainWindow::on_pushButton_backspace_clicked()
{
    if (ui->display->text().length() == 1) {
        if (ui->display->text()[ui->display->text().length() - 1] == '(') {
            OpenBrackets--;
        }
        ui->display->setText("0");
    } else {
        if (ui->display->text()[ui->display->text().length() - 1] == '(') {
            OpenBrackets--;
        }
        if (ui->display->text()[ui->display->text().length() - 1] == ')') {
            CloseBrackets--;
        }
        ui->display->setText(ui->display->text().remove(ui->display->text().length() - 1, 1));
    }
}

// erases the display
void MainWindow::on_pushButton_AC_clicked()
{
    ui->display->setEnabled(true);
    ui->display->setText("0");
    CloseBrackets = 0;
    OpenBrackets = 0;
}

void MainWindow::simple_functions()
{
    QPushButton * button_sender = (QPushButton *) sender();
    QString text = ui->display->text();
    if (text[text.size() - 1] == '(') {
        if (button_sender->text() == "+") {
            ui->display->setText(text + "0" + button_sender->text());
        } else if (button_sender->text() == "*" || button_sender->text() == "/") {
            ui->display->setText(text + "1" + button_sender->text());
        } else {
            ui->display->setText(text + button_sender->text());
        }
    } else if (text[text.size() - 1] == '+' ||
               text[text.size() - 1] == '-' ||
               text[text.size() - 1] == '/' ||
               text[text.size() - 1] == '*') {
        text.remove(text.length() - 1, 1);
        ui->display->setText(text + button_sender->text());
    } else if (text[text.size() - 1] == '.') {
        ui->display->setText(text + "0" + button_sender->text());
    } else {
        ui->display->setText(text + button_sender->text());
    }
    separator = button_sender->text();
}

void MainWindow::on_pushButton_pi_clicked()
{
    QPushButton * button_sender = (QPushButton *) sender();
    if (ui->display->text() == "0") {
        ui->display->setText(button_sender->text());
    } else if (ui->display->text()[ui->display->text().length() - 1].isDigit() ||
            isRightBracket(ui->display->text()[ui->display->text().length() - 1])) {
        ui->display->setText(ui->display->text() + "*" + button_sender->text());
        separator = "*";
    } else if (ui->display->text()[ui->display->text().length() - 1] == '.') {
        ui->display->setText(ui->display->text() + "0*" + button_sender->text());
        separator = "*";
    } else {
        ui->display->setText(ui->display->text() + button_sender->text());
    }
}

void MainWindow::on_pushButton_sqr_clicked()
{
    QPushButton * button_sender = (QPushButton *) sender();
    if (ui->display->text()[ui->display->text().length() - 1].isDigit() ||
            isRightBracket(ui->display->text()[ui->display->text().length() - 1]) ||
            isFactorial(ui->display->text()[ui->display->text().length() - 1]) ||
            ui->display->text().split(separator).last() == ui->pushButton_pi->text()) {
        ui->display->setText(ui->display->text() + button_sender->text() + "*");
        separator = "*";
    } else if (isSimpleOperation(ui->display->text()[ui->display->text().length() - 1])) {
        ui->display->setText(ui->display->text().remove(ui->display->text().length() - 1, 1) + button_sender->text());
        separator = button_sender->text();
    }
}

void MainWindow::brackets()
{
    QPushButton * button_sender = (QPushButton *) sender();
    if (isLeftBracket(button_sender->text())) {
        if (ui->display->text() == "0") {
            ui->display->setText(button_sender->text());
            separator = "(";
            OpenBrackets++;
        } else if (ui->display->text()[ui->display->text().length() - 1].isDigit()) {
            ui->display->setText(ui->display->text() + "*" + button_sender->text());
            separator = button_sender->text();
            OpenBrackets++;
        } else if (isDot(ui->display->text()[ui->display->text().length() - 1])) {
            ui->display->setText(ui->display->text() + "0*(");
            separator = button_sender->text();
            OpenBrackets++;
        } else if (isLeftBracket(ui->display->text()[ui->display->text().length() - 1])) {
            ui->display->setText(ui->display->text() + button_sender->text());
            separator = button_sender->text();
            OpenBrackets++;
        } else if (isRightBracket(ui->display->text()[ui->display->text().length() - 1])) {
            ui->display->setText(ui->display->text() + "*(");
            separator = button_sender->text();
            OpenBrackets++;
        } else if (isSimpleOperation(ui->display->text()[ui->display->text().length() - 1])) {
            ui->display->setText(ui->display->text() + button_sender->text());
            separator = button_sender->text();
            OpenBrackets++;
        }
    } else if (OpenBrackets > CloseBrackets) {
        if (isFactorial(ui->display->text()[ui->display->text().length() - 1]) ||
                ui->display->text()[ui->display->text().length() - 1].isDigit() ||
                isRightBracket(ui->display->text()[ui->display->text().length() - 1])) {
            ui->display->setText(ui->display->text() + button_sender->text());
            CloseBrackets++;
            separator = button_sender->text();
        } else if (isDot(ui->display->text()[ui->display->text().length() - 1])) {
            ui->display->setText(ui->display->text() + "0)");
            CloseBrackets++;
            separator = button_sender->text();
        } else if (isLeftBracket(ui->display->text()[ui->display->text().length() - 1])) {
            ui->display->setText(ui->display->text() + "0)");
            CloseBrackets++;
            separator = button_sender->text();
        }
    }
}

void MainWindow::standard_functions()
{
    QPushButton * button_sender = (QPushButton *) sender();
    if (ui->display->text() == "0" || ui->display->text().isEmpty()) {
        ui->display->setText(button_sender->text() + "(");
        separator = "(";
        OpenBrackets++;
    } else if (isFactorial(ui->display->text()[ui->display->text().length() - 1]) ||
            ui->display->text()[ui->display->text().length() - 1].isDigit() ||
            isRightBracket(ui->display->text()[ui->display->text().length() - 1])) {
        ui->display->setText(ui->display->text() + "*" + button_sender->text() + "(");
        separator = "(";
        OpenBrackets++;
    } else if (isSimpleOperation(ui->display->text()[ui->display->text().length() - 1]) ||
               isLeftBracket(ui->display->text()[ui->display->text().length() - 1])) {
        ui->display->setText(ui->display->text() + button_sender->text() + "(");
        separator = "(";
        OpenBrackets++;
    } else if (isDot(ui->display->text()[ui->display->text().length() - 1])) {
        ui->display->setText(ui->display->text() + "0*" + button_sender->text() + "(");
        separator = "(";
        OpenBrackets++;
    }
}

void MainWindow::on_pushButton_pow_clicked()
{
    QPushButton * button_sender = (QPushButton *) sender();
    if (ui->display->text()[ui->display->text().length() - 1].isDigit() ||
            isFactorial(ui->display->text()[ui->display->text().length() - 1]) ||
            isRightBracket(ui->display->text()[ui->display->text().length() - 1])) {
        ui->display->setText(ui->display->text() + button_sender->text() + "(");
        separator = "(";
        OpenBrackets++;
    } else if (isSimpleOperation(ui->display->text()[ui->display->text().length() - 1])) {
        ui->display->setText(ui->display->text().remove(ui->display->text().length() - 1, 1) + button_sender->text() + "(");
        separator = "(";
        OpenBrackets++;
    }
}

void MainWindow::on_pushButton_log_clicked()
{
    QPushButton * button_sender = (QPushButton *) sender();
    if (ui->display->text() == "0") {
        ui->display->setText(button_sender->text() + "(");
        separator = "(";
        OpenBrackets++;
    } else if (ui->display->text()[ui->display->text().length() - 1].isDigit() ||
            isFactorial(ui->display->text()[ui->display->text().length() - 1]) ||
            isRightBracket(ui->display->text()[ui->display->text().length() - 1])) {
        ui->display->setText(ui->display->text() + "*" + button_sender->text() + "(");
    } else if (isSimpleOperation(ui->display->text()[ui->display->text().length() - 1]) ||
              isLeftBracket(ui->display->text()[ui->display->text().length() - 1])) {
       ui->display->setText(ui->display->text() + button_sender->text() + "(");
       separator = "(";
       OpenBrackets++;
   } else if (isDot(ui->display->text()[ui->display->text().length() - 1])) {
       ui->display->setText(ui->display->text() + "0*" + button_sender->text() + "(");
       separator = "(";
       OpenBrackets++;
   }
}

void MainWindow::on_pushButton_coma_clicked()
{
    ui->display->setText(ui->display->text() + ",");
}

void MainWindow::on_pushButton_trigonometric_clicked()
{
    if (ui->pushButton_sin->isVisible()) {
        ui->pushButton_sin->setVisible(false);
        ui->pushButton_cos->setVisible(false);
        ui->pushButton_tg->setVisible(false);
        ui->pushButton_arcsin->setVisible(true);
        ui->pushButton_arccos->setVisible(true);
        ui->pushButton_arctg->setVisible(true);
    } else if (ui->pushButton_arcsin->isVisible()) {
        ui->pushButton_arcsin->setVisible(false);
        ui->pushButton_arccos->setVisible(false);
        ui->pushButton_arctg->setVisible(false);
        ui->pushButton_sinh->setVisible(true);
        ui->pushButton_cosh->setVisible(true);
        ui->pushButton_th->setVisible(true);
    } else if (ui->pushButton_sinh->isVisible()) {
        ui->pushButton_sin->setVisible(true);
        ui->pushButton_cos->setVisible(true);
        ui->pushButton_tg->setVisible(true);
        ui->pushButton_sinh->setVisible(false);
        ui->pushButton_cosh->setVisible(false);
        ui->pushButton_th->setVisible(false);
    }
}


void MainWindow::on_pushButton_result_clicked()
{
    if (OpenBrackets > CloseBrackets) {
        QString str = "";
        auto difference = OpenBrackets - CloseBrackets;
        for (auto index = 0; index < difference; ++index) {
            emit ui->pushButton_rightbracket->clicked(true);
        }
        ui->display->setText(ui->display->text() + str);
    }
    if (CalculateChecked) return;
    QString text = ui->display->text();
    text.replace(ui->pushButton_sqrt->text(), "sqrt", Qt::CaseSensitive);
    text.replace(ui->pushButton_pi->text(), "pi", Qt::CaseSensitive);
    Dictionary<QString, int> functions;
    functions.Add("exp", 5);
    functions.Add("ln", 5);
    functions.Add("lg", 5);
    functions.Add("sqrt", 5);
    functions.Add("sin", 5);
    functions.Add("cos", 5);
    functions.Add("tg", 5);
    functions.Add("arcsin", 5);
    functions.Add("arccos", 5);
    functions.Add("arctg", 5);
    functions.Add("sh", 5);
    functions.Add("ch", 5);
    functions.Add("th", 5);
    functions.Add("log", 5);

    Counter counter;
    double accurate = counter.Calculate_Result(text, functions);
    if (accurate == counter.ErrorValue) {
        ui->display->setText(ui->display->text() + "\n Wrong input");
    } else {
        int rounded = accurate;
        if (accurate == rounded) {
            ui->display->setText(ui->display->text() + "\n= " + QString::fromStdString(std::to_string(rounded)));
        } else {
            ui->display->setText(ui->display->text() + "\n= " + QString::fromStdString(std::to_string(accurate)));
        }
    }

    CalculateChecked = true;
}

void MainWindow::refresh_display()
{
    ui->display->setText(ui->display->text().split("\n").first());
    CalculateChecked = false;
}

void MainWindow::keyPressEvent(QKeyEvent *pe)
{
    switch (pe->key()) {
    case Qt::Key_0:
        emit ui->pushButton_zero->clicked(true);
        break;
    case Qt::Key_1:
        emit ui->pushButton_one->clicked(true);
        break;
    case Qt::Key_2:
        emit ui->pushButton_two->clicked(true);
        break;
    case Qt::Key_3:
        emit ui->pushButton_three->clicked(true);
        break;
    case Qt::Key_4:
        emit ui->pushButton_four->clicked(true);
        break;
    case Qt::Key_5:
        emit ui->pushButton_five->clicked(true);
        break;
    case Qt::Key_6:
        emit ui->pushButton_six->clicked(true);
        break;
    case Qt::Key_7:
        emit ui->pushButton_seven->clicked(true);
        break;
    case Qt::Key_8:
        emit ui->pushButton_eight->clicked(true);
        break;
    case Qt::Key_9:
        emit ui->pushButton_nine->clicked(true);
        break;
    case Qt::Key_Exclam: ///////
        emit ui->pushButton_factorial->clicked(true);
        break;
    case Qt::Key_Plus:
        emit ui->pushButton_plus->clicked(true);
        break;
    case Qt::Key_Minus:
        emit ui->pushButton_minus->clicked(true);
        break;
    case Qt::Key_Slash:
        emit ui->pushButton_divide->clicked(true);
        break;
    case Qt::Key_Asterisk:
        emit ui->pushButton_mult->clicked(true);
        break;
    case Qt::Key_Backspace:
        emit ui->pushButton_backspace->clicked(true);
        break;
    case Qt::Key_Return:
        emit ui->pushButton_result->clicked(true);
        break;
    case Qt::Key_Equal:
        emit ui->pushButton_result->clicked(true);
        break;
    case 94:
        emit ui->pushButton_pow->clicked(true);
        break;
    case 46:
        emit ui->pushButton_dot->clicked(true);
        break;
    case Qt::Key_ParenLeft:
        emit ui->pushButton_leftbracket->clicked(true);
        break;
    case Qt::Key_ParenRight:
        emit ui->pushButton_rightbracket->clicked(true);
        break;
    case Qt::Key_Comma:
        emit ui->pushButton_coma->clicked(true);
        break;
    case Qt::Key_Delete:
        emit ui->pushButton_AC->clicked(true);
        break;
    case Qt::Key_Q:
        emit ui->pushButton_sqr->clicked(true);
        break;
    case Qt::Key_A:
        emit ui->pushButton_sqrt->clicked(true);
        break;
    case Qt::Key_Z:
        emit ui->pushButton_sin->clicked(true);
        break;
    case Qt::Key_W:
        emit ui->pushButton_pow->clicked(true);
        break;
    case Qt::Key_S:
        emit ui->pushButton_log->clicked(true);
        break;
    case Qt::Key_X:
        emit ui->pushButton_cos->clicked(true);
        break;
    case Qt::Key_E:
        emit ui->pushButton_exp->clicked(true);
        break;
    case Qt::Key_D:
        emit ui->pushButton_ln->clicked(true);
        break;
    case Qt::Key_C:
        emit ui->pushButton_tg->clicked(true);
        break;
    case Qt::Key_R:
        emit ui->pushButton_tenpower->clicked(true);
        break;
    case Qt::Key_F:
        emit ui->pushButton_lg->clicked(true);
        break;
    }
}
