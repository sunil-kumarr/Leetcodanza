class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> heap;
        for(auto x:stones){
            heap.push(x);
        }
        while(heap.size()>1){
            int a = heap.top();heap.pop();
            int b = heap.top();heap.pop();
            // cout<<a<<" "<<b<<endl;
            if(abs(a-b)!=0){
                heap.push(abs(a-b));
            }
        }
        if(heap.empty())return 0;
        return heap.top();
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
        vector<int> stones = stringToIntegerVector(line);
        
        int ret = Solution().lastStoneWeight(stones);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}