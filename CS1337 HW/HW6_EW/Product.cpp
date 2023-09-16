#include <iostream>

using namespace std;

#include "Product.h"

void Product::setProductAttributes(string PLU_, string name_, int type_, double price_, int inventory_)
{
    PLU = PLU_;
    name = name_;
    type = type_;
    price = price_;
    inventory = inventory_;
} // function sets the inputted level of all variables to that of the object's variables
void Product::setInventory(int inventory_)
{
    inventory = inventory_;
} // function sets the inputted level of inventory to the inventory variable of the object
string Product::getPLU() const
{
    return PLU;
} // function returns the PLU of the object
string Product::getName() const
{
    return name;
} // function returns the name of the object
int Product::getType() const
{
    return type;
} // function returns the sales type of the object
double Product::getPrice() const
{
    return price;
} // function returns the unit price of the object
int Product::getInventory() const
{
    return inventory;
} // function returns the inventory level of the object
