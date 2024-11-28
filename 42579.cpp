#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, long long> playSum;
    unordered_map<string, priority_queue<pair<int, int> > > songPqMap;

    for(int i=0; i<genres.size(); i++) {
        string& genre = genres[i];
        playSum[genre] += plays[i];
        songPqMap[genre].push({plays[i], -i});
    }

    vector<pair<long long, string> > sortedList;

    for(auto p: playSum) {
        sortedList.push_back({-p.second, p.first});
    }
    sort(sortedList.begin(), sortedList.end());

    vector<int> answer;
    for(auto p: sortedList) {
        answer.push_back(-songPqMap[p.second].top().second);
        songPqMap[p.second].pop();
        if(!songPqMap[p.second].empty()) {
            answer.push_back(-songPqMap[p.second].top().second);
        }
    }

    return answer;
}