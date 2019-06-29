//コンテスト後
#include <iostream>
#include <vector>

using namespace std;

int INF = 1e9 + 7;

long long c[2000][2000];

void setPascal(int N){
    for(int i = 0; i < N; i++){
        c[i][0] = 1;
        for(int j = 1; j <= i; j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= INF;
        }
    }
}

void solve(){
    setPascal(2000);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        if(i == 1 && n == k){
            cout << 1 << "\n";
            continue;
        }
        if(i == n){
            cout << 0 << "\n";
            continue;
        }
        long long ans = c[n - k + 1][i] * c[k - 1][i - 1];
        ans %= INF;
        cout << ans << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    solve();
}