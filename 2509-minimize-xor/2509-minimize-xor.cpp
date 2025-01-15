class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int s1 = __builtin_popcount(num1);
        cout<<s1<<endl;
        int s2 = __builtin_popcount(num2);
        cout<<s2<<endl;
        if(s1 == s2) return num1;
        else if(s2>s1){
          int x = num1;
          int start = 1;
          int left = abs(s1-s2);
          int useful = 0;
          while(left > 0){
            int r = x%2;
            if(r==0){
                useful+=start;
                left--;
            }
            start = start*2;
            x = x/2;
          }
          return num1+useful;
        }else{
          int x = num1;
          int start = 1;
          int left = abs(s1-s2);
          int useful = 0;
          while(left > 0){
            int r = x%2;
            if(r==1){
                useful+=start;
                left--;
            }
            start = start*2;
            x = x/2;
          }
          return num1-useful;
        }
        return -1;
    }
};