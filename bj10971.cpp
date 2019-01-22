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
#include <cstdio>

using namespace std;
int main(int argc, const char * argv[]) {
  int n;
  unsigned int ans = 999999999;
  int cost[10][10];
  cin >> n;
  vector<int> v;
  for (int i=0;i<n;i++) {
    v.push_back(i);
    for (int j=0;j<n;j++) {
      cin >> cost[i][j];
    }
  }
  while (next_permutation(v.begin(),v.end())) {
    unsigned int temp = 0;
    for (int i=1;i<n;i++) {
      if (cost[v[i-1]][v[i]] == 0) {
        temp = 999999999;
        break;
      }
      temp += cost[v[i-1]][v[i]];
    }
    if (cost[v[n-1]][v[0]] == 0) temp = 999999999;
    else temp += cost[v[n-1]][v[0]];
    ans = min(ans,temp);
  }
  cout << ans << endl;
  return 0;
}
