#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int a[n][m];
        int maxval;
        if(n==2 && m==3)
        {
            maxval = 3;
            cout << "3" << endl;
            a[0][0] =1;
            a[0][1] = 1;
            a[0][2] = 2;
            a[1][0] = 2;
            a[1][1] = 3;
            a[1][2] = 3;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if(n==1 && m==3)
        {
            cout << "2" << endl;
            cout << "1 1 2" << endl;
        }
        else if(n==1 && m==4)
        {
            cout << "2" << endl;
            cout << "1 1 2 2" << endl;
        }
        else if(n==1 && m==5)
        {
            cout << "2" << endl;
            cout << "1 1 2 2 1" << endl;
        }
        else if(n==1 && m==6)
        {
            cout << "2" << endl;
            cout << "1 1 2 2 1 1" << endl;
        }
        else if(m==1 && n==3)
        {
            cout <<"2" << endl;
            cout << "1" << endl;
            cout << "1" << endl;
            cout << "2" << endl;
        }
        else if(m==1 && n==4)
        {
            cout <<"2" << endl;
            cout << "1" << endl;
            cout << "1" << endl;
            cout << "2" << endl << "2" << endl;
        }
        else if(m==1 && n==5)
        {
            cout <<"2" << endl;
            cout << "1" << endl;
            cout << "1" << endl;
            cout << "2" << endl << "2" << endl <<"1" << endl;
        }
        else if(m==1 && n==6)
        {
            cout <<"2" << endl;
            cout << "1" << endl;
            cout << "1" << endl;
            cout << "2" << endl <<"2" << endl << "1" << endl <<"1" << endl;
        }
        else if(n==2 && m==2)
        {
            maxval=2;
            cout << "2" << endl;
            a[0][0]=1;
            a[0][1]=1;
            a[1][0]=2;
            a[1][1]=2;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if(n==1 && m==1)
        {
            maxval=1;
            cout << "1" << endl;
            cout << "1" << endl;
        }
        else if(n==2 && m==1)
        {
            maxval=1;
            cout << "1" << endl;
            cout << "1" << endl;
            cout << "1" << endl;
        }
        else if(n==1 && m==2)
        {
            maxval=1;
            cout << "1" << endl;
            cout << "1 1" << endl;
        }
        else if(n==2 && m>2)
        {
            maxval =3;
            cout << "3"<< endl;
            int a[m];
            for(int p=0;p<m;p++)
            {
                if((p+1)%3==1)
                {
                    a[p]=1;
                }
                else if((p+1)%3==2)
                {
                    a[p]=2;
                }
                else{
                    a[p]=3;
                }
                cout << a[p] << " ";
            }
            cout << endl;
            for(int p=0;p<m;p++)
            {
                cout << a[p] << " ";
            }
            cout << endl;
        }
        else if(n>2 && m==2)
        {
            maxval = 3;
            cout << "3" << endl;
            int a[n][2];
            for(int p=0;p<n;p++)
            {
                for(int l=0;l<2;l++)
                {
                    if((p+1)%3==1)
                    {
                        a[p][l]=1;
                    }
                    else if((p+1)%3==2)
                    {
                        a[p][l] = 2;
                    }
                    else{
                        a[p][l]=3;
                    }
                    cout << a[p][l] << " ";
                }
                cout << endl;
            }

        }
        else if(n>2 && m==1)
        {
            maxval = 2;
            cout << "2" << endl;
            int a[n];
            a[0]=1;
            a[1] = 1;
            cout << a[0] << endl << a[1] << endl;
            for(int p=2;p<n;p++)
            {
                if(a[p-2]==1)
                {
                    a[p] = 2;
                }
                else{
                    a[p] = 1;
                }
                cout << a[p] << endl;
            }
        }
        else if(n==1 && m>2)
        {
            maxval = 2;
            cout << "2" << endl;
            int a[m];
            a[0] =1;
            a[1]=1;
            for(int p=0;p<m;p++)
            {
                if(p-2>=0)
                {
                   if(a[p-2]==1)
                   {
                       a[p] = 2;
                   }
                   else
                   {
                       a[p] = 1;
                   }
                }
                cout << a[p] << " ";
            }
            cout << endl;
        }
        else if(n==3 && m==2)
        {
            maxval = 3;
            cout << "3" << endl;
            a[0][0]=1;
            a[0][1]=2;
            a[1][0]=1;
            a[1][1]=3;
            a[2][0]=2;
            a[2][1]= 3;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if(n>2 && m>2)
        {
         maxval = 4;
         cout << "4" << endl;
        for(int i=0;i<m;i++)
        {
            if((i+1)%4 == 1 || (i+1)%4 == 2)
            {
                a[0][i]=1;
                cout << a[0][i] << " ";
            }
            if((i+1)%4 == 3 || (i+1)%4 == 0)
            {
                a[0][i]=2;
                cout << a[0][i] << " ";
            }
        }
        cout << endl;
        for(int i=1;i<n;i++)
        {
            if(i%4 == 1 || i%4 == 2)
                {
                    cout << "2 ";
                    a[i][0] = 2;
                }
                else{
                    cout << "1 ";
                    a[i][0] = 1;
                }
            for(int j=1;j<m;j++)
            {
                if(a[i-1][j-1] == 1)
                {
                    a[i][j] = 3;
                    cout << a[i][j] << " ";
                }
                else if(a[i-1][j-1] == 3)
                {
                    a[i][j] = 1;
                    cout << a[i][j] << " ";
                }
                else if(a[i-1][j-1] == 2)
                {
                    a[i][j] = 4;
                    cout << a[i][j] << " ";
                }
                else{
                    a[i][j] = 2;
                    cout << a[i][j] << " ";
                }
            }
            cout << endl;
        }
        }
    }
}
