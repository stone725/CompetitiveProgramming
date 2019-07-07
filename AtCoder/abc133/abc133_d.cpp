#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
vector<int> a;

int check(int mid){
    vector<int> b = a;
    for(int i = 0; i < n; i++){
        b[i] -= mid;
        b[(i + n - 1) % n] -= mid;
        mid = b[i];
    }
    if(b[n - 1] > 0) return 1;
    return 0;
}

int main(){
    cin >> n;
    a.resize(n);
    for(auto&& i : a){
        cin >> i;
    }
    int start = 0, end = min(a[0], a[n - 1]) + 1;
    while(start < end){
        int mid = (start + end) / 2;
        int score = check(mid);
        if(score == 0){
            end = mid;
        }
        if(score == 1){
            start = mid + 1;
        }
    }
    for(int i = 0; i < n - 1; i++){
            cout << start * 2 << " ";
            start = a[i] - start;
    }
    cout << start * 2 << "\n";
}