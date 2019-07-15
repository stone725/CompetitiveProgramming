#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for(auto&& i : a){
        cin >> i;
        sum += i;
    }
    int avg = sum / n, avg2 = sum / n + 1;
    int cnt = 0, cnt2 = 0;
    for(auto&& i : a){
        cnt += (i - avg) * (i - avg);
        cnt2 += (i - avg2) * (i - avg2);
    }
    cout << min(cnt, cnt2) << "\n";
}