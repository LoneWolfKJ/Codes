#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// function of subsets and numsub are copied from quora from one of the answers in the below link
//https://www.quora.com/What-is-the-recursive-solution-for-finding-all-subsets-of-a-given-array
// what we do is store a vector in a vector, eg: 1,3 is stores as first element, then 3 is pushed out, and 1,4 is stored and so on,
// then 4 is added to 1,3 to give 1,3,4, etc and so on..

void numsub(vector<int>& s, vector<vector<int> >& wolf,
            vector<int>& subset, int index)
{
    for (int i = index; i < s.size(); i++)
    {
        subset.push_back(s[i]);
        wolf.push_back(subset);
        numsub(s, wolf, subset, i + 1);
        subset.pop_back();
    }
}

vector<vector<int> > subsets(vector<int>&s)
{
    vector<int> subset;
    vector<vector<int> > wolf;
    int index = 0;
    numsub(s, wolf, subset, index);

   return wolf;
}

float median(vector<int> new_array, int num)
{
    float median;
    if(num%2==0)
    {
        median = (float)(new_array[(num/2)-1] + new_array[num/2]) / 2;
    }
    else
    {
        median = new_array[((num+1)/2)-1];
    }
return median;
}

int main()
{
    int t;
    cin >> t;
    for(int j=0;j<t;j++)
    {
        int n,kj;
        cin >> n;
        vector<int> s;
        sort(s.begin(),s.end());
        vector<vector<int> > wolf;
        for(int i=0;i<n;i++)
        {
            cin >> kj;
            s.push_back(kj);
        }
        unsigned long long int counter = 0;
        wolf = subsets(s);

        for (int i = 0; i < wolf.size(); i++)
        {
            if(wolf[i].size() % 2 == 0)
            {
                int size = wolf[i].size();
                if(median(wolf[i], wolf[i].size()) == wolf[i][size / 2] || median(wolf[i], wolf[i].size()) == wolf[i][(size - 1)/2])
                {
                    counter++;
                }
            }
            else
            {
                counter++;
            }
        }
        cout << counter % 1000000007;
    }
}
