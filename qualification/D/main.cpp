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

int T,N,Q;

void query(int a, int b, int c){
    cout << a << " " << b << " " << c << endl;
    Q--;
}

int ans(){
    int tmp;
    cin >> tmp;
    return tmp;
}

bool subsolve(vector<int> &vec, int ref, bool right, bool start){
    if(vec.size() == 1 || vec.empty()){
        return false;
    }
    if(vec.size() == 2){
        query(vec[0], vec[1], ref);
        int a = ans();
        if(right){
            if(vec[0] == a){
                vec[0] = vec[1];
                vec[1] = a;
            }
        }
        else{
            if(vec[1] == a){
                vec[1] = vec[0];
                vec[0] = a;
            }
        }
        return false;
    }
    query(vec[0], vec[1], vec[2]);
    int a = 0, c = 0, b = ans();
    if(b == vec[0]){
        a = vec[1]; c = vec[2];
    } else if(b == vec[1]){
        a = vec[0]; c = vec[2];
    } else{
        a = vec[0]; c = vec[1];
    }

    if(!start){
        query(a,c,ref);
        int k = ans();
        if((right && k == a) || (!right && k == c)){
            swap(a,c);
        }
    }
    
    vector<int> left;
    vector<int> middle;
    middle.pb(b);
    vector<int> rightv;

    for(int i = 3; i < vec.size(); ++i){
        query(vec[i],a,c);
        int med = ans();
        if(med == vec[i]){
            middle.pb(vec[i]);
        } else if(med == a){
            left.pb(vec[i]);
        } else {
            rightv.pb(vec[i]);
        }
    }

    bool result = false;
    result |= subsolve(left, a, true, false);
    result |= subsolve(middle, c, true, false);
    result |= subsolve(rightv, c, false, false);

    vector<int> newvec;
    newvec.insert(newvec.end(), left.begin(), left.end());
    newvec.pb(a);
    newvec.insert(newvec.end(), middle.begin(), middle.end());
    newvec.pb(c);
    newvec.insert(newvec.end(), rightv.begin(), rightv.end());
    vec = newvec;
    return result;
}

bool solve(){
    vector<int> v;
    FOR(i, N){
        v.pb(i+1);
    }
    subsolve(v, 1, true, true);
    FOR(i, N){
        cout << v[i] << " ";
    }
    cout << endl;
    return ans();
}

int main(){
    cin >> T >> N >> Q;
    FOR(i,T){
        if(!solve()){
            return 1;
        }
    }
    return 0;
}
