#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(vector<int> numbers) {

    vector<string> strNums;
    for(int num: numbers) {
        strNums.push_back(to_string(num));
    }

    sort(strNums.begin(), strNums.end(), [](const string& l, const string& r) {
        int num1 = stoi(l+r);
        int num2 = stoi(r+l);

        return num1>num2;
    });

    ostringstream oss;
    string answer = "";
    for(string str: strNums) {
        if(oss.str().empty()&&str=="0") {
            oss << "0";
            break;
        }
        oss << str;
    }

    answer = oss.str();
    return answer;
}