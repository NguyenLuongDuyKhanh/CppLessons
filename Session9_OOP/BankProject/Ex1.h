#include <iostream>
using namespace std;

class Account {
private:
    string m_name;
    
    int m_Accno{0};
    static int s_ANGenerator;
protected:
    float m_Balance{5};
public:
    // Account();
    Account(const string &name, float balance);
    ~Account();

    const string GetName() const;
    auto GetBalance() const;
    int GetAccountNo() const;

    virtual void AccumulateInterest();
    virtual void Withdraw(float amount);
    virtual void Deposit(float amount);
    virtual float GetInterestRate() const;

};

class Saving : public Account {
private:
    float m_Rate;
public:
    Saving(const string &name, float balance, float rate);
    ~Saving();

    float GetInterestRate() const;
    void AccumulateInterest();
};

class Checking : public Account {

public:
    /*  Constructor inheritance, 
        a feature of C++ 11, enable us to inherit all Base's constructors
    */
    using Account::Account;
    // Checking(const string &name, float balance);
    ~Checking();
    void Withdraw(float);

};

void Transact(Account* pAccount);