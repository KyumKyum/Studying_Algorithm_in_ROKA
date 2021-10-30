// No.12865: 평범한 배낭
// 분류: 동적 할당(Dynamic Programming), 0/1 배낭 문제 (0/1 Knapsack Problem)
//acmicpc.net/problem/12865


#include <iostream>
#include <algorithm>
#define WEIGHT_LIMIT 100001
#define NUM_LIMIT 101


using namespace std;

int cache[NUM_LIMIT][WEIGHT_LIMIT] = { 0 };
int value[NUM_LIMIT] = { 0 };
int weight[NUM_LIMIT] = { 0 };
int max_value = 0;

int main()
{
    int number, handable = 0;
    
    cin >> number >> handable;
    
    for(int i = 1; i <= number; i++){
        cin >> weight[i] >> value[i];
    }
    
    for(int target = 1; target <= number; target++){
        for(int current_weight = 1; current_weight <= handable; current_weight++){
            if(current_weight < weight[target])
                cache[target][current_weight] = cache[target-1][current_weight];
                //unable to hold current item.
            else
                cache[target][current_weight] = max(value[target] + cache[target-1][current_weight-weight[target]], cache[target-1][current_weight]);
                //max value == max(max value of the rest space, max value of the current handable weight)
            if (max_value < cache[target][current_weight])
                max_value = cache[target][current_weight];
        }
        
    }
    
    cout << max_value << endl;
    return 0;
}
