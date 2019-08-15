#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    string checkstr = "";
    for(int i = 0; checkstr.size() <= n; i++){
        checkstr += to_string(i);
    }
    cout << checkstr[n] << "\n";
}