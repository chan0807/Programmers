#include <string>
#include <vector>
using namespace std;
int calculateFence(int w, int h)
{
    int w_f = (w+2)*2;
    int h_f = (h+2)*2;
    int fence_area = w_f + h_f - 4;
    return fence_area;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int h = yellow/2 <= 0 ? 1 : yellow/2;
    
    for(int i = 1; i <= h; i++)
    {
        if(yellow%i != 0) continue;
        int candi_w = i;
        int candi_h = yellow/i;
        if(brown == calculateFence(candi_w, candi_h))
        {
            candi_h += 2;
            candi_w += 2;
            if(candi_h > candi_w)
                answer = {candi_h, candi_w};
            else
                answer = {candi_w, candi_h};
                
            break;
        }   
    }
    return answer;
}

int main()
{
    int brown = 16;
    int yellow = 9;

    auto ans = solution(brown, yellow);
    return 0;
}