clear
echo -e "\n\n\n\n\n"
echo -e "\t================================================================================"
echo -e "\n\n\n\n\n"
g++ -o HashTable -ggdb3 -Wall HashTable.cpp
valgrind --leak-check=full --show-leak-kinds=all ./HashTable
