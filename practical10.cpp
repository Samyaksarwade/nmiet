#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

// Class for drawing a DDA Line
class DDA {
public:
    // Method to draw a line using DDA algorithm
    void drawLine(int x1, int y1, int x2, int y2) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int steps = max(abs(dx), abs(dy)); // Determine the number of steps
        float xIncrement = dx / (float)steps;
        float yIncrement = dy / (float)steps;

        float x = x1;
        float y = y1;
        
        for (int i = 0; i <= steps; i++) {
            putpixel(round(x), round(y), WHITE);  // Plot the pixel
            x += xIncrement;
            y += yIncrement;
        }
    }
};

// Class for drawing a circle using Bresenham's circle algorithm
class Circle {
public:
    // Method to draw a circle using Bresenham's algorithm
    void drawCircle(int xc, int yc, int r) {
        int x = 0;
        int y = r;
        int p = 3 - 2 * r;

        // Plot the initial 8 symmetrical points of the circle
        plotCirclePoints(xc, yc, x, y);

        // Draw the circle using the algorithm
        while (x < y) {
            x++;

            // Decision parameter for moving along the x-axis
            if (p <= 0) {
                p = p + 4 * x + 6;
            } else {
                y--;
                p = p + 4 * (x - y) + 10;
            }

            // Plot the symmetrical points
            plotCirclePoints(xc, yc, x, y);
        }
    }

private:
    // Helper function to plot the symmetrical points of the circle
    void plotCirclePoints(int xc, int yc, int x, int y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Initialize graphics mode

    DDA dda;  // Object for drawing DDA line
    Circle circle;  // Object for drawing circle

    // Draw a DDA line from (100, 100) to (400, 300)
    dda.drawLine(100, 100, 400, 300);

    // Draw a circle with center (300, 300) and radius 100
    circle.drawCircle(300, 300, 100);

    // Wait for user input to close the graphics window
    getch();
    closegraph();  // Close graphics mode
    return 0;
}
