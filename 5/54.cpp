#include <iostream>
#include <string>

using namespace std;

class Cricketer {
private:
    string name;
    string dateOfBirth;
    int matchesPlayed;

public:
    // Default constructor
    Cricketer() : name(""), dateOfBirth(""), matchesPlayed(0) {}

    // Parameterized constructor
    Cricketer(const string& _name, const string& _dateOfBirth, int _matchesPlayed)
        : name(_name), dateOfBirth(_dateOfBirth), matchesPlayed(_matchesPlayed) {}

    // Function to take input for cricketer details
    void input() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Date of Birth: ";
        cin >> dateOfBirth;
        cout << "Enter Matches Played: ";
        cin >> matchesPlayed;
    }

    // Function to display cricketer details
    void display() {
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Matches Played: " << matchesPlayed << endl;
    }
};

class Bowler : public virtual Cricketer {
protected:
    int wicketsTaken;
    double averageEconomy;

public:
    Bowler() : Cricketer() {}

    Bowler(const string& _name, const string& _dateOfBirth, int _matchesPlayed, int _wicketsTaken, double _averageEconomy)
        : Cricketer(_name, _dateOfBirth, _matchesPlayed), wicketsTaken(_wicketsTaken), averageEconomy(_averageEconomy) {}

    void takeInput() {
        Cricketer::input();
        cout << "Enter Wickets Taken: ";
        cin >> wicketsTaken;
        cout << "Enter Average Economy: ";
        cin >> averageEconomy;
    }

    void display(){
        Cricketer::display();
        cout << "Wickets Taken: " << wicketsTaken << endl;
        cout << "Average Economy: " << averageEconomy << endl;
    }
};

class Batsman : public virtual Cricketer {
protected:
    int totalRunsScored;
    double averageScore;

public:
    Batsman() : totalRunsScored(0), averageScore(0.0) {}

    Batsman(const string& _name, const string& _dateOfBirth, int _matchesPlayed, int _totalRunsScored, double _averageScore)
        : Cricketer(_name, _dateOfBirth, _matchesPlayed), totalRunsScored(_totalRunsScored), averageScore(_averageScore) {}

    void takeInput() {
        Cricketer::input();
        cout << "Enter Total Runs Scored: ";
        cin >> totalRunsScored;
        cout << "Enter Average Score: ";
        cin >> averageScore;
    }

    void display() {
        Cricketer::display();
        cout << "Total Runs Scored: " << totalRunsScored << endl;
        cout << "Average Score: " << averageScore << endl;
    }
};
class Allrounder : public Batsman , public Bowler
{
   
    public:
    Allrounder():Bowler(),Batsman(){}
    void takeInput()
    {
        Cricketer::input();
        cin>>wicketsTaken;
        cin>>averageEconomy;
        cin >> totalRunsScored;
        cin >> averageScore;
    }
    void display()
    {
        Cricketer::display();
        cout<<wicketsTaken<<endl;
        cout<<averageEconomy<<endl;
        cout<<totalRunsScored<<endl;
        cout<<averageScore<<endl;
    }
    
    



};
class pair
{
    private:
    Bowler* bowler;
    Batsman* batsman;
    public:
    pair()
    {

    }
    void input()
    {
        bowler->takeInput();
        batsman->takeInput();
    }
    void display()
    {
        bowler->display();
        batsman->display();
    }

};
int main() {
    // Example usage:
    Cricketer* cricketer;

    // Create a Bowler
    Bowler bowler;
    Allrounder al;
    al.takeInput();
    al.display();

    return 0;
}