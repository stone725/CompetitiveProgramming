#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> a(n);
    for(auto&& i : a){
        cin >> i;
    }    
    sort(begin(a), end(a));
    for(int i = 1; i < n; i++){
        a[i] = (a[i] + a[i - 1]) / 2;
    }
    cout << setprecision(13) << a[n - 1] << "\n";
}