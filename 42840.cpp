#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    pair<vector<int>, int> p1 = {{1, 2, 3, 4, 5}, 5};
    pair<vector<int>, int> p2 = {{2, 1, 2, 3, 2, 4, 2, 5}, 8};
    pair<vector<int>, int> p3 = {{3, 3, 1, 1, 2, 2, 4, 4, 5, 5}, 10};

    int cnt[3] = {0, 0, 0};
    
    for(int i=0; i<answers.size(); i++) {
        if(p1.first[i%p1.second]==answers[i]) cnt[0]++;
        if(p2.first[i%p2.second]==answers[i]) cnt[1]++;
        if(p3.first[i%p3.second]==answers[i]) cnt[2]++;
    }

    int maxNum = max(cnt[0], max(cnt[1], cnt[2]));

    for(int i=0; i<3; i++) {
        if(cnt[i]==maxNum) answer.push_back(i+1);
    }

    return answer;
}