#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a, b;
    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        if(num || a.size()){
            a.push_back(num);
        }
    }
    for(int i = 0; i < m; i++){
        long long num;
        cin >> num;
        if(num || b.size()){
            b.push_back(num);
        }
    }
    if(a.size() < b.size()){
        cout << "X\n";
        return 0;
    }else if(b.size() < a.size()){
        cout << "Y\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]){
            cout << "X\n";
            return 0;
        }else if(b[i] < a[i]){
            cout << "Y\n";
            return 0;
        }
    }
    cout << "Same\n";
}