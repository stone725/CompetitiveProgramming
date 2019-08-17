#include <iostream>
#include <iomanip>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

int n;
long long d;
map<pair<int, long long>, double> dp;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

double dfs(int now, long long m){
    if(now == n) return m == 1;
    auto status = make_pair(now, m);
    if(dp.count(status)) return dp[status];
    double res = 0;
    for(int i = 1; i <= 6; i++){
        res += dfs(now + 1, m / gcd(m, i));
    }
    res /= 6;
    return dp[status] = res;
}

int main(){
    cin >> n >> d;
    cout << fixed << setprecision(9) << dfs(0, d) << "\n";
}