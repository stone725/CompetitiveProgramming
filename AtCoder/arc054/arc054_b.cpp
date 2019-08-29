#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double p;

double calc(double mid){
    return mid + p / pow(2, mid / 1.5);
}

int main(){
    cin >> p;
    double s = 0, g = 1e18;
    for(int i = 0; i < 1000; i++){
        double mid1 = (s * 2 + g) / 3;
        double mid2 = (s + g * 2) / 3;
        if(calc(mid1) > calc(mid2)){
            s = mid1;
        }else{
            g = mid2;
        }
    }
    cout << setprecision(10) << calc(s) << "\n";
}