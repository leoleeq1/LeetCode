class Solution {
public:
    char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool isVowel(const string& s, int index)
    {
        for (int i=0;i<10;++i)
        {
            if (s[index] == vowels[i])
                return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int l = 0;
        int r = s.length() - 1;
        
        while (l < r)
        {
            bool lb = isVowel(s, l);
            bool rb = isVowel(s, r);
            
            if (lb && rb)
            {
                swap(s[l++], s[r--]);
            }
            else if (lb)
            {
                --r;
            }
            else if (rb)
            {
                ++l;
            }
            else
            {
                ++l;
                --r;
            }
        }
        return s;
    }
};