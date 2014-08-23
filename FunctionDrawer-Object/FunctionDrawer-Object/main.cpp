#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "function.h"
#include "formula.h"


int object = linearFunction;

double const lenghtCoordinateX = 10.0;
double const lenghtCoordinateY = 10.0;

Function funcDrawer;
Formula funcFormula;



void CoordiateSystemDrawer()
{
    glPushMatrix();
    glBegin(GL_LINES);

        // X axis
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-lenghtCoordinateX, 0.0);
        glVertex2f(lenghtCoordinateX, 0.0);

        // Y axis
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, -lenghtCoordinateY);
        glVertex2f(0.0, lenghtCoordinateY);

    glEnd();
    glPopMatrix();
}

void Display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    {
        CoordiateSystemDrawer();

        switch(object)
        {
            case linearFunction:
                funcDrawer.linearFuncDrawer();
                funcFormula.linearFormula();
                break;

            case quadraticFunction:
                funcDrawer.quadraticFuncDrawer();
                funcFormula.quadraticFormula();
                break;

            case rationalFunction:
                funcDrawer.rationalFuncDrawer();
                funcFormula.rationalFormula();
                break;

            case sinusFunction:
                funcDrawer.sinusFuncDrawer();
                funcFormula.sinusFormula();
                break;

            case cosinusFunction:
                funcDrawer.cosinusFuncDrawer();
                funcFormula.cosinusFormula();
                break;

            case tangensFunction:
                funcDrawer.tangensFuncDrawer();
                funcFormula.tangensFormula();
                break;

            case clearScreen:
                funcDrawer.clearScreen();
                object = linearFunction;
                break;
        }

        funcDrawer.showFuncInfo(object);
    }
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-lenghtCoordinateX, lenghtCoordinateX, -lenghtCoordinateY, lenghtCoordinateY);
}

char keys[256];

void keyDown(unsigned char key, int width, int height)
{
    keys[key] = true;
}

void keyUp(unsigned char key, int width, int height)
{
    keys[key] = false;
}

void updateCamera()
{
    if(keys['1'])
        funcDrawer.updateValueA(0.01);

    if(keys['2'])
        funcDrawer.updateValueA(-0.01);

    if(keys['3'])
        funcDrawer.updateValueB(0.01);

    if(keys['4'])
        funcDrawer.updateValueB(-0.01);

    if(keys['5'] && object == quadraticFunction)
        funcDrawer.updateValueC(0.01);

    if(keys['6'] && object == quadraticFunction)
        funcDrawer.updateValueC(-0.01);
}

void idle()
{
    updateCamera();

    glutPostRedisplay();

    Sleep(10);
}

void menu(int choiceFunction)
{
    switch(choiceFunction)
    {
        case linearFunction:
        {
            object = linearFunction;
            Display();
        }
        break;

        case quadraticFunction:
        {
            object = quadraticFunction;
            Display();
        }
        break;

        case rationalFunction:
        {
            object = rationalFunction;
            Display();
        }
        break;

        case sinusFunction:
        {
            object = sinusFunction;
            Display();
        }
        break;

        case cosinusFunction:
        {
            object = cosinusFunction;
            Display();
        }
        break;

        case tangensFunction:
        {
            object = tangensFunction;
            Display();
        }
        break;

        case clearScreen:
        {
            object = clearScreen;
            Display();
        }
        break;
    }
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutCreateWindow("FunctionDrawer");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);

    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);

    glutCreateMenu(menu);
    glutAddMenuEntry("linearFunction", linearFunction);
    glutAddMenuEntry("quadraticFunction", quadraticFunction);
    glutAddMenuEntry("rationalFunction", rationalFunction);
    glutAddMenuEntry("sinusFunction", sinusFunction);
    glutAddMenuEntry("cosinusFunction", cosinusFunction);
    glutAddMenuEntry("tangensFunction", tangensFunction);
    glutAddMenuEntry("clear", clearScreen);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutIdleFunc(idle);

    glutMainLoop();

    funcDrawer.~Function();
    return 0;
}
