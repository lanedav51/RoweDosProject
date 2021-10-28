// Content Management System
//RoweDos Software Assurance Fall 2021
// Jake Rowe, Paul Schlabach, Ethan Mann, David Lane, David Leiden

#include <iostream>
#include <string>
#include <fstream>

using namespace std;



bool login()
{
    string choice1; //holds value for users choice in register/Login/Exit
    string storedUN, storedPass; // User name and password stored in db
    string inputUN, inputPass; // User name and password user inputs
    string registerUN, registerPass; // User name and password used to register

    while (1)
    {
        cout << "Select an action" << endl << endl;
        cout << "[1]Register" << endl;
        cout << "[2]Login" << endl;
        cout << "[3]Exit" << endl << endl;
        getline(cin, choice1); //Takes users input (1,2,3) and stores in choice1

        if (choice1=="1") // if user selects 1 this will register them
        {
            ofstream UNPassDB("UNPassDB.txt"); //creates/reads from file UNPassDB.txt

            cout << endl << endl; //spacing purposes
            cout << "Create New Username" << endl;
            getline(cin, registerUN); //Stores user input in registerUN
            cout << "Create Password" << endl;
            getline(cin, registerPass); //stores user input in registerPass

            UNPassDB << registerUN; //Stores Username in DB
            UNPassDB << endl;
            UNPassDB << registerPass; //Stores Password in DB

            UNPassDB.close();// closes DB
            cout << endl; //spacing
        }

        if (choice1=="2") // if user selects 2 this will take them to login
        {
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
                cout << "Incorrect Username or Password" << endl;
                return false;
            }

        }

        if (choice1=="3") //if user selects 3 and wants to exit the program
        {
            return false;
        }

    }
    return false;
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