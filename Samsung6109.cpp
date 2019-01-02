//
//  main.cpp
//  kms
//
//  Created by 김민상 on 2018. 12. 26..
//  Copyright © 2018년 김민상. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;
int board[20][20];

int main(int argc, const char * argv[]) {
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
      queue<int> q;
      int n;
      string dir;
      cin >> n >> dir;
      for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
          cin >> board[i][j];
        }
      }
      if (dir == "up") {
        for (int i=0;i<n;i++) {
          for (int m=0;m<n;m++) {
            if (board[m][i] != 0) {
              q.push(board[m][i]);
              board[m][i] = 0;
            }
          }
          int k = 0;
          while (!q.empty()) {
            if (board[k][i] == 0) {
              board[k][i] = q.front();
              q.pop();
            }
            else if (board[k][i] == q.front()) {
              board[k][i] += q.front();
              q.pop();
              k++;
            } else {
              k++;
              board[k][i] = q.front();
              q.pop();
            }
          }
        }
      } else if (dir == "down") {
        for (int i=0;i<n;i++) {
          for (int m=n-1;m>=0;m--) {
            if (board[m][i] != 0) {
              q.push(board[m][i]);
              board[m][i] = 0;
            }
          }
          int k = n-1;
          while (!q.empty()) {
            if (board[k][i] == 0) {
              board[k][i] = q.front();
              q.pop();
            }
            else if (board[k][i] == q.front()) {
              board[k][i] += q.front();
              q.pop();
              k--;
            } else {
              k--;
              board[k][i] = q.front();
              q.pop();
            }
          }
        }
      } else if (dir == "right") {
        for (int i=0;i<n;i++) {
          for (int m=n-1;m>=0;m--) {
            if (board[i][m] != 0) {
              q.push(board[i][m]);
              board[i][m] = 0;
            }
          }
          int k = n-1;
          while (!q.empty()) {
            if (board[i][k] == 0) {
              board[i][k] = q.front();
              q.pop();
            }
            else if (board[i][k] == q.front()) {
              board[i][k] += q.front();
              q.pop();
              k--;
            } else {
              k--;
              board[i][k] = q.front();
              q.pop();
            }
          }
        }
      } else {
        for (int i=0;i<n;i++) {
          for (int m=0;m<n;m++) {
            if (board[i][m] != 0) {
              q.push(board[i][m]);
              board[i][m] = 0;
            }
          }
          int k = 0;
          while (!q.empty()) {
            if (board[i][k] == 0) {
              board[i][k] = q.front();
              q.pop();
            }
            else if (board[i][k] == q.front()) {
              board[i][k] += q.front();
              q.pop();
              k++;
            } else {
              k++;
              board[i][k] = q.front();
              q.pop();
            }
          }
        }
      }
       cout << "#" << t << endl;
       for (int i=0;i<n;i++) {
         for (int j=0;j<n;j++) {
           cout << board[i][j] << " ";
         }
         cout << endl;
       }
    }
    return 0;
}
