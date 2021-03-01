/* 词频统计 从多到少，词语从前往后
输入样例：  输出样例：
this      plus 3
is        is 2
ok        this 2
this      ok 1
plus      that 1
that
is
plus
plus
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
using namespace std;

struct Word {
    int times;
    string wd;
};

struct Rule {
    bool operator () ( const Word & w1,const Word & w2) {
        if( w1.times != w2.times)
            return w1.times > w2.times;
        else
            return w1.wd < w2.wd;
    }
};

int main()
{   
    freopen("./words.txt","r",stdin);
    string s;
    set<Word,Rule> st;
    map<string,int> mp;
    while( cin >> s )
        ++ mp[s] ;
    for( map<string,int>::iterator i = mp.begin();i != mp.end(); ++i) {
        Word tmp;
        tmp.wd = i->first;
        tmp.times = i->second;
        st.insert(tmp);
    }
    for(set<Word,Rule>::iterator i = st.begin();i != st.end(); ++i)
        cout << i->wd << " " << i->times << endl;
}