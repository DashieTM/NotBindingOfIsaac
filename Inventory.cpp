#include "Inventory.h"

Inventory::Inventory(int Size, bool Type) 
: maxSize(Size), isUserInv(Type)
{
}

Inventory::~Inventory() {
}

int Inventory::returnSize() {
    return currentSize;
}

int Inventory::returnMaxSize() {
    return maxSize;
}

bool Inventory::isEmpty() {
    if (currentSize == 0) return true;
    return false;
}

bool Inventory::isFull() {
    if (currentSize == maxSize) return true;
    return false;
}

void Inventory::addItem(Item &item) {
    if (!isFull()) {
        arr[currentSize] = item;
        currentSize ++;
    }
}

Item* Inventory::removeLastItem() {
        //int offset = 0;
        //for (int i = 1 ; i < maxSize ; i++) {
            //if (&arr[i] == &item) {
             //   offset = 1;
               // continue;
           // }
           // inv[i - offset] = inv[i];
       // }
        currentSize--;
        return &arr[currentSize];
}

void Inventory::NoEffect() {
        arr[currentSize].SetEffectNone(); 
}