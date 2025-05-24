🛒 Shopkeeper Transaction Simulator
This C++ program simulates a shopkeeper managing stock, handling customer purchases, restocking inventory, taking loans if necessary, and tracking all financial transactions. It demonstrates object-oriented design, greedy query processing, and transaction logging.

📌 Problem Overview
You are tasked with implementing a system that:

Stores and manages products with stock, cost price, and selling price.

Handles multiple customers, each with a budget and a set of purchase queries.

Sells products if customer budgets allow and restocks if stock is insufficient.

Takes loans when funds are insufficient to restock.

Maintains a transaction log and prints a summary of the day's profit or loss.

🧱 Data Structures
Product
struct Product {
    int id;
    int stock;
    double costprice;
    double sellprice;
};
Query
struct Query {
    int prodid;
    int quantity;
    double payoff;
};
Customer
struct Customer {
    int customerid;
    vector<Query> queries;
    double budget;
};
Transaction
struct transaction {
    string type;
    int prodid;
    int quantity;
    double value;
};
💾 Global Variables
unordered_map<int, Product> list_products;
vector<transaction> transaction_log;
double funds = 0;
double loan = 0;
list_products: Maps product ID to product info.

transaction_log: Stores all transaction records.

funds: Current funds available.

loan: Accumulated loan amount.

🔄 Program Flow
Input Products
User enters product ID, stock, cost price, and selling price.

Input Customers and Queries
Each customer provides their ID, budget, and a list of product queries.

Process Customers

Sort each customer's queries by payoff (greedy approach).

For each query:

Skip if price exceeds customer budget.

If stock is insufficient, restock using funds or loan.

Sell the product and update funds, stock, and transaction log.

Restocking

If funds are enough, purchase stock directly.

If not, take a loan and then restock.

Log the loan and restock as transactions.

Logging Transactions
All actions (sales, loans, restocks, repayments) are logged.

Print Final Summary

Display remaining funds.

Total loan taken.

10% interest on loan.

Profit/Loss = Funds - Interest.

🧠 Greedy Strategy
Queries are sorted by payoff so that the most profitable transactions are fulfilled first, maximizing gains within budget and stock constraints.

📈 Financial Summary Format
nginx
Copy
Edit
Remaining Funds: $X.XX
Total Loan Taken: $Y.YY
Loan Interest (10%): $Z.ZZ
Profit/Loss after Interest: $W.WW
🛠️ How to Compile and Run
bash
Copy
Edit
g++ -std=c++11 shopkeeper.cpp -o shopkeeper
./shopkeeper
✅ Features
Greedy-based query fulfillment

Dynamic restocking with loan support

Transaction logging for audit trail

End-of-day profit and loan interest summary
