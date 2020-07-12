#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<vector<pair<int, int>>> grahp;
vector<int> dist;
struct option {
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
		return a.second > b.second;
	}
};

void Dijkstra(int s, int destination) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
	pq.push({s, 0});
	dist[s] = 0;
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		int from = top.first;
		if (from == destination) return;
		int cost = top.second;
		for (int i = 0; i < (int)grahp[from].size(); i++) {
			pair<int, int> neighbor = grahp[from][i];
			if (cost + neighbor.second < dist[neighbor.first]) {
				dist[neighbor.first] = cost + neighbor.second;
				pq.push({neighbor.first, dist[neighbor.first]});
			}
		}
	}
}