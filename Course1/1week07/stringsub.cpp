#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
/*
判断
s2不是s1的子串，返回-1
s2是s1的子串，返回在s1中第一次出现的位置
空串是任何串的子串，出现位置返回为0
*/
int substring(char s1[], char s2[]){
    if(s2[0] == 0) return 0;
    for(int i = 0; s1[i]; ++i){
        int k = i, j = 0;
        for(; s2[j]; ++j, ++k){
            if(s1[k] != s2[j]) break;
        }
        if(s2[j] == 0) return i;
    }
    return -1;
}

int main(){
    char s1[10];
    char s2[10];
    cin >> s1 >> s2 ;cout << s1 << endl << s2 << endl;
    cout << substring(s1, s2);
    return 0;
}