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
int main(int argc, const char * argv[]) {
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
      int n,k;
      cin >> n >> k;
      vector<double> v(n,0);
      for (int i=0;i<n;i++) {
        cin >> v[i];
      }
      sort(v.begin(),v.end());
      double ans = 0;
      for (int i=n-k;i<n;i++) {
        ans += v[i];
        ans /=2;
      }
      cout << "#" << t << " " << ans << endl;
    }
    return 0;
}
