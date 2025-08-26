#pragma once

// start
#include <cplib/general.h>

struct LCA {
    int n; std::vector<std::vector<int>> jmp; std::vector<int> dep;
    LCA(adjlist& adj) : n(adj.size()), jmp(lg(n) + 1, std::vector<int>(n)), dep(n) {
        rt(adj, 1, 0); 
        for(int i = 0; i < jmp.size() - 1; i++)
            for(int j = 0; j < n; j++)
                jmp[i + 1][j] = jmp[i][jmp[i][j]]; 
    }
    void rt(adjlist& adj, int s, int e) {
        dep[s] = dep[e] + 1; jmp[0][s] = e; for(int u : adj[s]) if(u != e) rt(adj, u, s); }
    int q(int a, int b) {
        if(dep[a] < dep[b]) std::swap(a, b);
        for(int i = jmp.size() - 1; i >= 0; i--)
            if(dep[jmp[i][a]] >= dep[b]) 
                a = jmp[i][a];
        if(a == b) return a;
        for(int i = jmp.size() - 1; i >= 0; i--)
            if(jmp[i][a] != jmp[i][b]) 
                a = jmp[i][a], b = jmp[i][b];
        return jmp[0][a];
    }
};

struct CentroidDecomp {
    int n; int rtc; std::vector<int> sz; std::vector<std::vector<int>> cc; std::vector<bool> rem;
    CentroidDecomp(adjlist& adj) : n(adj.size()), sz(n), cc(n), rem(n, false) {
        rtc = buildcentroid(1, adj);
    }

    void szdfs(int s, int e, adjlist& adj) {
        sz[s] = 1;
        for(int u : cc[s]) {
            if(u != e && !rem[u]) {
                szdfs(u, s, adj);
                sz[s] += sz[u];
            }
        }
    }

    int centroiddfs(int s, int e, int all, adjlist& adj) {
        for(int u : cc[s]) {
            if(u != e && !rem[u] && 2 * sz[u] > all) {
                return centroiddfs(u, s, all, adj);
            }
        }
        return s;
    }

    int buildcentroid(int s, adjlist& adj) {
        szdfs(s, 0, adj);
        int c = centroiddfs(s, 0, sz[s], adj);
        rem[c] = true;
        for(int u : cc[c]) {
            if(!rem[u]) {
                int subc = buildcentroid(u, adj);
                cc[c].push_back(subc);
            }
        }
        return c;
    }
    
};