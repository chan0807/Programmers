#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    unordered_map<string, vector<string>> edges;
    for(const auto& ticket: tickets)
            edges[ticket[0]].emplace_back(ticket[1]);

    for(auto& [key, value]: edges)
        sort(value.begin(), value.end(), std::greater<string>());
    vector<string> answer;
    stack<string> st;
    st.emplace("ICN");
    // answer.push_back("ICN");
    
    while(st.empty() == false)
    {
        auto srcCity = st.top();

        auto& connectedCities = edges[srcCity];
        if(connectedCities.empty())
        {
            edges.erase(srcCity);
            answer.push_back(srcCity);
            st.pop();
            continue;
        }
        st.push(connectedCities.back());
        connectedCities.pop_back();
    }
    // reverse(answer.begin(), answer.end());
    return vector<string>(answer.rbegin(), answer.rend());
}

int main()
{
    auto ans = solution({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}});
    return 0;
}