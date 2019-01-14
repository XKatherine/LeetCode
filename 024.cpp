#include<iostream>
#include<sstream>
#include<string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		if(!head || !head->next) return head;
		ListNode* next = head->next;
		head->next = swapPairs(next->next);
		next->next = head;
		return next;
	}
	/*
    ListNode* swapPairs(ListNode* head) {
		ListNode dummy(0);
		dummy.next = head;
		ListNode* p = &dummy;
		while((p)&&(p->next)&&(p->next->next)){
			ListNode* temp = p->next;
			p->next = p->next->next;
			temp->next = p->next->next;
			p->next->next = temp;
			p = temp;
		}
		return dummy.next;
    }
	*/
};

int main(){
	Solution s;
	std::string str;
	while(std::getline(std::cin,str)){
		std::string line = "";
		for(auto i : str)
			line += (i=='-'||i=='>')?' ':i;
		std::istringstream is(line);
		ListNode dummy(INT_MIN); 
		ListNode* p = &dummy;
		int data;
		while(is>>data){
			p->next = new ListNode(data);
			p = p->next;
		}
		p = NULL;
		delete p;
		ListNode* ans = s.swapPairs(dummy.next);
		while(ans!=NULL){
			std::cout<<ans->val<<"->";
			ans = ans->next;
		}
	}
}
//For reference: Smart use of recursion
/*
   class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;

        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;

        return next;
    }
};
*/
