//No.1158: 요세푸스 문제
//분류: 큐(Queue)
//https://www.acmicpc.net/problem/1158

#include<iostream>
#include <queue>

using namespace std;

int main()
{
    int people, elim, cnt = 0;
    queue<int> q;
    
    cin >> people >> elim;
    
    for (int i = 0; i < people; i++){
        
        q.emplace(i+1);
    }
        
    cout << "<";
        
    while(!(q.empty())){
        cnt++;
        
        if(cnt % elim == 0){//generating Josepus' matrix
            cout << q.front();
            q.pop();
            if(!(q.empty())){
                cout<<", ";
            }
        }else{
            int container = q.front();
            q.pop();
            //cout << "container: " << container;
            q.emplace(container);
        }
    }
    
    cout << ">";
    

    return 0;
}
