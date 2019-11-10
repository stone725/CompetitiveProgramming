#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

template<std::uint_fast64_t Mod>
class ModInt{
    using u64 = uint_fast64_t;
public:
    u64 num;
    constexpr ModInt(const u64 x = 0) noexcept : num(x % Mod) {}
    constexpr u64 &value() noexcept { return num; }
    constexpr const u64 &value() const noexcept { return num; }
    constexpr ModInt operator+(const ModInt rhs) const noexcept {
        return ModInt(*this) += rhs;
    }
    constexpr ModInt operator-(const ModInt rhs) const noexcept {
        return ModInt(*this) -= rhs;
    }
    constexpr ModInt operator*(const ModInt rhs) const noexcept {
        return ModInt(*this) *= rhs;
    }
    constexpr ModInt operator/(const ModInt rhs) const noexcept {
        return ModInt(*this) /= rhs;
    }
    constexpr ModInt &operator+=(const ModInt rhs) noexcept {
        num += rhs.num;
        if (num >= Mod) {
            num -= Mod;
        }
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt rhs) noexcept {
        if (num < rhs.num) {
            num += Mod;
        }
        num -= rhs.num;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt rhs) noexcept {
        num = num * rhs.num % Mod;
        return *this;
    }
    constexpr ModInt &operator/=(ModInt rhs) noexcept {
        u64 exp = Mod - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr ModInt &operator=(const u64 num) noexcept {
        this->num = num % Mod;
        return *this;
    }

    constexpr ModInt pow(u64 k){
        return pow(num, k);
    }

    static constexpr ModInt pow(ModInt x, u64 k){
        if(k == 0) return 1;
        if(k % 2 == 0) return pow((x * x).num % Mod, k / 2);
        else return (x * pow(x, k - 1)).num % Mod;
    }
};

template<std::uint_fast64_t Mod>
std::ostream &operator<<(std::ostream &out, const ModInt<Mod> &m)
{
    out << m.num;
    return out;
}
using namespace std;

static const int INF = 998244353;

int n;
vector<int> d;

int main(){
    cin >> n;
    d.resize(n);
    for(auto&& i : d){
        cin >> i;
    }
    if(d[0] != 0){
        cout << "0\n";
        return 0;
    }
    sort(begin(d), end(d));
    if(d[1] == 0){
        cout << "0\n";
        return 0;
    }
    vector<int> cnt(d.back() + 1);
    for(auto&& i : d){
        cnt[i]++;
    }
    vector<ModInt<INF>> dp(d.back() + 1);
    dp[0] = dp[1] = 1;
    for(int i = 2; i < cnt.size(); i++){
        dp[i] = dp[i - 1] * ModInt<INF>::pow(cnt[i - 1], cnt[i]);
    }
    cout << dp.back() << "\n";
}