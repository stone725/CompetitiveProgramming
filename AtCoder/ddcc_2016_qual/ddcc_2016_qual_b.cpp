#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

long long r, n, m;

long double score(long long num){
    if(num < 1 || n <= num) return 0;
    num *= 2;
    return sqrtl(r * r - (1. * r / n * (num - n)) * (1. * r / n * (num - n))) * 2;
}

int main(){
    cin >> r >> n >> m;
    long double ans = 0;
    for(int i = 1; i < n + m; i++){
        ans += max(score(i), score(i - m));
    }
    cout << fixed << setprecision(10) << ans << "\n";
}