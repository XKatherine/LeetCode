#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		map<int, string> m;
		m.insert(make_pair(2,"abc"));
		m.insert(make_pair(3,"def"));
		m.insert(make_pair(4,"ghi"));
		m.insert(make_pair(5,"jkl"));
		m.insert(make_pair(6,"mno"));
		m.insert(make_pair(7,"pqrs"));
		m.insert(make_pair(8,"tuv"));
		m.insert(make_pair(9,"wxyz"));

		//d is to record the previous steps
		vector<vector<string> > d;
		//initialize d[0]
		vector<string> v1;
		for(int i=0; i<m[digits[0]-'0'].length(); i++)
			v1.push_back(string(1,m[digits[0]-'0'][i]));
		d.push_back(v1);
		//D loop
		for(int i=1; i<digits.length(); i++){
			vector<string> v;
			//for every digits for ONE number
			for(int p=0; p<m[digits[i]-'0'].length(); p++)
				//for every string in previous combination
				for(int q=0; q<d[i-1].size(); q++)
					v.push_back(d[i-1][q]+string(1,m[digits[i]-'0'][p]));
			d.push_back(v);
		}
					
		return d[digits.length()-1];
    }
};

int main(){
	Solution s;
	string str;
	while(getline(cin,str)){
		vector<string> v = s.letterCombinations(str);
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<endl;
	}
}
