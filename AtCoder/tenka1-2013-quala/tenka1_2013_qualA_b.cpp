#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    while(n--){
        int sum = 0;
        for(int i = 0; i < 5; i++){
            int d;
            cin >> d;
            sum += d;
        }
        ans += sum < 20;
    }
    cout << ans << "\n";
}