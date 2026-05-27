#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <unordered_map>
#include <string>

namespace Duration
{
	constexpr long long lowerDot = 50;
	constexpr long long perfectDot = 100;
	constexpr long long upperDot = 199;

	constexpr long long lowerDash = 200;
	constexpr long long perfectDash = 300;
	constexpr long long upperDash = 500;

	constexpr long long lowerSymbolGap = 50;
	constexpr long long perfectSymbolGap = 100;
	constexpr long long upperSymbolGap = 299;

	constexpr long long lowerLetterGap = 300;
	constexpr long long perfectLetterGap = 300;

	constexpr long long lowerWordGap = 700;
	constexpr long long perfectWordGap = 700;
}


namespace Threshold
{
	constexpr int upper = 800;
	constexpr int lower = 200;
}

//Morsezeichen
static const std::unordered_map<std::string, char> morseTable = {
	{".-", 'A'},    {"-...", 'B'},  {"-.-.", 'C'},
	{"-..", 'D'},   {".", 'E'},     {"..-.", 'F'},
	{"--.", 'G'},   {"....", 'H'},  {"..", 'I'},
	{".---", 'J'},  {"-.-", 'K'},   {".-..", 'L'},
	{"--", 'M'},    {"-.", 'N'},    {"---", 'O'},
	{".--.", 'P'},  {"--.-", 'Q'},  {".-.", 'R'},
	{"...", 'S'},   {"-", 'T'},     {"..-", 'U'},
	{"...-", 'V'},  {".--", 'W'},   {"-..-", 'X'},
	{"-.--", 'Y'},  {"--..", 'Z'},

	{"-----", '0'}, {".----", '1'}, {"..---", '2'},
	{"...--", '3'}, {"....-", '4'}, {".....", '5'},
	{"-....", '6'}, {"--...", '7'}, {"---..", '8'},
	{"----.", '9'}
};

//Morsezeichen
static const std::unordered_map<char, std::string> reverseTable = {
	{'A', ".-"},    {'B', "-..."},  {'C', "-.-."},
	{'D', "-.."},   {'E', "."},     {'F', "..-."},
	{'G', "--."},   {'H', "...."},  {'I', ".."},
	{'J', ".---"},  {'K', "-.-"},   {'L', ".-.."},
	{'M', "--"},    {'N', "-."},    {'O', "---"},
	{'P', ".--."},  {'Q', "--.-"},  {'R', ".-."},
	{'S', "..."},   {'T', "-"},     {'U', "..-"},
	{'V', "...-"},  {'W', ".--"},   {'X', "-..-"},
	{'Y', "-.--"},  {'Z', "--.."},

	{'0', "-----"}, {'1', ".----"}, {'2', "..---"},
	{'3', "...--"}, {'4', "....-"}, {'5', "....."},
	{'6', "-...."}, {'7', "--..."}, {'8', "---.."},
	{'9', "----."}
};


#endif // !CONFIGURATION_H
