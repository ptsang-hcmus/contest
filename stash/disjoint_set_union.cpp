#include <bits/stdc++.h>
using namespace std;

string to_string(const string &s) { return '"' + s + '"'; }
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
	for (const auto &x : v) {
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
#define MAX 1000
#define MN 100000

int parent[MN + 5];
int ranks[MN + 5];
int cnt[MN + 5];
int maxEl = 1, minEl = 1;

int N, Q;

void makeSet() {
	memset(ranks, 0, sizeof(ranks));
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
}

int findSet(int x) {
	if (parent[x] != x) {
		parent[x] = findSet(parent[x]);
	}
	return parent[x];
}

void updateMinEl() {
	minEl = INT_MAX;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] >> 0 && cnt[i] < minEl) {
			minEl = cnt[i];
			if (minEl == 1) return;
		}
	}
}

void unionSet(int from, int to) {
	int fromParent = findSet(from);
	int toParent = findSet(to);
	if (fromParent == toParent) {
		return;
	}

	if (ranks[fromParent] > ranks[toParent]) {
		cnt[findSet(from)] += cnt[findSet(to)];
		cnt[findSet(to)] = 0;
		maxEl = max(maxEl, cnt[findSet(from)]);

		parent[toParent] = fromParent;
	} else if (ranks[fromParent] < ranks[toParent]) {
		cnt[findSet(to)] += cnt[findSet(from)];
		cnt[findSet(from)] = 0;
		maxEl = max(maxEl, cnt[findSet(to)]);

		parent[fromParent] = toParent;
	} else {
		cnt[findSet(to)] += cnt[findSet(from)];
		cnt[findSet(from)] = 0;
		maxEl = max(maxEl, cnt[findSet(to)]);

		parent[fromParent] = toParent;
		ranks[fromParent]++;
	}
	updateMinEl();
}

int main() {
	// ! DELETE THIS WHEN SUBMIT
	freopen("in", "rt", stdin);

	cin >> N >> Q;

	fill_n(cnt, N + 5, 1);

	makeSet();

	int u, v;

	ll ans = -1;

	while (Q--) {
		cin >> u >> v;

		int fu = findSet(u), fv = findSet(v);

		if (ans != -1 && fu == fv) {
			std::cout << ans << endl;
			continue;
		}

		unionSet(u, v);
		debug(minEl, maxEl);

		ans = maxEl - minEl;
		std::cout << ans << endl;
	}

	return 0;
}