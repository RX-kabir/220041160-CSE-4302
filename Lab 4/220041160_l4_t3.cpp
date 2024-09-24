#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    static inline int totalAccounts = 0;
    static inline int activeAccounts = 0;
    static inline float totalTax = 0;

    int accNumber;
    string accName;
    string accType;
    float currBalance;
    float minBalance;

public:
    BankAccount(int accNo, const string& name, const string& type, float initialBalance, float minimumBalance)
        : accNumber(accNo), accName(name), accType(type), currBalance(initialBalance), minBalance(minimumBalance) {
        totalAccounts++;
        activeAccounts++;
    }

    ~BankAccount() {
        activeAccounts--;
        cout << "Account of " << accName << " with account no " << accNumber
             << " is destroyed with a balance BDT " << currBalance << endl;
    }

    void showInfo() const {
        cout << "Account Number: " << accNumber << endl;
        cout << "Account Holder Name: " << accName << endl;
        cout << "Account Type: " << accType << endl;
        cout << "Current Balance: BDT " << currBalance << endl;
        cout << "Minimum Balance: BDT " << minBalance << endl;
    }

    void showBalance() const {
        cout << "Current Balance: BDT " << currBalance << endl;
    }

    void deposit(float amount) {
        if (amount > 0) {
            currBalance += amount;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdrawal(float amount) {
        if (amount > 0 && (currBalance - amount) >= minBalance) {
            currBalance -= amount;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    void giveInterest() {
        float interest = (currBalance * 3 / 100);
        float tax = interest * 0.1;
        interest -= tax;

        currBalance += interest;
        totalTax += tax;
    }

    float getBalance() const {
        return currBalance;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    static int getActiveAccounts() {
        return activeAccounts;
    }

    static float getTotalTaxCollected() {
        return totalTax;
    }
};


const BankAccount& LargerAccount(const BankAccount& A, const BankAccount& B) {
    return (A.getBalance() > B.getBalance()) ? A : B;
}

void displayAccountStatistics() {
    cout << "Total Bank Accounts Created: " << BankAccount::getTotalAccounts() << endl;
    cout << "Active Bank Accounts: " << BankAccount::getActiveAccounts() << endl;
    cout << "Total Source Tax Collected: BDT " << BankAccount::getTotalTaxCollected() << endl;
}

int main() {
    BankAccount account1(1, "John", "savings", 5000, 1000);
    BankAccount account2(2, "Jane", "current", 3000, 500);
    BankAccount account3(3, "Adnan", "current", 400000, 5000);

    const BankAccount& largerAccount = LargerAccount(account1, account2);
    cout << "Account with the larger balance is: " << endl;
    largerAccount.showInfo();

    account1.deposit(2000);
    account1.withdrawal(1000);
    account1.giveInterest();
    account1.showBalance();

    account3.showInfo();

    displayAccountStatistics();

    return 0;
}

