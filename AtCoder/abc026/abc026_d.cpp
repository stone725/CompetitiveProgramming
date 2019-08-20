#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int a, b, c;
static const double pi = acos(-1.0);

double calc(double t){
    return a * t + b * sin(c * t * pi);
}

int main(){
    cin >> a >> b  >> c;
    double s = 0, g = 300;
    for(int i = 0; i < 200000; i++){
        double mid = (s + g) / 2;
        if(calc(mid) < 100){
            s = mid;
        }else{
            g = mid;
        }
    }
    cout << setprecision(15) << s << "\n";
}