#include<bits/stdc++.h>
 
using namespace std;
//https://www.spoj.com/problems/LCA/
 
const int N = 1e3 + 1;
int v[2 * N];
int depth[N];
vector<int> g[N];
int countt = 0;
int tree[8 * N];
int ver[N];
int n;
 
void dfs(int u, int p = -1){
	ver[u] = countt;
    v[countt++] = u;
    for(auto x: g[u]){
        if(x == p) continue;
        depth[x] = depth[u] + 1;
        dfs(x, u);
        v[countt++] = u;
    }
}
void build(int u, int a, int b){
	if(a == b){
		tree[u] = v[a];
		return;
	}
	int mid = a + (b - a) / 2;
	build(2 * u, a, mid);
	build(2 * u + 1, mid + 1, b);
	if(depth[tree[2 * u]] < depth[tree[2 * u + 1]]) tree[u] = tree[2 * u];
	else tree[u] = tree[2 * u + 1];
}
int lca(int u, int a, int b, int l, int r){
	if(a > r || b < l) return INT_MAX;
	if(a >= l && b <= r){
		return tree[u];
	}
	int mid = a + (b - a) / 2;
	int left = lca(2 * u, a, mid, l, r);
	int right = lca(2 * u + 1, mid + 1, b, l, r);
	if(left == INT_MAX) return right;
	if(right == INT_MAX) return left;
	if(depth[left] < depth[right]) return left;
	else return right;
	
}
void Solve(int test_case){
    cin>>n;
    for(int i = 1; i <= n; i++){
    	int childs;
    	cin>>childs;
    	while(childs--){
    		int u;
    		cin>>u;
    		g[u].push_back(i);
    		g[i].push_back(u);
    	}
    }
 
    depth[1] = 0;
    dfs(1);
    build(1, 0, 2 * n - 2);
    cout<<"Case "<<test_case<<":"<<'\n';
    int q;
    cin>>q;
    while(q--){
    	int a, b;
    	cin>>a>>b;
    	int l = ver[a];
    	int r = ver[b];
    	if(l > r) swap(l, r);
    	cout<<lca(1, 0, 2 * n - 2, l, r)<<'\n';
    }
    for(int i = 1; i <= n; i++){
    	g[i].clear();
    }
    countt = 0;
    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin>>T;
    for(int i = 1; i <= T; i++){
    	Solve(i);
    }
} 