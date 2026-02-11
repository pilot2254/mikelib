#ifndef MIKE_ALGORITHM_HPP
#define MIKE_ALGORITHM_HPP

#include <string>
#include <iostream>

namespace mikelib
{
        bool isPalindrome(std::string s)
        {
                int n = s.length();

                for (int i = 0; i <= n / 2; i++)
                {
                        if (s[i] != s[n - 1 - i])
                                return false;
                }

                return true;
        }

        void countCharsInString(std::string s)
        {
                for (int i = 0; i < s.length(); i++)
                {
                        char c = s[i];

                        bool alreadyCounted = false;
                        for (int k = 0; k < i; k++)
                        {
                                if (s[k] == c)
                                {
                                        alreadyCounted = true;
                                        break;
                                }
                        }

                        if (alreadyCounted)
                                continue;

                        int count = 0;
                        for (int j = 0; j < s.length(); j++)
                        {
                                if (s[j] == c)
                                {
                                        count++;
                                }
                        }

                        std::cout << c << ": " << count << '\n';
                }
        }

        std::string removeSpacesFromString(std::string s)
        {
                std::string result = "";

                for (int i = 0; i < s.length(); i++)
                {
                        if (s[i] != ' ')
                        {
                                result += s[i];
                        }
                }

                return result;
        }

        bool stringIsAllDigits(std::string s)
        {
                int count = 0;

                for (int i = 0; i < s.length(); i++)
                {
                        if (s[i] >= 48 && s[i] <= 57)
                        { // https://www.ascii-code.com/
                                count++;
                        }
                }

                if (count == s.length())
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }

        std::string capitalizeWords(std::string s)
        {
                for (int i = 0; i < s.length(); i++)
                {
                        if (i == 0)
                        {
                                if (s[i] >= 97 && s[i] <= 122)
                                {
                                        s[i] -= 32;
                                }
                        }
                        else
                        {
                                if (s[i - 1] == ' ')
                                {
                                        s[i] -= 32;
                                }
                        }
                }

                return s;
        }

        std::string longestWord(std::string s)
        {
                std::string currentWord = "";
                std::string longestWord = "";

                for (int i = 0; i < s.length(); i++)
                {
                        if (s[i] == ' ')
                        {
                                if (currentWord.length() > longestWord.length())
                                {
                                        longestWord = currentWord;
                                }
                                currentWord.clear();
                        }
                        else
                        {
                                currentWord += s[i];
                        }
                }

                if (currentWord.length() > longestWord.length())
                {
                        longestWord = currentWord;
                }

                return longestWord;
        }

        std::string compressString(std::string s)
        {
                std::string result = "";

                for (int i = 0; i < s.length(); i++)
                {
                        char c = s[i];

                        int count = 1;

                        while (i + 1 < s.length() && s[i + 1] == c)
                        {
                                count++;
                                i++; // Move forward
                        }

                        result += c;

                        result += std::to_string(count);
                }

                return result; // aaabbc -> a3b2c1
        }

        std::string removeDuplicates(std::string s)
        {
                std::string result = "";

                for (int i = 0; i < s.length(); i++)
                {
                        char c = s[i];

                        // check if char c appeared before index i
                        bool seenBefore = false;
                        for (int j = 0; j < i; j++)
                        { // only check BEFORE current position
                                if (s[j] == c)
                                {
                                        seenBefore = true;
                                        break;
                                }
                        }

                        // if we havent seen it before then add it
                        if (seenBefore != true)
                        {
                                result += c;
                        }
                }

                return result;
        }

}

#endif