
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file" << filename << std::endl;
        return (1);
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create file " << outputFilename << std::endl;
        inputFile.close();
        return (1);
    }

    std::string line;
    while(std::getline(inputFile, line))
    {
        if(!s1.empty())
        {
            size_t pos = line.find(s1);
            while ((pos != std::string::npos))
            {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos = line.find(s1, pos + s2.length());
            }
        }
        outputFile << line;

        if (!inputFile.eof())
            outputFile << std::endl;
    }
    inputFile.close();
    outputFile.close();

    return (0);
}