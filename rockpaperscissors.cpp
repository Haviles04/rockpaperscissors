#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int getComputerChoice();
int getUserChoice();
void getWinner(int comp, int user);
string choiceToString(int choice);

int main() 
{
    // Seed the random number generator
    srand(time(0));

    int comp_choice = getComputerChoice();
    int user_choice = getUserChoice();

    cout << "Computer choice: " << choiceToString(comp_choice) << endl;
    cout << "User choice: " << choiceToString(user_choice) << endl;

    getWinner(comp_choice, user_choice);
    return 0;
}

int getComputerChoice() {
    int random_num = rand() % 3;
  
    return random_num;
}

int getUserChoice() 
{
    string userInput;
    int userChoice;
    cout << "Enter your choice (rock, paper, or scissors): ";
    cin >> userInput;

    if(userInput == "rock"){
        userChoice = 0;
    }else if (userInput == "paper"){
        userChoice = 1;
    }else if (userInput == "scissors"){
        userChoice = 2;
    }else{
        cout << "Invalid Choice, please choose again." << endl;
        return getUserChoice();
    }

    return userChoice;
}

void getWinner(int comp, int user)
{
    if (comp == user) {
        cout << "It's a tie!" << endl;
        return;
    }
    else if ((user == 0 && comp == 2) ||
             (user == 1 && comp == 0) ||
             (user == 2 && comp == 1))
    {
        cout << "You win!" << endl;
        return;
    }
    else
    {
        cout << "Computer wins!" << endl;
        return;
    }
}

string choiceToString(int choice) {
    switch (choice) {
        case 0: return "rock";
        case 1: return "paper";
        case 2: return "scissors";
        default: return "invalid";
    }
}