class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> ms;
        unordered_map<char, int> mg;
        for (int i=0;i<secret.length();++i)
        {
            ms[secret[i]] += 1;
            mg[guess[i]] += 1;
        }
        
        int bulls = 0;
        int cows = 0;
        for (int i=0;i<guess.length();++i)
        {
            if (ms.find(guess[i]) == ms.end())
                continue;
            
            if (secret[i] == guess[i])
            {
                ++bulls;
                if (ms[guess[i]] <= 0)
                {
                    --cows;
                }
                ms[guess[i]] -= 1;
            }
            else if (ms[guess[i]] > 0)
            {
                ++cows;
                ms[guess[i]] -= 1;
            }
        }
        char str[11];
        sprintf(str, "%dA%dB", bulls, cows);
        return string(str);
    }
};