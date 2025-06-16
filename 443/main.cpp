#include <iostream>

using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        if (chars.empty())
            return 0;

        int writeIndex = 0;
        int readIndex = 0;
        int n = chars.size();

        while (readIndex < n)
        {
            char currentChar = chars[readIndex];
            int count = 0;

            while (readIndex < n && chars[readIndex] == currentChar)
            {
                readIndex++;
                count++;
            }

            chars[writeIndex++] = currentChar;

            if (count > 1)
            {
                string countStr = to_string(count);
                for (char c : countStr)
                {
                    chars[writeIndex++] = c;
                }
            }
        }

        chars.resize(writeIndex);
        return writeIndex;
    }
};
int main()
{
    Solution s;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int result = s.compress(chars);
    cout << "Compressed length: " << result << endl;
}
