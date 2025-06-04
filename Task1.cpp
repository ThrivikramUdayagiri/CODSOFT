#include<iostream>
using namespace std;

int main(){
    int num=56;
    int input;
    cout<<"Enter the guess number in between 1-100 : ";
   

    while(true){

    cin>>input;
    
    if(input >= 100 || input <= 1){
        cout<<"Please enter the correct number."<<endl;
        cout<<"Enter the number again ";
        // break;
    } 

    if(input == num){
        cout<<"The guess number is correct."<<endl;
        break;
    }

    if(input > 75){
        cout<<"The number is too high."<<endl;
        cout<<"Enter the number again ";
        // break;
    }
    else if(input < 45){
        cout<<"The number is too low"<<endl;
        cout<<"Enter the number again ";
        // break;
    }
    else if(input >= 50 || input <= 59){
        cout<<"Hint: The digit is correct and the unit digit is multiple of 2."<<endl;
        cout<<"Enter the number again ";
        // break;
    }
    else if(input >=45 || input <=75){
        cout<<"Some what closer"<<endl;
        cout<<"Enter the number again ";
        // break;
    }
    

}
    return 0;

}