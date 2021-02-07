#include <iostream>
#include <string>
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
        return this->num;
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

int main()
{
    static const int INF = 1e9 + 7;
    int n;
    cin >> n;
    string str;
    cin >> str;
    ModInt<INF> ans = 1;
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (str[i] == 'W')
        {
            if ((cnt) % 2 == 0)
            {
                ans *= cnt;
                cnt--;
            }
            else
            {
                cnt++;
            }
        }
        else
        {
            if ((cnt) % 2 == 1)
            {
                ans *= cnt;
                cnt--;
            }
            else
            {
                cnt++;
            }
        }
        if (cnt < 0)
        {
            cout << "0\n";
            return 0;
        }
    }
    if (cnt)
    {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    cout << ans << "\n";
}