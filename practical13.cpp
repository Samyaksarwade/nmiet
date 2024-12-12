#include <GL/glut.h>
#include <cmath>

float sunY = -0.8;
float direction = 0.01;

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw sky background
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f); // Sky color
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(0.8f, 0.4f, 0.2f); // Horizon color
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Draw sun
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0.0f, sunY, 0.2f, 100);

    glFlush();
}

void update(int value) {
    sunY += direction;

    // Reverse direction at sunset/sunrise limits
    if (sunY > 0.8 || sunY < -0.8)
        direction = -direction;

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Sunrise and Sunset");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}
