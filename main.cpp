#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<conio.h>
#include <sstream>

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
    streampos filePosition;

    public:
    userDetail(){}

    friend void login(userDetail &obj,fstream &file);
    friend void signUp(userDetail &obj, fstream &file);
    friend void forgot(userDetail &obj,fstream &file);
    friend void activityLog(userDetail &obj,fstream &file);
    friend void goalSetting(userDetail &obj,fstream &file);
    friend void progressTracking(userDetail &obj,fstream &file);
    friend void profile(userDetail &obj,fstream &file);
};


void activityLog(userDetail &obj,fstream &file){
    int choice;
    while (1)
    {
    system("CLS");
    cout<<"Activity Log"<<endl;
    cout<<"Enter the muscle group you want to target today:"<<endl;
    cout<<"1.Chest."<<endl;
    cout<<"2.Triceps."<<endl;
    cout<<"3.Back."<<endl;
    cout<<"4.Biceps."<<endl;
    cout<<"5.Shoulders."<<endl;
    cout<<"6.Leg."<<endl;
    cout<<"7.Home Page"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            system("CLS");
            cout<<"Chest Day:"<<endl;
            cout<<"1.Bench press 4x12"<<endl;
            cout<<"2.Incline Dumbbel press 4x12"<<endl;
            cout<<"3.Cable Pull down 4x12"<<endl;
            cout<<"4.Push-Up 4x20"<<endl;
            cout<<"5.Machine Fly 4x15"<<endl;
            cout<<"6.Dumbbell Flyes 4x15"<<endl;
            getch();
            break;
        case 2:
            system("CLS");
            cout<<"Triceps Day:"<<endl;
            cout<<"1.Triceps Pulldown 4x12"<<endl;
            cout<<"2.Dips 4x15"<<endl;
            cout<<"3.Lying triceps extension 3x12"<<endl;
            cout<<"4. Overhead Triceps Extensions 3x12"<<endl;
            getch();
            break;

        case 3:
            system("CLS");
            cout<<"Back Day:"<<endl;
            cout<<"1.Deadlift 4x12"<<endl;
            cout<<"2.One-arm dumbbell row 4x12"<<endl;
            cout<<"3.Seated cable rows 4x12"<<endl;
            cout<<"4.Pull-Up 3x10"<<endl;
            cout<<"5.Goodmorning 3x10"<<endl;
            cout<<"6.Lats pulldown 4x15"<<endl;
            cout<<endl;
            getch();
            break;

        case 4:
            system("CLS");
            cout<<"Biceps Day:"<<endl;
            cout<<"1.Bicep curl 4x12"<<endl;
            cout<<"2.Barbell curl 4x12"<<endl;
            cout<<"3.Hammer curl 4x12"<<endl;
            cout<<"4.Concentration curls 4x12"<<endl;
            cout<<endl;
            getch();
            break;

        case 5:
            system("CLS");
            cout<<"Shoulders Day:"<<endl;
            cout<<"1.Side lateral raise 4x15"<<endl;
            cout<<"2.Overhead press 4x10"<<endl;
            cout<<"3.Face Pullup 4x20"<<endl;
            cout<<"4.Smith machine overhead shoulder press 4x12"<<endl;
            cout<<endl;
            getch();
            break;

        case 6:
            system("CLS");
            cout<<"Leg Day:"<<endl;
            cout<<"1.Squat 4x12"<<endl;
            cout<<"2.Split Squats 4x12"<<endl;
            cout<<"3.Goblet Squats 4x12"<<endl;
            cout<<"4.Calf Raises 4x20"<<endl;
            cout<<"5.Leg press 4x12"<<endl;
            cout<<"6.Front Squats 4x15"<<endl;
            cout<<"Outdoor running"<<endl;
            cout<<endl;
            getch();
            break;
        
        case 7:
            return;

        default:
            cout<<"Invalid Choice...!"<<endl;
    }
    }
    getch();
}

