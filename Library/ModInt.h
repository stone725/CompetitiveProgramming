//参考：http://noshi91.hatenablog.com/entry/2019/03/31/174006
#include <cstdint>
#include <iostream>

template <std::uint_fast64_t Mod>
class ModInt
{
    using u64 = uint_fast64_t;

public:
    u64 num;
    constexpr u64 getMod() noexcept { return Mod; }
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
