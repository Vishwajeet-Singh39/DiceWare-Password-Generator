#include<iostream>
#include<time.h>
using namespace std;
void randomNumber(){
    srand(time(0));
    for(int i=0;i<5;i++){
        cout<<(rand()%6)+1;   
    }
}
int main(){
    randomNumber();
}