#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		m--;n--;
		cout<<n<<endl;
		while(m >= 0 && n >= 0){
			if(nums1[m] > nums2[n]){
				nums1[m+n+1] = nums1[m];
				--m;
			} else {
				nums1[m+n+1] = nums2[n];
				--n;
			}
		}
		while(m >=0){
			nums1[m+n+1] = nums1[m];
			--m;
		}
		while(n >=0){
			nums1[m+n+1] = nums2[n];
			--n;
		}
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), ',', ' ');
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), '[', ' ');
		istringstream is(line);
		vector<int> v1;
		int n;
		while(is>>n) v1.push_back(n);

		getline(cin, line);

		replace(line.begin(), line.end(), ',', ' ');
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), '[', ' ');
		istringstream ist(line);
		vector<int> v2;
		while(ist>>n) v2.push_back(n);

		s.merge(v1, 3, v2, v2.size());

		for(auto i : v1) cout<<i<<" ";
		cout<<endl;
	}
}
