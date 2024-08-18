
#include <iostream>
#include <vector>

// time function
#include <chrono>

using namespace std;

vector<int> vec;

int userNum;

// old function to get it is prime number of not

string oldFindPrimenumber(int number)
{
   
        for (int j = 2; j < number; j++)
        {
            if (number % j == 0)
            {
                return "Not a prime number";
                break;
            }
        }
        
    
    return "It is prime number";
}
// end

int findUperNumberToNumber(int number)
{
    int i = 1;
    while (true)
    {
        if (number < (i * i))
        {
            return i;
        }

        i++;
    }
}

int findPrimenumber(int number)
{
    int value = findUperNumberToNumber(userNum);
    bool flag;
    for (int i = 2; i <= value; i++)
    {
        flag = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            vec.push_back(i);
        }
    }
}

string FindPrimeOrNot(int number)
{
    findPrimenumber(number);
    for (int prime : vec)
    {
        // cout << prime << endl;
        if (number % prime == 0)
        {
            return "this is not prime number";
            break;
        }
    }
    return "this is prime number";
}

int main()
{
    // Clear the vector
    cout << "Enter -1 to close the loop\n";
    userNum = 1;

    while (userNum != -1)
    {

        vec.clear();

        cout << "Enter your number ::  ";
        cin >> userNum;

        // old prime number function start
        // Start measuring time
        auto startf1 = chrono::high_resolution_clock::now();
        cout << oldFindPrimenumber(userNum);
        // Stop measuring time
        auto endf1 = chrono::high_resolution_clock::now();
        // deference in time
        chrono::duration<double> duration1 = endf1 - startf1;
        // duraton
        cout << endl;
        cout << "Time taken by old fun: " << duration1.count() << " seconds" << endl;
        cout << endl;

        // old prime number fun end

        // advance prime number fun start

        // Start measuring time
        auto start = chrono::high_resolution_clock::now();

        cout << FindPrimeOrNot(userNum);

        // Stop measuring time
        auto end = chrono::high_resolution_clock::now();
        // deference in time
        chrono::duration<double> duration = end - start;

        // duraton
        cout << endl;
        cout << "Time taken by advance fun: " << duration.count() << " seconds" << std::endl;

        // advance prime number fun end
        cout << endl;
        cout << endl;
    }
}