#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<map>

class Solution {
public:
	std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
		std::vector<int> res;
		if(s=="" || words.size()==0) return res;
		std::map<std::string,int> pool;
		std::map<int,std::string> index;
		int size = words[0].length();
		int num = words.size();
		int length = s.length();

		//Initialize pool of words
		for(auto i : words){
			auto it = pool.find(i);
			if(it!=pool.end())
				it->second += 1;
			else
				pool.insert(make_pair(i,1));
		}

		//Initialize the index map
		for(auto word : pool){
			int i = 0;
			while(i<=length-size){
				int pos = s.find(word.first,i);
				if(pos==-1) break;
				index.insert(make_pair(pos,word.first));
				i = pos+1;
			}
		}

		//
		for(auto it=index.begin();it!=index.end();++it){
			int idx = it->first;
			if(idx>length-num*size) break;
			std::map<std::string,int> cpy(pool);
			int i=0;
			for(; i<num; i++){
				if(index.find(idx)==index.end()) break;
				if(cpy[index[idx]]<=0) break;
				cpy[index[idx]] -= 1;
				idx += size;
			}
			if(i==num) res.push_back(it->first);
		}
		return res;
	}



		
		
	/* -- Solution 3: Cannot pass one test case
	bool match(std::string s, std::vector<std::string> words, int len){
		if(words.size() == 1) return s==words[0];
		for(auto word : words)
			if(s.substr(0,len)==word){
				words.erase(find(words.begin(),words.end(),word));
				return match(s.substr(word.length()),words,len);
			}
		return false;
	}
	std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
		std::vector<int> res;
		if(s=="" || words.size()==0) return res;
		int size = words[0].length();
		int len = size*words.size();
		int length = s.length();
		for(int i=0; i<size; i++)
			for(int start=i; start+len<=length; start+=size)
				if(match(s.substr(start,len),words,size)){
					res.push_back(start);
					while(start+len+size<=length&&s.substr(start,size)==s.substr(start+len,size)){
						res.push_back(start+size);
						start +=size;
					}
				}
		return res;
	}
	*/

	/* -- Solution 2: Cannot pass one test case
	bool match(std::string s, std::vector<std::string> words, int len){
		if(words.size() == 1) return s==words[0];
		for(auto word : words)
			if(s.substr(0,len)==word){
				words.erase(find(words.begin(),words.end(),word));
				return match(s.substr(word.length()),words,len);
			}
		return false;
	}

	std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
		std::vector<int> res;
		if(s=="" || words.size()==0) return res;
		int len = words[0].length() * words.size();
		if(s.length()<len) return res;
		for(int i=0; i<=s.length()-len; i++)
			if(match(s.substr(i,len),words,words[0].length()))
				res.push_back(i);
		return res;
	}
	*/




	/* -- Solution 1: Time exceed
	std::vector<std::string> erase(std::vector<std::string> words, std::string word){
		std::vector<std::string> wordsCpy(words);
		wordsCpy.erase(find(wordsCpy.begin(),wordsCpy.end(),word));
		return wordsCpy;
	}

	std::vector<std::string> combination(std::vector<std::string> words) {
		if(words.size() == 1) return words;
		std::vector<std::string> ret;
		for(auto i : words){
			for(auto j : combination(erase(words,i)))
				ret.push_back(i+j);
		}
		return ret;
	}

	std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
		std::vector<int> res;
		if(s=="" || words.size()==0) return res;
		std::vector<std::string> comb = combination(words);
		for(auto word : comb){
			int i = 0;
			while(i<s.length()){
				int pos = s.find(word,i);
				if(pos==-1) break;
				if(find(res.begin(),res.end(),pos)==res.end())
					res.push_back(pos);
				i = pos+1;
			}
		}
		return res;
    }
	*/
};

int main(){
	Solution s;
	std::string line;
	while(std::getline(std::cin,line)){
		std::string tmp;
		std::string word;
		std::string words = "";
		std::vector<std::string> v;
		std::getline(std::cin,tmp);
		for(auto i : tmp)
			words += ((i==','||i=='"')?' ': i);
		std::istringstream is(words);
		while(is>>word)
			v.push_back(word);
		for(auto i : s.findSubstring(line, v))
			std::cout<<i<<std::endl;
	}
}
