#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		return isMatch(s,p,0,0);
	}

	//Function to perform the recursion
	//sstart and pstart is the start point of s and p 
    bool isMatch(string s, string p, int sstart, int pstart) {
		int slen = s.length();
		int plen = p.length();

		//End Point
		if(sstart>=slen&&pstart>=plen)
			return true;
		else if(sstart>=slen&&p[pstart+1]=='*')
			return isMatch(s,p,sstart,pstart+2);
		else if(sstart>=slen)
			return false;

		//Based on the pattern to exhaust the pattern

		//Case A: X...without *
		if(p[pstart+1]!='*'){
			//Case A1: .
			if(p[pstart]=='.')
				return isMatch(s, p, sstart+1, pstart+1);
			//Case A2: a-z
			else{
				if(s[sstart]==p[pstart])
					return isMatch(s, p, sstart+1, pstart+1);
				else
					return false;
			}
		//Case B: X*
		}else{
			if(p[pstart]=='.'){
				for(int i=0;i<=slen-sstart;i++)
					if(isMatch(s, p, sstart+i, pstart+2))
						return true;
				return false;
			}else{
				int i=0;
				do{
					if(isMatch(s, p, sstart+i, pstart+2))
						return true;
					i++;
				}while(s[sstart+i-1]==p[pstart]);
				return isMatch(s, p, sstart, pstart+2);
			}
    	}

	}
};

int main(){
	Solution sl;
	string s;
	string p;
	while(getline(cin,s)){
		getline(cin,p);
		cout<<sl.isMatch(s,p)<<endl;
	}
}	
