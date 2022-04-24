// https://leetcode.com/problems/encode-and-decode-tinyurl/
// 535. Encode and Decode TinyURL
class Solution {
public:
    map<long long, string> keys;
    map<string, long long> urls;
    long long counter = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string result = "";
        long long key;
        
        if (urls.count(longUrl) > 0) {
            key = urls[longUrl];
        }
        else {
            key = counter;
            urls[longUrl] = key;
            keys[key] = longUrl;
            counter++;
        }
        
        result = "https://t.com/" + to_string(key);
        //cout << result << endl;
        return result;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string result = "";
        long long key;
        int i;
        int n;
        
        n = shortUrl.size();
        
        if (n == 0) return result;
        
        for (i = n - 1; i >= 0; --i) {
            if (shortUrl[i] == '/') {
                i++;
                break;
            }
        }
        
        key = 0;
        while (i < n) {
            key = key*10 + shortUrl[i] - '0';
            i++;
        }
        
        if (keys.count(key) > 0) {
            result = keys[key];
        }
        
        //printf("key: %lld, value: %s\n", key, result.c_str());
        
        return result;
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));