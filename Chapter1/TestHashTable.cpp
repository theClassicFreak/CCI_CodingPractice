#include "iostream"
#include "fstream"
#include "string"
#include "HashTable.cpp"

int main()
{
    // Generate Data
    // std::fstream entryFile;
    // std::fstream searchFile;    
    // entryFile.open("CompleteEntries.txt",std::ios::out);
    // searchFile.open("SearchEntries.txt",std::ios::out);
    // long double tmp = 0;
    // if(entryFile.is_open() && searchFile.is_open())
    // {
    //     for(long double i=0; i<50000; i++)
    //     {
    //         tmp = rand()%1000000;
    //         entryFile<<(tmp)<<std::endl;
    //         if(int(i)%2==0)
    //         {
    //             searchFile<<(tmp)<<std::endl;
    //         }
    //     }
    //     entryFile.close();
    //     searchFile.close();
    // }

    // Populate HashTable
    HashTable* obj = new HashTable();
    std::fstream newFile;
    newFile.open("CompleteEntries.txt",std::ios::in);
    if(newFile.is_open())
    {
        std::string value = "";
        while(std::getline(newFile, value))
        {
            obj->addToHashTable(std::stoi(value));
        }
        newFile.close();
    }

    // Search HashTable
    double searchHits = 0;
    double searchMiss = 0;
    newFile.open("SearchEntries.txt",std::ios::in);
    if(newFile.is_open())
    {
        std::string value = "";
        while(std::getline(newFile, value))
        {
            if(obj->findValue(std::stoi(value)))
            {
                searchHits++;
            }
            else
            {
                searchMiss++;
            }
        }
        newFile.close();
    }  
    std::cout<<"Search Hits: "<<searchHits<<", Search Misses: "<<searchMiss<<std::endl;
    
    delete obj;
    return 0;
}