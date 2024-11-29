#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());

    stack<pair<int, int> > st;
    for(int i=0; i<prices.size(); i++) {
        while(!st.empty()&&st.top().second>prices[i]) {
            answer[st.top().first] = i-st.top().first;
            st.pop();
        }
        st.push({i, prices[i]});
    }

    int lastInd = prices.size()-1;
    while(!st.empty()) {
        answer[st.top().first] = lastInd-st.top().first;
        st.pop();
    }

    return answer;
}