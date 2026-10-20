#include <vector>

using namespace std;

class CashFlow {
protected:
    int day;
    double amount;
    bool inflow; //true - поступление, false - выплата
public:
    CashFlow(int day, double amount, bool inflow) : day(day), amount(amount), inflow(inflow) {
    }

    int getDay() const { return day; }
    double getAmount() const { return amount; }
    bool isInflow() const { return inflow; }
};

class Income : public CashFlow {
public:
    Income(int day, double amount) : CashFlow(day, amount, true) {
    }
};

class Payment : public CashFlow {
public:
    Payment(int day, double amount) : CashFlow(day, amount, false) {
    }
};

class Enterprise {
    double initialBalance;
    vector<Income> incomes;
    vector<Payment> payments;

public:
    Enterprise(double initialBalance) : initialBalance(initialBalance) {
    }

    void addIncome(int day, double amount) {
        incomes.push_back(Income(day, amount));
    }

    void addPayment(int day, double amount) {
        payments.push_back(Payment(day, amount));
    }

    vector<double> calculateDailyBalances(int days) const {
        vector<double> balances;
        double balance = initialBalance;
        for (int d = 1; d <= days; ++d) {
            for (const Income &inc: incomes) {
                if (inc.getDay() == d) balance += inc.getAmount();
            }
            for (const Payment &pay: payments) {
                if (pay.getDay() == d) balance -= pay.getAmount();
            }
            balances.push_back(balance);
        }
        return balances;
    }
};
