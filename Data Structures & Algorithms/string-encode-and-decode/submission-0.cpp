class Solution {
public:

    string encode(vector<string>& strs)
    {
        std::string encoded {};
        for (const auto& str : strs)
        {
            encoded += std::to_string(str.length()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s)
    {
        std::vector<string> decoded;
        size_t i = 0;
        while (i < s.length())
        {
            size_t posHash = s.find('#', i);
            std::string length = s.substr(i, posHash - i); // number of characters between i and #
            size_t lengthInt = std::stoul(length); // unsigned long for non implicit conversion

            std::string word = s.substr(posHash + 1, lengthInt);
            decoded.push_back(word);

            i = posHash + 1 + lengthInt;
        }
        return decoded;
    }
};
