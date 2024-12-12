#include <GL/glut.h>
#include <cmath>

// Base class for shapes
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function for polymorphism
};

// Circle class to draw a ball
class Circle : public Shape {
    float cx, cy, radius;
    int segments;

public:
    Circle(float x, float y, float r, int seg) : cx(x), cy(y), radius(r), segments(seg) {}

    void setPosition(float x, float y) {
        cx = x;
        cy = y;
    }

    void draw() override {
        glBegin(GL_POLYGON);
        for (int i = 0; i < segments; i++) {
            float theta = 2.0f * M_PI * float(i) / float(segments);
            float x = radius * cosf(theta);
            float y = radius * sinf(theta);
            glVertex2f(x + cx, y + cy);
        }
        glEnd();
    }
};

// Bouncing ball class
class BouncingBall {
    Circle ball;
    float amplitude;
    float frequency;
    float phase;
    float xPos;

public:
    BouncingBall(float x, float y, float r, float amp, float freq, float phaseShift)
        : ball(x, y, r, 50), amplitude(amp), frequency(freq), phase(phaseShift), xPos(x) {}

    void update(float time) {
        float y = amplitude * sin(frequency * time + phase);
        ball.setPosition(xPos, y);
    }

    void draw() {
        ball.draw();
    }
};

float time = 0.0f;
BouncingBall ball(0.0f, 0.0f, 0.1f, 0.8f, 3.0f, 0.0f);

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f); // Ball color
    ball.draw();

    glFlush();
}

void timer(int value) {
    time += 0.02f;
    ball.update(time);

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // ~60 FPS
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
    glutCreateWindow("Bouncing Ball with Sine Wave");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}
