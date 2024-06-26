#include "Interpritator.h"

void Interpritator::parse(std::string input, short* memory)
{
    int pos = 0;
    int point = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '<')
        {
            pos -= 1;
            if (pos < 0) pos = 0; 
            continue;
        }
        if (input[i] == '>')
        {
            pos += 1;
            if (pos >= 36000) pos = 35999; 
            continue;
        }
        if (input[i] == '+')
        {
            memory[pos] += 1;
            continue;
        }
        if (input[i] == '-')
        {
            memory[pos] -= 1;
            continue;
        }
        if (input[i] == '[')
        {
            if (memory[pos] == 0)
            {
                int loopCounter = 1;
                while (loopCounter != 0)
                {
                    i += 1;
                    if (input[i] == '[')
                    {
                        loopCounter += 1;
                    }
                    else if (input[i] == ']')
                    {
                        loopCounter -= 1;
                    }
                }
            }
            continue;
        }
        if (input[i] == ']')
        {
            if (memory[pos] != 0)
            {
                int loopCounter = 1;
                while (loopCounter != 0)
                {
                    i -= 1;
                    if (input[i] == '[')
                    {
                        loopCounter -= 1;
                    }
                    else if (input[i] == ']')
                    {
                        loopCounter += 1;
                    }
                }
            }
            continue;
        }
        if (input[i] == '.')
        {
            std::cout << (char)memory[pos];
            continue;
        }
    }
}