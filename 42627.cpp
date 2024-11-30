#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job {
    int num, request, consume;
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    auto cmp = [](const Job& l, const Job& r) {
        if(l.consume!=r.consume) {
            return l.consume>r.consume;
        } else if(l.request!=r.request) {
            return l.request>r.request;
        } else {
            return l.num>r.num;
        }
    };

    priority_queue<Job, vector<Job>, decltype(cmp)> pq;
    vector<Job> jobList;

    for(int i=0; i<jobs.size(); i++) {
        jobList.push_back({i, jobs[i][0], jobs[i][1]});
    }
    
    sort(jobList.begin(), jobList.end(), [](const Job& l, const Job& r) {
        return l.request<r.request;
    });

    int time = 0;
    int ind = 0;
    
    while(!pq.empty() || ind<jobList.size()) {
        if(pq.empty()) {
            pq.push(jobList[ind]);
            time = max(time, jobList[ind].request);
            ind++;
        }

        while(ind<jobList.size() && time>=jobList[ind].request) {
            pq.push(jobList[ind]);
            ind++;
        }

        time += pq.top().consume;
        answer += time - pq.top().request;
        pq.pop();
    }

    return answer/jobs.size();
}