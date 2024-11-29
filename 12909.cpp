#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int left = 0;
    for(char c: s) {
        if(c=='(') {
            left++;
        } else {
            if(left>0) {
                left--;
            } else {
                answer = false;
                break;
            }
        }
    }

    return answer&&left==0;
}