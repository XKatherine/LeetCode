#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;
		ListNode dummy(0);
		ListNode* p = &dummy;
		p->next = head;

		ListNode* last = NULL;

		while(p->next->next){
			if(p->next->val == p->next->next->val){
				if(!last) last = p;
				p = p->next;
			}else{
				if(last) {
					last->next = p->next->next;
					p->next->next = NULL;
					p = last;
					last = NULL;
				}else p = p->next;
			}
		}
		if(last) last->next = NULL;
		return dummy.next;

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
			p->next = new ListNode(n);
			p = p->next;
		}

		dummy.next = s.deleteDuplicates(dummy.next);
		p = dummy.next;
		while(p!=NULL){
			cout<<p->val<<" ";
			p = p -> next;
		}
	}
}
