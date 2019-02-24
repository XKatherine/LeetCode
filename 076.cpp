#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<deque>
using namespace std;

struct ListNode{
	char val;
	int index;
	ListNode* next;

	ListNode(char v, int i):val(v), index(i), next(NULL){}
};

class Solution {
public:
    string minWindow(string s, string t) {
		if(s == "" || t == "") return "";
		if(s.length() < t.length()) return "";

		int size = t.length();
		unordered_map<char, int> m;
		for(auto i : t) m[i] = 1;
		for(auto i : t) m[i]++;

		ListNode dummy(' ', 0);
		ListNode* p = &dummy;

		int start = -1;
		int end = s.length();
		int n = 0;

		for(int i = 0; i < s.length(); i++){
			if(m[s[i]] > 1){
				p->next = new ListNode(s[i], i);
				p = p->next;
				m[s[i]] --;
				if(++n == size && p->index - dummy.next->index < end - start){
					start = dummy.next->index;
					end = p->index;
				}
			}else if(m[s[i]] == 1){
				ListNode* prev = &dummy;
				while(prev->next->val != s[i]){
					prev = prev->next;
				}
				if(prev->next->next){
					prev->next = prev->next->next;
					p->next = new ListNode(s[i], i);
					p = p->next;
				}else{
					prev->next = new ListNode(s[i], i);
					p = prev->next;
				}
				if(n == size && p->index - dummy.next->index < end - start){
					start = dummy.next->index;
					end = p->index;
				}
			}
		}

		if(start == -1) return "";
		return s.substr(start, end-start+1);
    }
};

int main(){
	Solution s;
	string s1;
	while(getline(cin,s1)){
		string s2;
		getline(cin,s2);

		cout<<s.minWindow(s1, s2)<<endl;
	}
}
