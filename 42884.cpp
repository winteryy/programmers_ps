#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    auto cmp = [](const vector<int>& l, const vector<int>& r) {
        if(l[1]==r[1]) {
           return l[0] > r[0];
        } else {
            return l[1] > r[1];
        }
    };
    priority_queue<vector<int>, vector<vector<int> >, decltype(cmp)> pq(cmp);
    for(auto route : routes) {
        pq.push(route);
    }

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        answer++;
        while(!pq.empty() && pq.top()[0]<=cur[1]) {
            pq.pop();
        }
    }

    return answer;
}