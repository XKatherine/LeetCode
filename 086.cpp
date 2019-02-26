#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		if(!head || !head->next) return head;
		ListNode* less = head;
		ListNode* more = head;

		while(less && more){
			if(more->val < x){
				swap(less->val, more->val);
				more = more->next;
				less = less->next;
			}else{
				more = more->next;
			}
		}
		return head;
	}



/*
    ListNode* partition(ListNode* head, int x) {
		if(!head || !head->next) return head;
		ListNode dummy(0);
		dummy.next = head;
		ListNode* p = head;
		ListNode* prev = &dummy;
		if(head->val < x) prev = head;

		while(p->next){
			if(prev == p && p->next->val < x){
				prev = prev->next;
				p = p->next;
			}else if(prev != p && p->next->val < x){
				ListNode* changedOne = p->next;
				p->next = p->next->next;
				changedOne->next = prev->next;
				prev->next = changedOne;
				prev = prev->next;
			}else{
				p = p->next;
			}
		}
		return dummy.next;
    }
	*/
};

int main(){
	Solution s;
	string line;

	while(getline(cin, line)){
		replace(line.begin(), line.end(), '-', ' ');
		replace(line.begin(), line.end(), '>', ' ');

		ListNode dummy(0);
		ListNode*p = &dummy;
		istringstream is(line);
		int n;

		while(is>>n){
			p->next = new ListNode(n);
			p = p->next;
		}
		getline(cin, line);
		n = stoi(line);

		p = s.partition(dummy.next, n);

		while(p){
			cout<<p->val<<"->";
			p = p->next;
		}
		cout<<endl;
	}
}
