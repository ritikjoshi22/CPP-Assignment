#include<iostream>
#include "login.cpp"

using namespace std;

void activityLog(){
    
}

void goalSetting(){

}

void progressTracking(){

}

void nutritionGoal(){

}

void profile(){

}

void welcomepage(){
    int choice;
    cout<<"Welcome to Fitness Tracker\n";
    cout<<"1.Activity Log"<<endl;
    cout<<"2.Goal setting"<<endl;
    cout<<"3.Progress tracking"<<endl;
    cout<<"4.Nutrition goal"<<endl;
    cout<<"5.Profile"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        activityLog();
        break;
    case 2:
        goalSetting();
        break;
    case 3:
        progressTracking();
        break;
    case 4:
        nutritionGoal();
        break;
    case 5:
        profile();
        break;
    default:
        cout<<"Invalid choice...!";
    }
}

int main()
{
    fstream file;
    userDetail obj;
    char choice;
    cout<<"\n1. Login";
    cout<<"\n2. Sign-Up";
    cout<<"\n3. Forgot Password";
    cout<<"\n4. Exit";
    cout<<"\nEnter Your choice: ";
    cin>>choice;
    cin.ignore();

    switch (choice)
    {
    case '1':
        login(obj,file);
        break;
    case '2':
        signUp(obj,file);
        break;
    case '3':
        forgot(obj,file);
        break;
    case '4':
        return 0;
        break;
    default:
        cout<<"Invalid Choice..!";
        break;
    }
    file.close();
    return 0;
}
