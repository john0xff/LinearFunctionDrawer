#include "function.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>


Function::Function()
{
    this->_a = 0.0;
    this->_b = 0.0;
    this->_c = 0.0;

    this->_counterPoints = 0.0;
}

Function::~Function()
{

}

void Function::linearFuncDrawer()
{
    this->_counterPoints = 0;

    for(this->_x = -20; this->_x < 20; this->_x += 0.01)
    {
        this->_y = this->_a * this->_x + this->_b;

        ::glPushMatrix();
        ::glBegin(GL_LINES);

        ::glColor3f(0.0, 1.0, 0.0);

        ::glVertex2f(this->_x, this->_y);

        for(this->_x_1 = this->_x + 0.01; this->_x_1 < this->_x + 0.02; this->_x_1 += 0.01)
        {
            this->_y_1 = this->_a * this->_x_1 + this->_b;

            ::glVertex2f(this->_x_1, this->_y_1);
        }

        ::glEnd();
        ::glPopMatrix();

        this->_counterPoints++;
    }
}

void Function::quadraticFuncDrawer()
{
    this->_counterPoints = 0;

    for(this->_x = -20; this->_x < 20; this->_x += 0.01)
    {
        this->_y = this->_a * (this->_x * this->_x) + this->_b * this->_x + this->_c;

        ::glPushMatrix();
        ::glPointSize(4.0);
        ::glBegin(GL_LINES);

        ::glColor3f(0.0, 1.0, 0.0);

        ::glVertex2f(this->_x, this->_y);

        for(this->_x_1 = this->_x + 0.01; this->_x_1 < this->_x + 0.02; this->_x_1 += 0.01)
        {
            this->_y_1 = this->_a * (this->_x_1 * this->_x_1) + this->_b * this->_x_1 + this->_c;

            ::glVertex2f(this->_x_1, this->_y_1);
        }

        ::glEnd();
        ::glPopMatrix();

        this->_counterPoints++;
    }
}

void Function::rationalFuncDrawer()
{
    this->_counterPoints = 0;

    for(this->_x = -20; this->_x < 20; this->_x += 0.001)
    {
        this->_y = this->_a + this->_b / this->_x;

        ::glPushMatrix();
        ::glPointSize(1.0);
        ::glBegin(GL_POINTS);

        ::glColor3f(0.0, 1.0, 0.0);

        ::glVertex2f(this->_x, this->_y);

        for(this->_x_1 = this->_x + 0.01; this->_x_1 < this->_x + 0.02; this->_x_1 += 0.01)
        {
            this->_y_1 = this->_a + this->_b / this->_x_1;

            ::glVertex2f(this->_x_1, this->_y_1);
        }

        ::glEnd();
        ::glPopMatrix();

        this->_counterPoints++;
    }
}

void Function::sinusFuncDrawer()
{
    this->_counterPoints = 0;

    for(this->_x = -6.283 * 2; this->_x < 6.283 * 2; this->_x += 0.001)
    {
        this->_y = ::sin(this->_x);

        ::glPushMatrix();
        ::glPointSize(1.0);
        ::glBegin(GL_POINTS);

        ::glColor3f(0.0, 1.0, 0.0);

        ::glVertex2f(this->_x, this->_y);

        ::glEnd();
        ::glPopMatrix();

        this->_counterPoints++;
    }
}

void Function::cosinusFuncDrawer()
{
    this->_counterPoints = 0;

    for(this->_x = -6.283 * 2; this->_x < 6.283 * 2; this->_x += 0.001)
    {
        this->_y = ::cos(this->_x);

        ::glPushMatrix();
        ::glPointSize(1.0);
        ::glBegin(GL_POINTS);

        ::glColor3f(0.0, 1.0, 0.0);

        ::glVertex2f(this->_x, this->_y);

        ::glEnd();
        ::glPopMatrix();

        this->_counterPoints++;
    }
}

void Function::tangensFuncDrawer()
{
    this->_counterPoints = 0;

    for(this->_x = -6.283 * 2; this->_x < 6.283 * 2; this->_x += 0.001)
    {
        this->_y = ::tan(this->_x);

        ::glPushMatrix();
        ::glPointSize(1.0);
        ::glBegin(GL_POINTS);

        ::glColor3f(0.0, 1.0, 0.0);

        ::glVertex2f(this->_x, this->_y);

        ::glEnd();
        ::glPopMatrix();

        this->_counterPoints++;
    }
}

void Function::showFuncInfo(int object)
{
    switch(object)
    {
        case linearFunction:
            ::sprintf(this->_buffer, "F(x) = %f * x + %f, counterPoints = %f ", this->_a, this->_b, this->_counterPoints);
            ::glutSetWindowTitle(this->_buffer);
            break;

        case quadraticFunction:
            ::sprintf(this->_buffer, "F(x) = %fx2 + %fx + %f, counterPoints = %f ", this->_a, this->_b, this->_c, this->_counterPoints);
            ::glutSetWindowTitle(this->_buffer);
            break;

        case rationalFunction:
            ::sprintf(this->_buffer, "F(x) = %f + %f / x, counterPoints = %f ", this->_a, this->_b, this->_counterPoints);
            ::glutSetWindowTitle(this->_buffer);
            break;

        case sinusFunction:
            ::sprintf(this->_buffer, "Sinus, counterPoints = %f ", this->_counterPoints);
            ::glutSetWindowTitle(this->_buffer);
            break;

        case cosinusFunction:
            ::sprintf(this->_buffer, "Cosinus, counterPoints = %f ", this->_counterPoints);
            ::glutSetWindowTitle(this->_buffer);
            break;

        case tangensFunction:
            ::sprintf(this->_buffer, "Tangens, counterPoints = %f ", this->_counterPoints);
            ::glutSetWindowTitle(this->_buffer);
            break;
    }
}

void Function::clearScreen()
{
    this->_a = 0.0;
    this->_b = 0.0;
    this->_c = 0.0;
}

void Function::updateValueA(double a)
{
    if(a == 0.01)
        this->_a += a;

    else if(a == -0.01)
        this->_a -= -a;
}

void Function::updateValueB(double b)
{
    if(b == 0.01)
        this->_b += b;

    else if(b == -0.01)
        this->_b -= -b;
}

void Function::updateValueC(double c)
{
    if(c == 0.01)
        this->_c += c;

    else if(c == -0.01)
        this->_c -= -c;
}
