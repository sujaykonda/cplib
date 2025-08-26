#pragma once

// start
#include <cplib/general.h>

rngseed genseed() {
    return rngseed(std::chrono::steady_clock::now().time_since_epoch().count());
}

#define randint(a, b, rng) std::uniform_int_distribution<int>(a, b)(rng)

#define randll(a, b, rng) std::uniform_int_distribution<ll>(a, b)(rng)