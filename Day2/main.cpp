#include <iostream>
#include <iterator>
#include <algorithm>

int Solve(int input[], int noun, int verb, size_t size)
{
    input[1] = noun;
    input[2] = verb;
    for(int i = 0; i < size; i+=4)
    {
        if(input[i] == 99) break;
        int pos1 = input[i + 1];
        int pos2 = input[i + 2];
        int target = input[i + 3];
        switch(input[i])
        {
            case 1: 
                input[target] = input[pos1] + input[pos2];
                break;
            case 2: 
                input[target] = input[pos1] * input[pos2];
                break;
        }
    }
    return input[0];
}

int main()
{
    int input[] = {1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,13,19,2,9,19,23,1,23,6,27,1,13,27,31,1,31,10,35,
                   1,9,35,39,1,39,9,43,2,6,43,47,1,47,5,51,2,10,51,55,1,6,55,59,2,13,59,63,2,13,63,67,
                   1,6,67,71,1,71,5,75,2,75,6,79,1,5,79,83,1,83,6,87,2,10,87,91,1,9,91,95,1,6,95,99,1,
                   99,6,103,2,103,9,107,2,107,10,111,1,5,111,115,1,115,6,119,2,6,119,123,1,10,123,127,
                   1,127,5,131,1,131,2,135,1,135,5,0,99,2,0,14,0};
    
    size_t size = sizeof(input)/sizeof(int);

    //for(int i = 0; i < size; i += 4)
    //{
    //    if(input[i] == 99) break;
    //    int pos1 = input[i + 1];
    //    int pos2 = input[i + 2];
    //    int target = input[i + 3];
    //    switch(input[i])
    //    {
    //        case 1: 
    //            input[target] = input[pos1] + input[pos2];
    //            break;
    //        case 2: 
    //            input[target] = input[pos1] * input[pos2];
    //            break;
    //    }
    //}

    for(int noun = 0; noun <= 99; noun++)
    {
        for(int verb = 0; verb <= 99; verb++)
        {
            int array[145];
            std::copy(std::begin(input), std::end(input), std::begin(array));
            int result = Solve(array, noun, verb, size);
            if(result == 19690720)
            {            
                std::cout << "Noun: " << noun << std::endl;
                std::cout << "Verb: " << verb << std::endl;
                std::cout << "Answer: " << (100 * noun) + verb << std::endl;
                break;
            }
        }
    }
}