// Content Management System
//RoweDos Software Assurance Fall 2021
// Jake Rowe, Paul Schlabach, Ethan Mann, David Lane, David Leiden

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;



string login()
{
    string choice1; //holds value for users choice in register/Login/Exit
    string username;

    while (1)
    {
        cout << "Select an action" << endl << endl;
        cout << "[1]Register" << endl;
        cout << "[2]Login" << endl;
        cout << "[3]Exit" << endl << endl;
        getline(cin, choice1); //Takes users input (1,2,3) and stores in choice1

        if (choice1=="1") // if user selects 1 this will register them
        {
            registerUser();
        }

        if (choice1=="2") // if user selects 2 this will take them to login
        {
            username = loginAtt();
            return username;
        }

        if (choice1=="3") //if user selects 3 and wants to exit the program
        {
            break;
        }

    }
    return "false";
}

bool registerUser()
{
    string registerUN, registerPass; // User name and password used to register

    ofstream UNPassDB("UNPassDB.txt"); //creates/reads from file UNPassDB.txt

    cout << endl << endl; //spacing purposes
    cout << "Create New Username" << endl;
    getline(cin, registerUN); //Stores user input in registerUN
    cout << "Create Password" << endl;
    getline(cin, registerPass); //stores user input in registerPass

    UNPassDB << registerUN; //Stores Username in DB !!! CHECK IF USER EXISTS !!!
    UNPassDB << endl;
    UNPassDB << registerPass; //Stores Password in DB !!! CHECK COMPLEXITY OF PASSWORD !!! REGEX

    UNPassDB.close();// closes DB
    cout << endl; //spacing

    return true;
}

string loginAtt()
{
    string storedUN, storedPass; // User name and password stored in db
    string inputUN, inputPass;

            ifstream UNPassDB("UNPassDB.txt"); //reads from DB file

            getline(UNPassDB, storedUN, '\n'); //grabs stored user name
            getline(UNPassDB, storedPass, '\n'); //grabs stored password
            UNPassDB.close(); // closes DB file

            while (1)
            {
                cout << "Enter Username: " << endl;
                getline(cin, inputUN); //takes user input and stores in inputUN
                cout << "Enter Password: " << endl;
                getline(cin, inputPass); // takes user input and stores in inputPass

                if (inputUN==storedUN && inputPass==storedPass) //checks if given username and password match the ones in the DB
                {
                    cout << "Login Succesful!" << endl << endl;
                    return true;
                }
                cout << "Incorrect Username or Password" << endl; //CHECK WHICH IS WRONG FOR FUTURE ITERATIONS
            }
            return inputUN;
}

bool contentSys(int UID, string user) //FILE TRANSFER PROTOCOLS NEEDED FROM USER TO DB
{
    //FOR THIS UID CHECK DB FOR GROUP
    char userGroup = 'u'; //place holder for user rn
    int choice = 0;
    bool loop = false;

    if(userGroup == 'a')
    {
        //admin options
        cout << "Welcome " + user + ", you are a standard user.\n What would you like to do?\n (1) Add Content\n(2) Delete Content\n"+
        "(3) Modify Content\n(4) List Content\n (5) Edit Permissions" << endl;
        do{
        cin >> choice;
        switch(choice)
       {
           case 1: 
            //add
            break;;
           case 2:
            //delete
            break;;
           case 3:
            //mod
            break;;
           case 4:
            //list
            break;;
           case 5:
               editPermissions();
           default:
            cout << "Please choose using numbers 1-4" << endl;
            loop = true;
            }
        }while(loop == true);
    }   
    else if(userGroup = 'u')
    {
        //user options
        cout << "Welcome " + user + ", you are a standard user.\n What would you like to do?\n (1) Add Content\n(2) Delete Content\n(3) Modify Content\n(4) List Content" << endl;
        do{
        cin >> choice;
       
       switch(choice)
       {
           case 1: 
            //add
            break;;
           case 2:
            //delete
            break;;
           case 3:
            //mod
            break;;
           case 4:
            //list
            break;;
           default:
            cout << "Please choose using numbers 1-4" << endl;
            loop = true;
            }
        }while(loop == true);
    }
    else
    {
        cout << "userGroup not found?" << endl;
        exit(EXIT_FAILURE); //exits on issue
    }
}

bool addContent(int UID)
{
    //allow user to add file
}

bool deleteContent(int UID)
{
    //allow user to delete file based off name
}

bool modifyContent(int UID)
{
    //cross ref UID with content DB
    //allow user to choose a file based on name
    //give user ability to override with new file (add and delete) or change name
}

bool listContent(int UID)
{
    //cross ref UID with content DB
    //List out content that the DB has linked

}

bool editPermissions()
{
    string userToEdit;
    cout << "Select a user to edit permissions for by entering username, or type add/remove to modify list of current users:" << endl;
    cin >> userToEdit; //Choose username
    string permissionLevel;
    if (userToEdit == "add") {
        string pass1;
        string pass2;
        cout << "Enter username of user to be added: ";
        cin >> userToEdit;
        //add user to list of users
        cout << "Enter password for that user: ";
        cin >> pass1;
        cout << "Re-enter password: ";
        cin >> pass2;
        if (pass1 == pass2) { //check if passwords match
            //add password to file matching to username^
            cout << "Enter permission level for new user\n(1) User\n(2) Admin\n";
            int level;
            cin >> level;
            bool loop;
            loop = true;
            switch (level)
            {
            case 1:
                //add user
                break;;
            case 2:
                //add admin
                break;;
            default:
                cout << "Please enter only 1 or 2" << endl;
                break;;
                loop = true;
            }while (loop == true);
        }
        else {
            cout << "Passwords did not match!\n";
        }
    }
    else if (userToEdit == "remove") {

    }
    else {
        //userToEdit.getPermissionLevel(); //need to add get and set for modifying user info
        cout << "These are the current permissions for this user: " << permissionLevel;
        //Choose options with user (list content, delete content, add to user, etc)
        cout << "What would you like to modify?\n(1) Output user info\n (2) Add permissions\n (3) Remove permissions\n";
    }
    //Delete users, add new user manually (register)
    
    //Remove content owners, add content owners, etc
}

int main()
{
    string user = login();
    int UID;
    //link username with a UID

    //content management
    contentSys(UID, user);

    

}

int main()
{
    bool auth = login();

    while(auth == false) //loops login until user chooses to stop
    {
        auth = login();
    }

    //Welcome user and begin options (create new function)

    //

}