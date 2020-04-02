#include <string>
#include <stdexcept>

using namespace std;

namespace phonetic
{
    std::string find(std::string text, std::string word);
};

namespace help
{
    bool check(std::string result, std::string word);
    std::string sub(std::string text, std::string word);
    std::string spl(std::string text);
};