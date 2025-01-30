class Solution {
public:
    // bool check(int idx,vector<int>& gas, vector<int>& cost){
    //     int n = gas.size();
    //     int i = (idx + 1)%n;
    //     int gastrack = gas[idx]-cost[idx];
    //     while(i!=idx){
    //           gastrack+=gas[i];
    //           gastrack=gastrack-cost[i];
    //           if(gastrack<0) return false;
    //           i = (i+1)%n;
    //     }
    //     return true;
    // }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gastrack = 0;
        int n = gas.size();
        // -2 , -2 , -2, 3 , 3
        // -1 , -1 , 1
        //  int n = gas.size();
        //  return -1;
        int totalgas = 0;
        int totalcost = 0;
        for (int i = 0; i < n; i++) {
            totalgas += gas[i];
            totalcost += cost[i];
        }
        if (totalgas < totalcost)
            return -1;

        int curr = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            curr += gas[i] - cost[i];
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }
        return start;
    }
};