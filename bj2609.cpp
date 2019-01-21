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
  int n,m;
  cin >> n >> m;
  int larger = max(n,m);
  int smaller = min(n,m);
  for (int i=smaller;i>=1;i--) {
    if (larger % i == 0 && smaller % i == 0) {
      cout << i << endl;
      break;
    }
  }

  for (int i=larger;i<=larger*smaller;i++) {
    if (i % larger == 0 && i % smaller == 0) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
