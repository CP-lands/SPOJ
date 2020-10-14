#include<bits/stdc++.h>

//https://www.spoj.com/problems/KGSS/
using namespace std;
const int N = 100000;

int tree[4 * N][2];
int v[N];
int res[4 * N][2];
int k[4];

void build(int u, int a, int b){
    if(a == b){
        tree[u][0] = v[a];
        tree[u][1] = INT_MIN;
        return;
    }
    int mid = a + (b - a) / 2;
    build(2 * u, a, mid);
    build(2 * u + 1, mid + 1, b);
    k[0] = tree[2 * u][0];
    k[1] = tree[2 * u][1];
    k[2] = tree[2 * u + 1][0];
    k[3] = tree[2 * u + 1][1];
    sort(k, k + 4);
    tree[u][0] = k[3];
    tree[u][1] = k[2];
}
void update(int u, int a, int b, int i, int val){
    if(a > i || b < i) return;
    if(a == i && b == i){
        v[i] = val;
        tree[u][0] = val;
        tree[u][1] = INT_MIN;
        return;
    }
    int mid = a + (b - a) / 2;
    update(2 * u, a, mid, i, val);
    update(2 * u + 1, mid + 1, b, i, val);
    k[0] = tree[2 * u][0];
    k[1] = tree[2 * u][1];
    k[2] = tree[2 * u + 1][0];
    k[3] = tree[2 * u + 1][1];
    sort(k, k + 4);
    tree[u][0] = k[3];
    tree[u][1] = k[2];
}
void getRes(int u, int a, int b, int x, int y){
    if(a > y || b < x){
        res[u][0] = res[u][1] = INT_MIN;
        return;
    }
    if(a >= x && b <= y){
        res[u][0] = tree[u][0];
        res[u][1] = tree[u][1];
        return;
    }
    int mid = a + (b - a) / 2;
    getRes(2 * u, a, mid, x, y);
    getRes(2 * u + 1, mid + 1, b, x, y);
    k[0] = res[2 * u][0];
    k[1] = res[2 * u][1];
    k[2] = res[2 * u + 1][0];
    k[3] = res[2 * u + 1][1];
    sort(k, k + 4);
    res[u][0] = k[3];
    res[u][1] = k[2];
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>v[i];
    int q;
    cin>>q;
    build(1, 0, n - 1);
    while(q--){
        char c;
        int x, y;
        cin>>c>>x>>y;
        if(c == 'U') update(1, 0, n - 1, x - 1, y);
        else{
            getRes(1, 0, n - 1, x - 1, y - 1);
            cout<<res[1][0] + res[1][1]<<'\n';
        }
    }
}