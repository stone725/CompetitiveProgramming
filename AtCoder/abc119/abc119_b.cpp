#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    const double BTCJPY = 380000.0;
    int n;
    cin >> n;
    double ans = 0;
    for(int i = 0; i < n; i++){
        double x;
        string str;
        cin >> x >> str;
        if(str == "JPY"){
            ans += x;
        }else{
            ans += x * BTCJPY;
        }
    }
    cout << fixed << setprecision(10) << ans << "\n";
}