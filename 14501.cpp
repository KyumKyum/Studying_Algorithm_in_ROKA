// No.14501: 퇴사
// 분류: 동적 할당(Dynamic Programming), 브루트포스(Bruteforce)
// https://www.acmicpc.net/problem/14501
#include <iostream>
#define MAXVAL 16
#define UNDEFINED 0

using namespace std;

int T[MAXVAL] = { UNDEFINED };
int P[MAXVAL] = { UNDEFINED };
int cache[MAXVAL] = { UNDEFINED };
int N = UNDEFINED;
int maxProf = UNDEFINED;

int select(int date){

    if(date > N || date + T[date] > N + 1)) //Base Condition #1: If counseling time exceeds the resing date, or it already exceeds currently.
        return UNDEFINED;
        
    
    if(cache[date] != UNDEFINED) //Base Condition #2: If current date is already calculated
        return cache[date];
    
    int& total = cache[date]; 
    int curIncome = P[date];
    
    int testDate = date;
    date += T[date];
    
    int curMax = UNDEFINED;
    
    for(int i = date; i <= N + 1; i++){
        int sum = select(i) + curIncome;
        curMax = (curMax <= sum) ? sum : curMax;
    }
    
    
    total = curMax;
    
    return curMax;
    
}


int main()
{
    int tInput, pInput = UNDEFINED;
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        cin >> tInput >> pInput;
        T[i] = tInput;
        P[i] = pInput;
    }
    
    for(int i = 1; i <= N; i++){
        int ans = select(i);
        
        maxProf = (maxProf <= ans) ? ans : maxProf;
    }
    
    cout << maxProf << endl;
    
    return 0;
}
