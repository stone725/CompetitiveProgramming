#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dp[10000001];
vector<bool> isprime;
vector<int> primenumber;

int solve(int now){
    if(now == 1){
        return 1;
    }
    if(isprime[now]){
        return 2;
    }
    if(~dp[now]){
        return dp[now];
    }
    for(int i = 0; primenumber[i] * primenumber[i] <= now; i++){
        if(now % primenumber[i] == 0){
            int div = primenumber[i];
            int cnt = 0;
            int score = now;
            while(score % div == 0){
                cnt++;
                score /= div;
            }
            return dp[now] = (cnt + 1) * solve(score); 
        }
    }
}

int main(){
    isprime.resize(10000001, true);
    isprime[0] = isprime[1] = 0;
    for(int i = 2; i * i <= 1e7; i += 2){
        if(!isprime[i]){
            continue;
        }
        for(int j = i * i; j <= 1e7; j += i){
            isprime[j] = false;
        }
        if(i == 2){
            i--;
        }
    }
    for(int i = 0; i <= isprime.size(); i++){
        if(isprime[i]){
            primenumber.push_back(i);
        }
    }
    int n;
    long long ans = 0;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(long long i = n; i > 0; i--){
        ans += i * solve(i);
    }
    cout << ans << "\n";
}