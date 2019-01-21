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

int solve(int a) {
  if (a == 1) {
    return 0;
  }
  if (a == 2) {
    return 1;
  }
  for (int i=2;i<=sqrt(a);i++) {
    if (a%i == 0) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, const char * argv[]) {
  int n;
  cin >> n;
  int sum = 0;
  for (int i=0;i<n;i++) {
    int temp;
    cin >> temp;
    sum += solve(temp);
  }
  cout << sum << endl;
  return 0;
}
