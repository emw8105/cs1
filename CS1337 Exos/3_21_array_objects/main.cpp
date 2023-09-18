// 3_21_array_objects

/*
When you create an array of objects (statically or dynamically),
you can call a constructor for each element, using an initialization
list
If there is no list, the default constructor will be called for
each element

Different overloaded constructors can be used in the same list

When an array of objects is destroyed, the destructor is called
for each element

Objects in the array are accessed by using array name + subscript
*/

#include <iostream>

using namespace std;

class Item
{
private:
    string description;
    double price;
    int inventoryLevel;
public:
    Item();
    Item(string);
    Item(string, double, int);
    ~Item();
    void printItem() const;
    void setDescription(string);
};


int main()
{
    cout << "Statically created array" << endl;
    Item inventory[] = {Item(), Item("Hammer"),
                        Item("Wrench", 10.5, 20)
                       };

    for (int i = 0; i < 3; i++)
        inventory[i].printItem();

    cout << "Dynamically created array" << endl;
    Item * inventoryPtr = new Item[3]
    {Item("Screwdriver"), Item(), Item("Wrench", 10.5, 20)};
    inventoryPtr[1].setDescription("Jackhammer");

    for (int i = 0; i < 3; i++)
        inventoryPtr[i].printItem();

    delete [] inventoryPtr;

    cout << endl << "Exiting program";


    return 0;
}

Item::Item()
{
    description = "";
    price = 0;
    inventoryLevel = 0;
}
Item::Item(string description_)
{
    description = description_;
    price = 0;
    inventoryLevel = 0;
}
Item::Item(string description_, double price_, int inventoryLevel_)
{
    description = description_;
    price = price_;
    inventoryLevel = inventoryLevel_;
}
Item::~Item()
{
    cout << endl << "In destructor of Item" << endl;
}
void Item::printItem() const
{
    cout << "Item name is " << description << ", price is $"
         << price << ", inventory level is " << inventoryLevel << endl;
}
void Item::setDescription(string description_)
{
    description = description_;
}
