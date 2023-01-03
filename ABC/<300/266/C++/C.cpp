#include<iostream>
using namespace std;
typedef pair<int, int> P;

bool onOtherSide_wrt_q1_q2(P q1, P q2, P p1, P p2);

int main(){
  P A; cin >> A.first >> A.second;
  P B; cin >> B.first >> B.second;
  P C; cin >> C.first >> C.second;
  P D; cin >> D.first >> D.second; 
  // if B and D are on the other side with respect to line AC,
  // and A and C are on the other side with respect to line BD, then ABCD is convex.
  bool isConvex = onOtherSide_wrt_q1_q2(A,C,B,D) && onOtherSide_wrt_q1_q2(B,D,A,C);
  cout << (isConvex ? "Yes" : "No") << endl;
  return 0;
}

bool onOtherSide_wrt_q1_q2(P q1, P q2, P p1, P p2){
  // check if p1 and p2 are on the other side with respect to line q1_q2. line q1_q2 is given below;
  // (q2.first - q1.first)*(y - q1.second) - (q2.second - q1.second)*(x - q1.first)
  bool sgn_p1 = (q2.first - q1.first)*(p1.second - q1.second) - (q2.second - q1.second)*(p1.first - q1.first) > 0;
  bool sgn_p2 = (q2.first - q1.first)*(p2.second - q1.second) - (q2.second - q1.second)*(p2.first - q1.first) > 0;
  // to be on the other side, the signs musd be different;
  return sgn_p1 != sgn_p2;
}