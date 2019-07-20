#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a, b;

int main(){
    cin >> n;
    a.resize(n);
    for(auto&& i : a){
        cin >> i;
    }
    for(int i = n; i > 0; i--){
        if(a[i - 1]){
            b.push_back(i);
            for(int j = 1; j * j <= i; j++){
                if(i % j) continue;
                a[j - 1] = !a[j - 1];
                if(j * j < i){
                    a[i / j - 1] = !a[i / j - 1];
                }
            }
        }
    }
    cout << b.size() << "\n";
    if(b.size()){
        cout << b[0];
        for(int i = 1; i < b.size(); i++){
            cout << " " << b[i];
        }
        cout << "\n";
    }
}