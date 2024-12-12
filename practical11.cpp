#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    float x, y;

    Point(float x = 0, float y = 0) : x(x), y(y) {}

    // Operator overloading for translation
    Point operator+(const Point &p) {
        return Point(x + p.x, y + p.y);
    }

    // Operator overloading for scaling
    Point operator*(float scale) {
        return Point(x * scale, y * scale);
    }

    // Operator overloading for rotation
    Point operator*(const pair<float, float> &rotation) {
        float angle = rotation.first;
        return Point(
            x * cos(angle) - y * sin(angle),
            x * sin(angle) + y * cos(angle)
        );
    }
};

class Object2D {
private:
    Point vertices[4];

public:
    Object2D(Point v[]) {
        for (int i = 0; i < 4; i++)
            vertices[i] = v[i];
    }

    void draw() {
        for (int i = 0; i < 4; i++) {
            int j = (i + 1) % 4;
            line(vertices[i].x, vertices[i].y, vertices[j].x, vertices[j].y);
        }
    }

    void translate(Point t) {
        for (int i = 0; i < 4; i++)
            vertices[i] = vertices[i] + t;
    }

    void scale(float s) {
        Point centroid = getCentroid();
        for (int i = 0; i < 4; i++) {
            vertices[i] = vertices[i] - centroid;
            vertices[i] = vertices[i] * s;
            vertices[i] = vertices[i] + centroid;
        }
    }

    void rotate(float angle) {
        Point centroid = getCentroid();
        for (int i = 0; i < 4; i++) {
            vertices[i] = vertices[i] - centroid;
            vertices[i] = vertices[i] * make_pair(angle, angle);
            vertices[i] = vertices[i] + centroid;
        }
    }

private:
    Point getCentroid() {
        float cx = 0, cy = 0;
        for (int i = 0; i < 4; i++) {
            cx += vertices[i].x;
            cy += vertices[i].y;
        }
        return Point(cx / 4, cy / 4);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    Point vertices[] = {
        Point(100, 100),
        Point(200, 100),
        Point(200, 200),
        Point(100, 200)
    };

    Object2D square(vertices);

    setcolor(WHITE);
    square.draw();

    // Perform transformations
    setcolor(RED);
    square.translate(Point(50, 50));
    square.draw();

    setcolor(GREEN);
    square.scale(1.5);
    square.draw();

    setcolor(BLUE);
    square.rotate(M_PI / 4); // Rotate by 45 degrees
    square.draw();

    getch();
    closegraph();
    return 0;
}
