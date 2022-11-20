#include <iostream>
#include <fstream>
#include <string>

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

    int wordCounter = 0;

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
                for (int i = 0; i < line.length(); ++i)
                {
                    if (separator(line[i]))
                    {
                        ++wordCounter;
                        while (separator(line[i]))
                        {
                            ++i;
                        }
                    }
                }
                if (!separator(line[line.length()-1]))
                    ++wordCounter;
                if (separator(line[0]))
                    --wordCounter;
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
        std::string msg = "word count is: " + std::to_string(wordCounter);
        printf("%s\n", msg.c_str());
        fs << msg << std::endl;
        fs.close();
    }
    else
    {
        printf("Error!!! i can't out information\n");
    }
}
