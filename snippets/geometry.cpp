#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

struct point {
    double x, y;
};

// finds the area of a polygon enclosed by a set of points
double polygon_area(const vector<point> &points) {
    double area = 0.0;
    for (int i = 0; i < points.size(); i++) {
        int j = (i + 1) % points.size();
        area += points[i].x * points[j].y;
        area -= points[i].y * points[j].x;
    }
    return abs(area / 2);
}

// finds the signed area of a parallelogram
double signed_area(const vector<point> &points) {
    point a = points[0];
    point b = points[1];
    point c = points[2];
    return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
}

// returns a list of points of the convex hull for `points`
vector<point> convex_hull(vector<point> &points) {

    // p0 is the point with lowest y, ties broken by lower x
    point p0 = points[0];
    for (point p : points) {
        if (p.y < p0.y)
            p0 = p;
        else if (p.y == p0.y && p.x < p0.x)
            p0 = p;
    }

    // sort points based on orientation from p0
    sort(points.begin(), points.end(), [&p0](const point &a, const point &b) {
        double area = signed_area({p0, a, b});
        if (area == 0) {    // no orientation, return point closer to p0
            return pow(p0.x - a.x, 2) + pow(p0.y - a.y, 2)
                < pow(p0.x - b.x, 2) + pow(p0.y - b.y, 2);
        }
        return area < 0;    // is it clockwise?
    });

    // iterate through each of the points
    vector<point> stk;
    for (int i = 0; i < points.size(); i++) {
        // check that going from the last point to this one is clockwise
        while (true) {
            if (stk.size() <= 1)
                break;
            if (signed_area({stk[stk.size() - 2], stk.back(), points[i]}) < 0)
                break;
            stk.pop_back();
        }
        stk.push_back(points[i]);
    }

    // edge case: ignore collinear points
    if (stk.size() == 2 && stk[0].x == stk[1].x && stk[0].y == stk[1].y)
        stk.pop_back();

    return stk;
}
