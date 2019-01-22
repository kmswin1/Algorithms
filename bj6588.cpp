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
  ios_base::sync_with_stdio(false); cin.tie(0);
  int chk[1000001] = { 0 };
  for (int i=2;i<=1000000;i++) {
    for (int j=2;j*i<=1000000;j++) {
      chk[i*j] = 1;
    }
  }
  vector<int> v;
  for (int i=3;i<=1000000;i++) {
    if (!chk[i]) v.push_back(i);
  }
  while(true) {
    int n;
    cin >> n;
    if (n == 0) break;
    for (int i=0;i<v.size();i++) {
      if (!chk[n-v[i]]) {
        cout << n << " = " << v[i] << " + " << n - v[i] << "\n";
        break;
      }
    }
  }
  return 0;
}
