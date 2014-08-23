#ifndef FORMULA_H
#define FORMULA_H

class Formula
{
private:
    char buffer[256];

public:
    Formula();

    void drawString(char *str);

    void linearFormula();
    void quadraticFormula();
    void rationalFormula();
    void sinusFormula();
    void cosinusFormula();
    void tangensFormula();

};

#endif // FORMULA_H
