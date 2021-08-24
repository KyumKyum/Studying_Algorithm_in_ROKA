//백준 2164: 카드 2
//분류: 큐 (Queue)
//https://www.acmicpc.net/problem/2164

#include <iostream>
#include <queue>

using namespace std;

int main() {
    
    int size, container = 0;
    
    cin >> size;
    
    queue<int> q;
    
    for(int i = 0; i < size; i++){
        q.emplace(i+1);
    }
    
    while(!(q.size() == 1)){
        //1. Withdraw
        q.pop();
        //2. Shuffle
        container = q.front();
        q.pop();
        q.emplace(container);
    }
    
    cout << q.front();
    
   return 0;
}
