#include <GL/glut.h>
#include<iostream>
#include "ObjLoader.h"


ObjMesh* trees;

int main(int argc, char** argv);

// All glut functions
void draw(void); void reshape(int width, int height); void key(unsigned char k, int x, int y); void idle(void);

void loadObjs(void);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Galton Board");

    glutInitWindowSize(900, 900);

    loadObjs();

    glutDisplayFunc(draw);
    glutKeyboardFunc(key);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glPushMatrix();
        DrawOBJ(trees->m_iMeshID);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);

    glFrustum(10, 10, 10, 10, 0, 100);

    glMatrixMode(GL_MODELVIEW);
}

void key(unsigned char k, int x, int y)
{
    switch (k)
    {
        case 27:
            exit(0);
            break;
        case 'w':
            break;
        case 'a':
            break;
        case 's':
            break;
        case 'd':
            break;
    }
    glutPostRedisplay();
}

void idle(void)
{

}

void loadObjs(void)
{
    trees = LoadOBJ(".\\assets\\trees9.obj");
    //SetTextures(trees->m_iMeshID, NULL, ".\\assets\\Texture\\Bark__0.jpg");
}

