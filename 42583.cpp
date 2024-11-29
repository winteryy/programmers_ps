#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int weightSum = 0;
    queue<pair<int, int> > q;
    int time = 1;

    for(auto truck: truck_weights) {
        while(weightSum+truck>weight || q.size()>=bridge_length) {
            weightSum -= q.front().first;
            time = max(time, q.front().second+bridge_length);
            q.pop();
        }
        q.push({truck, time++});
        weightSum+=truck;
    }

    while(!q.empty()) {
        time = q.front().second+bridge_length;
        q.pop();
    }

    return time;
}