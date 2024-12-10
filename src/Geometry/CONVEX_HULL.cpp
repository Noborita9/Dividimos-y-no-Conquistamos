#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point;

ll cross_product(Point O, Point A, Point B) {
    return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

vector<Point> convex_hull(vector<Point>& points) {
    sort(points.begin(), points.end());
    vector<Point> hull;

    // Parte inferior
    for (const auto& p : points) {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull[hull.size() - 1], p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }

    // Parte superior
    int t = hull.size() + 1;
    for (int i = points.size() - 1; i >= 0; --i) {
        while (hull.size() >= t && cross_product(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back(); 
    return hull;
}
