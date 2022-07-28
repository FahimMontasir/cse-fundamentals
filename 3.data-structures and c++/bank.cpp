//bank management demo using OOP
#include<bits/stdc++.h>
using namespace std;

class BankAccount {
public:
    string account_holder;
    string address;
    int age;
    int account_number;
protected:
    int balance;
private:
    string password;
public:
    BankAccount(string account_holder, string address, int age, string password){
        this->account_holder = account_holder;
        this->address = address;
        this->age = age;
        this->password = password;
        this->account_number = rand()%1000000000;
        this->balance = 0;
        cout<<"your account no is "<<this->account_number<<endl;
    }

    int show_balance(string password){
        if(this->password == password){
            return this-> balance;
        }
        else{
            return -1;
        }
    }

    void add_money(string password, int amount){
        if(this->password == password){
            this->balance +=amount;
            cout<<"Add money successful"<<endl;
        }else{
            cout<<"password did not match"<<endl;
        }
    }

    void deposite_money(string password, int amount){
        if(this->password == password){
            this->balance -=amount;
            cout<<"Deposite money successful"<<endl;
        }else{
            cout<<"password did not match"<<endl;
        }
    }
    friend class MyCash;
};

class MyCash{
protected:
    int balance;
public:
    MyCash(){
        this->balance=0;
    }

    void add_money_form_bank(BankAccount *myAccount, string password, int amount){
        if(myAccount->password == password){
            this->balance += amount;
            myAccount->balance -= amount;
            cout<<"Add money from bank is successful"<<endl;
        }else{
            cout<<"Password is wrong"<<endl;
        }
    }

    int show_balance(){
        return balance;
    }
};

BankAccount* create_account(){
    string account_holder, address, password;
    int age;

    cout<<"Create Account"<<endl;
    cin>>account_holder>>address>>age>>password;

    BankAccount *my_account = new BankAccount(account_holder, address, age, password);

    return my_account;
}

void add_money(BankAccount *myAccount){
    string passowrd;
    int amount;
    cout<<"add money"<<endl;
    cin>>passowrd>>amount;

    myAccount->add_money(passowrd, amount);

    cout<<"Your balance is "<< myAccount->show_balance("abc")<<endl;
}

void deposite_money(BankAccount *myAccount){
    string passowrd;
    int amount;
    cout<<"deposite money"<<endl;
    cin>>passowrd>>amount;

    myAccount->deposite_money(passowrd, amount);

    cout<<"Your balance is "<< myAccount->show_balance("abc")<<endl;
}

void add_money_from_bank(MyCash *myCash, BankAccount *myAccount){
    string passowrd;
    int amount;
    cout<<"Add money from bank"<<endl;
    cin>>passowrd>>amount;

    myCash->add_money_form_bank(myAccount,passowrd, amount);
    cout<<"Your balance is "<< myAccount->show_balance("abc")<<endl;
    cout<<"MyCash balance "<<myCash->show_balance()<<endl;
}

int main(){
    BankAccount *myAccount = create_account();

    add_money(myAccount);

    deposite_money(myAccount);

    MyCash *myCash = new MyCash();
    add_money_from_bank(myCash, myAccount);
    return 0;
}

