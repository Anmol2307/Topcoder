#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

class FriendScore {
  
  public:
  int highestScore(vector<string> friends) {
    int s = friends.size();
    int ans = 0;
    for (int i = 0; i < s; i++) {
      int visited[s];
      memset(visited,0,sizeof visited);
      queue<pii> q;
      q.push(pii(i,0));
      visited[i] = 1;
      int tmp = 0;
      while (!q.empty()) {
        pii top = q.front();
        q.pop();
        if (top.second < 2) {
          for (int j = 0; j < s; j++) {
            if (friends[top.first][j] == 'Y' && visited[j] == 0) {
              tmp++;
              q.push(pii(j,top.second+1));
              visited[j] = 1;
            }
          }
        }
      }
      if (tmp > ans) {
        ans = tmp;
      }
    }
    return ans;
  }
};