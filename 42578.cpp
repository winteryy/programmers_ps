#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> um;
    for(auto cloth: clothes) {
        um[cloth[1]]++;
    }

    for(auto p: um) {
        answer *= (p.second+1);
    }

    return answer-1;
}