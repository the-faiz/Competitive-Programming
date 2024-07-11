struct monotone_deque
{
    deque<int> dq;

    void insert(int x)
    { // O(k)
        while (!dq.empty() && dq.back() > x)
            dq.pop_back();
        dq.push_back(x);
    }
    void erase(int x)
    { // O(1)
        if (dq.front() == x)
            dq.pop_front();
    }
    int getmin()
    { // O(1)
        return dq.front();
    }
};


//For finding minimum and maximum of every k length window in array in O(1) time complexity