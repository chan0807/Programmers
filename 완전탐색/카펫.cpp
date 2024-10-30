#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int column = 1; 
    int b = (brown-4) /2;
    while(column <=yellow)
    {
        if(yellow % column !=0) { column+=1; continue;}
        int row = yellow / column;
        if(b ==row + column) return {row+2, column+2};
        column+=1;
    }
    
    return answer;
}