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

double sigmoid(double x){
    return 1/(1+exp(-x));
}

double getSi(double x){
    return log(-x/(x-1));
}

double getQi(double x){
    return log((1/x)-1);
}

void solve(){
    vector<vector<bool>> vec(100, vector<bool> (10000, false));
    vector<double> playerSkill(100);

    FOR(i, 100){
        string s;
        cin >> s;
        ll count = 0;
        FOR(j, 10000){
            vec[i][j] = s[j] == '1' ? 1 : 0;
            if(j < 5000){
                count += s[j] == '1' ? 1 : 0;
            }            
        }
        playerSkill[i] = getSi(((double)count)/10000.0);
    }

    vector<double> questionDifficulty(10000);
    FOR(i, 10000){
        ll ansCount = 0;
        FOR(j, 100){
            ansCount += vec[j][i];
        }
        questionDifficulty[i] = getQi(((double)ansCount)/100.0);
    }


    double maxAbsOutfit = 0.0;
    int cheater = 0;

    FOR(i, 100){
        double outfit = 0.0;
        FORAB(j, 5000, 10000){
            double ex = exp(playerSkill[i]-questionDifficulty[j]);
            double p = ex / (1 + ex);
            outfit += (vec[i][j]-p)*(vec[i][j]-p)/(p*(1-p));
        }
        if(abs(outfit) > maxAbsOutfit){
            maxAbsOutfit = abs(outfit);
            cheater = i;
        }
    }
    cout << cheater+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, P;
    cin >> T >> P;
    FOR(i,T){
    	cout << "Case #" << i+1 << ": ";
    	solve();
    	cout << '\n';
    }
    return 0;
}
