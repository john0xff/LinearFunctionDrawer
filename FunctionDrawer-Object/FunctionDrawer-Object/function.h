#ifndef FUNCTION_H
#define FUNCTION_H

enum
{
    linearFunction,
    quadraticFunction,
    rationalFunction,
    sinusFunction,
    cosinusFunction,
    tangensFunction,
    clearScreen
};

class Function
{
private:
    double _y;
    double _x;
    double _y_1;
    double _x_1;

    double _a;
    double _b;
    double _c;

    double _counterPoints;
    char _buffer[256];

public:
    Function();
    ~Function();

    void linearFuncDrawer();
    void quadraticFuncDrawer();
    void rationalFuncDrawer();
    void sinusFuncDrawer();
    void cosinusFuncDrawer();
    void tangensFuncDrawer();

    void showFuncInfo(int object);
    void clearScreen();

    void updateValueA(double a);
    void updateValueB(double b);
    void updateValueC(double c);
};

#endif // FUNCTION_H
