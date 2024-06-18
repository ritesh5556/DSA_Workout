#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int sumOfMinMaxSubArrK(vector<int>& nums, int k) {

        deque<int> dq, dq2;
        int ans = 0;

        //first window ko process karo
        for(int i=0; i<k; i++){
            int element = nums[i];
            //jitne bhi deque ke andar chote element hai remove kardo
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }

            //jitne bhi deque ke andar mote element hai remove kardo
            while(!dq2.empty() && element < nums[dq2.back()]){
                dq2.pop_back();
            }
            //now insert kardo
            dq.push_back(i);
            dq2.push_back(i);
        }

        //remaining windows ko process karo
        //ans store karo
        //removal
        //addition
        for(int i=k; i<nums.size(); i++){
            //ans
            ans+= nums[dq.front()] + nums[dq2.front()];

            //removal 
            //out of range elements form dq
            if(!dq.empty() && i- dq.front() >= k){
                dq.pop_front();
            }

            int element = nums[i];

            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }

            //removal 
            //out of range elements form dq2
            if(!dq2.empty() && i- dq2.front() >= k){
                dq2.pop_front();
            }

            

            while(!dq2.empty() && element < nums[dq2.back()]){
                dq2.pop_back();
            }

            //now insert kardo
            dq.push_back(i);
            dq2.push_back(i);


        }
        ans+= nums[dq.front()] + nums[dq2.front()];
        return ans;
        
    }

    int main(){
        vector<int>v{2,5,-1,7,-3,-1,-2};
        int k = 4;
        cout<<sumOfMinMaxSubArrK(v, k);

        return 0;
    }