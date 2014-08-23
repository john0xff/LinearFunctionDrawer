#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <windows.h>
#include <math.h>

enum
{
    linearFunction,
    quadraticFunction,
    rationalFunction,
    cosinusFunction,
    clearScreen
};

int object = linearFunction;

double _lenghtCoordinateX = 10.0;
double _lenghtCoordinateY = 10.0;

char buffer[256];

double y;
double x;
double y_1;
double x_1;

double a = 0.0;
double b = 0.0;
double c = 0.0;

double counterPoints = 0;

void updateCamera();


void CoordiateSystemDrawer()
{
    glPushMatrix();
    glBegin(GL_LINES);

        // X axis
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-_lenghtCoordinateX, 0.0);
        glVertex2f(_lenghtCoordinateX, 0.0);

        // Y axis
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, -_lenghtCoordinateY);
        glVertex2f(0.0, _lenghtCoordinateY);

    glEnd();
    glPopMatrix();
}

void linearFunctionDrawer()
{
    counterPoints = 0;

    for(x = -20; x < 20; x += 0.01)
    {
        y = a * x + b;

        glPushMatrix();
        glPointSize(4.0);
        glBegin(GL_LINES);

        glColor3f(0.0, 1.0, 0.0);

        glVertex2f(x, y);

        for(x_1 = x + 0.01; x_1 < x + 0.02; x_1 += 0.01)
        {
            y_1 = a * x_1 + b;

            glVertex2f(x_1, y_1);
        }

        glEnd();
        glPopMatrix();

        counterPoints++;
    }
}

void quadraticFunctionDrawer()
{
    counterPoints = 0;

    for(x = -20; x < 20; x += 0.01)
    {
        y = a * (x * x) + b * x + c;

        glPushMatrix();
        glPointSize(4.0);
        glBegin(GL_LINES);

        glColor3f(0.0, 1.0, 0.0);

        glVertex2f(x, y);

        for(x_1 = x + 0.01; x_1 < x + 0.02; x_1 += 0.01)
        {
            y_1 = a * (x_1 * x_1) + b * x_1 + c;

            glVertex2f(x_1, y_1);
        }

        glEnd();
        glPopMatrix();

        counterPoints++;
    }
}

bool rationalFunctionDrawer()
{
    counterPoints = 0;

    for(x = -20; x < 20; x += 0.001)
    {
        y = a + b / x;

        glPushMatrix();
        glPointSize(1.0);
        glBegin(GL_POINTS);

        glColor3f(0.0, 1.0, 0.0);

        glVertex2f(x, y);

        for(x_1 = x + 0.01; x_1 < x + 0.02; x_1 += 0.01)
        {
            y_1 = a + b / x_1;

            glVertex2f(x_1, y_1);
        }

        glEnd();
        glPopMatrix();

        counterPoints++;
    }

    return true;
}

bool cosinusFunctionDrawer()
{
    counterPoints = 0;

    for(x = -6.283 * 2; x < 6.283 * 2; x += 0.001)
    {
        y = cos(x);

        glPushMatrix();
        glPointSize(1.0);
        glBegin(GL_POINTS);

        glColor3f(0.0, 1.0, 0.0);

        glVertex2f(x, y);

        glEnd();
        glPopMatrix();

        counterPoints++;
    }

    return true;
}

void showInformation()
{
    switch(object)
    {
        case linearFunction:
            sprintf(buffer, "F(x) = %f * x + %f, counterPoints = %f ", a, b, counterPoints);
            glutSetWindowTitle(buffer);
            break;

        case quadraticFunction:
            sprintf(buffer, "F(x) = %fx2 + %fx + %f, counterPoints = %f ", a, b, c, counterPoints);
            glutSetWindowTitle(buffer);
            break;

        case rationalFunction:
            sprintf(buffer, "F(x) = %f + %f / x, counterPoints = %f ", a, b, counterPoints);
            glutSetWindowTitle(buffer);
            break;

        case cosinusFunction:
            sprintf(buffer, "F(x) = %f + %f / x, counterPoints = %f ", a, b, counterPoints);
            glutSetWindowTitle(buffer);
            break;
    }
}

void clearScreenFunction()
{
    a = 0;
    b = 0;
    c = 0;
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
                linearFunctionDrawer();
                break;

            case quadraticFunction:
                quadraticFunctionDrawer();
                break;

            case rationalFunction:
                rationalFunctionDrawer();
                break;

            case cosinusFunction:
                cosinusFunctionDrawer();
                break;

            case clearScreen:
                clearScreenFunction();
                object = linearFunction;
                break;
        }

        showInformation();
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

    gluOrtho2D(-_lenghtCoordinateX, _lenghtCoordinateX, -_lenghtCoordinateY, _lenghtCoordinateY);
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
        a += 0.01;

    if(keys['2'])
        a -= 0.01;

    if(keys['3'])
        b += 0.01;

    if(keys['4'])
        b -= 0.01;

    if(keys['5'])
        c += 0.01;

    if(keys['6'])
        c -= 0.01;
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

        case cosinusFunction:
        {
            object = cosinusFunction;
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
    glutAddMenuEntry("cosinusFunction", cosinusFunction);
    glutAddMenuEntry("clear", clearScreen);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutIdleFunc(idle);

    glutMainLoop();


    return 0;
}
