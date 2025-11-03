#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>

int main() {
    std::vector<std::string> firstNames = {
        "James", "Mary", "John", "Patricia", "Robert", "Jennifer", "Michael", "Linda",
        "William", "Barbara", "David", "Elizabeth", "Richard", "Susan", "Joseph", "Jessica",
        "Thomas", "Sarah", "Christopher", "Karen", "Charles", "Nancy", "Daniel", "Lisa",
        "Matthew", "Betty", "Anthony", "Margaret", "Mark", "Sandra", "Donald", "Ashley",
        "Steven", "Kimberly", "Paul", "Emily", "Andrew", "Donna", "Joshua", "Michelle",
        "Kenneth", "Carol", "Kevin", "Amanda", "Brian", "Dorothy", "George", "Melissa",
        "Timothy", "Deborah", "Ronald", "Stephanie", "Edward", "Rebecca", "Jason", "Sharon",
        "Jeffrey", "Laura", "Ryan", "Cynthia", "Jacob", "Kathleen", "Gary", "Amy",
        "Nicholas", "Angela", "Eric", "Shirley", "Jonathan", "Anna", "Stephen", "Brenda",
        "Larry", "Pamela", "Justin", "Emma", "Scott", "Nicole", "Brandon", "Helen",
        "Benjamin", "Samantha", "Samuel", "Katherine", "Raymond", "Christine", "Frank", "Debra",
        "Gregory", "Rachel", "Alexander", "Carolyn", "Patrick", "Janet", "Jack", "Catherine",
        "Dennis", "Maria", "Jerry", "Heather", "Tyler", "Diane", "Aaron", "Ruth"
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> firstDist(0, firstNames.size() - 1);

    std::ofstream outFile("name.txt");
    if (!outFile) {
        std::cerr << "Error opening name.txt for writing!" << std::endl;
        return 1;
    }

    for (int i = 0; i < 20000; i++) {
        std::string firstName = firstNames[firstDist(gen)];
        outFile << firstName << "\n";
    }

    outFile.close();
    std::cout << "Successfully generated 20,000 random names in name.txt" << std::endl;
    return 0;
}
