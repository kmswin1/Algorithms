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
      string s;
      cin >> s;
      int ans = 0;
      int c,r,o,a,k;
      c = r = o = a = k = 0;
      for (int i=0;i<s.size();i++) {
        switch (s[i]) {
          case 'c':
                c++;
                if (c > ans) c = ans;
                break;
          case 'r':
                r++;
          case 'o':
                o++;
          case 'a':
                a++;
          case 'k':
                k++;
          default:
          break;
        }
      }
      cout << "#" << t << " " << ans << endl;
    }
    return 0;
}
