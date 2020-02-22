#include <iostream>
#include <cstdint>
#include <vector>

template <unsigned long long Mod>
class ModInt
{
    using u64 = unsigned long long;

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

template <unsigned long long Mod>
std::ostream &operator<<(std::ostream &out, const ModInt<Mod> &m)
{
    out << m.num;
    return out;
}

template <unsigned long long Mod>
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
int n, a, b;

ModInt<INF> getC(int a, int b)
{
    ModInt<INF> ans = 1;
    if (b > a / 2)
    {
        return getC(a, a - b);
    }
    ModInt<INF> div = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a - i;
        div *= i + 1;
    }
    ans *= ModInt<INF>::pow(div, INF - 2);
    return ans;
}

int main()
{
    cin >> n >> a >> b;
    ModInt<INF> ans = ModInt<INF>::pow(2, n) - 1;
    ModInt<INF> aC = getC(n, a), bC = getC(n, b);
    if (ans.num < aC.num)
    {
        ans.num += INF - aC.num;
        ans.num %= INF;
    }
    else
    {
        ans -= aC;
    }
    if (ans.num < bC.num)
    {
        ans.num += INF - bC.num;
        ans.num %= INF;
    }
    else
    {
        ans -= bC;
    }
    cout << ans << "\n";
}