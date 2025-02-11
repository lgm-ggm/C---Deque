#include <deque>
#include <iostream>
#include <vector>
using namespace std;

void print(const deque<int> &d){
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++){//注意const_iterator 的使用区别与const iterator
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    deque<int> d(10,0);
    d.push_back(10);
    d.push_front(100);
    print(d);

    deque<int> d1(d.begin(),d.end());
    print(d1);

    deque<int> d2;
    d2 = d1;
    print(d2);

    deque<int> d3;
    d3.assign(10,10);
    print(d3);

    return 0;
}