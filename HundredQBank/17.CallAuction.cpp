/*
集合竞价：股票根据开盘前客户提交的订单来确定某特定股票的开盘价和开盘成交量
输入有多行组成，每行为一条记录，记录的可能性有以下几种：
1. buy p s 一个购买者的买单，每手出价为p,购买数为s.
2. sell p s 一个出售股票的卖单，每手出价为p,出售数为s.
3. cancel i 撤销第i行的记录

如果开盘价为p0,则系统可以将出价至少为p0的买单和所有出价至多为p0的卖单进行匹配。因此此时的开盘成交量为出价至少为p0的买单的总股数 和 所有出价至多为p0的卖单的总股数之间的较小值。

需要制定一个开盘价，使得开盘成交量最大化，如果有多个，选择输出最高的那个

输入多行记录，股数为不超过108的正整数，出价为精确到恰好小数点后两位的正实数，且不超过10000.00
输出一行两个实数，以一个空格分割，第一个是开盘价，要恰好精确到小数点后两位，第二个是成交量。
*/

#include <iostream>
#include <queue>
using namespace std;
const int N = 5000;
bool cancel[N];
struct trade
{
    double price;
    long long num;
    bool operator < (const trade& n) const {
        return price > n.price;
    }
}a[N];
priority_queue<trade> buy,sell;

int main(){

}