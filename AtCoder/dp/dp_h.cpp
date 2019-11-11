#include <iostream>
#include <string>
#include <vector>
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

int main(){
    static const int INF = 1e9 + 7;
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for(auto&& i : a){
        cin >> i;
    }
    vector<vector<ModInt<INF>>> dp(h + 1, vector<ModInt<INF>>(w + 1));
    for(int i = 1; i < h; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i < w; i++){
        dp[0][i] = 0;
    }
    dp[0][1] = 1;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(a[i - 1][j - 1] == '#'){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[h][w] << "\n";
}