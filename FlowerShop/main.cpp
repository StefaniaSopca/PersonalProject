#include<iostream>
#include <vector>
#include<string>
#include "header.h"
using namespace std;

int main(){
    FlowerShop AnnaBell = FlowerShop("AnnaBell", "Str. Republicii, nr. 22", "Monday-Saturday : 9:00 - 14:00\n\t\t\tSunday - CLOSE\n");
    AnnaBell.print_flowershop();


    options(0);


    return 0;
}


