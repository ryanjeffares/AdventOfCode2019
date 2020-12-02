#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int SumSingleFuel(int input)
{
    int div = (int)input / 3;
    div -= 2;
    return div;    
}

int SumFuel(std::vector<int> input)
{
    int total = 0;
    for(int i : input)
    {
        int res = 0;
        while(true)
        {
            i = SumSingleFuel(i);
            if(i <= 0)
            {
                break;
            }
            res += i;
        }
        total += res;
    }
    return total;
}

int main()
{
    std::vector<int> input;
    std::string line;
    std::ifstream fin("input.txt");
    while(std::getline(fin, line))
    {
        input.push_back(std::stoi(line));
    }
    std::cout << SumFuel(input) << std::endl;
}
