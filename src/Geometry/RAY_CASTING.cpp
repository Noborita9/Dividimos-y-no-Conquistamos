#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Point;


bool is_point_in_polygon(const vector<Point>& polygon, Point p) {
    bool inside = false;
    int n = polygon.size();
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if ((polygon[i].second > p.second) != (polygon[j].second > p.second) &&
            p.first < (polygon[j].first - polygon[i].first) * (p.second - polygon[i].second) / 
                      (polygon[j].second - polygon[i].second) + polygon[i].first) {
            inside = !inside;
        }
    }
    return inside;
}
