// 问题描述
// 给出一个字符串和多行文字，在这些文字中找到字符串出现的那些行。你的程序还需支持大小写
// 敏感选项：当选项打开时，表示同一个字母的大写和小写看作不同的字符；当选项关闭时，表示同一
// 个字母的大写和小写看作相同的字符。
// 输入格式
// 输入的第一行包含一个字符串 S，由大小写英文字母组成。
// 第二行包含一个数字，表示大小写敏感的选项，当数字为 0 时表示大小写不敏感，当数字为 1
// 时表示大小写敏感。
// 第三行包含一个整数 n，表示给出的文字的行数。
// 接下来 n 行，每行包含一个字符串，字符串由大小写英文字母组成，不含空格和其他字符
// 输出格式
// 输出多行，每行包含一个字符串，按出现的顺序依次给出那些包含了字符串 S 的行。
// 样例输入
// Hello
// 1 5
// HelloWorld
// HiHiHelloHiHi
// GrepIsAGreatTool
// HELLO
// HELLOisNOTHello
// 样例输出
// HelloWorld
// HiHiHelloHiHi
// HELLOisNOTHello
// 样例说明
// 在上面的样例中，第四个字符串虽然也是 Hello，但是大小写不正确。如果将输入的第二行改为
// 0，则第四个字符串应该输出。
// 评测用例规模与约定
// 1<=n<=100，每个字符串的长度不超过 100。

#include <iostream>
#include <string>

using namespace std;


int main(){
    freopen("./13StringMatching.data","r",stdin);
    string S,str,strt;
    int op, n, Sl, strl;

    cin >> S;
    Sl = S.length();
    cin >> op;
    if(!op){//将目标字符串变为小写
        for(int i=0;i<S.length();i++){
            S[i]=tolower(S[i]);
        }
    }
    cin >> n;
    
    for(int j=0;j<n;j++){//处理输入的字符串
        cin >> str;
        strl = str.length();
        if(strl<Sl) continue;//输入字符串小于目标字符串，直接跳过
        strt = str;
        if(!op){
            for(int i=0;i<strl;i++){
                strt[i]=tolower(str[i]);
            }
        }
        for(int k=0;k<=strl-Sl;k++){//字符串匹配
            int j=0;
            for(;j<Sl;j++){
                if(strt[k+j]!=S[j]) break;
            }
            if(j==Sl){
                cout << str << endl;
                break;
            }
        }
    }

    return 0;
}