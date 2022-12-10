#include<iostream>
#include<vector>
#include<queue>
#define rep(i,n) for(int i=0; i<(n); ++i)

using namespace std;

int main(){
    int N, M, K; cin >> N >> M >> K;
    vector<vector<pair<int,int>>> E(2*N);
    rep(i,M){
        int u, v, a; cin >> u >> v >> a;
        u -= 1; v -= 1;
        if(a==0){
            u += N;
            v += N;
        }
        E[u].push_back(pair<int,int>(v, 1));
        E[v].push_back(pair<int,int>(u, 1));
    }
    rep(i,K){
        int s; cin >> s;
        s -= 1;
        E[s].push_back(pair<int,int>(s+N, 0));
        E[s+N].push_back(pair<int,int>(s, 0));
    }

    // 01-BFS
    deque<int> q;
    q.push_back(0);
    vector<int> D(2*N, 1e9);
    D[0] = 0;
    while(q.size()){
        int u = q.front(); q.pop_front();
        rep(i, (int)E[u].size()){
            int v = E[u][i].first; int d = E[u][i].second;
            if(D[v] > D[u] + d){
                D[v] = D[u] + d;
                if(d) q.push_back(v);
                else  q.push_front(v);
            }
        }
    }
    int answer = min(D[N-1], D[2*N-1]);
    cout << (answer == 1e9 ? -1 : answer) << endl;
    return 0;
}