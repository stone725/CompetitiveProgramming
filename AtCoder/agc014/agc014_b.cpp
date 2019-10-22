#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    set<int> s;
    while(m--){
        int a, b;
        cin >> a >> b;
        if(s.count(a)){
            s.erase(a);
        }else{
            s.insert(a);
        }
        if(s.count(b)){
            s.erase(b);
        }else{
            s.insert(b);
        }
    }
    if(s.size()){
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }
}