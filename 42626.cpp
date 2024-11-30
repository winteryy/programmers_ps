#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int food: scoville) {
        pq.push(food);
    }

    int answer = 0;
    while(pq.size()>1 && pq.top()<K) {
        answer++;

        int newScoville = pq.top();
        pq.pop();
        newScoville += pq.top()*2;
        pq.pop();

        pq.push(newScoville);
    }

    if(pq.top()<K) answer = -1;
    return answer;
}