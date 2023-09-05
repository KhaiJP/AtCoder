#include<iostream>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

// rate[i] : the rate of i-th person, hand[i] : the hand of i-th person; 0 - rock, 1 - scissors, 2 - paper
// rate_hand_num[r][h] : # of persons of rating r and hand h
// rate_tot[r] : # of persons whose ratings less than r
int rate[100010], hand[100010], rate_hand_num[100010][3], rate_tot[100010], N;

int main(){
  cin >> N;
  
  rep(i, 0, N){
    // make hand '1 to 3' to '0 to 2' then hand h wins to (h+1)%3 and loses to (h+2)%3 
    cin >> rate[i] >> hand[i]; --hand[i];
    ++rate_hand_num[rate[i]][hand[i]];
  }
  
  // count rate_tot[r], the # of persons; that people having rate = r can win regardless of their hands
  rep(r, 1, 100001){
    rate_tot[r] = rate_tot[r-1];
    rep(j, 0, 3) rate_tot[r] += rate_hand_num[r-1][j];
  }
  
  rep(i, 0, N){
    int &h = hand[i], &r = rate[i];
    // # of persons who have same rating and have hand (h+1)%3  +  # of persons whose ratings are below r   
    int wins  = rate_hand_num[r][(h + 1) % 3] + rate_tot[r];
    // rate_hand_num[r][h] includes the person i -> need "- 1"
    int draws = rate_hand_num[r][h] - 1;
    // "- 1" subtracts the i-th person
    int loses = N - (wins + draws) - 1;
    cout << wins << ' ' << loses << ' ' << draws << endl;
  }
  
  return 0;
}