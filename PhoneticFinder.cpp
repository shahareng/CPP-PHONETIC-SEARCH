#include <string>
#include <iostream>
#include "PhoneticFinder.hpp"
#include <bits/stdc++.h> 
//#include <boost/algorithm/string.hpp>

using namespace std;

namespace phonetic
{
    string find(string text, string word)
    {
        if(text.empty() || word.empty())
        {
            throw runtime_error("that word doesn't exist!");
        }
        word = help::spl(word);
        string ans = help::sub(text, word);
        if(ans.compare("no") == 0)
        {
            throw runtime_error("that word doesn't exist!");
        }
        else
        {
            return ans;
        }
    }
};

namespace help
{
    // check if the word apear in the text
    bool check(string result, string word)
    {
        char letter[] = "afktepjhygqlmnubcrzdowvxis"; // all the spelling errors in the task
        // replace all the letter in the string to lowercase
        int i=0;
        while (result[i])
        {
            result[i]= tolower(result[i]);
            word[i]= tolower(word[i]);
            i++;
        }
        int ans = 0;
        for (int i=0; i<result.size(); i++)
        {
            // check if it's the same letter
            if ((result.at(i)) == (word.at(i)))
            {
                ans++;
            }
            // Checks for spelling errors
            else if ((letter[result.at(i)-'a']) == (word.at(i)) || (letter[letter[result.at(i)-'a']-'a']) == (word.at(i)))
            {
                ans++;
            }
            // else - stop to check
            else
            {
                return 0;
            }
        }
        return ans;
    }
    
    // subscribe the text to separate words
    string sub(string text, string word)
    {
        int start=0, end=0, ans=0;
        string result;
        for(int i=0; i<text.length(); i++)
        {
            if(text.at(i) != ' ')
            {
                start = i;
                end=0;
                while(i<text.length() && text.at(i) != ' ')
                {
                    i++;
                    end++;
                }
                result = text.substr(start,end);
                if(result.size() == word.size())
                {
                    ans = check(result, word);
                    if(ans != 0)
                    {
                        return result;
                    }
                }
            }
        }
        return "no"; 
    }

    // remove the spaces from 'word'
    string spl(string text)
    {
        string result = "";
        for(int i=0; i<text.length(); i++)
        {
            if(text.at(i) != ' ')
            {
                result+=text.at(i);
            }
        }
        return result;
    }
};

