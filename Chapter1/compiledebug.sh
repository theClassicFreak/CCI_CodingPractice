clear
echo -e "\n\n\n\n\n"
echo -e "\t\t================================================================================"
echo -e "\n\n\n\n\n"
g++ -o Tester -ggdb3 -Wall TestHashTable.cpp
# valgrind --leak-check=full --show-leak-kinds=all ./Tester
./Tester
