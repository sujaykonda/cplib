#pragma once
// start
#include <cplib/general.h>
#include <cplib/ds/srq.h>

int _min(int a, int b) {
    return std::min(a, b);
}
struct SuffixArray {
    std::string s;
    std::vector<int> sa, isa, lcp;
    SRQ<int, _min> st;

    SuffixArray(const std::string& _s) {
        s = _s + "$";
        int N = s.size();
        sa.resize(N); isa.resize(N);
        sa[0] = N - 1;
        std::iota(sa.begin() + 1, sa.end(), 0);
        std::sort(sa.begin() + 1, sa.end(), [&](int a, int b) {
            return s[a] < s[b];
        });

        for (int i = 1; i < N; ++i) {
            int a = sa[i - 1], b = sa[i];
            isa[b] = (i > 1 && s[a] == s[b]) ? isa[a] : i;
        }

        for (int len = 1; len < N; len *= 2) {
            std::vector<int> old_sa = sa, old_isa = isa, pos(N);
            std::iota(pos.begin(), pos.end(), 0);
            for (int t : old_sa) {
                int T = t - len;
                if (T >= 0) sa[pos[old_isa[T]]++] = T;
            }
            for (int i = 1; i < N; ++i) {
                int a = sa[i - 1], b = sa[i];
                bool same = old_isa[a] == old_isa[b] &&
                            old_isa[a + len] == old_isa[b + len];
                isa[b] = same ? isa[a] : i;
            }
        }

        sa.erase(sa.begin()); // remove '$' at position N-1
        isa.pop_back();
        for(int& i : isa) i--;
        N--;

        int h = 0;
        lcp.resize(N - 1);  // lcp[i] = LCP(sa[i], sa[i+1])
        for (int b = 0; b < N; ++b) {
            int i = isa[b];
            if(i == 0) continue;
            int a = sa[i - 1];
            while (a + h < N && b + h < N && s[a + h] == s[b + h]) ++h;
            lcp[i - 1] = h;
            if (h) --h;
        }
        st = SRQ<int, _min>(lcp);
    }

    int qlcp(int i, int j) {
        if (i == j) return s.size() - 1 - i;
        int ri = isa[i], rj = isa[j];
        if (ri > rj) std::swap(ri, rj);
        return st.query(ri, rj - 1);
    }

    int compare(int l1, int r1, int l2, int r2) {
        int m = qlcp(l1, l2);
        if(r1 - l1 + 1 <= m || r2 - l2 + 1 <= m) {
            return (r1 - l1 > r2 - l2) - (r1 - l1 < r2 - l2);
        }
        return (isa[l1] < isa[l2]) ? -1 : 1;
    }
};

