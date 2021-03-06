#include<iostream>
#include<string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
		if( needle.size() == 0 ) return 0;

		int i = 0, j = 0; // i is the index of haystack and j is the index of needle
		while( i < haystack.length()){
			if( haystack[i] == needle[j] ){
				++ i;
				if (++j == needle.length())
					return i-j;
			}else if( j == 0 ){
				++ i;
			}else{
				i -= j-1;
				j = 0;
			}
		}
		return -1;
	}
	/*KMP by K
	int* findNext(std::string s){
		int* res = new int[s.length()];
		res[0]=-1;
		for(int i=1; i < s.length(); i++){
			int j = i-1;
			while(j>=0 && s[i] != s[res[j]+1]){
				j = res[j];
			}
			if(j==-1)
				res[i] = -1;
			else
				res[i] = res[j]+1;
		}
		return res;
	}
    int strStr(std::string haystack, std::string needle) {
        if(needle=="") return 0;
        if(haystack=="") return -1;
		int* next = findNext(needle);
		int i = 0;//i is the index of haystack
		int j = 0;//j is the index of needle
		while(i < haystack.length()){
			if(haystack[i]==needle[j]){
				i++; j++;
			}else if(j==0){
				i++;
			}else{
				j = next[j-1]+1;
			}
			if(j==needle.length())
				return i-j;
		}
		return -1;
    }
	*/
};

int main(){
	Solution s;
	std::string line1;
	while(std::getline(std::cin,line1)){
		std::string line2;
		std::getline(std::cin,line2);
		std::cout<<s.strStr(line1,line2)<<std::endl;
	}
}
