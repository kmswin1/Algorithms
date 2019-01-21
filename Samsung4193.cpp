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
int map[15][15];
int ans,n;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int isVisited[15][15];
int score[15][15];

void printMap(int map[15][15]) {
  cout << endl;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      cout << map[i][j] << " ";
    }
    cout << endl;
  }
}

void bfs(int sy, int sx, int ey, int ex) {
  int time = 0;
  queue<int> qx,qy;
  qy.push(sy);
  qx.push(sx);
  isVisited[sy][sx] = 1;
  while(!qy.empty()&&!qx.empty()) {
    int y = qy.front(); qy.pop();
    int x = qx.front(); qx.pop();

    for (int i=0;i<4;i++) {
      int cy = y + dy[i];
      int cx = x + dx[i];
      if (cy < 0 || cx < 0 || cy > n-1 || cx > n-1 || isVisited[cy][cx] == 1 || map[cy][cx] == 1) continue;
      if (cy == ey && cx == ex) {
        if (score[cy][cx] == 0) {
          score[cy][cx] = score[y][x] + 1;
        }
        score[cy][cx] = min(score[cy][cx],score[y][x]+1);
        continue;
      }
      if (map[cy][cx] == 2 && (time % 3) != 2) {
        qy.push(cy);
        qx.push(cx);
        isVisited[cy][cx] = 1;
        score[cy][cx] = score[y][x] + (3 - (time % 3));
        continue;
      }
      qy.push(cy);
      qx.push(cx);
      isVisited[cy][cx] = 1;
      score[cy][cx] = score[y][x] + 1;
    }
    time++;
  }
}
int main(int argc, const char * argv[]) {
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
      ans=9999;
      cin >> n;
      for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
          cin >> map[i][j];
          isVisited[i][j] = 0;
          score[i][j] = 0;
        }
      }
      int sy,sx,ey,ex;
      cin >> sy >> sx >> ey >> ex;
      bfs(sy,sx,ey,ex);
      ans = score[ey][ex];
      if (score[ey][ex] == 0) ans = -1;
      printf("#%d %d\n",t,ans);
    }
    return 0;
}
