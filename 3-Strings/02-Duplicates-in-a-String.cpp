/*
https://takeuforward.org/data-structure/print-all-the-duplicates-in-the-string/
*/

/**
 * First step is to create an Array of size 26(because of the range a – z).
 * We are going to use the ASCII values of the characters to index the array.
 * For eg. ASCII of ‘a’ is 97, if we subtract 97 we get 0.
 * Likewise we can store all the characters from a – z within the index range 0 – 25.
 * We need to initialise all the entries in the array with 0.
 * After this, as usual we traverse the given string, character by character and index the array with the character and increment its value.
 */
class Solution
{
    void solve(string str)
    {
        int count[26] = {0};

        for (int i = 0; i < str.length(); i++)
            counts[str[i] - 'a']++;

        for (int i = 0; i < 26; i++)
            if (counts[i] > 1)
                cout << (char)(i + 'a') << " - " << counts[i] << "\n";
    }
}