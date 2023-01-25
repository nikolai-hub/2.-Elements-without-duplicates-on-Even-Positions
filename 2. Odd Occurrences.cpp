#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

typedef std::vector<std::string> VecOfStrings;

VecOfStrings readInput() {
    VecOfStrings input;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream istr(line);
    std::string word;
    while (istr >> word)
    {
        input.push_back(word);
    }


    return input;
}

void ElemInVecToLowerCase(VecOfStrings& wordsWithOddSize) {
    for (size_t i = 0; i < wordsWithOddSize.size(); i++)
    {
        for (int j = 0; j < wordsWithOddSize[i].length(); j++)
        {
            (wordsWithOddSize[i])[j] = tolower((wordsWithOddSize[i])[j]);
        }
    }
}

void removeDuplicates(VecOfStrings& wordsWithOddSize)
{
    auto end = wordsWithOddSize.end();
    for (auto it = wordsWithOddSize.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }

    wordsWithOddSize.erase(end, wordsWithOddSize.end());
}

void printSolution(const VecOfStrings& wordsWithOddSize) {
    for (size_t i = 0; i < wordsWithOddSize.size(); i++)
    {
        std::cout << wordsWithOddSize[i] << std::endl;
    }
}


int main()
{
    VecOfStrings readAllWords = readInput();
    VecOfStrings wordsWithOddSize;
    

    for (size_t i = 0; i < readAllWords.size(); i++)
    {
        if (readAllWords[i].size() %2 == 0)
        {
            wordsWithOddSize.push_back(readAllWords[i]);
        }
        else
        {
            continue;
        }
    }
   
    ElemInVecToLowerCase(wordsWithOddSize);
    removeDuplicates(wordsWithOddSize);
    printSolution(wordsWithOddSize);
    
    
    
    

    return 0;
}
