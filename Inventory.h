#include "Entity.h"
#include "Item.h"

class Inventory : public Entity {

protected:
    int currentSize;
    int maxSize;
    bool isUserInv;

    Item *inv[];



public:

Inventory(int Size, bool Type);
~Inventory();

void addItem(Item &item);
void removeItem(Item &item);
bool isEmpty();
bool isFull();
int returnSize();
int returnMaxSize();
};