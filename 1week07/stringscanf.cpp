#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char aline[10];
    cin.getline(aline,sizeof(aline));//读到n-1, 自动加上了'\0'结束符
    cout << aline;

    char s[10];
    while(gets(s)){//会越界，unsafe
        printf("%s",s);
    }
}