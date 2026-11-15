class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
    /*vector<long long>ans;
    
    int i=0;
    while(i<arr.size()){
    int sum=0;
    for(int j=i;j<arr.size();j++){
      sum+=arr[j];
      ans.push_back(sum);
    }
    i++; 
    } 
    long long count=0;
    for(int t=0;t<ans.size();t++){
        if(ans[t]%2!=0){
            count++;
        }
    }
   
    
    return count % 1000000007;*/
    
        long long count = 0;
        int even = 1, odd = 0;   
        int sum = 0;
        for (int j = 0; j < arr.size(); j++) {
            sum += arr[j];
            if (sum % 2 == 0) {
                count += odd;    
                even++;
            } else {
                count += even;   
                odd++;
            }
        }
        return count % 1000000007;
    }
};
    