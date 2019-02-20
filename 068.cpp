#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
	void fullJustify_(vector<string>& words, int maxWidth, vector<string>& ret){
		if(words.size() == 0) return;

		int i = 1;
		int res = maxWidth - words[0].length();
		while(i < words.size() && words[i].length() + 1 <= res){
			res -= words[i].length() + 1;
			++i;
		}

		string sum = words[0];

		if(i==words.size()){
			for(int j = 1; j < i; j++){
				sum += " ";
				sum += words[j];
			}
			sum += string(res, ' ');
			ret.push_back(sum);
			return;
		}
		if(i==1){
			ret.push_back(sum + string(res, ' '));
			words.erase(words.begin());
			fullJustify_(words, maxWidth, ret);
			return;
		}

		vector<int> spaces(i-1, res/(i-1)+1);
		res -= res/(i-1) * (i-1);
		int k = 0;
		while(res-- > 0){
			++(spaces[k]);
			++k;
		}
		for(int j = 1; j < i; j++){
			sum += string(spaces[j-1], ' ');
			sum += words[j];
		}
		ret.push_back(sum);
		words.erase(words.begin(), words.begin()+i);
		fullJustify_(words, maxWidth, ret);
		return;
	}

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ret;
		fullJustify_(words, maxWidth, ret);

		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		vector<string> v;
		while(line.find('"')!=string::npos){
			int start = line.find('"') + 1;
			int stop = line.find('"', start);
			v.push_back(line.substr(start, stop-start));

			line = line.substr(stop + 1);
		}

		string str;
		getline(cin,str);
		int m = stoi(str);
		
		vector<string> ans = s.fullJustify(v, m);

		for(auto i : ans)
			cout<<i<<endl;
	}
}

