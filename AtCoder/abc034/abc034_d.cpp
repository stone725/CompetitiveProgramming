#include <iostream>
#include <utility>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int n, k;
vector<pair<int, int>> w;

bool check(double mid){
    vector<double> scores(n);
    for(int i = 0; i < n; i++){
        scores[i] = (1. * w[i].second - mid) * w[i].first;
    }
    sort(rbegin(scores), rend(scores));
    double score = 0;
    for(int i = 0; i < k; i++){
        score += scores[i];
    }
    return score > -1e-10;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    w.resize(n);
    for(auto&& i : w){
        cin >> i.first >> i.second;
    }
    double ok = 0, ng = 100.0;
    for(int i = 0; i < 1000; i++){
        double mid = (ok + ng) / 2;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << fixed << setprecision(10) << ok << "\n";
}