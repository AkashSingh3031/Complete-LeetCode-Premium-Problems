class Logger {
public:
    Logger() {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (mp.count(message) > 0 && timestamp - mp[message] < 10)
            return false;
        mp[message] = timestamp;
        return true;
    }
private:
    map<string, int> mp;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */