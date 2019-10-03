#include "counter.h"
#include "QDebug"
#include <math.h>

void Counter::Conversion_From_Mathexpr()
{
    QString digits = "", // stores digits of the number
            function = "", // stores mathematical functions
            warning = "Wrong input!";
    foreach (QChar element, MathExpr) {
        if (element == ',') {
            if (!function.isEmpty()) {
                if (IsPi(function)) {
                    OutVal.push_back(function);
                } else if (FunPriority[function] == 5) {
                    OutExpr.push_back(function);
                } else {
                    throw warning;
                }
                function.clear();
            } else if (!digits.isEmpty()) {
                OutVal.push_back(digits);
                digits.clear();
            }
        } else if (element.isDigit() || IsDot(element)) {
            if (!function.isEmpty()) {
                if (IsPi(function)) {
                    OutVal.push_back(function);
                } else if (FunPriority[function] == 5) {
                    OutExpr.push_back(function);
                } else {
                    throw warning;
                }
                function.clear();
            }
            digits.append(element);
        }
        else if (element.isLetter()) {
            if (!digits.isEmpty()) {
                OutVal.push_back(digits);
                digits.clear();
            }
            function.append(element);
        }
        else if (IsOperation(element)) {
            QString oper;
            oper.append(element);
            if (!function.isEmpty()) {
                if (IsPi(function)) {
                    OutVal.push_back(function);
                } else if ((FunPriority)[function] == 5) {
                    OutExpr.push_back(function);
                } else {
                    throw warning;
                }
                function.clear();
            }
            else if (!digits.isEmpty()) {
                OutVal.push_back(digits);
                digits.clear();
            }

            if (OutExpr.empty()) {
                OutExpr.push_back(oper);
            } else {
                 if (OperPriority[oper] == 6) {
                     while (!OutExpr.empty() &&
                            (OperPriority[OutExpr.back()] > 1 || FunPriority[OutExpr.back()] == 5)) {
                         OutVal.push_back(OutExpr.back());
                         OutExpr.pop_back();
                     }
                     OutExpr.pop_back();
                 } else if (OperPriority[oper] == 1) {
                     OutExpr.push_back(oper);
                 } else if (OperPriority[oper] <= OperPriority[OutExpr.back()] ||
                            FunPriority[OutExpr.back()] == 5) {
                     while (!OutExpr.empty() &&
                            (OperPriority[oper] <= OperPriority[OutExpr.back()] ||
                             FunPriority[OutExpr.back()] == 5)) {
                         OutVal.push_back(OutExpr.back());
                         //qDebug() << OutExpr.back();
                         OutExpr.pop_back();
                     }
                     OutExpr.push_back(oper);
                 } else {
                     OutExpr.push_back(oper);
                 }
             }
        }
    }
    if (!function.isEmpty()) {
        OutVal.push_back(function);
    }
    if (!digits.isEmpty()) {
        OutVal.push_back(digits);
    }
    while (!OutExpr.empty()) {
        OutVal.push_back(OutExpr.back());
        OutExpr.pop_back();
    }

//    foreach (QString str, OutVal) {
//        qDebug() << str;
//    }
}

/// calculating the result
double Counter::Calculate_Result(const QString mathExpr, const Dictionary<QString, int> & priorities)
{
    MathExpr = mathExpr;
    FunPriority = priorities;
    // making the output list of expressions
    Conversion_From_Mathexpr();

    std::vector<double> stack;
    foreach (QString element, OutVal) {
        if (element[0].isDigit()) {
            stack.push_back(element.toDouble());
        } else if (element == "pi") {
            stack.push_back(M_PI);
        } else if (element == "-") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                double b = stack.back();
                stack.pop_back();
                stack.push_back(b - a);
            } else return ErrorValue;
        } else if (element == "+") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                double b = stack.back();
                stack.pop_back();
                stack.push_back(b + a);
            } else return ErrorValue;
        } else if (element == "*") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                double b = stack.back();
                stack.pop_back();
                stack.push_back(b * a);
            } else return ErrorValue;
        } else if (element == "/") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                double b = stack.back();
                stack.pop_back();
                stack.push_back(b / a);
            } else return ErrorValue;
        } else if (element == "^") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                double b = stack.back();
                stack.pop_back();
                stack.push_back(pow(b, a));
            } else return ErrorValue;
        } else if (element == "!") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(tgamma(a + 1));
            } else return ErrorValue;
        } else if (element == "sin") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(sin(a));
            } else return ErrorValue;
        } else if (element == "cos") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(cos(a));
            } else return ErrorValue;
        } else if (element == "tg") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(tan(a));
            } else return ErrorValue;
        } else if (element == "arcsin") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(asin(a));
            } else return ErrorValue;
        } else if (element == "arccos") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(acos(a));
            } else return ErrorValue;
        } else if (element == "arctg") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(atan(a));
            } else return ErrorValue;
        } else if (element == "sh") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(sinh(a));
            } else return ErrorValue;
        } else if (element == "ch") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(cosh(a));
            } else return ErrorValue;
        } else if (element == "th") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(tanh(a));
            } else return ErrorValue;
        } else if (element == "ln") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(log(a));
            } else return ErrorValue;
        } else if (element == "lg") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(log10(a));
            } else return ErrorValue;
        } else if (element == "exp") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(exp(a));
            } else return ErrorValue;
        } else if (element == "sqrt") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                stack.push_back(sqrt(a));
            } else return ErrorValue;
        } else if (element == "log") {
            if (!stack.empty()) {
                double a = stack.back();
                stack.pop_back();
                double b = stack.back();
                stack.pop_back();
                stack.push_back(logarithm(b, a));
            } else return ErrorValue;
        } else if (element == "(" || element == ")") {
            return ErrorValue;
        }
    }

    Result = stack.back();
    stack.clear();

    return Result;
}

double Counter::logarithm(double a, double b)
{
    return log(b)/log(a);
}
