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

int gcd(int a, int b) {
  int r = a%b;
  return r == 0 ? b : gcd(b, r);
}

int main(int argc, const char * argv[]) {
  int tc;
  cin >> tc;
  while (tc--) {
    int m,n;
    cin >> m >> n;
    int r = gcd(m,n);
    cout << r*(m/r)*(n/r) << endl;
  }
  return 0;
}
