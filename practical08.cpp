#include <graphics.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Base class for shapes
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function for drawing
    virtual void fill(int color) = 0; // Pure virtual function for filling
};

// Derived class for Polygon
class Polygon : public Shape {
private:
    vector<pair<int, int>> vertices;

    void sortEdges(vector<pair<int, int>> &edges) {
        sort(edges.begin(), edges.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        });
    }

public:
    Polygon(vector<pair<int, int>> v) : vertices(v) {}

    void draw() override {
        int n = vertices.size();
        for (int i = 0; i < n; ++i) {
            line(vertices[i].first, vertices[i].second, vertices[(i + 1) % n].first, vertices[(i + 1) % n].second);
        }
    }

    void fill(int color) override {
        int ymin = vertices[0].second, ymax = vertices[0].second;
        for (auto &vertex : vertices) {
            ymin = min(ymin, vertex.second);
            ymax = max(ymax, vertex.second);
        }

        for (int y = ymin; y <= ymax; ++y) {
            vector<int> intersections;
            for (size_t i = 0; i < vertices.size(); ++i) {
                pair<int, int> v1 = vertices[i];
                pair<int, int> v2 = vertices[(i + 1) % vertices.size()];

                if (v1.second == v2.second) continue; // Horizontal edge

                if (y >= min(v1.second, v2.second) && y < max(v1.second, v2.second)) {
                    int x = v1.first + (y - v1.second) * (v2.first - v1.first) / (v2.second - v1.second);
                    intersections.push_back(x);
                }
            }

            sort(intersections.begin(), intersections.end());

            for (size_t i = 0; i < intersections.size(); i += 2) {
                line(intersections[i], y, intersections[i + 1], y);
                setcolor(color);
            }
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    // Define vertices of a concave polygon
    vector<pair<int, int>> vertices = {
        {200, 100}, {300, 200}, {250, 300}, {150, 250}, {100, 150}
    };

    // Create a Polygon object
    Polygon polygon(vertices);

    // Draw the polygon
    polygon.draw();

    // Fill the polygon with the desired color
    polygon.fill(YELLOW);

    getch();
    closegraph();
    return 0;
}
