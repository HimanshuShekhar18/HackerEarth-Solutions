#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> w;
vector<int> dp;
vector<int> ans;

// dp[i] = maximum no. of treats i can get, from the subtree of node i, if I start from node i

// I Calculated my ans for a single one root
void dfs1(int node, int par)
{
  dp[node]=0;
  for(auto ch: adj[node])
  {
    if(ch==par)
        continue;
    dfs1(ch,node);
 // will select maximum among all children niche se upar
Or wapas aate waqat; here contribution of MAX
    dp[node]=max(dp[node],dp[ch]);
  }
  // source node ke weight ko add karo wapas aate waqat
  dp[node]+=w[node];
}

// Now Re-rooting is needed to calculate ans for each node
void dfs2(int node, int par)
{
  ans[node]=dp[node];
  int t1=dp[node];
  vector<int> pre,suff;
  // Prefix Maximum and Suffix Maximum array

  for(auto ch: adj[node])
  {
    if(ch==par)
      continue;
    pre.push_back(dp[ch]) ;
    suff.push_back(dp[ch]) ;    
  }

  int sz=pre.size();
  for(int i=1; i<sz; i++)
  {
    pre[i]=max(pre[i],pre[i-1]);
  }
  for(int i=sz-2; i>=0; i--)
  {
    suff[i]=max(suff[i],suff[i+1]);
  }  

  int i=0;
  for(auto ch: adj[node])
  {
    if(ch==par) continue;
    int t2=dp[ch];

    // re-rooting from node to ch
    int l=0, r=0;    
    if(i-1>=0)
      l=pre[i-1];
    if(i+1<sz)
     r=suff[i+1];

    dp[node]=max(l,r)+w[node];
    if(par!=-1)
    {
      dp[node]=max(dp[node], dp[par]+w[node]);
    }

    dp[ch]=max(dp[ch], dp[node]+w[ch]);

    dfs2(ch,node);

    // restoring dp values
    dp[node]=t1;
    dp[ch]=t2;
    i++;
  }
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    w.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> w[i];
    }
    adj.clear();
    adj.resize(n);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dp.resize(n);
    ans.resize(n);
    dfs1(0,-1); // assuming node 1 as root
    dfs2(0,-1); // re-root to all the nodes, one by one
    for(int i=0; i<n; i++)
    {
      cout<<ans[i]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}
