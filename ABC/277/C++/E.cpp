#include<iostream>
#include<vector>
#include<queue>
#define rep(i,n) for(int i=1; i<=n; ++i)

using namespace std;
typedef pair<int, int> edge;

const int inf = 1e9;

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<edge> E[2*N+2];
    
    int u, v, a, s;
    rep(i, M){
        cin >> u >> v >> a;
        if(a){
            E[u].push_back(edge(v, 1));
            E[v].push_back(edge(u, 1));
        }else{
            E[N+v].push_back(edge(N+u, 1));
            E[N+u].push_back(edge(N+v, 1));
        }
    }
    rep(i,K){
        cin >> s;
        E[s].push_back(edge(N+s, 0));
        E[N+s].push_back(edge(s, 0));
    }

    deque<int> q;
    q.push_back(1);
    int dist[2*N+2];
    rep(i, 2*N) dist[i] = inf;
    dist[1] = 0;

    while(q.size()){
        int v = q.front(); q.pop_front();
        rep(i, (int)E[v].size()){
            int u = E[v][i-1].first, d_vu = E[v][i-1].second;
            if(dist[u] > dist[v]+d_vu){
                dist[u] = dist[v] + d_vu;
                if(d_vu == 0) q.push_front(u);
                else q.push_back(u);
            }
        }
    }

    int ans = min(dist[N], dist[2*N]);
    if(ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}