void goalSetting(userDetail &obj,fstream &file){
    system("CLS");
    string goalWeight,time;
    double bmr;
    int choice;
    bmr=447.593+(9.247*stoi(obj.weight))+(3.098*stoi(obj.height))-(4.330*stoi(obj.age));
    cout<<"Goal Setting"<<endl;
    cout<<"1.Sedentary (little or no exercise)"<<endl;
    cout<<"2.Lightly active (light exercise/sports 1-3 days/week)"<<endl;
    cout<<"3.Moderately active (moderate exercise/sports 3-5 days/week)"<<endl;
    cout<<"4.Very active (hard exercise/sports 6-7 days a week)"<<endl;
    cout<<"5.Extremely active (very hard exercise/sports & physical job or 2x training)"<<endl;
    cin>>choice;
    if(choice==1){
        bmr*=1.2;
    }
    else if (choice==2)
    {
        bmr*=1.375;
    }
    else if(choice==3)
    {
        bmr*=1.55;
    }
    else if(choice==4){
        bmr*=1.725;
    }
    else if(choice==5){
        bmr*=1.9;
    }
    else{
        cout<<"Invalid choice...!"<<endl;
    }

    cout<<"Calorie intake chart"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+   Maintain Weight +"<<"         "<<bmr<<"         +"<<endl;
    cout<<"+                   +"<<"       Calories/day      +"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+ Mild Weight Loss  +"<<"         "<<bmr-300<<"         +"<<endl;
    cout<<"+     0.25kg/week   +"<<"       Calories/day      +"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+    Weight Loss    +"<<"         "<<bmr-500<<"         +"<<endl;
    cout<<"+     0.5kg/week    +"<<"       Calories/day      +"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+Extreme weight Loss+"<<"         "<<bmr-1000<<"         +"<<endl;
    cout<<"+      1kg/week     +"<<"       Calories/day      +"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+  Mild weight gain +"<<"         "<<bmr+250<<"         +"<<endl;
    cout<<"+     0.25kg/week   +"<<"       Calories/day      +"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+    Weight Gain    +"<<"         "<<bmr+500<<"         +"<<endl;
    cout<<"+     0.5kg/week    +"<<"       Calories/day      +"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"+  Fast weight gain +"<<"         "<<bmr+1000<<"         +"<<endl;
    cout<<"+      1kg/week     +"<<"       Calories/day      +"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    getch();
}

void progressTracking(userDetail &obj,fstream &file){
    system("CLS");
    int choice,weight;
    cout<<"Progress Tracking"<<endl;
    cout<<"!.Weight gain"<<endl;
    cout<<"2.Weight Loss"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter the gain weight in kg:"<<endl;
        cin>>weight;
         try {
        int intValue = stoi(obj.weight);

        intValue += weight;

        stringstream ss;
        ss << intValue;
        obj.weight = ss.str();

        file.seekp(obj.filePosition); 
        file << obj.weight;


        cout << "Weight after adding gain: " << obj.weight << endl;
        } 
        catch (const invalid_argument& e) {
       cerr << "Invalid argument: " << e.what() << std::endl;
        } 
        catch (const out_of_range& e) {
       cerr << "Out of range: " << e.what() << std::endl;
        }
        break;
        case 2:
        cout<<"Enter the loss weight in kg:"<<endl;
        cin>>weight;
         try {
        int intValue = stoi(obj.weight);

        intValue -= weight;

        stringstream ss;
        ss << intValue;
        obj.weight = ss.str();


        cout << "Weight after adding gain: " << obj.weight << endl;
        } catch (const invalid_argument& e) {
       cerr << "Invalid argument: " << e.what() << std::endl;
        } catch (const out_of_range& e) {
       cerr << "Out of range: " << e.what() << std::endl;
        }
        break;
        default:
        cout<<"Invalid choice...!"<<endl;
    }
    getch();
}

void profile(userDetail &obj,fstream &file){
    system("CLS");
    cout<<"Profile"<<endl;
    cout<<"Name="<<obj.fullName<<endl;
    cout<<"Age="<<obj.age<<endl;
    cout<<"Weight="<<obj.weight<<endl;
    cout<<"Height="<<obj.height<<endl;
    cout<<"Email="<<obj.email<<endl;
    getch();
}

void welcomepage(userDetail &obj,fstream &file){
    while (1)
    {
        system("CLS");
    int choice;
    cout<<"Welcome to Fitness Tracker\n";
    cout<<"1.Activity Log"<<endl;
    cout<<"2.Goal setting"<<endl;
    cout<<"3.Progress Tracking."<<endl;
    cout<<"4.Profile"<<endl;
    cout<<"5.Exit."<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        activityLog(obj,file);
        break;
    case 2:
        goalSetting(obj,file);
        break;
    case 3:
        progressTracking(obj,file);
        break;
    case 4:
        profile(obj,file);
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
            welcomepage(obj,file);
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
