#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<string> v;
    long long  con_s[n];
    for(int i=0;i<n;i++)
    {
      string s;
      cin>>s;
      con_s[i]=0;
      for(int j=0;j<s.length();j++)
      {
        con_s[i] = con_s[i] | (1<<(s[j]-'a'));
      }
    }
    long long complete = 0;
    complete = (1<<('a'-'a')) | (1<<('e'-'a')) | (1<<('i'-'a')) | (1<<('o'-'a')) | (1<<('u'-'a'));
    // cout<<complete;
    int count = 0;
    for(int i=0;i<n-1;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        if((con_s[i] | con_s[j])==complete)count++;
      }
    }
    cout<<count<<"\n";
  }
  return 0;
}
