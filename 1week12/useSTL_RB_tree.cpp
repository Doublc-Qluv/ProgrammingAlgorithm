#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>//使用multiset和set使用头文件

using namespace std;

int main(){
    multiset<int> st;
    int b[] = {3,5,1,-7,4,9,-6,8,10,4};
    int c[] = {53,125,43,-6,8,10,4,0};
    for(int i = 0; i < 10; ++i){
        st.insert(b[i]);
    }
    multiset<int>::iterator i;//迭代器类似指针
    for(i = st.begin();i!=st.end();++i){
        cout << *i << ",";
    }
    cout<<endl;

    i = st.find(22);//定义i，查找22
    if(i == st.end()) cout << "not found"<<endl;
    
    st.insert(22);//插入22
    i = st.find(22);
    if(i == st.end()) cout << "not found"<<endl;
    else cout << "found:"<< *i <<endl;
    
    i = st.lower_bound(5);
    cout << *i <<endl;

    i = st.upper_bound(3);
    cout << *i <<endl;
    

    for(i = st.begin();i!=st.end();++i){
        cout << *i << ",";
    }
    cout<<endl;

    i = st.find(22);
    st.erase(i);//删除i

    for(i = st.begin();i!=st.end();++i){
        cout << *i << ",";
    }
    return 0;
}