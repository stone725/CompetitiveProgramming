#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;
int w, h;
static const int INF = 1e9 + 7;

vector<long long> fact;
vector<long long> revfact;

int powMod(long long x, int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return powMod(x * x % INF, k / 2);
    else	return x * powMod(x, k - 1) % INF;
}

void setfact(int N){
    fact.resize(N + 1);
    revfact.resize(N + 1);
    fact[0] = 1;
    for(int i = 1; i < N + 1; i++){
        fact[i] = fact[i - 1] * i;
        fact[i] %= INF;
    }
    revfact[N] = powMod(fact[N], INF - 2);
    for(int i = N - 1; i >= 0; i--){
        revfact[i] = revfact[i + 1] * (i + 1);
        revfact[i] %= INF;
    }
}

long long getC(int a, int b){
    return (((fact[a] * revfact[b]) % INF) * revfact[a - b]) % INF;
}

int main(){
    cin >> w >> h;
    w--;
    h--;
    setfact(w + h);
    cout << getC(w + h, w) << "\n";
}