//NotBindingOfIsaac     A Shitgaem made by a noob
#include "Item.h"

/*Item::Item()
    : value(0), weight(0), droprate(0), IsUsable(false)
    {}*/


Item::Item(int a, int b, int c, bool d)
    : value(a), weight(b), droprate(c), IsUsable(d)
    {}




int Item::GetDroprate()
{
    return droprate;
}

int Item::GetUsablestatus()
{
    return IsUsable;
}

int Item::GetValue()
{
    return value;
}

int Item::GetWeight()
{
    return weight;
}

