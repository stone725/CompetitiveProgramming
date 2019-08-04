#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto&& i : a){
        cin >> i;
    }
    for(int i = n - 1; i > 0; i--){
        if(a[i] - a[i - 1] < -1){
            cout << "No\n";
            return 0;
        }
        else if(a[i] - a[i - 1] == -1){
            a[i - 1]--;
        }
    }
    cout << "Yes\n";
}