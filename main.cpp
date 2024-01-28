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

void activityLog(string name,string age,string weight){
    system("CLS");
    int choice;
    cout<<"Activity Log"<<endl;
    cout<<"Enter the muscle group you want to target today:"<<endl;
    cout<<"1.Chest."<<endl;
    cout<<"2.Triceps."<<endl;
    cout<<"3.Back."<<endl;
    cout<<"4.Biceps."<<endl;
    cout<<"5.Shoulders."<<endl;
    cout<<"6.Leg."<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"Chest Day:"<<endl;
            cout<<"1.Bench press 4x12"<<endl;
            cout<<"2.Incline Dumbbel press 4x12"<<endl;
            cout<<"3.Cable Pull down 4x12"<<endl;
            cout<<"4.Push-Up 4x20"<<endl;
            cout<<"5.Machine Fly 4x15"<<endl;
            cout<<"6.Dumbbell Flyes 4x15"<<endl;
            break;
        case 2:
            cout<<"Triceps Day:"<<endl;
            cout<<"1.Triceps Pulldown 4x12"<<endl;
            cout<<"2.Dips 4x15"<<endl;
            cout<<"3.Lying triceps extension 3x12"<<endl;
            cout<<"4. Overhead Triceps Extensions 3x12"<<endl;
            break;

        case 3:
            cout<<"Back Day:"<<endl;
            cout<<"1.Deadlift 4x12"<<endl;
            cout<<"2.One-arm dumbbell row 4x12"<<endl;
            cout<<"3.Seated cable rows 4x12"<<endl;
            cout<<"4.Pull-Up 3x10"<<endl;
            cout<<"5.Goodmorning 3x10"<<endl;
            cout<<"6.Lats pulldown 4x15"<<endl;
            cout<<endl;

        case 4:
            cout<<"Biceps Day:"<<endl;
            cout<<"1.Bicep curl 4x12"<<endl;
            cout<<"2.Barbell curl 4x12"<<endl;
            cout<<"3.Hammer curl 4x12"<<endl;
            cout<<"4.Concentration curls 4x12"<<endl;
            cout<<endl;
            break;

        case 5:
            cout<<"Shoulders Day:"<<endl;
            cout<<"1.Side lateral raise 4x15"<<endl;
            cout<<"2.Overhead press 4x10"<<endl;
            cout<<"3.Face Pullup 4x20"<<endl;
            cout<<"4.Smith machine overhead shoulder press 4x12"<<endl;
            cout<<endl;
            break;

        case 6:
            cout<<"Leg Day:"<<endl;
            cout<<"1.Squat 4x12"<<endl;
            cout<<"2.Split Squats 4x12"<<endl;
            cout<<"3.Goblet Squats 4x12"<<endl;
            cout<<"4.Calf Raises 4x20"<<endl;
            cout<<"5.Leg press 4x12"<<endl;
            cout<<"6.Front Squats 4x15"<<endl;
            cout<<"Outdoor running"<<endl;
            cout<<endl;
            break;

        default:
            cout<<"Invalid Choice...!"<<endl;
    }
    getch();
}

void goalSetting(string name,string age,string weight,string height){
    system("CLS");
    cout<<"Goal Setting"<<endl;
    getch();
}

void nutritionGoal(string name,string age,string weight,string height){
    system("CLS");
    cout<<"Nutrition Goal"<<endl;
    getch();
}

void profile(string name,string age,string weight,string height,string email){
    system("CLS");
    cout<<"Profile"<<endl;
    cout<<"Name="<<name<<endl;
    cout<<"Age="<<age<<endl;
    cout<<"Weight="<<weight<<endl;
    cout<<"Height="<<height<<endl;
    cout<<"Email="<<email<<endl;
    getch();
}

void welcomepage(string name,string age,string weight,string height,string email){
    while (1)
    {
        system("CLS");
    int choice;
    cout<<"Welcome to Fitness Tracker\n";
    cout<<"1.Activity Log"<<endl;
    cout<<"2.Goal setting"<<endl;
    cout<<"3.Nutrition goal"<<endl;
    cout<<"4.Profile"<<endl;
    cout<<"5.Exit."<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        activityLog(name,age,weight);
        break;
    case 2:
        goalSetting(name,age,weight,height);
        break;
    case 3:
        nutritionGoal(name,age,weight,height);
        break;
    case 4:
        profile(name,age,weight,height,email);
        break;
    case 5:
        return;
    default:
        cout<<"Invalid choice...!";
    }
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
            welcomepage(obj.fullName,obj.age,obj.weight,obj.height,obj.email);
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
