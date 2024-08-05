#include<iostream>
using namespace std;

//class design using friend
class accountlist; //a class for list of accounts
class withdraw;

class account{
    //private data members
    int id; //account ID
    int balance; //account balance

    public:
    //public member functions
    
    //default constructor
    account(int i=0, int b=0);
    friend class accountlist; //since accountlist will store account details
    friend class withdraw; //since account details is required for withdrawal
};

class accountlist{
    //private data members
    int max; //maximum number accounts this accountlist can hold
    account** list; //list of account pointers (so that any operation on the account will reflect on the original account object)
    int count; //how many accounts registered in the accountlist

    public:
    //public member functions
    //constrcutor
    accountlist(int x){
        max=x;
        list=new account*[x];
        count=0;
    }

    //registering an account in the accountlist
    int add(account* a);

    //searching for an account
    int search(int id);

    //show all accounts registered
    static void showAll();
    friend class withdraw; //since withdraw class will check withdraw money from a specific account of the accountlist
};

class withdraw{
    //private member functions
    int id; //account ID from which money will be withdrawn
    int money; //amount of money to be withdrawn
 
    public:
    //public member functions
    //constrcutor 
    withdraw(int i, int m){
        id=i;
        money=m;
    }

    //function to withdraw money
    void transaction(accountlist b);
};

