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
	ListNode* rotate(ListNode* head, int k){
		if(k<=1) return head;
		ListNode* tail = head;
		for(int i=0; i<k-1; i++){
			tail = tail->next;
			if(!tail) return head;
		}
		ListNode* prev = head->next;
		tail->next = head;
		return rotate(head->next, --k);
	}
    ListNode* reverseKGroup(ListNode* head, int k) {
		if(k<=1||!head) return head;
		ListNode* tail = head;
		for(int i=0; i<k-1; i++){
			tail = tail->next;
			if(!tail) return head;
		}
		ListNode* prev = head->next;
		head->next = reverseKGroup(tail->next, k);
		tail->next = head;
		return prev;

		ListNode* tail;
		ListNode* current = tail;
		ListNode* prev;
		current->next = prev;

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
