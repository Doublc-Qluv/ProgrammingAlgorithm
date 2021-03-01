#include <iostream>
#include <cstdio>
#include <map>//使用multimap和map使用头文件

using namespace std;

struct StudentInfo
{
    int id;
    char name[20];
};

struct Student
{
    int score;
    StudentInfo info;
};

typedef multimap<int,StudentInfo> Map_Std;
//使得Map_Std 等价于 multimap<int,StudentInfo>

int main(){
    Map_Std mp;
    Student st;
    char cmd[20];
    while (cin >> cmd)
    {
        if (cmd[0] == 'A') {
            cin >> st.info.name >> st.info.id >> st.score;
            mp.insert(make_pair(st.score, st.info));//first = st.score  |  second = st.score
        }
        else if ( cmd[0] == 'Q')
        {
            int score;
            cin >> score;
            Map_Std::iterator p = mp.lower_bound(score);
            if(p!=mp.begin()){
                --p;
                score = p->first;
                Map_Std::iterator maxp = p;
                int maxid = p->second.id;
                for(;p!=mp.begin() && p->first == score;--p){//遍历所有与score相等的学生
                    if(p->second.id > maxid){
                        maxp = p;
                        maxid = p->second.id;
                    }
                }
                if(p->first == score){
                    if(p->second.id > maxid){
                        maxp = p;
                        maxid = p->second.id;
                    }
                }
                cout << maxp->second.name << " " << maxp->second.id << " " 
                << maxp->first <<endl;
            }
            else cout << "Nobody" <<endl;
        }
    }

    return 0;
    
}