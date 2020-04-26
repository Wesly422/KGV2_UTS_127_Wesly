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
