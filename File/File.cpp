/******************************************************************************
Павлов Владислав Евгеньевич
КТбо1-2
Лабораторная работа №5 «Файлы данных»
Вариант № 9
Задание: Написать программу, которая в тексте из файла выберет слова с нечетным количеством букв и выведет результат в файл. 
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool separator(char ch)
{
    std::string separators = " ./!?&,(){}[]-+1234567890\n";
    for (int i = 0; i < separators.length(); ++i)
    {
        if (ch == separators[i])
            return true;
    }

    return false;
}

int main()
{
    std::string textFilePath = "text.txt";
    std::string outFilePath = "wordCount.txt";

    std::fstream fs;

    std::vector<std::string> words;
    std::vector<std::string> oddWords;

    fs.open(textFilePath, std::fstream::in);

    if (fs.is_open())
    {
        printf("File readed!\n");
        std::string line;
        while (!fs.eof())
        {
            std::getline(fs, line);
            if (!line.empty())
            {
                std::string word = "";
                for (int i = 0; i < line.length(); ++i)
                {
                    if (!separator(line[i]))
                    {
                        word = word + line[i];
                    }
                    else
                    {
                        if (!word.empty())
                        {
                            words.push_back(word);
                            word = "";
                        }
                    }
                }
            }
            for (auto& word : words)
            {
                if (word.size() % 2 != 0)
                    oddWords.push_back(word);
            }
        }
        fs.close();
    }
    else
    {
        printf("Error!!! file don't open\n");
    }


    fs.open(outFilePath, std::fstream::out);

    if (fs.is_open())
    {
        for (auto& word : oddWords)
        {
            //std::cout << word << std::endl;
            fs << word << std::endl;
        }
        fs.close();
    }
    else
    {
        printf("Error!!! i can't out information\n");
    }
}
