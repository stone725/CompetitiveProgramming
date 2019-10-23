#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    cin >> n;
    int s = 0, g = n - 1;
    string info;
    cout << n - 1 << "\n";
    cout.flush();
    cin >> info;
    if(info == "Vacant"){
        return 0;
    }
    while(true){
        int mid = (s + g) / 2;
        cout << mid << "\n";
        cout.flush();
        string res;
        cin >> res;
        if(res == "Vacant"){
            return 0;
        }
        if(res == info && mid % 2 == (n - 1) % 2){
            g = mid;
        }else if(res != info && mid % 2 != (n - 1) % 2){
            g = mid;
        }else{
            s = mid;
        }
    }
}