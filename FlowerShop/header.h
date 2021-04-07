#include<iostream>
#include<vector>
#ifndef PERSONALPROJECTS_HEADER_H
#define PERSONALPROJECTS_HEADER_H


using namespace std;
class FlowerShop
{
private:
    string name;
    string address;
    string program;
public:
    FlowerShop(string n, string a, string p)
    {
        name = n;
        address=a;
        program = p;
    }
    void print_flowershop();

};

class Flower{
private:
    string name;
    double price;

public:
    Flower(string n, int p){
        name = n;
        price = p;

    }

    const string &getName() const;

    double getPrice() const;

    void print_flower();


};

class Floral_arrangements{
private:
    string name;
    string flowers;
    int price;

public:
    Floral_arrangements(string n ,string f, int p)
    {
        name= n;
        flowers =f;
        price = p;

    }

    void print_floral_arrangements();

    int getPrice() const;

    const string &getName() const;


};

void bouquet_category(double total);
void floral_arrangements_category(double total);
void choose_arrangements( vector<Floral_arrangements> arrangements, double total);
double sum(double total,double price);
void choose_bouquet( vector<Flower> flowers, double total);
void options(double total);
bool caseInsensitive(string s1, string s2);
#endif