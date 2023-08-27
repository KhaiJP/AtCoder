#include<iostream>
#include<set>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// COL[r][c] : the colour of the cookie on (row, column) = (r, c)
// 'a' -> 0, 'b' -> 1, ... , 'z' -> 25
int H, W, COL[2010][2010];
// typeR[r] : number of colours of cookies on row r, and same for typeC
// cntR[r][col] : number of cookies on row r whose colour is col, and same for cntC
int typeR[2010], typeC[2010], cntR[2010][30], cntC[2010][30];
// r ∈ remainR, cookies on row r are not removed yet, and some for remainC
set<int> remainR, remainC;

int main(){
  cin >> H >> W;
  rep(r, 0, H)rep(c, 0, W){
    char letter; cin >> letter;
    COL[r][c] = letter - 'a';
    ++cntR[r][COL[r][c]];
    ++cntC[c][COL[r][c]];
  }

  // count number of colours on each row/column
  rep(r, 0, H)rep(colour, 0, 26) typeR[r] += ( cntR[r][colour] > 0 );
  rep(c, 0, W)rep(colour, 0, 26) typeC[c] += ( cntC[c][colour] > 0 );

  // before performimg each procedure, all the rows and columns are not removed
  rep(r, 0, H) remainR.insert(r);
  rep(c, 0, W) remainC.insert(c);

  while(1){
    // procedure 1 
    set<int> tobe_del_R;
    for(auto r : remainR)if(remainC.size() > 1 && typeR[r] == 1){
      tobe_del_R.insert(r);
    }

    // procedure 2
    set<int> tobe_del_C;
    for(auto c : remainC)if(remainR.size() > 1 && typeC[c] == 1){
      tobe_del_C.insert(c);
    }

    // when there is no rows/columns to be removed -> break
    if(tobe_del_R.size() == 0 && tobe_del_C.size() == 0) break;


    // procedure 3
    // for rows
    if(remainR.size() > 1)for(auto r : tobe_del_R)for(auto c : remainC){
      --cntC[c][COL[r][c]];
      if(cntC[c][COL[r][c]] == 0) --typeC[c];
    }
    // 3 for columns
    if(remainC.size() > 1)for(auto c : tobe_del_C)for(auto r : remainR){
      --cntR[r][COL[r][c]];
      if(cntR[r][COL[r][c]] == 0) --typeR[r];
    }
    // remove rows and columns
    for(auto r : tobe_del_R) remainR.erase(r);
    for(auto c : tobe_del_C) remainC.erase(c);
  }

  // the answer corresponds the area of the rectangle with length remainR/C.size()
  cout << (remainR.size()) * (remainC.size()) << endl;
  return 0;
}