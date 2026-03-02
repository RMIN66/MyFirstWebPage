#include <iostream>
using namespace std;

bool isEqual(char* word1, char* word2)
{
    int i = 0;

    while (word1[i] != '\0' && word2[i] != '\0')
    {
        if (word1[i] != word2[i])
        {
            return false;
        }
        i++;
    }

    if (word1[i] == '\0' && word2[i] == '\0')
    {
        return true;
    }
    return false;
}

void replacingsynonyms(char**& dictionary, int size, char*& useCases1, char**& synonyms, char*& result)
{
    char temp[60];
    int tempindex = 0;
    int resultindex = 0;
 
    for (int i = 0; useCases1[i] != '\0'; i++)
    {
        if (useCases1[i] != ' ' && useCases1[i] != '\0')
        {
            temp[tempindex++] = useCases1[i];
        }
        else
        {
            if (tempindex > 0)
            {
                temp[tempindex] = '\0';
                bool flag = false;

                for (int j = 0; j < size; j++)
                {
                    if (isEqual(temp, dictionary[j]))
                    {
                        if (synonyms[j] != nullptr)
                        {
                            int k = 0;
                            while (synonyms[j][k] != '\0')
                            {
                                result[resultindex++] = synonyms[j][k++];
                            }
                        }
                        else
                        {
                            int s = 0;
                            while (temp[s] != '\0')
                            {
                                result[resultindex++] = temp[s++];
                            }
                        }
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    int m = 0;
                    while (temp[m] != '\0')
                    {
                        result[resultindex++] = temp[m++];
                    }
                }
                tempindex = 0;
            }
            if (useCases1[i] == ' ')
            {
                result[resultindex++] = ' ';
            }
        }
    }

    // Process the last word (if any) that doesn't have a space after it
    if (tempindex > 0)
    {
        temp[tempindex] = '\0';
        bool flag = false;

        for (int j = 0; j < size; j++)
        {
            if (isEqual(temp, dictionary[j]))
            {
                if (synonyms[j] != nullptr)
                {
                    int k = 0;
                    while (synonyms[j][k] != '\0')
                    {
                        result[resultindex++] = synonyms[j][k++];
                    }
                }
                else
                {
                    int s = 0;
                    while (temp[s] != '\0')
                    {
                        result[resultindex++] = temp[s++];
                    }
                }
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            int m = 0;
            while (temp[m] != '\0')
            {
                result[resultindex++] = temp[m++];
            }
        }
    }

    result[resultindex] = '\0';
}

int main()
{
	int size = 2;
	char** dictionary = new char* [size];
	dictionary[0] = new char[11] { 'a', 's', 's', 'i', 'g', 'n', 'm', 'e', 'n', 't', '\0'  };
    dictionary[1] = new char[5] { 'l', 'o', 'v', 'e', '\0' };

    char** synonyms = new char* [size];
    synonyms[0] = new char[11] { 'a', 's', 's', 'e', 's', 's', 'm', 'e', 'n', 't', '\0' };
    synonyms[1] = new char[10] { 'a', 'f', 'f', 'e', 'c', 't', 'i', 'o', 'n', '\0' };

    char* useCases1 = new char[2600];
    cout << "Input: ";
    cin.getline(useCases1, 2600);

    char* result = new char[2600];

    replacingsynonyms(dictionary, size, useCases1, synonyms, result);

    cout << "Output: " << result;

    return 0;
}
