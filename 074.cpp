#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) { 
		int m = matrix.size();
		if(m == 0) return false;
		int n = matrix[0].size();
		if(n == 0) return false;
		if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;

		int row;
		int l = 0;
		int r = m;
		while(l < r){
			int mid = (l + r)/2;

			if(matrix[mid][0] < target){
				if(mid+1 == m || matrix[mid+1][0] > target){
					row = mid;
					break;
				}else l = mid + 1;
			}else if(matrix[mid][0] > target){
				if(matrix[mid-1][0] < target){
					row = mid - 1;
					break;
				}else r = mid;
			}else return true;
		}

		l = 0;
		r = n;
		while(l < r){
			int mid = (l + r)/2;

			if(matrix[row][mid] < target){
				l = mid + 1;
			}else if(matrix[row][mid] > target){
				r = mid;
			}else return true;
		}
		return false;
	}
};

int main(){
	Solution s;
	string line;
	vector<vector<int>> m;
	getline(cin, line);
	getline(cin, line);
	while(line != "]"){
		replace(line.begin(), line.end(), ']', ' ');
		replace(line.begin(), line.end(), '[', ' ');
		replace(line.begin(), line.end(), ',', ' ');

		istringstream is(line);
		vector<int> v;
		int n;
		while(is >> n) v.push_back(n);

		m.push_back(v);
		getline(cin, line);
	}

	int target;
	cin >> target;
	
	cout<<s.searchMatrix(m, target)<<endl;
}
