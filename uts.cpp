// uts.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<stdlib.h>
#include<glut.h>

float a = 0;
float b = 0;
float c = 0;
float d = 0;

void Kotak() {  
    glBegin(GL_QUADS);
    glColor3f(0, 1, 1);
    glVertex2i(0., 0.);
    glVertex2i(100., 0.);
    glColor3f(0, 0, 1);
    glVertex2i(100., 100.);
    glVertex2i(0., 100.);
    glEnd();
    glFlush();
}
void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(c, d, 0);
    Kotak();
    glPopMatrix();
}
void myKeyboard(unsigned char key, int x, int y) {
    if (key == 'a') c -= 100;
    else if (key == 'd') c += 100;
    else if (key == 'w') d += 100;
    else if (key == 's') d -= 100;
}
void update(int value) {
    glutPostRedisplay();
    glutTimerFunc(50, update, 0);
}
void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Ujian Tengah Semester");
    gluOrtho2D(-320.0, 320.0, -320.0, 320.0);
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(myKeyboard);
    glutTimerFunc(1000, update, 0);
    glutMainLoop();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
