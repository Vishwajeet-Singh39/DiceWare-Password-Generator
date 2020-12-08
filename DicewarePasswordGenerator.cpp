#include<iostream>
#include<random>
using namespace std;
#include"phraseList.h"
void randomNumber(int dice[]){
    random_device random;
	mt19937 gen(random());
	uniform_int_distribution<int> dis(1,6);
	for(int i=0;i<5;i++){
		dice[i]=dis(gen);
	}
}
int getIndex(int dice[]){
    int index;
    int value1[]={0 , 1297, 2593, 3889, 5185, 6481};
    int value2[]={0 , 216, 432, 648, 864, 1080};
    int value3[]={0, 37, 73, 109, 145, 181};
    int value4[]={0, 7, 13, 19, 25, 31};
    int value5[]={0, 1, 2, 3, 4, 5};

    index= value1[dice[1]-1];
    index+=value2[dice[2]-1];
    index+=value3[dice[3]-1];
    index+=value4[dice[4]-1];
    index+=value5[dice[5]-1];
    return index;
}
string generatePhrase(){
    int dice[5];
    randomNumber(dice);
    int index=getIndex(dice);
    string phrase=phraseList[index];
    return phrase;
}
int main(){
    string password="";
    int n;
    cout<<"How many words do you you want in your password: ";
    cin>>n;
    for(int i=0;i<n;i++){
        password=password+" "+generatePhrase();
    }
    cout<<"The genrated password is:"<<password;
}