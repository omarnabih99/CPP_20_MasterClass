#include <iostream>
using namespace std;


class Order
{
    public:
    string createDate;
    Order(string date)
    {
        createDate = date;
    }
};

class Customer
{
    public:

    string name, deliveryAddress, contact;
    bool active;
    Order* orders[10];
    int countOrders = 0;

    Customer(string n, string d, string c)
    {
        name = n;
        deliveryAddress = d;
        contact = c;
    }

    void addOrder(string date)
    {
        orders[countOrders] = new Order(date);
        countOrders++;
    }
    
};

int main()
{
    Customer Omar("Omar", "Cairo, Egypt", "01111111111");
    Omar.addOrder("feb 27 2024");
    cout<<Omar.name<<endl;
    cout<<Omar.deliveryAddress<<endl;
    cout<<Omar.contact<<endl;
    cout<<Omar.orders[0]->createDate<<endl;
}