#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string weekdays[] =  {"Monday", "Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int main(){
    int n;
    cin >> n;
    if(n > 7 || n < 1)
        cout << "Illegal";
    else
        cout << weekdays[n-1];
    
    return 0;
}