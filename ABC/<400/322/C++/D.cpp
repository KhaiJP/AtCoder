#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int F[20][20], head[10];
set<pair<int,int>> P[3];

void clip(int H, int W, char target, set<pair<int,int>> &container){
  int u = -100, v = -100; 
  rep(r, 0, H)rep(c, 0, W){
    char ch; cin >> ch;
    if(ch != target) continue;
    if(u == -100 && -100) u = r, v = c;
    container.insert({r-u, c-v});
  }
  return ;
}

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
  rep(i, 0, 3) clip(4, 4, '#', P[i]);

  rep(i, 0, 64*64*64){
    int I = i;
    rep(j, 0, 9){
      head[j] = I % 4;
      I /= 4;
    }

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