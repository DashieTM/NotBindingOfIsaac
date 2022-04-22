#include "Entity.h"
#include "Item.h"

class Inventory : public Entity {

protected:
    int currentSize = 0;
    int maxSize = 5;
    bool isUserInv;
    Item arr[5];
    Item* inv = arr;
    Item empty = Item();

public:

Inventory(int Size, bool Type);
~Inventory();

void addItem(Item &item);
void removeLastItem();
bool isEmpty();
bool isFull();
int returnSize();
int returnMaxSize();

Item* returnItem(int index);
Item* returnLastItem();
};