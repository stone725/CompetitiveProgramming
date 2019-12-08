#include <iostream>

using namespace std;

int main(){
    int sum = 0;
    for(int i = 0; i < 3; i++){
        int a;
        cin >> a;
        sum += a;
    }
    if(22 <= sum){
        cout << "bust\n";
    }else{
        cout << "win\n";
    }
}