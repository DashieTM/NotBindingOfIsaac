//NotBindingOfIsaac     A Shitgaem made by a noob


class Item
{
protected:

    int value;
    int weight;
    int droprate;
    bool IsUsable;

public:

    Item(int a, int b, int c, bool d);
   // Item();
    ~Item();

    int GetValue();
    int GetWeight();
    int GetDroprate();
    int GetUsablestatus();
};