#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    auto mm = minmax_element(people.begin(), people.end());
    int minWeight = *mm.first;
    int maxWeight = *mm.second;
    int weightDiff = maxWeight-minWeight;
    vector<int> weights(weightDiff+1, 0);

    for(int person: people) {
        weights[person-minWeight]++;
    }

    limit -= minWeight*2;
    for(int i=weightDiff; i>=0; i--) {
        int target = min(i, min(limit-i, weightDiff));
        while(target>=0 && weights[i]>0) {
            if(weights[target]>0) {
                int minNum = min(weights[target], weights[i]);
                if(target==i) minNum/=2;
                weights[target] -= minNum;
                weights[i] -= minNum;
                answer += minNum;
            }
            target--;
        }
        answer += weights[i];
        weights[i] = 0;
    }
    return answer;
}