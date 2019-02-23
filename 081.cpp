#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 0) return false;
        if(size == 1) return nums[0] == target;
        
        int point = -1;
        int l = 0, r = size;
        while(l < r){
            int mid = (l+r)/2;
            
            if(mid == size - 1 && nums[mid] < nums[mid-1]){
                point = mid - 1;
                break;
            }else if(mid == size - 1){
                point = -1;
                break;
            }if(nums[mid] > nums[mid+1]){
                point = mid;
                break;
            }else if(nums[mid] > nums[0]){
                l = mid + 1;
            }else if(nums[mid] < nums[0]){
                r = mid;
            }else if(nums[mid] == nums[0]){
                if(mid == 0){
                    point = -1;
                    break;
                }else if(nums[mid] > nums[size-1]){
                    l = mid + 1;
                }else{
                    bool isFirst = false;
                    for(int i = mid+1; i < size; i++)
                        if(nums[i] > nums[0])
                            isFirst = true;
                    if(isFirst) l = mid + 1;
                    else r = mid;
                }
            }
        }
        
        if(point >= 0 && point < size-1){
            if(target > nums[point] || target < nums[point+1]) return false;
            if(target > nums[0]){
                l = 0;
                r = point + 1;
            }else if(target < nums[0]){
                l = point + 1;
                r = size;
            }else return true;
        }else{
            l = 0;
            r = size;
        }
        
        while(l < r){
            int mid = (r+l)/2;
            
            if(nums[mid] < target)
                l = mid + 1;
            else if(nums[mid] > target)
                r = mid;
            else return true;
        }
        return false;
        
    }
};
int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), ',', ' ');

		istringstream is(line);
		vector<int> v;
		int n;
		while(is>>n) v.push_back(n);

		getline(cin, line);
		int target = stoi(line);

		cout<<s.search(v, target)<<endl;
	}
}
