#include<iostream>
using namespace std;

template<typename T>

void calculator(){
    T a,b,c;
    char choice;
    cin>>a;
    cin>>b;
    cin>>choice;
    switch(choice){
        case '+':
            c = a + b;
            break;
        case '-':
            c = a - b;
            break;

        case '*':
            c = a * b;
            break;
        case '/':
        if(b==0){cout<<"Error";}
        break;
            c = a / b;
            break;
        default:
            cout<<"errror";
    };

    cout<<c;
}
int main() {
    calculator<double>();
    return 0;
}