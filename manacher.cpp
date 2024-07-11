string preprocess(string s) {
    if (s.empty()) return "^$";
    string ret = "^";
    for (int i = 0; i < s.length(); i++)
        ret += "#" + s.substr(i, 1);
    ret += "#$";
    return ret;
}

vector<int> longestPalindrome(string s) {
    string T = preprocess(s);
    int n = T.length();
    vector<int> P(n);
    int C = 0, R = 0;
    for (int i = 1; i < n-1; i++) {
        int i_mirror = 2*C - i;
        if (R > i) {
            P[i] = min(R-i, P[i_mirror]);
        } else {
            P[i] = 0;
        }
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    return P;
}