#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    static const long double pi = acosl(-1.0);
    long double a, b, x, ans;
    cin >> a >> b >> x;
    if(a * a * b < x * 2){
        ans = atan(2 * (a * a * b - x) / (a * a * a)) / pi * 180;
    }else{
        ans = atan((a * b * b) / (2 * x)) / pi * 180;
    }
    cout << fixed << setprecision(11) << ans << "\n";
}