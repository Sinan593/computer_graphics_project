#include "Breakout.h"

Breakout game;

void display()
{
    game.display();
}

void reshape(int w, int h)
{
    game.reshape(w, h);
}

void keyboard(unsigned char key, int x, int y)
{
    game.keyStroke(key, x, y);
}

void specialKeys(int key, int x, int y)
{
    game.specialKeyStroke(key, x, y);
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // 60 FPS
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Breakout");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(0, timer, 0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    glutMainLoop();
    return 0;
}