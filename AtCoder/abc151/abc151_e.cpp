#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

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

template <std::uint_fast64_t Mod>
std::istream &operator>>(std::istream &in, ModInt<Mod> &m)
{
    in >> m.num;
    if (m.num >= Mod)
    {
        m.num %= Mod;
    }
    return in;
}

using namespace std;

static const int INF = 1e9 + 7;

vector<ModInt<INF>> fact;
vector<ModInt<INF>> revfact;

void setfact(int N)
{
    fact.resize(N + 1);
    revfact.resize(N + 1);
    fact[0] = 1;
    for (int i = 1; i < N + 1; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
    revfact[N] = ModInt<INF>::pow(fact[N], INF - 2);
    for (int i = N - 1; i >= 0; i--)
    {
        revfact[i] = revfact[i + 1] * (i + 1);
    }
}

ModInt<INF> getC(int a, int b)
{
    return ((fact[a] * revfact[b]) * revfact[a - b]);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &&i : a)
    {
        cin >> i;
    }
    setfact(100002);
    sort(begin(a), end(a));
    vector<int> b(rbegin(a), rend(a));
    long long ans = 0;
    for (int i = k - 1; i < n; i++)
    {
        ans += getC(i, k - 1).num * (a[i] - b[i]);
        ans %= INF;
    }
    cout << ans << "\n";
}