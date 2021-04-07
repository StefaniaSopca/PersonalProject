#include<iostream>
#include<string>
#include "header.h"
#include<vector>
using namespace std;
void FlowerShop::print_flowershop() {
    cout<< "\t\t\tWELCOME TO "<<name<<" !";
    cout<<"\n\t\t\t"<<address<<endl<<"\t\t\t"<<program;
}

void Flower::print_flower() {
    cout<<name<<" $"<< price<<endl<<endl;
}

const string &Flower::getName() const {
    return name;
}

double Flower::getPrice() const {
    return price;
}

void Floral_arrangements::print_floral_arrangements() {
    cout<<name<<endl;
    cout<<"\t";
    cout<<flowers<<endl;
    cout<<"\t$"<<price<<endl<<endl;
}

const string &Floral_arrangements::getName() const {
    return name;
}

int Floral_arrangements::getPrice() const {
    return price;
}


void floral_arrangements_category(double total)
{

    Floral_arrangements spring_flowers = Floral_arrangements("Spring flowers", "mum flowers, roses" , 19);
    Floral_arrangements _4Flowers = Floral_arrangements("4Flowers", "lily-of-the-valley, roses, freesia, gillyflower", 22.5 );
    Floral_arrangements leon = Floral_arrangements("Leon", "leon-flower, peonies", 24.5 );
    Floral_arrangements peonies = Floral_arrangements("Peonies", "peonies, lilies" , 18.5);

    vector<Floral_arrangements> arrangements;
    arrangements.push_back(spring_flowers);
    arrangements.push_back(_4Flowers);
    arrangements.push_back(leon);
    arrangements.push_back(peonies);

    for(Floral_arrangements i : arrangements)
        i.print_floral_arrangements();


    choose_arrangements(arrangements, total);
}



void bouquet_category(double total) {
    Flower mum= Flower("Mum flower", 5);
    Flower rose= Flower("Rose", 6);
    Flower tulip= Flower("Tulip", 3);
    Flower lily_of_the_valley= Flower("Lily-of-the-valley", 4);
    Flower peony= Flower("Peony", 7.5);
    Flower lily= Flower("Lily", 5.5);
    Flower gilly_flower= Flower("Gillyflower", 3.5);
    Flower freesia= Flower("Freesia", 6.5);

    vector<Flower> flowers;

    flowers.push_back(mum);
    flowers.push_back(rose);
    flowers.push_back(tulip);
    flowers.push_back(lily_of_the_valley);
    flowers.push_back(peony);
    flowers.push_back(lily);
    flowers.push_back(gilly_flower);
    flowers.push_back(freesia);

    for(Flower i : flowers)
    {
        i.print_flower();
    }

    choose_bouquet(flowers, total);
}

void choose_arrangements( vector<Floral_arrangements> arrangements, double total)
{
    string name;
    cout<<"Choose an arrangements:('Back' for principal menu')"<<endl;
    cin.ignore(1, '\n');
    getline(cin, name, '\n');


    while(name !="back" ) {
        int k = 0;
        for (Floral_arrangements f : arrangements) { //cout<<f.getName()<<" " << name;
            if (f.getName() == name)
            {
                total = sum(total, f.getPrice());
                cout<<"Total $"<<total<<endl;}
            else {k++;}
        }

        while (k >= arrangements.size()) {
            cout << "Incorect, please choose again!\n";
            //cin.ignore(1, '\n');
            getline(cin, name,'\n');
            k = 0;
            if(name == "back")
            {options(total);}
            else {
                for (Floral_arrangements f : arrangements) {
                    if (f.getName() == name) {
                        total = sum(total, f.getPrice());
                        cout << "Total $" << total << endl;
                    } else k++;
                }
            }
        }
        cout<<"Choose an arrangements:('-' to exit')"<<endl;
        //cin.ignore(1, '\n');
        getline(cin, name,'\n');
    }

    options(total);

}


void choose_bouquet( vector<Flower> flowers, double total)
{
    string name;
    cout<<"Choose a flower:('-' to exit')"<<endl;
    cin.ignore(1, '\n');
    getline(cin, name, '\n');
    while(name != "-")
    {

        int k = 0;
        for (Flower f : flowers) {
            if (f.getName() == name)
            {
                total = sum(total, f.getPrice());
                cout<<"Total $"<<total<<endl;}
            else k++;
        }

        while (k >= flowers.size()) {
            cout << "Incorect, please choose again!\n";
            getline(cin, name);
            k = 0;
            for (Flower f : flowers) {
                if (f.getName() == name)
                {
                    total = sum(total, f.getPrice());
                    cout<<total;
                }

                else k++;
            }
        }
        cout<<"Choose a flower:('-' to exit')"<<endl;
        cin.ignore(1, '\n');
        getline(cin, name);

    }

    options(total);

}


void options(double total)
{
    cout<<"TOTAL $"<<total<<endl;
    cout<<"Choose an option:";
    cout<<"\n\t\t1. Floral arragaments\n\t\t2.Create your bouquet flower\n";
    int input;
    cin>>input;
    if(input!=1 && input != 2)
    {
        cout<<"Non-existent option";
    }
    switch(input)
    {
        case 1:
            floral_arrangements_category(total);
            break;
        case 2:
            bouquet_category(total);
            break;
    }
}

double sum(double total,double price)
{
    return total+price;
}

