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

using namespace std;

int board[12][12];
const int EAST = 1;
const int NORTH = 2;
const int WEST = 3;
const int SOUTH = 4;
int n,ans,edge,core;

int cal(int board[12][12]) {
  int temp = 0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (board[i][j] == 2) temp++;
    }
  }
  return temp;
}

void copyMap(int to[12][12], int from[12][12]) {
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      to[i][j] = from[i][j];
    }
  }
}

void solve() {

}

int main(int argc, const char * argv[]) {
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
      ans = 0;
      edge = 0;
      core = 0;
      cin >> n;
      for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
          cin >> board[i][j];
          if (board[i][j] == 1) {
            core++;
            if (i == 0 || j == 0) {
              board[i][j] = 2;
              edge++;
              ans--;
            }
          }
        }
      }

      for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
          if (board[i][j] == 1) {

          }
        }
      }
      cout << "#" << t << " " << ans << endl;
    }
    return 0;
}
