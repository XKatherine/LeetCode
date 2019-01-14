#include<iostream>
#include<sstream>
#include<string>

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reverse_list(ListNode* head, ListNode* tail) {
		ListNode* next;
		while(head){
			next = head->next;
			head->next = tail;
			tail = head;
			head = next;
		}
	}

    ListNode* reverseKGroup(ListNode* head, int k) {
		if(!head) return head;
		ListNode dummy(0);
		dummy.next = head;
		ListNode* last = &dummy;
		ListNode* prev = &dummy;
		while(true){
			int i = 0;
			for(; i<k && (last->next); i++) last = last->next;
			if(i != k) break;
			ListNode* next = last->next;
			last->next = nullptr;
			reverse_list(prev->next, next);
			next = prev->next;
			prev->next = last;
			last = next;
			prev = next;
		}
		return dummy.next;
	/* Stupid way by K
    ListNode* reverseKGroupI(ListNode* head, int k) {
		if(k<1||!head) return head;
		if(k == 1) return head;
		ListNode* tail = head;
		for(int i=0; i<k-1; i++){
			tail = tail->next;
			if(!tail) return head;
		}
		ListNode* prev = head->next;
		head->next = tail->next;
		tail->next = head;
		return reverseKGroupI(prev, k-1);
	}
    ListNode* reverseKGroup(ListNode* head, int k) {
		if(k<1||!head) return head;
		if(k == 1) return head;
		ListNode* tail = head;
		for(int i=0; i<k-1; i++){
			tail = tail->next;
			if(!tail) return head;
		}
		//std::cout<<"head: "<<head->val<<std::endl;
		//std::cout<<"tail: "<<tail->val<<std::endl;
		ListNode* prev = head->next;
		head->next = reverseKGroup(tail->next, k);
		tail->next = head;
		return reverseKGroupI(prev, k-1);
		*/

    }
};

int main(){
	Solution s;
	std::string str;
	while(std::getline(std::cin,str)){
		int n,data;
		std::cin>>n;
		std::string line = "";
		for(auto i : str)
			line += (i=='-'||i=='>')?' ':i;
		std::istringstream is(line);
		ListNode dummy(0);
		ListNode* p = &dummy;
		while(is>>data){
			p->next = new ListNode(data);
			p = p->next;
		}
		ListNode* ans = s.reverseKGroup(dummy.next, n);
		while(ans!=NULL){
			std::cout<<ans->val<<"->";
			ans = ans->next;
		}
	}
}
