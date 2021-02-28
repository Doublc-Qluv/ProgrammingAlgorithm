//ISBN形如：x-xxx-xxxxx-x ，求识别码
//例如如0-670-82162-4，对 067082162 这 9 个数字，从左至右，分别乘以 1， 2，…， 9，
//再求和取 158 mod 11 的结果 4 作为识别码
//要求正确的ISBN输出Right，错误的ISBN输出正确的

#include <iostream>
#include <string>
using namespace std;

int main(){
    string isbn;
    int sum;
    getline(cin,isbn);
    sum = (isbn[0] - '0')*1 + (isbn[2] - '0') * 2 + (isbn[3] - '0') * 3 + 
        (isbn[4] - '0') * 4 + (isbn[6] - '0') * 5 + (isbn[7] - '0') * 6 + 
        (isbn[8] - '0') * 7 + (isbn[9] - '0') * 8 + (isbn[10] - '0') * 9;
    if(sum%11==isbn[12]-'0' || sum%11==10 && isbn[12]=='X')
        cout << "Right" << endl;
    else{
        if(sum%11==10) {isbn[12] = 'X';}
        else{
            isbn[12] = sum%11 + '0';
            cout << "Correct ISBN is "<< isbn << endl;
        }
    }
    return 0;
}