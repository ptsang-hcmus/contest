#include <bits/stdc++.h>
using namespace std;

string to_string(const string& s) { return '"' + s + '"'; }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
vector<A> sub(vector<A> v, int from = 0, int to = -1) {
    if (to == -1) to = (int)v.size();
    return vector<A>(v.begin() + from, v.begin() + to);
}
template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

#define ll long long

ll n, k;
vector<int> a[3];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (y == 0 && z == 0) continue;
        if (y == 1 && z == 1)
            a[0].push_back(x);
        else if (y == 1)
            a[1].push_back(x);
        else
            a[2].push_back(x);
    }

    sort(a[1].begin(), a[1].end());
    sort(a[2].begin(), a[2].end());

    int minLen = min(a[1].size(), a[2].size());
    for (int i = 0; i < minLen; i++) {
        a[0].push_back(a[1][i] + a[2][i]);
    }

    sort(a[0].begin(), a[0].end());

    if (a[0].size() >= k) {
        ll ans = 0;
        for (int i = 0; i < k; i++) {
            ans += a[0][i];
        }
        cout << ans;
    } else {
        cout << -1;
    }

    return 0;
}