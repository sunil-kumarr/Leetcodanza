class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total=0;
        int lowest=prices[0];
        for(int i=1;i<prices.size();i++){
            // cout<<lowest<<" "<<prices[i]<<endl;
            if(prices[i-1]>prices[i]){
                total+=(prices[i-1]-lowest);
                lowest=prices[i];
            }else{
                lowest=min(lowest,prices[i]);
            }
        }
        if(lowest!=INT_MAX)
            total+=prices[prices.size()-1]-lowest;
        return total;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}