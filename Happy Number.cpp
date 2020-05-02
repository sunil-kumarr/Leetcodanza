class Solution {
public:
    int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
            if(fast == 1) return 1;
        } while(slow != fast);
         return 0;
    }
    // bool isHappy(int n) {
    //     set<int> number_store;
    //     number_store.insert(n);
    //     while(n!=1){
    //         int new_number=0;
    //         while(n>0){
    //             int rem=n%10;
    //             new_number+=rem*rem;
    //             n=n/10;
    //         }
    //         n=new_number;
    //         if(number_store.find(n)!=number_store.end()){
    //             return false;
    //         }
    //         number_store.insert(n);
    //     }
    //     return true;
    // }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        bool ret = Solution().isHappy(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}