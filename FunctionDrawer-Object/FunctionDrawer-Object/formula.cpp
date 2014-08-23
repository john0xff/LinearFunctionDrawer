#include "formula.h"
#include "iso8859.h"
#include <GL/gl.h>
#include <GL/glut.h>

Formula::Formula()
{
}

void Formula::drawString(char *str)
{
    while(* str)
        ::glBitmap(8, 16, 0, 0, 8, 0, iso8859_2_8x16_font[(int)(* str++) - 32]);
}

void Formula::linearFormula()
{
    ::glColor3f(1.0, 0.0, 1.0);

    // format upakowania danych map bitowych fontów
    ::glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // pozycja rastra
    ::glRasterPos2f(-8.0, -8.0);

    this->drawString("y = ax + b");
}

void Formula::quadraticFormula()
{
    ::glColor3f(1.0, 0.0, 1.0);

    ::glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    ::glRasterPos2f(-8.0, -8.0);

    this->drawString("y = a(x * x) + bx + c");
}

void Formula::rationalFormula()
{
    ::glColor3f(1.0, 0.0, 1.0);

    ::glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    ::glRasterPos2f(-8.0, -8.0);

    this->drawString("y = (a + b) / x");
}

void Formula::sinusFormula()
{
    ::glColor3f(1.0, 0.0, 1.0);

    ::glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    ::glRasterPos2f(-8.0, -8.0);

    this->drawString("cos(0)  = 0");

    ::glRasterPos2f(-8.0, -9.0);

    this->drawString("cos(90) = 1");
}


void Formula::cosinusFormula()
{
    ::glColor3f(1.0, 0.0, 1.0);

    ::glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    ::glRasterPos2f(-8.0, -8.0);

    this->drawString("cos(0)  = 1");

    ::glRasterPos2f(-8.0, -9.0);

    this->drawString("cos(90) = 0");
}

void Formula::tangensFormula()
{
    ::glColor3f(1.0, 0.0, 1.0);

    ::glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    ::glRasterPos2f(-8.0, -8.0);

    this->drawString("tg(0)  = 0");

    ::glRasterPos2f(-8.0, -9.0);

    this->drawString("tg(90) = -");
}
