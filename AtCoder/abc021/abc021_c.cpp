#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <map>
#include <utility>

template <std::uint_fast64_t Mod>
class ModInt
{
    using u64 = uint_fast64_t;

public:
    u64 num;
    constexpr ModInt(const u64 x = 0) noexcept : num(x % Mod) {}
    constexpr u64 &value() noexcept { return num; }
    constexpr const u64 &value() const noexcept { return num; }
    constexpr ModInt operator+(const ModInt rhs) const noexcept
    {
        return ModInt(*this) += rhs;
    }
    constexpr ModInt operator-(const ModInt rhs) const noexcept
    {
        return ModInt(*this) -= rhs;
    }
    constexpr ModInt operator*(const ModInt rhs) const noexcept
    {
        return ModInt(*this) *= rhs;
    }
    constexpr ModInt operator/(const ModInt rhs) const noexcept
    {
        return ModInt(*this) /= rhs;
    }
    constexpr ModInt &operator+=(const ModInt rhs) noexcept
    {
        num += rhs.num;
        if (num >= Mod)
        {
            num -= Mod;
        }
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt rhs) noexcept
    {
        if (num < rhs.num)
        {
            num += Mod;
        }
        num -= rhs.num;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt rhs) noexcept
    {
        num = num * rhs.num % Mod;
        return *this;
    }
    constexpr ModInt &operator/=(ModInt rhs) noexcept
    {
        u64 exp = Mod - 2;
        while (exp)
        {
            if (exp % 2)
            {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr ModInt &operator=(const u64 num) noexcept
    {
        this->num = num % Mod;
        return *this;
    }

    constexpr ModInt pow(u64 k)
    {
        return pow(num, k);
    }

    static constexpr ModInt pow(ModInt x, u64 k)
    {
        if (k == 0)
            return 1;
        if (k % 2 == 0)
            return pow((x * x).num % Mod, k / 2);
        else
            return (x * pow(x, k - 1)).num % Mod;
    }
};

template <std::uint_fast64_t Mod>
std::ostream &operator<<(std::ostream &out, const ModInt<Mod> &m)
{
    out << m.num;
    return out;
}

using namespace std;

static const int INF = 1e9 + 7;
int n, m;
int a, b;
vector<vector<int>> edge;
vector<vector<int>> minroot;
map<pair<int, int>, ModInt<INF>> dp;

ModInt<INF> dfs(int p, int cnt)
{
    if (p == b)
        return 1;
    if (cnt == minroot[a][b])
        return 0;
    auto status = make_pair(p, cnt);
    if (dp.count(status))
        return dp[status];
    ModInt<INF> res = 0;
    for (auto &&i : edge[p])
    {
        res += dfs(i, cnt + 1);
    }
    return dp[status] = res;
}

int main()
{
    cin >> n;
    edge.resize(n);
    minroot.resize(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
    {
        minroot[i][i] = 0;
    }
    cin >> a >> b;
    a--;
    b--;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[x - 1].push_back(y - 1);
        edge[y - 1].push_back(x - 1);
        minroot[x - 1][y - 1] = minroot[y - 1][x - 1] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                minroot[j][k] = min(minroot[j][k], minroot[j][i] + minroot[i][k]);
            }
        }
    }
    cout << dfs(a, 0) << "\n";
}