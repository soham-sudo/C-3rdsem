#include<iostream>
using namespace std;

class account{
    //private data members
    int id; //account ID
    int balance; //account balance
public:
    //default constructor
    account(int =0, int =0);
    //to get id
    int getid();
    //to get balance
    int get_balance();
    //to show id
    int showid()const;
    //to show balance
    int showbalance()const;
};

//a class for list of accounts
class accountlist{
    //max lsit of accounts
    account list[100];
    //to store no of accounts
    int count;
public:
//constructor
    accountlist(){
        count=0;
    }
    //searches account with id returns 1 true, 0 false 
    int search_account(int);
    //adds account to list and incrases count after searching
    void add_account();
    //show particular account with id, searches in list if present shows
    void show_account(int);
    //show all accounts in list 
    static void show_all_account();
    //to give access to account list, returns list pointer refernce
    accountlist*& get_accountlist();
    //to get count
    int getcount();

};

//for withdraw object
class withdraw{
    int id;
    int money;
public:
    //constructor wit parameter id , money
    withdraw(int=-1,int=0);
    //to do transaction , will check id in account list,check withdraw amt less than balance if true update balance
    void transaction(accountlist*&);
};