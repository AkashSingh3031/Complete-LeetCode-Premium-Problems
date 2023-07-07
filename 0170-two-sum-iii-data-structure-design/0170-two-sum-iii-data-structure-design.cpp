class TwoSum {
    
private:
       unordered_map<int, int> values_;
public:
    
    TwoSum() { }
    
    void add(const int number) {
        values_[number]++;
    }
    
    bool find(const int value) {
        for (const auto& [num, occur] : values_) {
            if (value <= long(INT_MIN) + num) { continue; }
            if (value >= long(INT_MAX) + num) { continue; }
            
            int valueToSearch = value - num;            
            if (values_.count(valueToSearch) && (valueToSearch != num || occur > 1)) {
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */