#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int F[200][200], head[10];
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
      if(head[3*i + 2] == 0) r =  u, c =  v;
      if(head[3*i + 2] == 1) r = -v, c =  u;
      if(head[3*i + 2] == 2) r = -u, c = -v;
      if(head[3*i + 2] == 3) r =  v, c = -u;
      F[head[3*i] + r][head[3*i+1] + c] += isput;
    }
  }
}

int main(){
  rep(i, 0, 3){
    int u = -1, v = -1;
    rep(r, 0, 4)rep(c, 0, 4){
      char p; cin >> p;
      if(p != '#') continue;
      if(u == -1 && v == -1){
        u = r, v = c;
        P[i].insert({0, 0});
      }else{
        P[i].insert({r-u, c-v});
      }
    }
  }

  rep(r0, 10, 14)rep(c0, 10, 14)rep(rot0, 0, 4){
    head[0] = r0, head[1] = c0, head[2] = rot0;
    rep(r1, 10, 14)rep(c1, 10, 14)rep(rot1, 0, 4){
      head[3] = r1, head[4] = c1, head[5] = rot1;
      rep(r2, 10, 14)rep(c2, 10, 14)rep(rot2, 0, 4){
        head[6] = r2, head[7] = c2, head[8] = rot2;
        
        putPolyominos(1);
        if(isFoccupied()){
          cout << "Yes" << endl;
          return 0;
        }
        putPolyominos(-1);
      }
    }
  }
  
  cout << "No" << endl;
  return 0;
}