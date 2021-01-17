//--------my brain isn't at home right now------------------
#include<bits/stdc++.h>  
 
using namespace std; 
//https://www.spoj.com/problems/RPLB/
 
#define pb push_back
#define fi first
#define se second
#define nl '\n'
typedef long long ll;
 
void Solve(int t){
    int n, k;
    cin>>n>>k;
    vector<int> v(n + 2);
    for(int i = 2; i < n + 2; i++){
        cin>>v[i];
    }
    vector<vector<int>> dp(n + 2, vector<int> (k + 1));
    for(int i = 2; i <= n + 1; i++){
        for(int j = 0; j <= k; j++){
            if(v[i] > j) dp[i][j] = dp[i - 1][j];
            else{
                dp[i][j] = dp[i - 1][j];
                if(dp[i - 2][j - v[i]] + v[i] <= k) dp[i][j] = max(dp[i][j], dp[i - 2][j - v[i]] + v[i]);
            }
        }
    }
    int res = 0;
    for(int i = 0; i <= n + 1; i++){
        res = max(res, dp[i][k]);
    }
    cout<<"Scenario #"<<t<<": "<<res<<nl;
 
}
int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T= 1;
    cin>>T;
    for(int i = 1; i <= T; i++){
        Solve(i);
    }
}