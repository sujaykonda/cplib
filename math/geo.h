#pragma once
// start
#include <cplib/general.h>
template<class T> struct P {
    T x, y;
    P() : P(0, 0) {}
    P(T _x, T _y) : x(_x), y(_y) {}
    friend P operator+(const P& a, const P& b) { return P(a.x + b.x, a.y + b.y); }
    friend P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
    friend P operator*(const P& a, const T& b) { return P(a.x * b, a.y * b); }
    friend P operator*(const T& b, const P& a) { return a * b; }
    friend T cross(const P& a, const P& b) {
        return a.x * b.y - a.y * b.x; 
    }
    friend std::string str(P a) { return "(" + str(a.x) + "," + str(a.y) + ")"; }
    friend T tarea(P a, P b, P c) { return cross(a - b, c - b); }
    friend double angle(P a) { return atan2(a.y, a.x); }
};

template<class T> double poly_area(const std::vector<P<T>>& fig) {
    double res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        P p = i ? fig[i - 1] : fig.back();
        P q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}

template<class T> std::vector<P<T>> conv_hull(const std::vector<P<T>>& v) {
    std::vector<P<T>> hull;
    for(int i = 0; i < v.size(); i++) {
        while(hull.size() >= 2 && tarea(hull.end()[-1], v[i], hull.end()[-2]) <= 0) {
            hull.pop_back();
        }
        hull.pb(v[i]);
    }
    return hull;
}
