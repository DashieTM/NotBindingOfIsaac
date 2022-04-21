#include "Entity.h"
#include "Item.h"

class Inventory : public Entity {

protected:
    int currentSize = 0;
    int maxSize = 5;
    bool isUserInv;
    Item arr[5];
    Item* inv = arr;

public:

Inventory(int Size, bool Type);
~Inventory();

void addItem(Item &item);
Item* removeLastItem();
bool isEmpty();
bool isFull();
int returnSize();
int returnMaxSize();

void NoEffect();
};