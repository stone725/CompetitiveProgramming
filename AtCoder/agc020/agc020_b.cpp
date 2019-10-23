#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<long long> a;

bool check(long long mid){
    for(auto&& i : a){
        mid -= mid % i;
    }
    return 2 <= mid;
}

bool check2(long long mid){
    for(auto&& i : a){
        mid -= mid % i;
    }
    return mid <= 2;
}

int main(){
    int n;
    cin >> n;
    a.resize(n);
    long long s1 = 0, g1 = 1ll << 60;
    for(auto&& i : a){
        cin >> i;
        g1 = max(g1, i);
    }
    g1 *= 2;
    if(a.back() != 2){
        cout << "-1\n";
        return 0;
    }
    set<long long> s;
    while(abs(s1 - g1) > 1){
        long long mid = (s1 + g1) / 2;
        if(check(mid)){
            g1 = mid;
        }else{
            s1 = mid;
        }
    }
    long long s2 = 0, g2 = 1ll << 60;
    while(abs(s2 - g2) > 1){
        long long mid = (s2 + g2) / 2;
        if(check2(mid)){
            s2 = mid;
        }else{
            g2 = mid;
        }
    }
    if(g1 > s2){
        cout << "-1\n";
        return 0;
    }
    cout << g1 << " " << s2 << "\n";
}