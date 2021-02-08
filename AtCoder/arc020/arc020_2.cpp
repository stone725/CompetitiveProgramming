#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, c;
    cin >> n >> c;
    int color[2][10] = {};

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        color[i % 2][a - 1]++;
    }
    int ans = c * n;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i == j){
                continue;
            }
            ans = min(ans, (((n / 2 + n % 2) - color[0][i]) + ((n / 2) - color[1][j])) * c);
        }
    }
    cout << ans << "\n";
}