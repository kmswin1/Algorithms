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
  return r == 0 ? b : gcd(b,r);
}

int main(int argc, const char * argv[]) {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> v(n,0);
    for (int i=0;i<n;i++) {
      cin >> v[i];
    }
    long long sum = 0;
    for (int i=0;i<n-1;i++) {
      for (int j=i+1;j<n;j++) {
        sum += gcd(v[i],v[j]);
      }
    }
    cout << sum << endl;
  }
  return 0;
}
