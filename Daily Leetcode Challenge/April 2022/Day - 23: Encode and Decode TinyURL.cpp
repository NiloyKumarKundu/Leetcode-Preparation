class Solution {
public:
    map<string, string> mp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s = "";
        s += to_string(floor(random() * 100));
        while (mp.find(s) != mp.end()) {
            s += to_string(floor(random() * 100));
        }
        mp[s] = longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));