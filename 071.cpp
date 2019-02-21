#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
		stack<string> directions;

		int start = path.find_first_not_of('/'); 
		while(start != string::npos){
			int end = path.find_first_of('/', start);
			end = end == string::npos ? path.length() : end;
			string dir = path.substr(start, end - start);

			path = path.substr(end);
			start = path.find_first_not_of('/'); 
			
			if(dir == ".") continue;
			if(dir == ".."){
				if(!directions.empty())
					directions.pop();
			}
			else directions.push(dir);
		}

		if(directions.empty()) return "/";
		
		string ret = "";
		while(!directions.empty()){
			ret = "/" + directions.top() + ret;
			directions.pop();
		}

		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		cout<<s.simplifyPath(line)<<endl;
	}
}
