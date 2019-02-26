#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
		ListNode dummy(0);
		dummy.next = head;
		ListNode*p = &dummy;
		while(p->next){
			if(--m == 0){
				ListNode* lastOne = p->next;
				ListNode* next = p->next->next->next;
				ListNode* cur = p->next->next;
				ListNode* prev = p->next;
				while(--n > 0){
					cur->next = prev;
					prev = cur;
					cur = next;
					next = next == NULL ? NULL : next->next;
				}
				p->next = prev;
				lastOne->next = cur;
                break;
			}
			--n;
			p = p->next;
		}
		return dummy.next;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin,line)){
		replace(line.begin(), line.end(), '-', ' ');
		replace(line.begin(), line.end(), '>', ' ');

		istringstream is(line);
		ListNode dummy(0);	
		ListNode* p = &dummy;
		int m, n;
		while(is >> n){
			p->next = new ListNode(n);
			p = p->next;
		}

		getline(cin,line);
		istringstream ist(line);

		ist >> m >> n;

		p = s.reverseBetween(dummy.next, m, n);
		while(p){
			cout<<p->val<<"->";
			p = p->next;
		}
	}
}
