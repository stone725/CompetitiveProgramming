#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto&& i : a){
        cin >> i;
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for(auto&& i : b){
        cin >> i;
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    for(auto&& i : a){
        for(auto&& j : b){
            if(binary_search(begin(a), end(a), i + j) || binary_search(begin(b), end(b), i + j)){
                continue;
            }
            cout << i << " " << j << "\n";
            return 0;
        }
    }
}