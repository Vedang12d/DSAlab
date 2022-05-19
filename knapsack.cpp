#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> p1,const pair<int,int> p2){
    return ((double)p1.first/p1.second) > ((double)p2.first/p2.second);
}

int main()
{
    int n,capacity;
    cin>>n>>capacity;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end(),cmp);
    int current_capacity=0;
    double profit=0;
    for(int i=0;i<n;i++){
        if(current_capacity+v[i].second<=capacity){
            profit+=(double)v[i].first;
            current_capacity+=v[i].second;
        }
        else{
            profit+=((double)v[i].first/v[i].second)*((double)capacity-current_capacity);
            break;
        }
    }
    cout<<profit<<"\n";
}