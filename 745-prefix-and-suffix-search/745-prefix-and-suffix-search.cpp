class WordFilter {
    unordered_map<string,int> data;
public:
    WordFilter(vector<string>& words) {
        for (int k = 0; k < words.size(); ++k) {
            string const& word = words[k];
            int const n = word.size();
            for (int i = 1; i <= n; ++i) {
                string key = word.substr(0, i);
                key += '.';
                for (int j = 1; j <= n; ++j) {
                    key.resize(i+1);
                    key.append(word, n-j, j);
                    data[key] = k;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        prefix += '.';
        prefix += suffix;
        return data.count(prefix) ? data[prefix] : -1;
    }
};