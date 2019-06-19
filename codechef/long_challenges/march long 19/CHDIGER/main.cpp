#include<bits/stdc++.h>
using namespace std;
bool Compare (pair<int, int> p1, pair<int, int> p2)  {
    if (p1.first < p2.first) {
        return true;
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    while(t--){
    priority_queue <pair<long long int, long long int>, vector <pair <long long int, long long int> >, function<bool (pair <long long int, long long int>, pair <long long int, long long int>) > > pq (Compare);
    long long int n, k=0,kjs;
    cin>>n>>kjs;
    long long int i = 1;
    while (n) {
        pq.push(make_pair(n%10, i));
        if(n%10 > kjs)
            k++;
        n = n/10;
        i++;
    }
    for(long long int j =1; j<=k;j++){
        pq.pop();
    }
    long long int number = pq.top().first;
    long long int index = pq.top().second;
    long long int digit = 1;
    pq.pop();
    while(!pq.empty()){
        long long int current_index = pq.top().second;
        digit = digit * 10;
        if(current_index < index) {
            number = number * 10 + pq.top().first;
        } else {
            number = digit * pq.top().first + number;
        }
        pq.pop();
    }
    cout<<number<<endl;
    }
    return 0;
}
