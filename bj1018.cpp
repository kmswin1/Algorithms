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

char map[50][50];
char first[8][8];
char second[8][8];
int ans;

void printMap(char map[8][8]) {
  for (int i=0;i<8;i++) {
    for (int j=0;j<8;j++) {
      cout << map[i][j];
    }
    cout << endl;
  }
}

int solve(int sRow, int sCol){
  int temp1,temp2;
  temp1 = temp2 = 0;
  for (int i=sRow;i<sRow+8;i++) {
    for (int j=sCol;j<sCol+8;j++) {
      if (map[i][j] != first[i-sRow][j-sCol]) temp1++;
      if (map[i][j] != second[i-sRow][j-sCol]) temp2++;
    }
  }
  return min(temp1,temp2);
}

int main(int argc, const char * argv[]) {
    /*int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
      int n,ans=0;

      printf("#%d %d\n",t,ans);
    }*/
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        if (i%2 == 0) {
          if (j%2 == 0) {
            first[i][j] = 'W';
            second[i][j] = 'B';
          } else {
            first[i][j] = 'B';
            second[i][j] = 'W';
          }
        } else {
          if (j%2 == 0) {
            first[i][j] = 'B';
            second[i][j] = 'W';
          } else {
            first[i][j] = 'W';
            second[i][j] = 'B';
          }
        }
      }
    }
    int row,col;
    ans=64;
    cin >> row >> col;
    for (int i=0;i<row;i++) {
      for (int j=0;j<col;j++) {
        cin >> map[i][j];
      }
    }

    for (int i=0;i<=row-8;i++) {
      for (int j=0;j<=col-8;j++) {
        ans = min(ans,solve(i,j));
      }
    }
    cout << ans << endl;
    return 0;
}
