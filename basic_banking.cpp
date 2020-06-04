#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>

using namespace std;

class Account
{

public:
  
    Account() {}
    Account(string fname, string lname, double balance);
   
    long getAccNo() { return accNo; }
    string getname() { return name; }
    string getsurname() { return surname; }
    double getBalance() { return balance; }

    void Deposit(double amount);
    void Withdraw(double amount);
    
    static void setLastaccNo(long accNo);
    static long getLastaccNo();
    
    friend ofstream& operator<<(ofstream& ofs, Account& acc);
    friend ifstream& operator>>(ifstream& ifs, Account& acc);
    friend ostream& operator<<(ostream& os, Account& acc);

private:

    long accNo;

    string name;

    string surname;

    double balance;

    static long nAccNo;
};

long Account::nAccNo = 0;

class Bank
{

public:
    
    Bank();
    
    Account OpenAccount(string fname, string lname, double balance);
    Account BalanceEnquiry(long accNo);
    Account Deposit(long accNo, double amount);
    Account Withdraw(long accNo, double amount);
    
    void CloseAccount(long accNo);
    void ShowAllAccounts();
    
    ~Bank();

private:

    map<long, Account> accounts;
};

Account::Account(string fname, string lname, double balance)
{

    nAccNo++;

    accNo = nAccNo;

    name = fname;

    surname = lname;

    this->balance = balance;
}

void Account::Deposit(double amount)
{
    balance += amount;
}
void Account::Withdraw(double amount)
{
    if (balance - amount < 500)
        cout << "Insufficient Balance";

    else
        balance -= amount;
}
void Account::setLastaccNo(long accNo)
{
    nAccNo = accNo;
}
long Account::getLastaccNo()
{
    return nAccNo;
}
ofstream& operator<<(ofstream& ofs, Account& acc)
{
    ofs << acc.accNo << endl;
    ofs << acc.name << endl;
    ofs << acc.surname << endl;
    ofs << acc.balance << endl;

    return ofs;
}
ifstream& operator>>(ifstream& ifs, Account& acc)
{
    ifs >> acc.accNo;
    ifs >> acc.name;
    ifs >> acc.surname;
    ifs >> acc.balance;

    return ifs;

}
ostream& operator<<(ostream& os, Account& acc)
{
    os << "First Name:" << acc.getname() << endl;
    os << "Last Name:" << acc.getsurname() << endl;
    os << "Account Number:" << acc.getAccNo() << endl;
    os << "Balance:" << acc.getBalance() << endl;

    return os;
}
Bank::Bank()
{

    Account account;

    ifstream myFile;

    myFile.open("Bank.data");

    if (!myFile)
    {
        cout<<"Error!"<<endl;
        return;
    }
  
    while (!myFile.eof())
    {
        myFile >> account;
    
        accounts.insert(pair<long, Account>(account.getAccNo(), account));
    }
    
    Account::setLastaccNo(account.getAccNo());

    myFile.close();

}
Account Bank::OpenAccount(string fname, string lname, double balance)
{
    ofstream MyFile;
   
    Account account(fname, lname, balance);
   
    accounts.insert( pair<long, Account> (account.getAccNo(), account) );

    MyFile.open( "Bank.data", ios::trunc );

    map< long, Account >:: iterator temp;
 
    for (temp = accounts.begin(); temp != accounts.end(); ++ temp)
    
        MyFile << temp->second;
    
    MyFile.close();
   
    return account;
}
Account Bank::BalanceEnquiry(long accNo)
{
    map<long, Account>::iterator temp = accounts.find(accNo);
    
    return temp->second;
}
Account Bank::Deposit(long accNo, double amount)
{
    map<long, Account>::iterator temp = accounts.find(accNo);
    
    temp->second.Deposit(amount);
    
    return temp->second;
}
Account Bank::Withdraw(long accNo, double amount)
{
    map<long, Account>::iterator temp = accounts.find(accNo);
    
    temp->second.Withdraw(amount);
    
    return temp->second;
}
void Bank::CloseAccount(long accNo)
{
    map<long, Account>::iterator temp = accounts.find(accNo);
    
    cout << "Account Deleted" << temp->second;
    
    accounts.erase(accNo);
}
void Bank::ShowAllAccounts()
{
    map<long, Account>::iterator temp;
   
    for (temp = accounts.begin(); temp != accounts.end(); temp++)
    
        cout << "Account " << temp->first << endl << temp->second << endl;
    
}
Bank::~Bank()
{
    ofstream MyFile;
    
    MyFile.open("Bank.data", ios::trunc);

    map<long, Account>::iterator temp;
    
    for (temp = accounts.begin(); temp != accounts.end(); temp++)
    
        MyFile << temp->second;
    
    MyFile.close();
}

int main()
{
    Bank b;
    Account acc;

    int choice;
   
    string fname, lname;
   
    long accNo;
  
    double balance , amount;

    cout << "***Banking System***" << endl;
   
    do
    {
        cout << "\n\tSelect one option below ";
        cout << "\n\t1 Open an Account";
        cout << "\n\t2 Balance Enquiry";
        cout << "\n\t3 Deposit";
        cout << "\n\t4 Withdrawal";
        cout << "\n\t5 Close an Account";
        cout << "\n\t6 Show All Accounts";
        cout << "\n\t7 Quit";
        cout << "\nEnter your choice: ";
      
        cin >> choice;
     
        switch (choice)
        {
        case 1:
            cout << "Enter First Name: ";
            cin >> fname;
            cout << "Enter Last Name: ";
            cin >> lname;
            cout << "Enter initil Balance: ";
            cin >> balance;
            acc = b.OpenAccount(fname, lname, balance);
            cout << endl << "Congradulation Account is Created" << endl;
            cout << acc;
       
            break;
     
        
        case 2:
            cout << "Enter Account Number:";
            cin >> accNo;
            acc = b.BalanceEnquiry(accNo);
            cout << endl << "Your Account Details" << endl;
            cout << acc;
       
            break;
    
        
        case 3:
            cout << "Enter Account Number:";
            cin >> accNo;
            cout << "Enter Balance:";
            cin >> amount;
            acc = b.Deposit(accNo, amount);
            cout << endl << "Amount is Deposited" << endl;
            cout << acc;
     
            break;
    
        
        case 4:
            cout << "Enter Account Number:";
            cin >> accNo;
            cout << "Enter Balance:";
            cin >> amount;
            acc = b.Withdraw(accNo, amount);
            cout << endl << "Amount Withdrawn" << endl;
            cout << acc;
      
            break;
   
        
        case 5:
            cout << "Enter Account Number:";
            cin >> accNo;
            b.CloseAccount(accNo);
            cout << endl << "Account is Closed" << endl;
            cout << acc;
    
        
        case 6:
            b.ShowAllAccounts();
       
            break;
    
        
        case 7: break;
    
        
        default:
            cout << "\nEnter corret choice";
            exit(0);
      
        }
    } while (choice != 7);

    return 0;
}



/*

#include <iostream>
#include<fstream>
#include <string>
using namespace std;


int main(){

	string x = "";

	ofstream Myfile("eihebam.tihebt");
	Myfile << "wroclaw university ";
	Myfile.close();

	ifstream Myreadfile("exam.txt");
	while (getline(Myreadfile, x)) {
		cout << x;
	}
	Myreadfile.close();

	

	return 0;
}
*/
