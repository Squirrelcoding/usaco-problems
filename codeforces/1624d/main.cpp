#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define all(x) begin(x), end(x)

int nxt()
{
    int n;
    cin >> n;
    return n;
}

int main()
{
    freopen("input", "r", stdin);
    int t = nxt();
    for (int a = 0; a < t; ++a)
    {
        int n = nxt();
        int k = nxt();
        string s;
        cin >> s;
        map<char, int> char_map;
        for (char c : s)
        {
            if (char_map.count(c))
            {
                char_map[c]++;
            }
            else
            {
                char_map[c] = 1;
            }
        }

        int character_pairs = 0;
        int single_characters = 0;

        for (auto p : char_map)
        {
            if (p.second % 2 == 0)
            {
                character_pairs += p.second / 2;
            }
            else
            {
                single_characters += 1;
                character_pairs += (p.second - 1) / 2;
            }
        }

        int low = 1;
        int high = n / k;

        int max_length = 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int required_pairs = k * mid / 2;
            if (mid % 2 == 0)
            {
                if (character_pairs >= required_pairs)
                {
                    max_length = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else
            {
                if (character_pairs >= required_pairs ||
                    (character_pairs + 1 == required_pairs && single_characters >= mid))
                {
                    max_length = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        cout << max_length << endl;
    }
    return 0;
}