#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    double l, x, y, s, d;
    cin >> l >> x >> y >> s >> d;
    cout << fixed << setprecision(10);
    if(d < s){
        if(y < x){
            cout << (d + l - s) / (x + y) << "\n";
            return 0;
        }
        cout << min((d + l - s) / (x + y), (s - d) / (y - x)) << "\n";
    }else{
        if(y < x){
            cout << (d - s) / (x + y) << "\n";
        }else{
            cout << min((d - s) / (x + y), (s + l - d) / (y - x)) << "\n";
        }
    }
}