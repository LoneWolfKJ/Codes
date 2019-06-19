// problem in this is that min len 1's also decrease on shifting nd its possible a new min len be required
// solved above problem a bit, a realy huge code, hopw it works
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int,int> hm;
    int n,q,k;
    string query;
    cin >> n >> q >> k;
    bool s[n];
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
    }
    cin >> query;
    int ml1,indexending0,count1ending;
    int prev_index,result[n];
    int results1o=0;
    result[n] = {0};
    prev_index = -1;
    int wolfy=0;
    int storage[2];
    int minlen;
    //cout << storage[0] << "storage[0]" << endl;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]==0)
        {
            indexending0=i;
            goto hola;
        }
    }
    hola:
        ;
    int indexstarting0=0;
    int count1starting=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==0)
        {
            indexstarting0=i;
            goto hola1;
        }
    }
    hola1:
        ;
    long long int excounter=0,kj=0;
    int aldreadyshft=0;
    count1ending = n-1- indexending0;
    count1starting= indexstarting0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 0)
            {
                result[wolfy] = i-prev_index-1;
                wolfy++;
                prev_index = i;
            }
    }
    for (int i = 0; i <n; i++)
    {
        if (s[i] == 0)
            {
              if(i- prev_index-1 > results1o)
              {
                  results1o = i-prev_index-1;
                  storage[0] = prev_index;
                  storage[1]= i;
              }
              prev_index = i;
            }
    }
    result[wolfy] = count1ending;
    sort(result,result+wolfy+1);
    ml1 = result[wolfy];
    //for(int i =0; i<=wolfy; i++)
    //{
        //cout << i <<" result is " << result[i] << endl;
    //}
    //cout << minlen << " minlen is " << endl;
    //cout << ml1 <<"ml1" << endl;
    if(count1starting!=0 && count1ending!=0 && (count1starting + count1ending)>=ml1)
    {
        aldreadyshft=1;
    }
    minlen=result[wolfy-1];

    if(aldreadyshft)
    {
        if(ml1==count1starting)
        {
            if(result[wolfy-1]==count1ending)
            {
                minlen = result[wolfy-2];
            }
            else{
                minlen = result[wolfy-1];
            }
        }
        else if(ml1 == count1ending)
        {
            if(result[wolfy-1]==count1starting)
            {
                minlen= result[wolfy-2];
            }
            else{
                minlen = result[wolfy-1];
            }
        }
        else{
            minlen = ml1;
        }
    }
    cout << aldreadyshft << " shifted" << endl;
    cout << count1starting << " starting   " << count1ending << "ending" << endl;
    cout << kj << " kj initial" << endl;
    cout << "storage[1] = " << storage[1] << endl;
    int bola;
    cout << " minlen " << minlen << endl;
    bola = n-storage[1];
    for(int i=0;i<q;i++)
    {
        if(query[i]=='!')
        {
            excounter++;
            kj = excounter%n;
            cout << kj << " loop " << i << endl;
        }
        if(query[i]=='?')
        {
            if(!aldreadyshft)
        {
            if(kj>=0 && kj<= bola)
            {
                if(ml1 <=k && ml1>=minlen)
                    cout << ml1 << endl;
                else if(ml1<minlen)
                    cout << minlen << endl;
                else
                    cout << k << endl;
            }
            if(kj>bola && kj<=(bola + (ml1)/2))
            {
                if((ml1 - (kj-n+storage[1])) <=k && (ml1 - (kj-n+storage[1]))>=minlen)
                    cout << (ml1 - (kj-n +storage[1])) << endl;
                else if((ml1 - (kj-n+storage[1]))<minlen)
                    cout << minlen << endl;
                else
                    cout << k << endl;
            }
            if(kj>(bola + (ml1)/2) && kj<=(bola + ml1))
            {
                if((kj-bola) <=k && (kj-bola)>=minlen)
                    cout << kj - bola << endl;
                else if((kj-bola)<minlen)
                    cout << minlen << endl;
                else
                    cout << k << endl;
            }
            if(kj>(bola + ml1) && kj < n)
            {
                if(ml1<=k && ml1>=minlen)
                    cout << ml1 << endl;
                else if(ml1<minlen)
                    cout << ml1 << endl;
                else
                    cout << k << endl;
            }
        }
        else{
             if(count1starting>=count1ending)
             {
                 if(kj>=0 && kj<=count1ending)
                 {
                     if((count1starting + kj)<= k &&(count1starting + kj)>=minlen)
                        cout << count1starting + kj << endl;
                    else if((count1starting + kj) <minlen)
                        cout << minlen << endl;
                     else
                        cout << k << endl;
                 }
                 else if(kj>count1ending && kj<= (n - (storage[1] - storage[0] )))
                 {
                     if((count1starting + count1ending) <=k &&(count1starting + count1ending)>=minlen)
                        cout << count1starting + count1ending << endl;
                    else if((count1starting + count1ending) < minlen)
                        cout << minlen << endl;
                     else
                        cout << k << endl;
                 }
                 else if(kj > (n - (storage[1] - storage[0])) && kj<= ((n - (storage[1] - storage[0] - 1)) + (count1starting + count1ending)/2))
                 {
                     //cout << " wrong here " << endl;
                     if((count1starting + count1ending - (kj - n +storage[1]-storage[0] -1)) <=k && (count1starting + count1ending - (kj - n +storage[1] - storage[0] - 1))>= minlen)
                        cout << ((count1starting + count1ending - (kj - n +storage[1] - storage[0] - 1))) << endl;
                    else if((count1starting + count1ending - (kj - n +storage[1] - storage[0] - 1))<minlen)
                        cout << minlen << endl;
                     else
                        cout << k << endl;
                 }
                 else if((kj> ((n - (storage[1] - storage[0] - 1)) + ((count1starting + count1ending)/2))) && kj < n-1 )
                 {
                     if(((kj - n +storage[1] - storage[0] - 1)) <=k && ((kj - n +storage[1] - storage[0] - 1))>=minlen)
                        cout << (((kj - n +storage[1] - storage[0] - 1))) << endl;
                    else if(((kj - n +storage[1] - storage[0] - 1))<minlen)
                        cout << minlen << endl;
                     else
                        cout << k << endl;
                 }
                 else
                 {
                     if(count1starting <=k && count1starting>=minlen)
                        cout << count1starting << endl;
                    else if(count1starting < minlen)
                        cout << minlen << endl;
                     else
                        cout << k << endl;
                 }
             }
             if(count1starting<count1ending)
             {
                 //cout << "kj value = " << kj << " for loop " << i << endl;
                if(kj==0)
                {
                    if(count1ending <=k && count1ending>=minlen)
                        cout << count1ending << endl;
                    else if(count1ending < minlen)
                        cout << minlen << endl;
                    else
                        cout << k << endl;
                }
                if(kj>0 && kj<= count1ending)
                {
                    if((count1starting + kj)<=k && (count1starting + kj)>=minlen)
                        cout << count1starting + kj << endl;
                    else if ((count1starting + kj) < minlen)
                        cout << minlen << endl;
                    else
                        cout << k << endl;
                }
                if(kj>count1ending && kj<= (n - (count1starting + count1ending)))
                {
                    if((count1starting + count1ending) <= k && (count1starting + count1ending)>=minlen)
                        cout << count1starting + count1ending << endl;
                    else if((count1starting + count1ending)<minlen)
                        cout << minlen << endl;
                    else
                        cout << k << endl;
                }
                if(kj>(n - (count1starting + count1ending)) && kj<n)
                {
                    if((count1starting + count1ending -(kj - n + storage[1] - storage[0] -1)) <=k && (count1starting + count1ending -(kj - n + storage[1] - storage[0] -1))>=minlen)
                        cout << (count1starting + count1ending -(kj - n + storage[1] - storage[0] - 1)) << endl;
                    else if((count1starting + count1ending -(kj - n + storage[1] - storage[0] -1))<minlen)
                        cout << minlen << endl;
                    else
                        cout << k << endl;
                }
             }
            }
        }
    }
}


