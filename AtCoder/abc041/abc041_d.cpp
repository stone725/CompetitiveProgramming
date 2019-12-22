#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

const int INF = 1e9 + 7;

int n, m;
long long dp[1 << 16];
vector<bitset<16>> v;

long long dfs(bitset<16> bits)
{
	if (bits.count() == n)
		return 1;
	unsigned long score = bits.to_ulong();
	if (~dp[score])
		return dp[score];
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		if (bits[i])
			continue;
		if ((bits.to_ulong() & v[i].to_ulong()) != v[i].to_ulong())
			continue;
		bits[i] = true;
		res += dfs(bits);
		bits[i] = false;
	}
	return dp[score] = res;
}

int main()
{
	cin >> n >> m;
	memset(dp, -1, sizeof dp);
	v.resize(n);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[y - 1][x - 1] = true;
	}
	cout << dfs(0) << "\n";
}