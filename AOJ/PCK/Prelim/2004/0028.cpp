#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int cnt[101] = {}, most = 0, a;
    while(cin >> a){
        most = max(most, ++cnt[a]);
    }
    for(int i = 1; i <= 100; i++){
        if(most == cnt[i]){
            cout << i << "\n";
        }
    }
}