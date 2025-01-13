#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using Coord = tuple<int, int, int>;
using PCoord = pair<int, Coord>;

#define rep(i, s, t) for(int i = s; i < t; i++)


bool F[1010][1010];
int H, W, sx, sy, gx, gy;
int dist[1010][1010][2];
int inf = 1e9;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void get_input(){
    cin >> H >> W;
    rep(i, 1, H+1)rep(j, 1, W+1){
        char c;
        cin >> c;
        if(c == 'S'){
            sx = i;
            sy = j;
            c = '.';
        }
        if(c == 'G'){
            gx = i;
            gy = j;
            c = '.';
        }
        F[i][j] = (c == '.');
    }
}


void init_dist(){
    rep(i, 1, H+1)rep(j, 1, W+1)rep(f, 0, 2) dist[i][j][f] = inf;
    dist[sx][sy][0] = 0;
    dist[sx][sy][1] = 0;
}


int dijkstra(){
    rep(idrc, 0, 2){
        priority_queue<PCoord> q;
        q.push({0, {sx, sy, idrc}});    
        while(!q.empty()){
            int d, x, y, drc;
            d = -q.top().first;
            tie(x, y, drc) = q.top().second;
            q.pop();

            if(dist[x][y][drc] < d) continue;

            int ndrc = 1 - drc;
            rep(k, 0, 2){
                int nx = x + dx[drc*2+k];
                int ny = y + dy[drc*2+k];
                if(F[nx][ny] && d+1 < dist[nx][ny][ndrc]){
                    dist[nx][ny][ndrc] = d + 1;
                    q.push({-(d+1), {nx, ny, ndrc}});
                }
            }
        }
    }
    int ans = 0;
    if(dist[gx][gy][0] == inf && dist[gx][gy][1] == inf){
        ans = -1;
    }else{
        ans = min(dist[gx][gy][0], dist[gx][gy][1]);
    }

    return ans;
}


int main(){
    get_input();
    init_dist();
    cout << dijkstra() << endl;
    return 0;
}
