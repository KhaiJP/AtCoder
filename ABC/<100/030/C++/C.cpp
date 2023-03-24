#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, s, t) for(int i = (s); i < (t); ++i)

int num_flights[2], travel_time[2], depart_time[2][100010];

int main(){
  rep(i, 0, 2) cin >> num_flights[i];
  rep(i, 0, 2) cin >> travel_time[i];
  rep(i, 0, 2)rep(j, 0, num_flights[i]) cin >> depart_time[i][j];
  
  // false -> Takahashi is at airport A, true -> at airport B
  bool current_airport = false;
  int current_time     = 0;
  int answer           = 0;
  
  // main part
  while(1){
    auto &time_table = depart_time[current_airport];
    int &n_flights   = num_flights[current_airport];

    auto itr = lower_bound(time_table,  time_table + n_flights,  current_time);
    if(itr == time_table + n_flights) break;
    
    current_time     = *itr + travel_time[current_airport];
    answer          += current_airport;
    current_airport  = !current_airport;
  }
  
  cout << answer << endl;
  return 0;
}