#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        string str = to_string(i);
        int num = 0;
        for(auto&& j : str){
            num += j - '0';
        }
        ans += (a <= num && num <= b) * i;
    }
    cout << ans << "\n";
}