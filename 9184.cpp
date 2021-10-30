//백준 9184 : 신나는 함수 실행
//분류: 동적 할당(Dynamic Programming) , 재귀 호출 (Recursive Call)
//https://www.acmicpc.net/problem/9184


#include <iostream>
#include <vector>
#define UNDEFINED 0
#define FIN -1

using namespace std;

int cache[21][21][21] = { UNDEFINED,};
int in_stream[3] = { 0 };
int first, second, third = 0;
int cnt = 0;
vector<int> vec;

int w(int x, int y, int z){
    if(x <= 0 || y <= 0 || z <= 0){
        return 1;
    }
    else if(x > 20 || y > 20 || z > 20){
        return w(20,20,20);
    }
    else if(x < y && y < z){
        if(cache[x][y][z] != 0)
            return cache[x][y][z];
        else{
            int ret =  w(x ,y ,z-1) + w(x, y-1, z-1) - w(x, y-1, z);
            cache[x][y][z] = ret;
            return ret;
        }
    }else{
        if(cache[x][y][z] != 0)
            return cache[x][y][z];
        else{
            int ret = w(x-1, y, z) + w(x-1, y-1, z) + w(x-1, y, z-1) - w(x-1, y-1, z-1);
            cache[x][y][z] = ret;
            return ret;
        }
       
    }
}

void print(int first, int second, int third){
    cout<<"w("<<first<<", "<<second<<", "<<third<<") = ";
    return;
}

int main()
{
    while (true){
        for(int i = 0; i < 3; i++){
        cin >> in_stream[i];
        vec.push_back(in_stream[i]);
        }
        
        if(in_stream[0] == FIN && in_stream[1] == FIN && in_stream[2] == FIN )
            break;
    }
    
    while(true){
        first = vec.at(cnt++);
        second = vec.at(cnt++);
        third = vec.at(cnt++);
        
        if(first == FIN && second == FIN && third == FIN)
            break;
        
        print(first,second,third);
        cout << w(first, second, third) << endl;
    }

    return 0;
} 
