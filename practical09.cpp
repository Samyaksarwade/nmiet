#include <graphics.h>
#include <iostream>
using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

int x_min, y_min, x_max, y_max;

// Function to compute region code for a point (x, y)
int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < x_min)       // to the left of rectangle
        code |= LEFT;
    else if (x > x_max)  // to the right of rectangle
        code |= RIGHT;
    if (y < y_min)       // below the rectangle
        code |= BOTTOM;
    else if (y > y_max)  // above the rectangle
        code |= TOP;

    return code;
}

// Cohen-Sutherland clipping algorithm to clip a line from (x1, y1) to (x2, y2)
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints lie inside rectangle
            accept = true;
            break;
        } else if (code1 & code2) {
            // Both endpoints are outside rectangle in the same region
            break;
        } else {
            // Some segment of line lies within the rectangle
            int code_out;
            int x, y;

            // At least one endpoint is outside the rectangle, pick it
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point
            if (code_out & TOP) { // Point is above the rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) { // Point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) { // Point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) { // Point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Replace outside point with intersection point
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        // Draw the clipped line
        setcolor(WHITE);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    // Define the clipping rectangle
    x_min = 100, y_min = 100, x_max = 300, y_max = 300;

    // Draw the clipping rectangle
    setcolor(RED);
    rectangle(x_min, y_min, x_max, y_max);

    // Define a line to be clipped
    int x1 = 50, y1 = 150, x2 = 350, y2 = 250;

    // Draw the original line
    setcolor(YELLOW);
    line(x1, y1, x2, y2);

    // Perform line clipping
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
