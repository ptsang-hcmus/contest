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

#define MAX 105
#define INF 1e9
vector<vector<int>> grahp;
vector<vector<int>> dist;
vector<vector<int>> path;

int V;

void printPath(int s, int t) {
    int b[MAX];
    int m = 0;
    while (s != t) {
        b[m++] = t;
        t = path[s][t];
    }
    b[m++] = s;
    for (int i = m - 1; i >= 0; i--) {
        cout << b[i] << " ";
    }
}

bool floydWarshall(vector<vector<int>>& grahp, vector<vector<int>>& dist) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = grahp[i][j];
            if (grahp[i][j] != INF && i != j) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++)
        if (dist[i][i] < 0) return false;

    return true;
}

int main() {
    int temp;
    cin >> V;
    grahp.assign(V, vector<int>(V));
    dist.assign(V, vector<int>(V));
    path.assign(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> temp;
            if (temp == 0 && i != j)
                grahp[i][j] = INF;
            else
                grahp[i][j] = temp;
        }
    }

    floydWarshall(grahp, dist);
    int s = 0;
    int t = 4;
    int result = dist[s][t];
    printPath(s, t);
    cout << "\n" << result;
    return 0;
}