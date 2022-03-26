#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    int size;
    deque<int> dq;
    map<int, deque<int> ::iterator> mp;

    public:
        LRUCache(int s){
            size = s;
        }
        void refer(int page){

            if(mp.find(page) == mp.end()){
                if(dq.size() == size){
                    int ele = dq.front();
                    dq.pop_front();
                    mp.erase(ele);
                    dq.push_front(page);
                }else{
                    dq.push_front(page);
                    mp[page] = dq.begin();
                }
            }else{
                dq.erase(mp[page]);
                dq.push_front(page);
                mp[page] = dq.begin();
            }
        }

        void display(){

            for(deque<int> :: iterator it=dq.begin(); it!= dq.end(); it++){
                cout<<(*it)<<" ";
            }
        }
};


int main(){

    LRUCache ca(4);
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(4);
    
    ca.refer(4);
    // ca.display();
    ca.refer(5);
    ca.display();
}