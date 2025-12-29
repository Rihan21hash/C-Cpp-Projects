#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <limits>

using namespace std;

class Bill
{
private:
    string Item;
    int Rate, Quantity;

public:
    Bill() : Item(""), Rate(0), Quantity(0) {}

    void setItem(string item) { Item = item; }
    void setRate(int rate) { Rate = rate; }
    void setQuant(int quant) { Quantity = quant; }

    string getItem() { return Item; }
    int getRate() { return Rate; }
    int getQuant() { return Quantity; }
};


void addItem(Bill b)
{
    bool close = false;
    while (!close)
    {
        int choice;
        cout << "\n\t1. Add";
        cout << "\n\t2. Close";
        cout << "\n\tEnter Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1)
        {
            system("cls");
            string item;
            int rate, quant;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\tEnter Item Name: ";
            getline(cin, item);
            b.setItem(item);

            cout << "\tEnter Rate Of Item: ";
            cin >> rate;

            cout << "\tEnter Quantity Of Item: ";
            cin >> quant;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tInvalid input!\n";
                Sleep(2000);
                continue;
            }

            b.setRate(rate);
            b.setQuant(quant);

            ofstream out("D:/Bill.txt", ios::app);
            if (!out)
            {
                cout << "\tError: File Can't Open!\n";
            }
            else
            {
                out << b.getItem() << " : "
                    << b.getRate() << " : "
                    << b.getQuant() << endl;
            }
            out.close();

            cout << "\tItem Added Successfully\n";
            Sleep(2000);
        }
        else if (choice == 2)
        {
            system("cls");
            close = true;
        }
    }
}


void printBill()
{
    system("cls");
    int count = 0;
    bool close = false;

    while (!close)
    {
        system("cls");
        int choice;
        cout << "\t1. Add Bill\n";
        cout << "\t2. Close Session\n";
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1)
        {
            string item;
            int quant;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\tEnter Item: ";
            getline(cin, item);

            cout << "\tEnter Quantity: ";
            cin >> quant;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\tInvalid quantity!\n";
                Sleep(2000);
                continue;
            }

            ifstream in("D:/Bill.txt");
            ofstream out("D:/Bill Temp.txt");

            string line;
            bool found = false;

            while (getline(in, line))
            {
                string itemName;
                int itemRate, itemQuant;
                char colon1, colon2;

                stringstream ss(line);
                getline(ss, itemName, ':');
                ss >> itemRate >> colon1 >> itemQuant;

                // trim trailing space
                if (!itemName.empty() && itemName.back() == ' ')
                    itemName.pop_back();

                if (item == itemName)
                {
                    found = true;
                    if (quant <= itemQuant)
                    {
                        int amount = itemRate * quant;
                        cout << "\nItem | Rate | Qty | Amount\n";
                        cout << itemName << "   "
                             << itemRate << "   "
                             << quant << "   "
                             << amount << endl;

                        itemQuant -= quant;
                        count += amount;

                        out << itemName << " : "
                            << itemRate << " : "
                            << itemQuant << endl;
                    }
                    else
                    {
                        cout << "\tNot enough stock\n";
                        out << line << endl;
                    }
                }
                else
                {
                    out << line << endl;
                }
            }

            if (!found)
                cout << "\tItem Not Available!\n";

            in.close();
            out.close();
            remove("D:/Bill.txt");
            rename("D:/Bill Temp.txt", "D:/Bill.txt");

            Sleep(3000);
        }
        else if (choice == 2)
        {
            close = true;
        }
    }

    system("cls");
    cout << "\n\tTOTAL BILL: " << count << endl;
    cout << "\tThanks For Shopping!\n";
    Sleep(4000);
}


int main()
{
    Bill b;
    bool exit = false;

    while (!exit)
    {
        system("cls");
        int val;

        cout << "\tWelcome To Super Market Billing System\n";
        cout << "\t**************************************\n";
        cout << "\t1. Add Item\n";
        cout << "\t2. Print Bill\n";
        cout << "\t3. Exit\n";
        cout << "\tEnter Choice: ";
        cin >> val;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (val == 1)
            addItem(b);
        else if (val == 2)
            printBill();
        else if (val == 3)
            exit = true;
    }

    return 0;
}
