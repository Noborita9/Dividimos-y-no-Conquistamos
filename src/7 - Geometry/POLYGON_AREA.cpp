#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point;

// Calcula el área de un polígono
double polygon_area(const vector<Point>& polygon) {
    ll area = 0;
    int n = polygon.size();
    for (int i = 0; i < n; ++i) {
        ll j = (i + 1) % n;
        area += (polygon[i].first * polygon[j].second - polygon[i].second * polygon[j].first);
    }
    return abs(area) / 2.0;
}
