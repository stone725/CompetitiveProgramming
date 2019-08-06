#include <iostream>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    set<pair<int, int>> pairs;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pairs.insert(make_pair(min(a, b), max(a, b)));
    }
    cout << pairs.size() << "\n";
}