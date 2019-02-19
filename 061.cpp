#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if(head == NULL || k == 0) return head;

		ListNode* p = head;
		ListNode* ret;
		int cnt = 1;

		while(p->next!=NULL){
			++cnt;
			p = p->next;
		}
		p->next = head;

		for(int i = 0; i < cnt - k%cnt; ++i) p = p->next;
		ret = p->next; 
		p->next = NULL;

		return ret;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), '-', ' ');
		replace(line.begin(), line.end(), '>', ' ');

		istringstream is(line);
		ListNode dummy(0);
		ListNode* p = &dummy;
		int n;
		while(is >> n){
			ListNode* node = new ListNode(n);
			p->next = node;
			p = node;
		}

		getline(cin, line);
		istringstream i(line);
		int k;
		i >> k;
		ListNode*ans = s.rotateRight(dummy.next, k);

		while(ans!=NULL){
			cout<<ans->val<<"->";
			ans = ans->next;
		}
	}
}
