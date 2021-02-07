#include <iostream>
#include <vector>
#include <numeric>
#include <bitset>
#include <array>
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

using namespace std;

unsigned long long calc(unsigned long long l, unsigned long long r)
{
    return l ^ r;
}

int main()
{
    int n;
    cin >> n;
    vector<unsigned long long> a(n);
    array<int, 60> b;
    for (auto &&i : b)
    {
        i = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i - 1];
        bitset<60> bits(a[i - 1]);
        for (int j = 0; j < 60; j++)
        {
            b[j] += bits[j];
        }
    }
    static const int INF = 1e9 + 7;
    ModInt<INF> ans = 0;
    for (int i = 0; i < 60; i++)
    {
        ans += ModInt<INF>::pow(2, i) * b[i] * (n - b[i]);
    }
    cout << ans << "\n";
}