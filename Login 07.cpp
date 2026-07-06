#include <iostream>

#include <fstream>

#include <string>

#include <ctime>

using namespace std;

bool checkIfUserNameExists(string username)

{

ifstream file("users.txt");

string user, pass;

while (file >> user >> pass)

{

if (user == username)

{

file.close();

return true;

}

}

file.close();

return false;

}

 void registerNewUser()

{

string username, password;

cout << "\nEnter username: ";

cin >> username;

if (checkIfUserNameExists(username))

{

cout << "This username is already taken!\n";

return;

}

cout << "Enter password: ";

cin >> password;

ofstream file("users.txt", ios::app);

file << username << " " << password << endl;

file.close();

cout << "You have been registered successfully!\n";

}

void loginExistingUser()

{

string username, password;

string user, pass;

int attempts = 0;

time_t locktime= 0;

while (attempts < 3)

{

cout << "\nEnter your username: ";

cin >> username;

cout << "Enter your password: ";

cin >> password;

ifstream file("users.txt");

bool found = false;

while (file >> user >> pass)

{

if (user == username && pass == password)

{

found = true;

break;

}

}

file.close();

if (found)

{

cout << "You have logged in successfully!\n";

return;

}

else

{

attempts++;

cout << "Your username or password is incorrect.\n";

cout << "You have " << 3 - attempts << " attempts left.\n";

}

}

cout << "\nYour account has been locked for 30 seconds...\n";

locktime = time(0);

while (time(0)- locktime < 30)

{

}

cout << "You can try logging in again now.\n";

}

int main()

{

int choice;

do

{

cout << "\n===== MENU =====\n";

cout << "1. Register\n";

cout << "2. Login\n";

cout << "3. Exit\n";

cout << "Enter your choice: ";

cin >> choice;

if (choice == 1)

{

registerNewUser();

}

else if (choice == 2)

{

loginExistingUser();

}

else if (choice == 3)

{

cout << "Goodbye!\n";

}
  else 
{

 { cout << "That's not a valid choice!\n"; }

}

} while (choice != 3);

return 0;

}
