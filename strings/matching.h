#pragma once
// start
#include <cplib/general.h>
std::vector<int> manacher_odd(std::string s) {
    int n = s.size();
    s = "$" + s + "^";
    std::vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = std::max(0, std::min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return std::vector<int>(begin(p) + 1, end(p) - 1);
}
std::vector<int> manacher(const std::string& s) {
    std::string t;
    for(auto c: s) {
        t += std::string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return std::vector<int>(begin(res) + 1, end(res) - 1);
}
std::vector<int> kmp(const std::string &s) {
	int n = (int)s.size();
	std::vector<int> pi_s(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[j] != s[i]) { j = pi_s[j - 1]; }
		if (s[i] == s[j]) { j++; }
		pi_s[i] = j;
	}
	return pi_s;
}
std::vector<int> z(const std::string& s) {
    int n = s.size();
    std::vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}