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
int main(int argc, const char * argv[]) {
  int n;
  cin >> n;
  int chk[1001] = { 0 };
  chk[1] = 1;
  for (int i=2;i<=1000;i++) {
    int k = i;
    for (int j=i*k;j<1000;j=i*(++k)) {
      chk[j] = 1;
    }
  }
  int sum = 0;
  for (int i=0;i<n;i++) {
    int temp;
    cin >> temp;
    if (!chk[temp]) sum++;
  }
  cout << sum << endl;
  return 0;
}
