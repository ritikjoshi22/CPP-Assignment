#include<iostream>

using namespace std;

class detail
{
    public:
    string username;
    string password;
};

int main()
{
    detail u1;
    cout<<"\t\t\t\t\t\tLogin page\n";
    cout<<"Username:";
    cin>>u1.username;
    cout<<"Password:";
    cin>>u1.password;
    if(u1.username=="ritik" && u1.password=="ironman"){
        cout<<"Access granted"<<endl;
    }
    else{
        cout<<"Try Again"<<endl;
    }
    return 0;
}