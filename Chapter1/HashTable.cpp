#include "iostream"
#include "vector"
#include "LinkedList.cpp"

std::vector<LinkedList> hashTable;

class HashTable
{
    private:
        
    public:
        HashTable()
        {
            hashTable.reserve(10);
            for (int i = 0; i < 10 ; i++) 
            {
                LinkedList* bucket = new LinkedList();
                hashTable.push_back(*bucket);
                delete bucket;
            }
        }
        ~HashTable()
        {
            hashTable.clear();
        }
        // Hash function to return an array index (key) based on value
        int hashFunction(int value);
        // Add the value to the hash table at the given array index (key)
        void addToHashTable(int value);
        // Delete the value from the hash table at the given array index (key)
        void removeFromHashTable(int value);
        // Show the current state of the hash table
        void showHashTable();
        // Find a value in the hash table
        bool findValue(int value);

};

int HashTable::hashFunction(int value)
{
    int key = abs(value % 10);
    return key;
}

void HashTable::addToHashTable(int value)
{
    int key = hashFunction(value);
    auto bucket = hashTable.begin() + key;
    bucket->addNodeToEnd(value);
}

void HashTable::removeFromHashTable(int value)
{
    int key = hashFunction(value);
    auto bucket = hashTable.begin() + key;
    bucket->removeNode(value);
}

void HashTable::showHashTable()
{
    int index = 0;
    for (auto i = hashTable.begin(); i != hashTable.end(); i++) 
    {
        std::cout<<index++<<" : ";
        i->showList();
    }
    std::cout<<std::endl;
}

bool HashTable::findValue(int value)
{
    int key = hashFunction(value);
    auto bucket = hashTable.begin() + key;
    bool searchResult = bucket->findNode(value);
    return searchResult;
}

int main()
{
    // HashTable* obj = new HashTable();
    // obj->addToHashTable(12);
    // obj->addToHashTable(88);
    // obj->addToHashTable(32);
    // obj->addToHashTable(688);
    // obj->addToHashTable(35);
    // obj->addToHashTable(14);
    // obj->removeFromHashTable(12);
    // obj->removeFromHashTable(34);
    // obj->removeFromHashTable(14);
    // obj->addToHashTable(14);
    // obj->addToHashTable(176);
    // obj->addToHashTable(112);
    // obj->findValue(176);
    // obj->findValue(-12);
    // obj->findValue(14);
    // obj->findValue(688);
    // obj->showHashTable();
    // delete obj;
    return 0;
}