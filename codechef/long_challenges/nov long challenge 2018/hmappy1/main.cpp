#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// a program for decimal to binary just for checking would be commented later. program is directly from geekforgeeks
void decToBinary(long int n)
{
    // array to store binary number
    long int binaryNum[1000];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j] << " ";
}
int main()
{
    unordered_map<long int,long int> hm;
    long int n,q,k,number=0,copi;
    string query;
    cin >> n >> q >> k;
    long int wolf,wolf1;
    wolf = n-1;
    bool s[n];
    for(long int i=0;i<n;i++)
    {
        cin >> s[i];
        if(s[i]==1)
        {
            number = number + pow(2,n-i-1);
        }
    }
    decToBinary(number);
    cin >> query;
    cout << number << endl;
    for(long int i=0;i<q;i++)
    {
        copi = number;
        if(query[i]=='?')
        {
            cout << "iif1"<< endl;
        while(copi!=0)
        {
            copi=(copi&(copi<<1)); // makes all the ending 1's in all subsequences to 0, eg: 111011 would become 110010
            //method to calculate length of longest continuous subsequence
            hm[i]++;
            if(hm[i] >= k){
            cout << k << endl;
            goto hola;
            }
        }
        cout << hm[i] << endl;
        }
        else{
                cout << " else" << endl;
                wolf = number >> 1;
                cout << wolf << " w";
                wolf1 = number << n-1;
                cout << wolf1 << "w1";
                number = wolf|wolf1;
            cout << number << " num";
            decToBinary(number);
        }
        hola:
            ;
    }
}
