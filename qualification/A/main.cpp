#include <bits/stdc++.h>
using namespace std;

/////////////////////////
// START OF TEMPLATE   //
/////////////////////////
// Constants
#define INF (int)1e9
#define PI 3.14159265359
// Shorthand
#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define FOR(x, n) for(int x = 0; x < n; ++ x)
#define FORAB(x, a, b) for(int x = a; x < b; ++ x)
// Debug
template<typename T> void pvec(vector<T> &v){cout << "[";for(auto k : v){cout << k << ", ";}cout << "]" << endl;}
template<typename T> void parr(T *arr, size_t n){cout << "[";for(auto i = 0; i < n; ++i){cout << arr[i] << ", ";}cout << "]" << endl;}
template<class T1> void deb(T1 a1){cout << a1 << endl;}
template<class T1, class T2> void deb(T1 a1, T2 a2){cout << a1 << " | " << a2 << endl;}
template<class T1, class T2, class T3> void deb(T1 a1, T2 a2, T3 a3){cout << a1 << " | " << a2 << " | " << a3 << endl;}
template<class T1, class T2, class T3, class T4> void deb(T1 a1, T2 a2, T3 a3, T4 a4){cout << a1 << " | " << a2 << " | " << a3  << " | " << a4 << endl;}
/////////////////////////
// END OF TEMPLATE     //
/////////////////////////



void solve(){
    ll N;
    cin >> N;
    vector<ll> L;
    L.reserve(N);
    FOR(i,N){
        ll tmp;
        cin >> tmp;
        L.pb(tmp);
    }
    
    ll count = 0;
    FORAB(i,0,N-1){
        auto begin_it = L.begin() + i;
        auto it = min_element(begin_it, L.end());
        count += distance(begin_it, it+1);
        reverse(begin_it, it+1);
    }
    cout << count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    FOR(i,T){
    	cout << "Case #" << i+1 << ": ";
    	solve();
    	cout << '\n';
    }
    return 0;
}

