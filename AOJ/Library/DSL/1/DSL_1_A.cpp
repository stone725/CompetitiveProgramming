#include <iostream>
#include <vector>

struct Union_Find {
    std::vector<int> par;
    std::vector<int> rank;
    
    //初期化
    void init( int n ) {
        par.resize( n );
        rank.resize( n );
        for ( int i = 0; i < n; ++i ) {
            par[ i ] = i;
            rank[ i ] = 0;
        }
    }
    
    //木の根を探す
    int find( int s ) {
        if ( par[ s ] == s ) {
            return s;
        }
        return par[ s ] = find( par[ s ] );
    }
    
    //結合
    void unite( int x, int y ) {
        int a = find( x ), b = find( y );
        if ( a == b ) {
            return;
        }
        if ( rank[ a ] < rank[ b ] ) {
            par[ a ] = b;
        }
        else {
            par[ a ] = b;
            if ( rank[ a ] == rank[ b ] ) {
                ++rank[ b ];
            }
        }
    }
    
    //二つの数の根が同じかどうか
    bool same( int x, int y ) {
        return find( x ) == find( y );
    }
    
    //サイズを返す
    unsigned int size() {
        return par.size();
    }
};

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    Union_Find uf;
    uf.init(n);
    while(q--){
        int com, x, y;
        cin >> com >> x >> y;
        if(com){
            cout << uf.same(x, y) << "\n";
        }else{
            uf.unite(x, y);
        }
    }
}