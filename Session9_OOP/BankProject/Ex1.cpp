#include "Ex1.h"

/* Account class definition

*/
// Account::Account() {}

Account::Account(const string &name, float balance) :
    m_name(name),
    m_Balance{balance}
{    
    m_Accno = ++s_ANGenerator;
    cout << "Constructor of Account is called " << endl;
}

Account::~Account() {}

int Account::s_ANGenerator = 1000;

const string Account::GetName() const {
    return m_name;
}

auto Account::GetBalance() const {
    return m_Balance;
}

int Account::GetAccountNo() const {
    return m_Accno;
}

void Account::AccumulateInterest() {

}
void Account::Withdraw(float amount) {
    if (amount < m_Balance) {
        m_Balance -= amount;
    } else {
        cout << "Insufficient balance" << endl;
    }
}
void Account::Deposit(float amount) {
    m_Balance += amount;
}
float Account::GetInterestRate() const {
    return 0.0f;
}

/*  Saving class definition

*/
Saving::Saving(const string &name, float balance, float rate) :
    Account(name,balance),
    m_Rate{rate}
{
    cout << "Constructor of Saving is called " << endl;    
}

Saving::~Saving() {}

float Saving::GetInterestRate() const {
    return m_Rate;
}

void Saving::AccumulateInterest() {
    /*  This function is trying to access a member of base class
        Hence, m_Balance must be protected/public, it would fail if m_Balance is private in base class
    */
    m_Balance += (m_Balance * m_Rate);
}

/*  Checking class definition

*/
/*
Checking::Checking(const string &name, float balance) :
    Account(name, balance) {}
*/
Checking::~Checking() {

}

void Checking::Withdraw(float amount) {
    /*  In this function, a child's method is expanding its Base's method
        by calling classname::method
    */
    if ((m_Balance - amount) > 50) {
        Account::Withdraw(amount);
    } else {
        cout << "Invalid amount " << endl;
    }
}

/*

*/
void Transact(Account* pAccount) {
    cout << "Transaction started" << "\n" << flush;
    cout << "Initial balance: " << pAccount->GetBalance() << endl;
    pAccount->Deposit(100);
    pAccount->AccumulateInterest();
    pAccount->Withdraw(170);
    cout << "Interest rate: " << pAccount->GetInterestRate() << endl;
    cout << "Final balance: " << pAccount->GetBalance() << endl;
}

void test_1() {
    Account acc("Bob", 1000);
    cout << "Initial balance: " << acc.GetBalance() << endl;
    acc.Deposit(200);
    acc.Withdraw(380);
    cout << "Balance: " << acc.GetBalance() << endl;

    Saving SavingAcc("Bob", 1000, 0.1);
    cout << "Initial balance: " << SavingAcc.GetBalance() << endl;
    SavingAcc.AccumulateInterest();
    cout << "Balance: " << SavingAcc.GetBalance() << endl;

    Checking CheckingAcc("Bob", 1000);
    cout << "Initial balance: " << CheckingAcc.GetBalance() << endl;
    CheckingAcc.Withdraw(990);
    cout << "Balance: " << CheckingAcc.GetBalance() << endl;
}

int main() {
    /*  This demonstrade the use of auto
        The return type is f -> b is a float, it is deduct from it initialization
    */
    auto b = Account("",0).GetBalance();
    cout << typeid(b).name() << " = " << b << endl;
    b  *= 2;
    cout << typeid(b).name() << " = " << b << endl;

    /*
        Test hirachy classes
    */
    
    Saving acc("Bob", 100, 0.05f);
    Transact(&acc);
    return 0;
}