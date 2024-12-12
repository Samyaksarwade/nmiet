#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

void drawSnowflake(int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        drawLine(x1, y1, x2, y2);
        return;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;

    int x3 = x1 + dx / 3;
    int y3 = y1 + dy / 3;

    int x5 = x1 + 2 * dx / 3;
    int y5 = y1 + 2 * dy / 3;

    float angle = M_PI / 3; // 60 degrees

    int x4 = x3 + (int)(cos(angle) * (x5 - x3) - sin(angle) * (y5 - y3));
    int y4 = y3 + (int)(sin(angle) * (x5 - x3) + cos(angle) * (y5 - y3));

    drawSnowflake(x1, y1, x3, y3, depth - 1);
    drawSnowflake(x3, y3, x4, y4, depth - 1);
    drawSnowflake(x4, y4, x5, y5, depth - 1);
    drawSnowflake(x5, y5, x2, y2, depth - 1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    int x1 = 200, y1 = 300;
    int x2 = 400, y2 = 300;
    int x3 = 300, y3 = 100;

    int depth = 4; // Change depth to control fractal complexity

    setcolor(WHITE);
    drawSnowflake(x1, y1, x2, y2, depth);
    drawSnowflake(x2, y2, x3, y3, depth);
    drawSnowflake(x3, y3, x1, y1, depth);

    getch();
    closegraph();
    return 0;
}
