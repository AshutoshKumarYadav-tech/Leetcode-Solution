class Solution {
public:
    bool checkDivisibility(int n) {
    int original =n;
    long sum=0;
    long product=1;

    while(n!=0){
        int rem=n%10;
        sum+=rem;
        product*=rem;
        n/=10;
    }
    if(original %(sum+product)==0){
        return true;
    }
    return false;
    }
};