#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < 10; i++){
        if(n % i || 9 < n / i){
            continue;
        }
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
}