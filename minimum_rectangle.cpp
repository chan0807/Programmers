#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;

int calculateArea(const vector<vector<int>>& sizes, const vector<int>& changeIndices)
{
    int wMax = 0; int hMax = 0 ;
    for(int i=0; i < sizes.size(); i++)
    {
        if(find(changeIndices.begin(), changeIndices.end(), i) != changeIndices.end()) {
            wMax = sizes[i][1] > wMax ? sizes[i][1]: wMax;
            hMax = sizes[i][0] > hMax ? sizes[i][0]: hMax;   
        }
        else{
            wMax = sizes[i][0] > wMax ? sizes[i][0]: wMax;
            hMax = sizes[i][1] > hMax ? sizes[i][1]: hMax;   
        }
    }
    return wMax * hMax;
}

void print(vector<int> v)
{
    for(auto val : v)
    {
        cout << val;
    }
    cout<< "permuated" << endl;;
}

int combination(const vector<vector<int>>& sizes)
{
    int res = INT_MAX;
    const auto len = sizes.size();
    for(int i = 1; i <= len; i++)
    {
        vector<int> checker(len-i, false);
        checker.insert(checker.end(), i, true);
        do{
            vector<int> combi;
            for(int k=0; k < len; ++k)
            {
                if(checker[k])
                    combi.push_back(k);
            }
            const auto area = calculateArea(sizes, combi);
            res = area < res ? area : res;
        }
        while(next_permutation(checker.begin(), checker.end()));
    }
    return res;
}


int solution(vector<vector<int>> sizes) {

    for_each(sizes.begin(), sizes.end(), [](vector<int>& size){
        if(size[0] < size[1])
            swap(size[0], size[1]); 
    });

    int max_w = 0; int max_h = 0;
    for(auto size : sizes)
    {
        max_w = max(size[0], max_w);
        max_h = max(size[1], max_h);
    }
    return max_w * max_h;
}

int main()
{
    vector<vector<int>> sizes = {{10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15}};
    int res = solution(sizes);
    cout << "result : " << res;
    // for(auto n : solution(arr, commands))
        // std::cout << "hi" ;/
    return 0;
}