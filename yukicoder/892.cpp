#include <iostream>

using namespace std;

int main(){
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        int a, b;
        cin >> a >> b;
        cnt += a % 2;
    }
    if(cnt % 2){
        cout << ":-(\n";
    }else{
        cout << ":-)\n";
    }
}