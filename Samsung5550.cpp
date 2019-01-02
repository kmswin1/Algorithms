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
                if (c > ans) ans = c;
                break;
          case 'r':
                r++;
                if (r > ans) ans = -1;
                if (r > c) ans = -1;
                break;
          case 'o':
                o++;
                if (o > ans) ans = -1;
                if (o > c || o > r) ans = -1;
                break;
          case 'a':
                a++;
                if (a > ans) ans = -1;
                if (a > o || a > r || a > c) ans = -1;
                break;
          case 'k':
                k++;
                if (k > ans) ans = -1;
                if (k > a || k > o || k > r || k > c) ans = -1;
                c--;
                o--;
                r--;
                a--;
                k--;
                break;
          default:
                break;
        }
        if (ans == -1) break;
      }
      if (c != 0 || r != 0 || o != 0 || a != 0 || k != 0) ans = -1;
      cout << "#" << t << " " << ans << endl;
    }
    return 0;
}
