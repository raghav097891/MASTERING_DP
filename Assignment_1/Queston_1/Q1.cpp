#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Query{
    int prodid;
    int quantity;
    double payoff;
};
struct Product{
    int id;
    int stock;
    double costprice;
    double sellprice;
};
struct Customer{
    int customerid;
    vector<Query> queries;
    double budget;
};
struct transaction{
    string type;
    int prodid;
    int quantity;
    double value;
};
unordered_map< int, Product>list_products;
vector<transaction> transaction_log;
double funds=0;//AS BOTH ARE INITIALLY ZERO AND DEFINED IT GLOBALLY
double loan=0;
void plustransaction(const string& type,int prodid,int quantity,double value){
    transaction_log.push_back({type,prodid,quantity,value});
}
//Now basically I am defining a fn which will restock the stock 
void restock(int prodid,int quantity){
    Product& curr_product=list_products[prodid];// Using address to basically have a chnage in original dataset not an copy
    double price=(curr_product.costprice)*quantity;
    if(price<=funds){
        funds -= price;
        curr_product.stock+=quantity;
        plustransaction("Restock",prodid,quantity,price);
        return;
    }
    else{
        double amt=price-funds;
        loan+=amt;
        curr_product.stock+=quantity;
        plustransaction("Loan",0,0,amt);//AS we cannot define quantity and id of loan so used it as 0
        plustransaction("Restock",prodid,quantity,price);
        funds=0;
        return;
    }
}
//AS for each customer, select a subset of their queries such that:
void customerp(Customer& customer){
    vector<Query> curr_queries=customer.queries;
    sort(curr_queries.begin(),curr_queries.end(),[](const Query& a, const Query& b){
        return a.payoff>b.payoff;
    });
    double curr_budget=customer.budget;
    for(auto& q : curr_queries){
        Product& curr_product=list_products[q.prodid];//Checking customer order with our product list
        int quantity= q.quantity;
        double price=quantity*curr_product.sellprice;
        if(price>curr_budget) continue;
        if(quantity>curr_product.stock){
            restock(q.prodid,quantity-curr_product.stock);
            curr_product.stock=0;
            funds+=price;
            curr_budget-= price;
            plustransaction("Sale",q.prodid,quantity,price);
        }
        else{
            curr_product.stock-=quantity;
            funds+=price;
            curr_budget-= price;
            plustransaction("Sale",q.prodid,quantity,price);
        }
    }
}
void printtransactionlog() {
    cout << fixed << setprecision(2);
    cout << "\n**** Transaction Log ****\n";
    for (const auto& q : transaction_log) {
        cout << q.type << " | Productid: " << q.prodid << " | Quantity: " << q.quantity << " | Value: " << q.value << endl;
    }
}
void printconclusion() {
    double interest = loan * 0.10;
    double finalamt = funds - interest;
    cout << fixed << setprecision(2);
    cout << "\n****End of Day Conclusion ****\n";
    cout << "Remaining Funds: $" << funds << endl;
    cout << "Total Loan Taken: $" << loan << endl;
    cout << "Loan Interest (10%): $" << interest << endl;
    cout << "Profit/Loss after Interest: $" << finalamt << endl;
    plustransaction("Repayment", 0, 0, interest);
}
int main() {
    int n; 
    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Product p;
        cout << "Enter product id, stock, cost price, sell price: ";
        cin >> p.id >> p.stock >> p.costprice >> p.sellprice;
        list_products[p.id] = p;
    }
    int m; 
    cout << "Enter number of customers: ";
    cin >> m;

    vector<Customer> customers(m);
    for (int i = 0; i < m; i++) {
        cout << "Enter customer id and budget: ";
        cin >> customers[i].customerid >> customers[i].budget;

        int q; 
        cout << "Enter number of queries for customer " << customers[i].customerid << ": ";
        cin >> q;

        customers[i].queries.resize(q);
        for (int j = 0; j < q; j++) {
            cout << "Enter product id, quantity, payoff for query " << j+1 << ": ";
            cin >> customers[i].queries[j].prodid 
                >> customers[i].queries[j].quantity 
                >> customers[i].queries[j].payoff;
        }
    }
    for (auto& customer : customers) {
        customerp(customer);
    }
    printtransactionlog();
    printconclusion();

    return 0;
}
