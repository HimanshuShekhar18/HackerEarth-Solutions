// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;    // for Policy Based DS
const int MOD = 1e9 + 7;
const long long INF = 1e9;
const int MAX_N = 200 * 1000 + 13;

vector<pair<int,int>> graph[MAX_N];




# define f(a,n,i) for(int i = a; i<n; i++)
# define fe(a,n,i) for(int i = a; i<=n; i++)
# define fje(a,n,i,j) for(int i = a; i<=n; i+=j)
# define fn(n,a,i) for(int i = n; i>=a; i--)
# define fme(s,n,i,a) for(int i = s; i<=n; i*=a)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define in3(a,b,c) cin>>a>>b>>c
# define in4(a,b,c,d) cin>>a>>b>>c>>d
# define ll long long

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;


struct st{
  int node;
  int leftout;
  int distance;

  bool operator>(const st &s) const{ return distance>s.distance;}

};


void solve(){

  int dist[n+1][k+1];
  fill_n(&dist[0][0],(n+1)*(k+1),INF);

  priority_queue<st,vector<st>,greater<st>> pq;
  pq.push({1,0,0});  // node,leftour,distance
  while(!pq.empty()){
      st s = pq.top();
      pq.pop();
      int node = s.node;
      int leftout = s.leftout;
      int distance = s.distance;

      if(dist[node][leftout]<distance) continue;
      dist[node][leftout] = distance;

      for(auto it: graph[node]){

        int vertex = it.first;
        int dis = it.second;

        if(dis+distance<dist[vertex][leftout]){
          dist[vertex][leftout]=dis+distance;
          pq.push({vertex,leftout,dis+distance});
        }

        if(leftout==k) continue;

        if(distance<dist[vertex][leftout+1]){
          dist[vertex][leftout+1]=distance;
          pq.push({vertex,leftout+1,distance});
        }

      }
  }

  for(int i = 1; i<=n; i++){
     int mini = INT_MAX;
     for(int j = 0; j<=k; j++){
        mini = min(mini,dist[i][j]);
     }
     cout << mini << " ";
  }

  cout << endl;

       fflush(stdout);
       cout << flush;
    }


int main() {

    #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif

// time_t timetoday
//    time (&timetoday);
//    cout << asctime(localtime(&timetoday)) << endl;
//    // return 0;

ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

    in3(n,m,k);

    

    for (int i = 0; i < m; ++i)
    {
      int u, v, wt;
      in3(u,v,wt);

      graph[u].push_back({v,wt});
      graph[v].push_back({u,wt});
    }

     solve();
      

       return 0;
}
