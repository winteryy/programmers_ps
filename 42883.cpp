#include <string>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    deque<char> prev;
    int cnt = 0;
    for(char c: number) {
        while(cnt<k && !prev.empty() && prev.back()<c) {
            prev.pop_back();
            cnt++;
        }
        prev.push_back(c); 
    }

    ostringstream oss;

    for(int i=0; i<prev.size()-(k-cnt); i++) {
        oss << prev[i];
    }

    return oss.str();
}