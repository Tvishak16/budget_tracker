#include<iostream>
#include<vector>
#include <string>
#include <algorithm>
#include <__split_buffer>

using namespace std;


struct budgetentry{
    int amount;
    string description;
    char type;
};//struct

vector<budgetentry> new_entry;
int total = 0;

void add_transaction() {
    budgetentry entry;
    cout << "Enter the amount: ";
    cin >> entry.amount;
    cout << "Enter the description: ";
    cin >> entry.description;
    cout << "Enter the type (I for income, E for expense): ";
    cin >> entry.type;
    new_entry.push_back(entry);

    cout<<"Your entry has been recorded\n";
    
    

}//add_transaction


void view_transactions(){
    cout << "Transactions: " << endl;
    for (int i = 0; i < new_entry.size(); i++) {
        cout << "Amount: " << new_entry[i].amount << ", Description: " << new_entry[i].description << ", Type: ";
    }
}//view_transaction


void calculate_total(){
    for (int i = 0; i < new_entry.size(); i++) {
        if (new_entry[i].type == 'I') {
            total += new_entry[i].amount;
            }
        else {
            total -= new_entry[i].amount;
            }
    }//for_loop
}//calculate_total

void delet_entry(){
    int index;
    cout<<"Enter the index of the entry you want to delete: ";
    cin>>index;
    new_entry.erase(new_entry.begin()+index);
    cout<<"Entry deleted";
    }//delet_entry



int main(){
    cout<<"\n"<<"WELCOME TO YOUR EXPENSE TRACKER\n";
    cout<<"What would you like to do?\n"<<"\n1. Add a transaction\n"<<"2. View transactions\n"<<"3. Delet a transaction\n"<<"4. Find the total \n";
while(true){   
    int n;
    cin>>n;
    switch(n) {
    case 1:
        add_transaction();
        break;
    case 2:
        view_transactions();
        break;
    case 3:
        delet_entry();
        break;
    case 4:
        calculate_total();
        break;
    case 5:
        break;
break;
    default:
        cout << "Invalid input. Please try again." << endl;
        break;
}//switch

}
return 0;
}//main