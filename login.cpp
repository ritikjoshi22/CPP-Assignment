#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

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

void signUp(userDetail &obj,fstream &file)
{
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
            cout << "\nAccount Login Successful!\n";
            cout<<"Full Name: "<<obj.fullName<<endl;
            cout<<"Age: "<<obj.age<<endl;
            cout<<"Weight: "<<obj.weight<<endl;
            cout<<"Height: "<<obj.height<<endl;
            cout << "Username: " << obj.userName << endl;
            cout << "Email: " << obj.email << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Login failed. Incorrect username or password." << endl;
    }

}


void forgot(userDetail &obj,fstream &file) {
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
