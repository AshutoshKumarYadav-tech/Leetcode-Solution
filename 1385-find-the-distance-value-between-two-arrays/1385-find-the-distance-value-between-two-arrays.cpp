class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
     
     int count=0;
     int i=0;
     while(i<arr1.size()){
        bool flag=true;
     for(int j=0;j<arr2.size();j++){
        if((abs(arr1[i]-arr2[j]))<=d){
          flag=false;
          break;
        } 
     }
     if (flag==true){
        count++;
     }
     i++;  
     }
     return count;
    }
};