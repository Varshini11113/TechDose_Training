#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class HashMap{
    public:
    vector<vector<pair<int,int>>>mp;
    HashMap(){
        mp.resize(1000);
    }
 int hash(int key){
        return key%1000;
    }

    void put(int key, int value) {
      auto &curr=mp[hash(key)];
        
        for(auto it=curr.begin();it!=curr.end();it++){
            if(it->first==key){
                it->second=value;
                return;
            }
        }  
        curr.push_back({key,value});
        return;
        
    }
    
    int get(int key) {
       auto &curr=mp[hash(key)];
        for(auto it:curr){
            if(it.first==key){
                return it.second;
            }
        }    
       return -1;
    }
    
    void remove(int key) {

        auto &curr=mp[hash(key)];
        for(auto it=curr.begin();it!=curr.end();it++){
            if(it->first==key){
                curr.erase(it);
                return ;
            }
        }    

    }
};

int main(){
    HashMap mp;
    mp.put(10,200);
    mp.put(20,300);
    mp.remove(20);
    cout<<mp.get(20);
}