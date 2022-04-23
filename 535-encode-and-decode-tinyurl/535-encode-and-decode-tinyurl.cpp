class Solution {
public:

    unordered_map<string, string> encoded;
    unordered_map<string, string> decoded;
    string baseUrl = "http://tinyurl.com/";
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        if(encoded.find(longUrl)==encoded.end()){
            string newUrl = baseUrl + to_string(encoded.size()+1);
            encoded[longUrl] = newUrl;
            decoded[newUrl] = longUrl;
        }
        
        return encoded[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoded[shortUrl];
    };
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));