#pragma once

// start
#include <cplib/random.h>
#include <cplib/graph/dsu.h>

std::vector<std::pair<int, int>> gentree(int n, rngseed rng) {
    std::vector<std::pair<int, int>> e;
    DSU dsu(n + 1);
    int sz = n;
    while(sz > 1) {
        int a = randint(1, n, rng);
        int b = randint(1, n, rng);
        if(dsu.unite(a, b)) {
            e.push_back({a, b});
            sz--;
        }
    }
    return e;
}