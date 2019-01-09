#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	void generator(vector<string> &v, string str, stack<char> st, int n){
		if(n==0){
			while(!st.empty()){
				st.pop();
				str += ")";
			}
			v.push_back(str);
			return;
		}
		if(st.empty()){
			st.push('(');
			str += "(";
			generator(v, str, st, n-1);
		}else{
			st.push('(');
			generator(v, str+"(", st, n-1);
			st.pop();
			st.pop();
			generator(v, str+")", st, n);
		}
	}
    vector<string> generateParenthesis(int n) {
		vector<string> ans;
		if(n<1)
			return ans;
		stack<char> st;
		st.push('(');
		generator(ans, "(", st, n-1);
		return ans;
    }
};

int main(){
	Solution s;
	int n;
	while(cin>>n){
		vector<string> ans = s.generateParenthesis(n);
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i]<<endl;
		}
	}
}
