#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int F[20][20], head[10];
set<pair<int,int>> P[3];

bool isFoccupied(){
  bool occupied = true;
  rep(r, 9, 15)rep(c, 9, 15){
    if(9 == r || r == 14 || c == 9 || c == 14){
      occupied = occupied && F[r][c] == 0;
    }else{
      occupied = occupied && F[r][c] == 1;
    }
  }
  return occupied;
}

void putPolyominos(int isput){
  rep(i, 0, 3){
    for(auto p : P[i]){
      int u = p.first, v = p.second;
      int r, c;
      // rotation
      if(head[3*i + 2] == 0) r =  u, c =  v;
      if(head[3*i + 2] == 1) r = -v, c =  u;
      if(head[3*i + 2] == 2) r = -u, c = -v;
      if(head[3*i + 2] == 3) r =  v, c = -u;
      F[10 + head[3*i] + r][10 + head[3*i+1] + c] += isput;
    }
  }
}

int main(){
  rep(i, 0, 3){
    // the left-most square on the top row is set to (0, 0)
    // other squares are specified by relative positions
    int u = -1, v = -1;
    rep(r, 0, 4)rep(c, 0, 4){
      char p; cin >> p;
      if(p != '#') continue;
      if(u == -1 && v == -1) u = r, v = c;
      P[i].insert({r-u, c-v});
    }
  }

  rep(s0, 0, 64)rep(s1, 0, 64)rep(s2, 0, 64){
    int t0 = s0%16, t1 = s1%16, t2 = s2%16;
    head[0] = t0/4, head[1] = t0%4, head[2] = s0/16;
    head[3] = t1/4, head[4] = t1%4, head[5] = s1/16;
    head[6] = t2/4, head[7] = t2%4, head[8] = s2/16;

    putPolyominos(1);
    if(isFoccupied()){
      cout << "Yes" << endl;
      return 0;
    }
    putPolyominos(-1);
  }
  
  cout << "No" << endl;
  return 0;
}