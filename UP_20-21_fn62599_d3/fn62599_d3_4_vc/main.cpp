#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define MAX_SIZE 100

int getLength(const char arr[])
{
    int counter = 0;

    while (arr[counter] != '\0')
    {
        counter++;
    }

    return counter;
}

void addOne(bool arr[])
{
    for (int i = MAX_SIZE - 1; i >= 0; --i)
    {
        if (arr[i] == 0)
        {
            arr[i] = 1;
            break;
        }

        if (arr[i] == 1)
        {
            arr[i] = 0;
        }
    }
}

bool wordExist(const char word[], ifstream &file)
{
    char tempWord[MAX_SIZE];

    while (file.good())
    {
        file >> tempWord;

        if (strcmp(word, tempWord) == 0)
            return true;
    }


    return false;
}

void clearArr(char arr[])
{
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        arr[i] = '\0';
    }
}

long long int allPossibleCombinations(const char arr[])
{
    ofstream writeToFile("test1.txt", ios::trunc);
    writeToFile.close();

    long long int allWordsCounter = 0;

    char currentWord[MAX_SIZE];
    int currentWordCounter = 0;

    int wordLength = getLength(arr);

    bool combinations[MAX_SIZE] = {0,};

    addOne(combinations);

    for (long long int i = 0; i < pow(2, wordLength) - 1; ++i)
    {
        int counter = 0;
        currentWordCounter = 0;

        clearArr(currentWord);

        for (int j = MAX_SIZE - wordLength; j < MAX_SIZE; ++j)
        {
            if (combinations[j])
            {
                //cout << arr[counter];
                currentWord[currentWordCounter] = arr[counter];
                currentWordCounter++;

            }
            else
            {
                //cout << "_";
            }
            counter++;
        }
        //cout << '\n';

        ifstream ReadFile("test1.txt");

        if (!wordExist(currentWord, ReadFile))
        {
            //cout << currentWord << endl;
            ReadFile.close();

            ofstream writeToFile("test1.txt", std::fstream::app);

            if (!writeToFile.is_open())
            {
                return -1;
            }

            writeToFile << currentWord;

            writeToFile << '\n';

            allWordsCounter++;

            writeToFile.close();
        }
        addOne(combinations);

        ReadFile.close();
    }

    ofstream writeToFile2("test1.txt", std::fstream::app);

    writeToFile2 << allWordsCounter;
    writeToFile2.close();


    return allWordsCounter;
}

int main()
{
    // Secures a file in directory
    ofstream writeToFile2("test1.txt", std::fstream::trunc);
    writeToFile2.close();

    cout << allPossibleCombinations("steeer");

    return 0;
}