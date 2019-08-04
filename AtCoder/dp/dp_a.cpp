#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n), cost(n, -1);
    for(auto&& i : h){
        cin >> i;
    }
    cost[0] = 0;
    for(int i = 1; i < n; i++){
        cost[i] = cost[i - 1] + abs(h[i - 1] - h[i]);
        if(2 <= i){
            cost[i] = min(cost[i], cost[i - 2] + abs(h[i - 2] - h[i]));
        }
    }
    cout << cost[n - 1] << "\n";
}