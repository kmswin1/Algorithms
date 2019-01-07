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
      int n,ans=0,minVal=0,maxVal=0,upCnt=0,downCnt=0;
      cin >> n;
      vector<int> v(n,0);
      for (int i=0;i<n;i++) cin >> v[i];
      for (int i=0;i<n;){
        if (i == 0) {
          maxVal = v[i];
          minVal = v[i];
          i++;
          continue;
        }
        if (maxVal <= v[i]) {
          while (maxVal <= v[i] && i < n) {
            maxVal = v[i];
            upCnt++;
            i++;
          }
        } else {
          minVal = v[i];
          while(minVal >= v[i] && i < n) {
            minVal = v[i];
            downCnt++;
            i++;
          }
          ans += upCnt*downCnt;
          upCnt = 0;
          downCnt = 0;
          maxVal = v[i];
        }
      }

      printf("#%d %d\n",t,ans);
    }
    return 0;
}
