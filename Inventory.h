#include "Entity.h"
#include "Item.h"
#include "Actor.h"

class Inventory : public Entity {

protected:
    int currentSize;
    int maxSize;
    bool isUserInv;
    Actor* owner;

    Item *inv[];



public:

Inventory(int Size, bool Type, Actor* user);
~Inventory();

void addItem(Item &item);
void removeItem(Item &item);
void useItem(Item &item);
bool isEmpty();
bool isFull();
int returnSize();
int returnMaxSize();
};