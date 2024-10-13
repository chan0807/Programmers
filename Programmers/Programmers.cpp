#include <iostream>
#include "Hash.h"
#include "QueueStack.h"
#include "Heap.h"
#include "Array.h"

using namespace std;

int main()
{
    vector<int> a = { 1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> b = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    vector<string> c = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};

    vector<int> answer = HeapThree2(c);
}