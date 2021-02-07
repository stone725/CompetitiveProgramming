#include <iostream>
#include <cstdint>
#include <vector>
#include <numeric>
#include <map>

class RuntimeModInt
{
    using u64 = std::uint_fast64_t;

    static u64 &mod()
    {
        static u64 mod_ = 0;
        return mod_;
    }

public:
    u64 num;

    RuntimeModInt(const u64 x = 0) : num(x % get_mod()) {}
    u64 &value() noexcept { return num; }
    const u64 &value() const noexcept { return num; }
    RuntimeModInt operator+(const RuntimeModInt rhs) const
    {
        return RuntimeModInt(*this) += rhs;
    }
    RuntimeModInt operator-(const RuntimeModInt rhs) const
    {
        return RuntimeModInt(*this) -= rhs;
    }
    RuntimeModInt operator*(const RuntimeModInt rhs) const
    {
        return RuntimeModInt(*this) *= rhs;
    }
    RuntimeModInt operator/(const RuntimeModInt rhs) const
    {
        return RuntimeModInt(*this) /= rhs;
    }

    RuntimeModInt &operator+=(const RuntimeModInt rhs)
    {
        num += rhs.num;
        if (num >= get_mod())
        {
            num -= get_mod();
        }
        return *this;
    }
    RuntimeModInt &operator-=(const RuntimeModInt rhs)
    {
        if (num < rhs.num)
        {
            num += get_mod();
        }
        num -= rhs.num;
        return *this;
    }
    RuntimeModInt &operator*=(const RuntimeModInt rhs)
    {
        num = num * rhs.num % get_mod();
        return *this;
    }
    RuntimeModInt &operator/=(RuntimeModInt rhs)
    {
        u64 exp = get_mod() - 2;
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

    RuntimeModInt &operator=(const u64 num) noexcept
    {
        this->num = num % get_mod();
        return *this;
    }

    RuntimeModInt pow(u64 k)
    {
        return pow(num, k);
    }

    RuntimeModInt pow(RuntimeModInt x, u64 k)
    {
        if (k == 0)
            return 1;
        if (k % 2 == 0)
            return pow((x * x).num % get_mod(), k / 2);
        else
            return (x * pow(x, k - 1)).num % get_mod();
    }
    static void set_mod(const u64 x) { mod() = x; }
    static u64 get_mod() { return mod(); }
};

std::ostream &operator<<(std::ostream &out, const RuntimeModInt &m)
{
    out << m.num;
    return out;
}

std::istream &operator>>(std::istream &in, RuntimeModInt &m)
{
    in >> m.num;
    if (m.num >= m.get_mod())
    {
        m.num %= m.get_mod();
    }
    return in;
}

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    RuntimeModInt::set_mod(m);
    vector<RuntimeModInt> a(n), b(n + 1);
    for (auto &&i : a)
    {
        cin >> i;
    }
    for (int i = 0; i < n; i++)
    {
        b[i + 1] = b[i] + a[i];
    }
    map<uint_fast64_t, int> cnt;
    long long ans = 0;
    for (auto &&i : b)
    {
        ans += cnt[i.num];
        cnt[i.num]++;
    }
    cout << ans << "\n";
}