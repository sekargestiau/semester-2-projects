#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main()
{
    list<string> fruit_list;

    fruit_list.insert(fruit_list.begin(), "Apple");
    fruit_list.insert(fruit_list.end(),"Orange");
    fruit_list.insert(fruit_list.end(),"Banana");
    fruit_list.insert(fruit_list.end(),"Orange");
    fruit_list.insert(fruit_list.end(),"Banana");
    fruit_list.insert(fruit_list.end(),"Mango");
    
    fruit_list.erase(std::next(fruit_list.begin(), 1));
    fruit_list.erase(std::next(fruit_list.begin(), 2));
    
    cout << "" << endl;
    cout << "List of Fruits :" << endl;
    cout << "" << endl;
    for (
        list<string>::iterator it = fruit_list.begin();
        it != fruit_list.end();
        ++it
    ) {
        cout << " -> " << *it << endl;
    }

    return 0;
}
