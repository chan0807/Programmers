#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    while(k != 0){
        for(int i =0;i< number.size(); i++)
        {
            if(i == number.size()-1){ 
                number.pop_back(); 
                k--;
            }
            
            if( number[i] <number[i+1])
               { number.erase(number.begin()+i);
                k--;
                break;
               }
        }
    }
    
    return number;
}