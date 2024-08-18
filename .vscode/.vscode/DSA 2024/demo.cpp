#include <iostream> // For std::cin, std::cout
#include <vector>   // For std::vector
using namespace std;
int main() {
    std::vector<int> vec;
    int element;

    std::cout << "Enter elements (type -1 to stop):" << std::endl;

    // Read elements and add them to the vector
    while (true) {
        std::cin >> element;
        if (element == -1) break; // Stop input if -1 is entered
        vec.push_back(element);   // Add element to the vector
    }

    // Display the elements in the vector
   cout << "The elements in the vector are:" << std::endl;
    for (int num : vec) {
        std::cout << num << " ";
    }
 cout << std::endl;

    return 0;
}
