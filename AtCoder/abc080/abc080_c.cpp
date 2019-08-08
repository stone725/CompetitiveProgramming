#include <iostream>
#include <vector>
#include <array>
#include <bitset>
#include <algorithm>

using namespace std;

int n;
vector<bitset<10>> f;
vector<array<int, 11>> p;

long long dfs(int now, bitset<10> bits){
    if(now == 10){
        if(bits.count() == 0) return -1e9;
        long long res = 0;
        for(int i = 0; i < n; i++){
            res += p[i][bitset<10>(bits & f[i]).count()];
        }
        return res;
    }
    long long res = dfs(now + 1, bits);
    bits[now] = true;
    res = max(res, dfs(now + 1, bits));
    bits[now] = false;
    return res;
}

int main(){
    cin >> n;
    f.resize(n);
    p.resize(n);
    for(auto&& i : f){
        for(int j = 0; j < 10; j++){
            short num;
            cin >> num;
            i[j] = num;
        }
    }
    for(auto&& i : p){
        for(auto&& j : i){
            cin >> j;
        }
    }
    cout << dfs(0, 0) << "\n";
}