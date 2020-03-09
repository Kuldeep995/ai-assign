#include <bits/stdc++.h>
using namespace std;

void fitfunc(int a[],int n, int arr[4])
{
    int i,p,b,c,fit = 0;
      for(i=0;i<n;i++)
      {
          p =  abs(a[i]-arr[0]);
          b =  abs(a[i]-arr[1]);
          c =  abs(a[i]-arr[2]);

          p>b?(b>c?fit+=c:fit+=b):(p>c?fit+=c:fit+=p);
      }
      arr[3]=fit;
}


void selcrossmut(int a[],int n,int arr[][4],int m)
{
    srand(time(0));
    int i,t,k,j,w;
    int arr1[m][4];
    for(i=0;i<m/2;i++)
    {  
        int mini=9999999;
        for(t=0;t<20;t++)
           { w = rand()%m;
             if(arr[w][3]<mini)
             {   mini = arr[w][3];
                 k=w;}
           }
        mini =9999999;
        for(t=0;t<20;t++)
           { w = rand()%m;
             if(arr[w][3]<mini)
             {   mini = arr[w][3];
                 j=w;}
           }

         int c = rand()%3;

         for(t=0;t<=c;t++)
         {
             arr1[i][t] = arr[k][t];
             arr1[m-i-1][t] = arr[j][t];
         }
         for(t=c+1;t<=2;t++)
         {
             arr1[i][t] = arr[j][t];
             arr1[m-i-1][t] = arr[k][t];
         }
         
    }
   
    int y = rand()%m;

    for(i=0;i<y;i++)
    {
        int g,h,r;
        g = rand()%m;
        h = rand()%3;
        r = rand()%n;
        arr1[g][h] = a[r];
    }

    for(i=0;i<m;i++)
     {
         fitfunc(a,n,arr1[i]);
     }

     for(i=0;i<m;i++)
     {
          for(t=0;t<4;t++)
          {
              arr[i][t]=arr1[i][t];
          }
     }

   
}

void chromo(int a[],int n,int arr[][4],int m)
{   
    srand(time(0));
    int i,j,k;


    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        {
            k = rand()%n;
            arr[i][j] = a[k];
        }
    }

     for(i=0;i<m;i++)
     {
         fitfunc(a,n,arr[i]);
     }

}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    srand(time(0));

    cout<<"Enter number of students: "<<endl;

    int i,j,n;
    cin>>n;
    int a[n];

    for(i=0;i<n;i++)
     {
         a[i] = rand()%101+1;                
     }
    int popu[50][4];

    //making chromosomes                   
    chromo(a,n,popu,50);
    int gmi = 99999999,gmini[4],itr = 2000,mi = 99999999;
    
    while(itr-- || ((mi-gmi)>0) )
    {
    int mini[4];
    i=0;
    while(i<50)
    {
        if(popu[i][3] < mi)
        {
            mi = popu[i][3];
            mini[0] = popu[i][0];
            mini[1] = popu[i][1];
            mini[2] = popu[i][2];
            mini[3] = popu[i][3];
        }
        i++;
    }
    if(mi<gmi)
    {
        gmi = mi;
        gmini[0] = mini[0];
        gmini[1]=mini[1];
        gmini[2]=mini[2];
        gmini[3]=mini[3];
    }
     selcrossmut(a,n,popu,50);
    }
    vector <pair<int,int>> g1,g2,g3;
     int p,b,c;
      for(j=0;j<n;j++)
      {
          p =  abs(a[j]-gmini[0]);
          b =  abs(a[j]-gmini[1]);
          c =  abs(a[j]-gmini[2]);
          p>b?(b>c?(g3.push_back(make_pair(a[j],j))):(g2.push_back(make_pair(a[j],j)))):(p>c?(g3.push_back(make_pair(a[j],j))):(g1.push_back(make_pair(a[j],j))));
      }
    cout<<"########Group1:"<<gmini[0]<<" Group2:"<<gmini[1];
    cout<<" Group3 : "<<gmini[2]<<" fitness : "<<gmini[3]<<" "<<"##############"<<endl;
    cout<<"GROUP-1******"<<endl<<endl;
    for(j=0;j<g1.size();j++)
    {
        cout<<"student  "<<g1[j].second<<" : "<<g1[j].first<<endl;
    }
    cout<<"GROUP-2********"<<endl<<endl;
    for(j=0;j<g2.size();j++)
    {
        cout<<"student  "<<g2[j].second<<" : "<<g2[j].first<<endl;
    }
    cout<<"GROUP-3****"<<endl<<endl;
    for(j=0;j<g3.size();j++)
    {
        cout<<"student  "<<g3[j].second<<" : "<<g3[j].first<<endl;
    }
    return 0;
}
