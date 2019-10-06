#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;

int bubbleSort(){
    int cnt = 0;
    bool flag;
    do{
        flag = false;
        for(int i = a.size() - 1; i > 0; i--){
            if(a[i] < a[i - 1]){
                swap(a[i], a[i - 1]);
                flag = true;
                cnt++;
            }
        }
    }while(flag);
    return cnt;
}

int main(){
    int n;
    cin >> n;
    a.resize(n);
    for(auto&& i : a){
        cin >> i;
    }
    int ans = bubbleSort();
    for(int i = 0; i < n - 1; i++){
        cout << a[i] << " ";
    }
    cout << a[n - 1] << "\n";
    cout << ans << "\n";
}