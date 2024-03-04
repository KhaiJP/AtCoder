#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int abc[5][5], v[5], V[5];

bool is_V3(){
  v[3] = 1;
  rep(xyz, 0, 3){
    int left_bound = -1000, right_bound = 1000;
    rep(i, 0, 3){
      left_bound  = max(left_bound,  abc[i][xyz]);
      right_bound = min(right_bound, abc[i][xyz]+7);
    }
    v[3] *= max(right_bound - left_bound, 0);
  }
  return v[3] == V[3];
}

bool is_V2(){
  v[2] = 0;
  rep(i, 0, 3){
    int tmp_v = 1;
    rep(xyz, 0, 3){
      int left_bound  = max(abc[i][xyz], abc[(i+1)%3][xyz]);
      int right_bound = min(abc[i][xyz], abc[(i+1)%3][xyz]) + 7;
      tmp_v *= max(right_bound-left_bound, 0);
    }
    v[2] += tmp_v;
  }

  v[2] -= 3 * v[3];
  return v[2] == V[2];
}

bool is_V1(){
  return 3*7*7*7 - 2*v[2] -3*v[3] == V[1];
}

bool eval(){
  if(!is_V3()) return false;
  if(!is_V2()) return false;
  return is_V1();
}

int main(){
  rep(i, 1, 4) cin >> V[i];

  rep(a1,0,8)rep(b1,0,8)rep(c1,0,8){
    abc[1][0]=a1, abc[1][1]=b1, abc[1][2]=c1;
    rep(a2,-7,8)rep(b2,-7,8)rep(c2,-7,8){
      abc[2][0]=a2, abc[2][1]=b2, abc[2][2]=c2;
      if(eval()){
        cout << "Yes\n";
        rep(i, 0, 3)rep(xyz, 0, 3) cout << abc[i][xyz] << ' ';
        cout << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}