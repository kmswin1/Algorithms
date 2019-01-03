//
//  main.cpp
//  kms
//
//  Created by 김민상 on 2018. 9. 4..
//  Copyright © 2018년 김민상. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    int test_case;
    cin >> test_case;

    for (int tc=1;tc<=test_case;tc++) {
        stack<char> s;
        int ans = 0;
        string input;
        cin >> input;
        for (int i=0;i<input.size();i++) {
            if (input[i] == '(') {
                s.push(input[i]);
            } else {
                if (input[i-1] == '(') {
                    s.pop();
                    ans += s.size();
                }
                else {
                    s.pop();
                    ans += 1;
                }
            }
        }
        cout << "#" << tc << " " << ans << endl;
    }
    return 0;
}
