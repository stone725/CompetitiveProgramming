#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>
#include <set>

using namespace std;

using ll = long long;

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

vector<ll> A;
vector<vector<pair<ll, int>>> v;
vector<vector<pair<ll, int>>> v2;
vector<ll> cost;
vector<ll> cost2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, t;
	cin >> n >> m >> t;
	A.resize(n);
	for (auto &&i : A)
	{
		cin >> i;
	}
	v.resize(n);
	v2.resize(n);
	cost.resize(n, 1ll << 62);
	cost2.resize(n, 1ll << 62);
	cost[0] = cost2[0] = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[--a].push_back(make_pair(c, --b));
		v2[b].push_back(make_pair(c, a));
	}
	pq.push(make_pair(0ll, 0));
	while (pq.size())
	{
		auto info = pq.top();
		pq.pop();
		for (auto &&i : v[info.second])
		{
			if (cost[i.second] <= info.first + i.first)
				continue;
			cost[i.second] = info.first + i.first;
			pq.push(make_pair(cost[i.second], i.second));
		}
	}
	pq.push(make_pair(0ll, 0));
	while (pq.size())
	{
		auto info = pq.top();
		pq.pop();
		for (auto &&i : v2[info.second])
		{
			if (cost2[i.second] <= info.first + i.first)
				continue;
			cost2[i.second] = info.first + i.first;
			pq.push(make_pair(cost2[i.second], i.second));
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (cost[i] == 1ll << 62 || cost2[i] == 1ll << 62)
			continue;
		ans = max(ans, A[i] * (t - cost[i] - cost2[i]));
	}
	cout << ans << "\n";
}
