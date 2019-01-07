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
				//Case B1: X*abc: find the location of a
				if((pstart+3==plen&&p[pstart+2]!='.')||(pstart+3<plen&&p[pstart+3]!='*'&&p[pstart+2]!='.')){
					while(sstart<slen){
						if(s[sstart]==p[pstart+2]&&isMatch(s, p, sstart+1, pstart+3))
							return true;
						sstart++;
					}
					return false;
				}
				//Case B2: X*.: 
				else if((pstart+3==plen&&p[pstart+2]=='.')||(pstart+3<plen&&p[pstart+3]!='*'&&p[pstart+2]=='.')){
					for(int i=1;i<=slen-sstart;i++)
						if(isMatch(s, p, sstart+i, pstart+3))
							return true;
					return false;
				}
				//Case B3: X*X*: Equal or not Equal
				else if(pstart+3<plen&&p[pstart+3]=='*'){
				   if(p[pstart+2]==p[pstart])	   
					   return isMatch(s,p, sstart, pstart+2);
				   else{
						for(int i=0;i<=slen-sstart;i++)
							if(isMatch(s, p, sstart+i, pstart+2))
								return true;
						return false;
				   }
				}else{
					return true;
				}
			}else{
				if((pstart+3==plen&&p[pstart+2]!='.')||(pstart+3<plen&&p[pstart+3]!='*'&&p[pstart+2]!='.')){
					if(p[pstart+2]!=p[pstart]){
						while(s[sstart]!=p[pstart+2]){
							if(s[sstart]!=p[pstart])
								return false;
							sstart++;
							if(sstart>=slen)
								return false;
						}
						return isMatch(s, p, sstart+1, pstart+3);
					}else{
						if(s[sstart]!=p[pstart])
							return false;
						else{
							int i=1;
							do{
								if(isMatch(s, p, sstart+i, pstart+2))
									return true;
								i++;
							}while(s[sstart+i-1]==p[pstart]);
							return isMatch(s, p, sstart, pstart+2);
						}
					}
				}
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
