#include <iostream>

using namespace std;

int main(){
    int cnt[4] = {};
    for(int i = 0; i < 3; i++){
        int a, b;
        cin >> a >> b;
        cnt[a - 1]++;
        cnt[b - 1]++;
        if(cnt[a - 1] == 3 || cnt[b - 1] == 3){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}