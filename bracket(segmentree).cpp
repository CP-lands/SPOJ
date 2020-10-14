#include<bits/stdc++.h>

using namespace std;

//https://www.spoj.com/problems/BRCKTS/
const int N = 30001;
int l[4 * N];
int r[4 * N];
string s;

void build(int u, int a, int b){
    if(a == b){
        if(s[a] == '('){
            l[u] = 1;
            r[u] = 0;
        }
        else{
            l[u] = 0;
            r[u] = 1;
        }
        return;
    }
    int mid = a + (b - a) / 2;
    build(2 * u, a, mid);
    build(2 * u + 1, mid + 1, b);
    int k = min(l[2 * u], r[2 * u + 1]);
    l[u] = l[2 * u] + l[2 * u + 1] - k;
    r[u] = r[2 * u + 1] + r[2 * u] - k;
}
void update(int u, int a, int b, int index){
    if(a > index || b < index) return;
    if(a == index && b == index){
        if(s[a] == '(') s[a] = ')';
        else s[a] = '(';
        if(l[u] == 0) l[u] = 1;
        else l[u] = 0;
        if(r[u] == 0) r[u] = 1;
        else r[u] = 0;
        return;
    }
    int mid = a + (b - a) / 2;
    update(2 * u, a, mid, index);
    update(2 * u + 1, mid + 1, b, index);
    int k = min(l[2 * u], r[2 * u + 1]);
    l[u] = l[2 * u] + l[2 * u + 1] - k;
    r[u] = r[2 * u + 1] + r[2 * u] - k;
}
void Solve(){
    int n, m;
    cin>>n>>s>>m;
    build(1, 0, n - 1);
    while(m--){
        int operation;
        cin>>operation;
        if(operation == 0){
            if(l[1] == r[0]) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            update(1, 0, n - 1, operation - 1);
        }
    }

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 10;
    //cin>>t;
    for(int i = 1; i <= t; i++){
        cout<<"Test "<<i<<":\n";
        Solve();
    }
}