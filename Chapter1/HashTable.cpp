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
                // bucket.addNodeToEnd(1234+i);
                // bucket.addNodeToEnd(4321+i);
                hashTable.push_back(*bucket);
            }
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
    int key = value % 10;
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