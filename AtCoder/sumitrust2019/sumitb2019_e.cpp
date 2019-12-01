#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint>
#include <tuple>
#include <algorithm>
#include <map>

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

static const int INF = 1e9 + 7;
int n;
vector<int> a;
map<tuple<int, int, int>, ModInt<INF>> dp;

ModInt<INF> dfs(int mx, int mid, int mn){
    if(mx + mid + mn == n){
        return 1;
    }
    auto status = make_tuple(mx, mid, mn);
    if(dp.count(status)) return dp[status];
    int p = mx + mid + mn;
    ModInt<INF> res = 0;
    if(mx == a[p]){
        res += dfs(mx + 1, mid, mn);
    }
    if(mid == a[p]){
        res += dfs(mx, mid + 1, mn);
    }
    if(mn == a[p]){
        res += dfs(mx, mid, mn + 1);
    }
    return dp[status] = res;
}

int main(){
    cin >> n;
    a.resize(n);
    for(auto&& i : a){
        cin >> i;
    }
    ModInt<INF> ans = dfs(0, 0, 0);
    cout << ans << "\n";
}