//No.15828: Router
//분류: 큐 (Queue)
//https://www.acmicpc.net/problem/15828

#include <iostream>
#include <queue>

using namespace std;

int main() {
    
    int size, input = 0;
    
    cin >> size;
    
    queue<int> q;
    
    while(1){
        cin >> input;
        
        if(input <= -1){
            break;
        }else if(input == 0 && !q.empty()){
            q.pop();
        }else if (input > 0 && q.size() < size){ // Normal Input
            q.emplace(input);
        }
    }
    
    if(q.empty()){
        cout << "empty";
    }else{
        while(!q.empty()){
            cout << q.front() << " ";
            q.pop();
        }
    }
    
   return 0;
}
