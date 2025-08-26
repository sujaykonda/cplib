#pragma once
// start
#include <cplib/math/mint.h>
template<int M1, int M2, int M3> struct HashC {
    mint<M1> a; mint<M2> b; mint<M3> c;
    HashC() {a.v = 0, b.v = 0, c.v = 0; }
    HashC(int v) { a.v = v, b.v = v, c.v = v; }
    HashC& operator+=(HashC o) { a += o.a, b += o.b, c += o.c; return *this; }
    HashC& operator-=(HashC o) { a -= o.a, b -= o.b, c -= o.c; return *this; }
    HashC& operator*=(HashC o) { a *= o.a, b *= o.b, c *= o.c; return *this; }
    HashC& operator/=(HashC o) { a /= o.a, b /= o.b, c /= o.c; return *this; }
    friend HashC operator+(HashC a, HashC b) { return a += b; }
    friend HashC operator-(HashC a, HashC b) { return a -= b; }
    friend HashC operator*(HashC a, HashC b) { return a *= b; }
    friend HashC operator/(HashC a, HashC b) { return a /= b; }
    friend bool operator<(HashC a, HashC b) { 
        if(a.a.v == b.a.v) {
            if(a.b.v == b.b.v) {
                if(a.c.v == b.c.v)
                    return false;
                return a.c < b.c;
            }
            return a.b < b.b;
        }
        return a.a < b.a;
    }
    friend bool operator==(HashC a, HashC b) { return a.a.v == b.a.v && a.b.v == b.b.v && a.c.v == b.c.v; }
    friend bool operator!=(HashC a, HashC b) { return !(a == b); }
    friend std::string str(HashC a) { return "(" + str(a.a.v) + "," + str(a.b.v) + "," + str(a.c.v) + ")"; }
};
typedef HashC<1000000007, 1000000009, 998244353> Hash;
