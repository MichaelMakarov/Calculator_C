#ifndef COUNTER_H
#define COUNTER_H
#include "QString"
#include <vector>
#include "additionalfunctions.h"
#include <qmath.h>

class Counter
{
private:

    // stack which will be consist of the variables and mathematical actions
    std::vector<QString> OutVal;
    std::vector<QString> OutExpr;
    // stores the information about mathematical actions priority
    Dictionary<QString, int> OperPriority;
    // mathematical expression that should be calculated
    QString MathExpr = "";
    Dictionary<QString, int> FunPriority;

    // converts from string to stack in polsky postfix type
    void Conversion_From_Mathexpr();

    /// additional usefull functions
    bool IsDot(const QChar str) { return str == '.'; }
    bool IsOperation(const QChar str)
    {
        return (str == '(' || str == ')' || str == '+' || str == '-' || str == '*' || str == '/' || str == '^' || str == '!');
    }
    bool IsPi(const QString str) { return "pi" == str; }

    // calculates an arbitrary logarithm
    double logarithm(double a, double b);

    // calculates factorial
    double factorial(double a);

public:
    /// here is the result of the calculations
    double Result = 0;

    // default return value
    double ErrorValue = 0.123456789;

    Counter() {
        OperPriority.Add("(", 1);
        OperPriority.Add("-", 2);
        OperPriority.Add("+", 2);
        OperPriority.Add("/", 3);
        OperPriority.Add("*", 3);
        OperPriority.Add("^", 4);
        OperPriority.Add("!", 5);
        OperPriority.Add(")", 6);
    }

    ~Counter() { MathExpr.clear(); OutVal.clear(); OutExpr.clear(); }

    QString math_expression() { return MathExpr; }

    // calculates the result
    double Calculate_Result(const QString mathExpr, const Dictionary<QString,int> & priorities);

};

#endif // COUNTER_H
