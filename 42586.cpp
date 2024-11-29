#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int prevConsume = -1;
    for(int i=0; i<progresses.size(); i++) {
        int consume = (100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i]!=0) consume++;

        if(prevConsume>=consume) {
            answer[answer.size()-1]++;
        } else {
            answer.push_back(1);
            prevConsume = consume;
        }
    }
    
    return answer;
}