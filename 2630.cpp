//백준 2630: 색종이만들기
//분류: 분할정복 (Divide & Conquer)
//https://www.acmicpc.net/problem/2630

// Online C++ compiler to run C++ program online
#include <iostream>

//Definitions
#define BLUE 1
#define WHITE 0
#define UNDEFINED -1

int paper[200][200] = { UNDEFINED };
int size, cache = 0;
int blue, white = 0;

int decompose(int start, int end, int size){
    
    if(size <= 1){//Base case: the size of the paper is 1.
        // cout<<"DEBUG: Returning " << paper[start][end]<<" from <" <<start <<" , "<<end<<" >"<<endl; 
        return paper[start][end];
    }
    
    //Divide
    int upperLeft = decompose(start, end, size/2);
    int upperRight = decompose(start, end+(size/2), size/2);
    int underLeft = decompose(start+(size/2), end, size/2);
    int underRight = decompose(start+(size/2), end+(size/2), size/2);
    
    //debug
    // cout<<"DEBUG: Conquering [" << start<<" , " <<end<<"], size: " << size<<endl;
    // cout<<"< "<<upperLeft<<" , "<<upperRight<<" , "<<underLeft<<" , "<<underRight<<" >"<<endl;
    //Conquer
    if(upperLeft == upperRight && upperRight == underLeft && underLeft == underRight && underRight == upperLeft){
        return upperLeft; //All partitions have same colour.
    }else{ //if the colour is different,
        if(upperLeft != -1){
            (upperLeft == BLUE) ? ++blue : ++white;
        }
        if(upperRight != -1){
            (upperRight == BLUE) ? ++blue : ++white;
        }
        if(underLeft != -1){
            (underLeft == BLUE) ? ++blue : ++white;
        }
        if(underRight != -1){
            (underRight == BLUE) ? ++blue : ++white;
        }
    }
    
    return -1;
    
}

int main() {
    std::cin >> size;
    
    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= size; j++){
            std::cin >> cache;
            paper[i][j] = cache; 
        }
    }
    
    int result = decompose(1,1,size);
    
    if(result != -1){// The whole paper is solid colour.
        (result == BLUE) ? ++blue : ++white;
    }
    
    std::cout<<white<<"\n"<<blue<<std::endl;
    
    return 0;
}
