#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<conio.h>

using namespace std;


class userDetail;

class userManager
{
    public:
    friend void login(userDetail &obj,fstream &file);
    friend void signUp(userDetail &obj,fstream &file);
    friend void forgot(userDetail &obj,fstream &file);
};

class userDetail{
    string fullName;
    string age;
    string weight;
    string height;
    string userName;
    string email;
    string password;
    string searchName;
    string searchEmail;
    string searchPass;

    public:
    userDetail(){}

    friend void login(userDetail &obj,fstream &file);
    friend void signUp(userDetail &obj, fstream &file);
    friend void forgot(userDetail &obj,fstream &file);
};

void activityLog(string name,string age,string weight,string height){
    system("CLS");
    cout<<"Activity Log"<<endl;
    getch();
}

void goalSetting(string name,string age,string weight,string height){
    system("CLS");
    cout<<"Goal Setting"<<endl;
    getch();
}

void progressTracking(string name,string age,string weight,string height){
    system("CLS");
    cout<<"Progress Tracking"<<endl;
    getch();
}

void nutritionGoal(string name,string age,string weight,string height){
    system("CLS");
    cout<<"Nutrition Goal"<<endl;
    getch();
}

void profile(string name,string age,string weight,string height){
    system("CLS");
    cout<<"Profile"<<endl;
    getch();
}

void welcomepage(string name,string age,string weight,string height){
    system("CLS");
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
        activityLog(name,age,weight,height);
        break;
    case 2:
        goalSetting(name,age,weight,height);
        break;
    case 3:
        progressTracking(name,age,weight,height);
        break;
    case 4:
        nutritionGoal(name,age,weight,height);
        break;
    case 5:
        profile(name,age,weight,height);
        break;
    default:
        cout<<"Invalid choice...!";
    }
}

void signUp(userDetail &obj,fstream &file)
{
    system("CLS");
    cout<<"Enter your Full Name:\n";
    getline(cin,obj.fullName);
    cout<<"Enter your age:\n";
    cin>>obj.age;
    cout<<"Enter your weight in KG:\n";
    cin>>obj.weight;
    cout<<"Enter your height in cm:\n";
    cin>>obj.height;
    cout<<"\nUserName:\n";
    cin.ignore();
    getline(cin, obj.userName);
    cout<<"Password:\n";
    getline(cin, obj.password);
    cout<<"\nEmail:\n";
    getline(cin, obj.email);

    file.open("loginData.txt",ios::out | ios::app);
    if(!file.is_open()){
        cerr<<"Error opening file 'loginData.txt'\n";
        return;
    }
    file << obj.fullName << "*" << obj.age << "*" << obj.weight << "*" << obj.height << "*" << obj.userName << "*" << obj.email << "*" << obj.password << endl;
}

void login(userDetail &obj,fstream &file) {
    system("CLS");
    cout << "--------Login--------" << endl;
    cout << "\nUserName: ";
    getline(cin, obj.searchName);
    cout << "Password: ";
    getline(cin, obj.searchPass);

    file.open("loginData.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file 'loginData.txt'\n";
        return;
    }

    bool found = false;

    while (getline(file, obj.fullName, '*') && getline(file, obj.age, '*') && getline(file, obj.weight, '*') && getline(file, obj.height, '*') && getline(file, obj.userName, '*') && getline(file, obj.email, '*') && getline(file, obj.password, '\n')) {
        if (obj.userName == obj.searchName && obj.password == obj.searchPass) {
            welcomepage(obj.fullName,obj.age,obj.weight,obj.height);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Login failed. Incorrect username or password." << endl;
    }

}


void forgot(userDetail &obj,fstream &file) {
    system("CLS");
    cout << "\nUserName: ";
    getline(cin, obj.searchName);
    cout << "\nEmail: ";
    getline(cin, obj.searchEmail);

    file.open("loginData.txt", ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file 'loginData.txt'\n";
        return;
    }

    bool found = false;

           while (getline(file, obj.fullName, '*') && getline(file, obj.age, '*') && getline(file, obj.weight, '*') && getline(file, obj.height, '*') && getline(file, obj.userName, '*') && getline(file, obj.email, '*') && getline(file, obj.password, '\n'))  {
        if (obj.userName == obj.searchName && obj.email == obj.searchEmail) {
            cout << "\nAccount Found!";
            cout << "Password: " << obj.password << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Account not found or incorrect combination of username and email." << endl;
    }

}

int main()
{

    fstream file;
    userDetail obj;
    char choice;
    while(1){
    system("CLS");
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
    }
    return 0;
}
