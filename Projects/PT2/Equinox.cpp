/**
 * 🏦 EQUINOX BANKING SYSTEM
 * Course: Programming Technique II (SECJ1023)
 * Section: 02
 * Authors: CHEW CHIU XIAN (A23CS0061), LAU YAN KAI, LEE YIN SHENG
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Struct to store historical transaction logs
struct Transaction {
    string timestamp;
    string type;
    string originAcc;
    string destinationAcc;
    double amount;
};

// Base User Class demonstrating private encapsulation and data access controls
class User {
protected:
    string accountNumber;
    string pin;
    string name;

public:
    User(string accNum, string userPin, string userName) 
        : accountNumber(accNum), pin(userPin), name(userName) {}
    
    virtual ~User() {}

    bool verifyCredentials(string accNum, string enteredPin) const {
        return (accountNumber == accNum && pin == enteredPin);
    }

    string getAccountNumber() const { return accountNumber; }
    string getName() const { return name; }
};

// Customer Class handling internal account modifications and credit statuses
class Customer : public User {
private:
    double balance;
    double creditLimit;
    bool cardActive;

public:
    Customer(string accNum, string userPin, string userName, double initialBalance)
        : User(accNum, userPin, userName), balance(initialBalance), creditLimit(5000.0), cardActive(true) {}

    double getBalance() const { return balance; }
    double getCreditLimit() const { return creditLimit; }
    bool isCardActive() const { return cardActive; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "💵 Successfully deposited RM " << fixed << setprecision(2) << amount << "\n";
        } else {
            cout << "❌ Invalid deposit amount.\n";
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "💸 Successfully withdrew RM " << fixed << setprecision(2) << amount << "\n";
            return true;
        } else {
            cout << "❌ Transaction Failed: Insufficient funds or invalid amount.\n";
            return false;
        }
    }

    bool payBill(string serviceProvider, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "🧾 Payment of RM " << fixed << setprecision(2) << amount << " to " << serviceProvider << " successful.\n";
            return true;
        } else {
            cout << "❌ Bill payment failed: Insufficient funds.\n";
            return false;
        }
    }

    void modifyCreditSettings(double newLimit, bool activateCard) {
        creditLimit = newLimit;
        cardActive = activateCard;
        cout << "🔒 Credit configurations updated successfully.\n";
    }
};

// Administrator Class implementing full audit loop visibility
class Administrator : public User {
public:
    Administrator(string accNum, string userPin, string userName)
        : User(accNum, userPin, userName) {}

    void displayCustomerRegistry(const vector<Customer>& registry) const {
        cout << "\n==================================== CUSTOMER USER REGISTRY ====================================\n";
        cout << left << setw(15) << "Account No" << setw(25) << "Name" << setw(18) << "Balance (RM)" << setw(18) << "Credit Limit" << setw(12) << "Card Status" << "\n";
        cout << "------------------------------------------------------------------------------------------------\n";
        for (const auto& customer : registry) {
            cout << left << setw(15) << customer.getAccountNumber()
                 << setw(25) << customer.getName()
                 << "RM " << setw(15) << fixed << setprecision(2) << customer.getBalance()
                 << "RM " << setw(15) << customer.getCreditLimit()
                 << setw(12) << (customer.isCardActive() ? "ACTIVE" : "FROZEN") << "\n";
        }
        cout << "================================================================--------------------------------\n";
    }

    void displayMasterLedger(const vector<Transaction>& history) const {
        cout << "\n=================================== GLOBAL TRANSACTION HISTORY ===================================\n";
        cout << left << setw(15) << "Timestamp" << setw(15) << "Type" << setw(15) << "Origin Acc" << setw(18) << "Destination Acc" << setw(15) << "Amount" << "\n";
        cout << "--------------------------------------------------------------------------------------------------\n";
        if (history.empty()) {
            cout << "                                  [ No Transactions Logged ]                                      \n";
        } else {
            for (const auto& tx : history) {
                cout << left << setw(15) << tx.timestamp
                     << setw(15) << tx.type
                     << setw(15) << tx.originAcc
                     << setw(18) << (tx.destinationAcc.empty() ? "N/A" : tx.destinationAcc)
                     << "RM " << fixed << setprecision(2) << tx.amount << "\n";
            }
        }
        cout << "================================================================----------------------------------\n";
    }
};

// Initial Mock Datastore Setup
void seedDatabase(vector<Customer>& clients, vector<Administrator>& admins) {
    clients.push_back(Customer("1001", "1111", "Chew Chiu Xian", 8500.50));
    clients.push_back(Customer("1002", "2222", "Lau Yan Kai", 12450.00));
    clients.push_back(Customer("1003", "3333", "Lee Yin Sheng", 450.25));
    
    admins.push_back(Administrator("9001", "9999", "SuperAdmin Executive"));
}

int main() {
    vector<Customer> customers;
    vector<Administrator> administrators;
    vector<Transaction> transactionLedger;

    seedDatabase(customers, administrators);

    while (true) {
        cout << "\n=========================================\n";
        cout << "       WELCOME TO EQUINOX BANKING        \n";
        cout << "=========================================\n";
        cout << "1. Customer Access\n";
        cout << "2. Administrator Audit Desk\n";
        cout << "3. Exit System\n";
        cout << "Enter system choice (1-3) >> ";
        
        int mainChoice;
        if (!(cin >> mainChoice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (mainChoice == 3) {
            cout << "\nThank you for choosing Equinox. System shutting down gracefully...\n";
            break;
        }

        string enteredAcc, enteredPin;
        cout << "Enter Account/ID Number >> ";
        cin >> enteredAcc;
        cout << "Enter Secret Secure PIN >> ";
        cin >> enteredPin;

        if (mainChoice == 1) {
            // Customer Session Scope
            Customer* activeCustomer = nullptr;
            for (auto& client : customers) {
                if (client.verifyCredentials(enteredAcc, enteredPin)) {
                    activeCustomer = &client;
                    break;
                }
            }

            if (!activeCustomer) {
                cout << "❌ Access Denied: Invalid account credentials.\n";
                continue;
            }

            bool customerSession = true;
            while (customerSession) {
                cout << "\n--- CUSTOMER MAIN DASHBOARD (" << activeCustomer->getName() << ") ---\n";
                cout << "1. Balance Inquiry\n";
                cout << "2. Capital Deposit\n";
                cout << "3. Secure Cash Withdrawal\n";
                cout << "4. Direct Account Transfer\n";
                cout << "5. Pay Utility Bills\n";
                cout << "6. Credit Card Settings\n";
                cout << "7. Log Out\n";
                cout << "Select operational step >> ";
                
                int clientStep;
                cin >> clientStep;

                double actionAmt;
                switch (clientStep) {
                    case 1:
                        cout << "💳 Current Liquid Balance: RM " << fixed << setprecision(2) << activeCustomer->getBalance() << "\n";
                        break;
                    case 2:
                        cout << "Enter deposit amount (RM) >> ";
                        cin >> actionAmt;
                        activeCustomer->deposit(actionAmt);
                        transactionLedger.push_back({"09:30 AM", "DEPOSIT", activeCustomer->getAccountNumber(), "", actionAmt});
                        break;
                    case 3:
                        cout << "Enter withdrawal amount (RM) >> ";
                        cin >> actionAmt;
                        if (activeCustomer->withdraw(actionAmt)) {
                            transactionLedger.push_back({"10:15 AM", "WITHDRAWAL", activeCustomer->getAccountNumber(), "", actionAmt});
                        }
                        break;
                    case 4: {
                        string targetAcc;
                        cout << "Enter target destination account number >> ";
                        cin >> targetAcc;
                        cout << "Enter transfer quantity (RM) >> ";
                        cin >> actionAmt;

                        Customer* receiver = nullptr;
                        for (auto& client : customers) {
                            if (client.getAccountNumber() == targetAcc && targetAcc != activeCustomer->getAccountNumber()) {
                                receiver = &client;
                                break;
                            }
                        }

                        if (receiver) {
                            if (activeCustomer->withdraw(actionAmt)) {
                                receiver->deposit(actionAmt);
                                transactionLedger.push_back({"02:45 PM", "TRANSFER", activeCustomer->getAccountNumber(), targetAcc, actionAmt});
                                cout << "✅ Transfer to account " << targetAcc << " completed successfully.\n";
                            }
                        } else {
                            cout << "❌ Transfer Failed: Destination account not found.\n";
                        }
                        break;
                    }
                    case 5: {
                        cout << "1. Tenaga Nasional Berhad (TNB)\n2. Syabas Water\n3. Telekom Malaysia (TM)\nSelect bill utility >> ";
                        int billChoice; cin >> billChoice;
                        string utilityName = (billChoice == 1) ? "TNB" : (billChoice == 2) ? "Syabas" : "TM";
                        cout << "Enter statement invoice balance (RM) >> ";
                        cin >> actionAmt;
                        if (activeCustomer->payBill(utilityName, actionAmt)) {
                            transactionLedger.push_back({"04:10 PM", "BILL_PAY", activeCustomer->getAccountNumber(), utilityName, actionAmt});
                        }
                        break;
                    }
                    case 6: {
                        cout << "Enter requested new credit instrument limit (RM) >> ";
                        double newLimit; cin >> newLimit;
                        cout << "Activate card instrument? (1 = Yes, 0 = Freeze) >> ";
                        bool cardOpt; cin >> cardOpt;
                        activeCustomer->modifyCreditSettings(newLimit, cardOpt);
                        break;
                    }
                    case 7:
                        customerSession = false;
                        cout << "🔒 Session terminated securely. Logging out...\n";
                        break;
                    default:
                        cout << "❌ Invalid choice parameters.\n";
                }
            }

        } else if (mainChoice == 2) {
            // Admin Session Scope
            Administrator* activeAdmin = nullptr;
            for (auto& admin : administrators) {
                if (admin.verifyCredentials(enteredAcc, enteredPin)) {
                    activeAdmin = &admin;
                    break;
                }
            }

            if (!activeAdmin) {
                cout << "❌ Audit Authorization Revoked: Secure ID invalid.\n";
                continue;
            }

            bool adminSession = true;
            while (adminSession) {
                cout << "\n--- COMPLIANCE MANAGEMENT DESK (" << activeAdmin->getName() << ") ---\n";
                cout << "1. Audit All Customer Accounts\n";
                cout << "2. Fetch Master Ledger History\n";
                cout << "3. Exit Audit Panel\n";
                cout << "Select audit parameter >> ";
                
                int adminStep;
                cin >> adminStep;

                if (adminStep == 1) {
                    activeAdmin->displayCustomerRegistry(customers);
                } else if (adminStep == 2) {
                    activeAdmin->displayMasterLedger(transactionLedger);
                } else if (adminStep == 3) {
                    adminSession = false;
                    cout << "🔒 Admin terminal disconnected.\n";
                } else {
                    cout << "❌ Parameter choice out of legal boundaries.\n";
                }
            }
        }
    }
    return 0;
}
