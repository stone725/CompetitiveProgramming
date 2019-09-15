#include <iostream>
#include <string>

using namespace std;

int n;
string str;

bool check(int mid){
    for(int i = 0; i < n - mid; i++){
        if(string(str.begin() + i + mid, str.end()).find(str.substr(i, mid)) != string::npos){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n;
    cin >> str;
    int s = 0, g = n / 2 + 1;
    while(g - s > 1){
        int mid = (s + g) / 2;
        if(check(mid)){
            s = mid;
        }else{
            g = mid;
        }
    }
    cout << s << "\n";
}