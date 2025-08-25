typedef pair<ll, ll> Point;
double polygon_area(const vector<Point>& polygon) {
    ll area = 0;
    int n = polygon.size();
    for (int i = 0; i < n; ++i) {
        ll j = (i + 1) % n;
        area += (polygon[i].first * polygon[j].second - polygon[i].second * polygon[j].first);
    }
    return abs(area) / 2.0;
}
