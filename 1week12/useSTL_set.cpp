#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>//使用multiset和set使用头文件

using namespace std;


int main(){
    set<int> st;
    int a[10] = {1,2,3,8,7,7,5,6,8,12};
    for(int i = 0;i < 10; ++i){
        st.insert(a[i]);
    }// set中不能有重复元素
    cout << st.size() << endl;//8
    set<int>::iterator i;
    for(i = st.begin(); i!=st.end(); ++i){
        cout << *i << ",";
    }
    cout << endl;//1,2,3,5,6,7,8,12,

    //set 有可能插入不成功
    
    
    /*
    pair<set<int>::iterator, bool> result = st.insert(2);
    < = >
    
    struct 
    {
        set<int>::iterator first;
        bool second
    };
    */
    pair<set<int>::iterator, bool> result = st.insert(2);
    
    if(!result.second){
        cout << *result.first << " already exsit" << endl;
    }
    else cout << *result.first << "inserted" << endl;
    
    return 0;
}