class Solution {
public:

    string encode(vector<string>& strs) {
        // each string in list needs a length information
        // so we know where it starts and ends with reference to
        // the beginning 

        // we can have length at the start, along with a seperator
        string res;
        for (string& s : strs) { 
            s = to_string(s.length()) + "-" + s;
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        // then decode can also start from beginning and split
        // read up until the seperator to get the length
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            string size;
            while (s[i] != '-') {
                size += s[i];
                ++i;
            }
            int sz = stoi(size);
            res.push_back(s.substr(i + 1, sz));
            i += sz + 1;
        }
        return res;
    }
};
