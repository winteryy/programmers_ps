#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();
    vector<int> notA;
    for(int i=0; i<len; i++) {
        char c = name[i];

        if(c != 'A' || i==0) {
            int diffMin = min(c-'A', 26-(c-'A'));
            answer += diffMin;

            notA.push_back(i);
        }
    }

    int minDist = 0;
    if(notA.size()>1) {
        minDist = min(len-notA[1], notA[notA.size()-1]);
    }

    for(int i=1; i<notA.size()-1; i++) {
        int cur = notA[i];
        int next = notA[i+1];

        minDist = min(minDist, min(cur*2+len-next, (len-next)*2+cur));
    }

    return answer+minDist;
}

int main() {
    solution("JEROEN");
}