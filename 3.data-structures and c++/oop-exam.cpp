#include<bits/stdc++.h>
using namespace std;

class Restaurant {
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
protected:
    int total_tax;
public:
    int n;
    void takeInput(){
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>this->food_item_codes[i];
            cin>>ws;
            getline(cin, this->food_item_names[i]);
            cin>>this->food_item_prices[i];
        }
        
    }
    void printInput(){
            cout<<"\t \t Make Bill \t \t"<<endl;
            cout<<"Item Code \t"<<"Item Name \t"<<"Item Price"<<endl;
        for (int i = 0; i < n; i++)
        {   
            cout<<this->food_item_codes[i]<<"\t \t"<<this->food_item_names[i]<<"\t \t"<<this->food_item_prices[i]<<endl;
        }
        
    }
private:
    int table_number;
    int number_of_items;
    int item_code[12];
    int quantity[12];
public:
    void takeUserInput(){
        cout<<"Enter Table number: ";
        cin>>table_number;
        cout<<"Enter Number of Items: ";
        cin>>number_of_items;
        for (int i = 0; i < number_of_items; i++)
        {
            cout<<"Enter Item Code: ";
            cin>>item_code[i];
            cout<<"Enter Quantity: ";
            cin>>quantity[i];
        }
    }
};

int main() {
    Restaurant resObj=  Restaurant();
    resObj.takeUserInput();
    return 0;
}
