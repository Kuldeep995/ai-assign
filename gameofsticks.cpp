#include<bits/stdc++.h>
using namespace std;

int aich = 0;

int prune(bool chance, int score, int sticks, int n)
{
    if((chance && score == 1) || (!chance && score == -1))
    {
        aich = sticks;
        return score;
    }
    else if(n == sticks)
    {
        aich = 1;
        return score;
    }
    else
        return 0;
}

bool toss()
{
    double x =((double) rand()/ (RAND_MAX));
    if(x >= 0.5)
        return true;
    else
       return false;
}


int minimax(int n, bool chance)
{
    if(n == 0)
    {
        if(chance)
            return 1;
        return -1;
    }
    
    int s1 = minimax(n-1, !chance);
    int x = prune(chance, s1, 1, n);
    if(x != 0)
        return x;
    int s2 = minimax(n-2, !chance);
    x = prune(chance, s2, 2, n);
    if(x != 0)
        return x;
    int s3 = minimax(n-3, !chance);
    if(chance)
    {
        if(s3 == 1)
        {
            aich = 3;
            return 1;
        }
        else{
            aich = 1;
            return s3;
        }
    }
    else{
        if(s3 == 1)
        {
            aich = 1;
            return s3;
        }
        else{
            aich = 3;
            return s3;
        }
    }
}



int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, pch;
    bool t = true;
    char choice;
    while(t)
    {
        cout<<"Enter no. of sticks ";
        cin>>n;

        cout<<"Now lets have toss"<<endl;
        bool chance = toss();
        if(chance)
            cout<<"AI won the toss"<<endl;
        else
            cout<<"Congrats, You won the toss"<<endl;

        cout<<"total sticks "<<n<<" are on the table"<<endl<<endl;
        cout<<"***********Game Starts Now***********"<<endl<<endl;

        if(!chance)
        {
            cout<<"pick up sticks in range of 1 to 3: ";
            cin>>pch;
            while(pch < 1 || pch > 3)
            {
                cout<<"please pick up sticks striclty between 1 to 3: ";
                cin>>pch;
            }
            cout<<endl;
            cout<<"you picked up "<<pch<<" sticks"<<endl;
            n = n - pch;
            cout<<"remaining sticks are "<<n<<endl;
            chance = !chance;
        }

        while(n)
        {
            int x = minimax(n, chance);
            cout<<"AI picked up "<<aich<<" sticks"<<endl;
            n = n - aich;
            cout<<"remaining sticks are "<<n<<endl<<endl<<endl;

            if(n == 0)
            {
                cout<<"**************** Congrats You won , AI lost**************"<<endl<<endl<<endl;
                break;
            }

            cout<<"pick up sticks in range of 1 to 3: ";
            cin>>pch;
            while(pch < 1 || pch > 3)
            {
                cout<<"please pick up sticks striclty between 1 to 3: ";
                cin>>pch;
            }
            cout<<"you picked up "<<pch<<" sticks"<<endl;

            while(pch > n)
            {
                cout<<"you tried to pick more than remaining sticks"<<endl;
                cout<<"enter less than remaining sticks on table: ";
                cin>>pch;
            }
            cout<<"remaining sticks are "<<n<<endl<<endl;

            n = n - pch;
            cout<<endl;
            if(n == 0)
            {
                cout<<"**************** AI won , You lost **************"<<endl<<endl;
                break;
            }
        }

        cout<<"Do you want to play again? Type 'y' for yes and 'n' for no: ";
        cin>>choice;
        if(choice == 'n')
            t = false;
    }

    return 0;
}