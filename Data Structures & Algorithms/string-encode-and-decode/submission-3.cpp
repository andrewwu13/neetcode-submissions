class Solution {
public:

    string encode(vector<string>& strs) {
        // each string in list needs a length information
        // so we know where it starts and ends with reference to
        // the beginning 

        // we can have length at the start, along with a seperator
        if (strs.empty()) {
            return "";
        }
        for (string& s : strs) { 
            s = to_string(s.length()) + "-" + s;
        }
        string res;
        for (string&s : strs) {
            res.append(s);
            cout << s;
        }
        
        return res;
    }

    vector<string> decode(string s) {
        // then decode can also start from beginning and split
        // read up until the seperator to get the length
        vector<string> res;
        if (s == "") {
            return res;
        }
        int i = 0;
        while (i < s.length() - 1) {
            string size;
            while (s[i] != '-') {
                size += s[i];
                ++i;
            }
            int sz = stoi(size);
            cout << i;
            res.push_back(s.substr(i + 1, sz));
            i += sz + 1;
        }
        return res;
    }
};
