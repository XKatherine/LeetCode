#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1==NULL || l2==NULL)
			return l1==NULL?l2:l1;
		ListNode* ans = new ListNode(min(l1->val,l2->val));
		l1->val<l2->val?l1=l1->next:l2=l2->next;
		ListNode* p = ans;
		while(l1!=NULL && l2!=NULL){	
			int valu;
			if(l1->val<l2->val){
				valu = l1->val;
				l1 = l1->next;
			}else{
				valu = l2->val;
				l2 = l2->next;
			}
			ListNode* temp = new ListNode(valu);
			p->next = temp;
			p = temp;
		}
		if(l1!=NULL)
			p->next = l1;
		if(l2!=NULL)
			p->next = l2;
		return ans;
    }
};

int main(){
	Solution s;
	string line1, line2;
	while(getline(cin,line1)){
		getline(cin,line2);
		istringstream is(line1);
		istringstream ss(line2);
		int n1,n2;
		is>>n1;
		ss>>n2;
		ListNode* head1 = new ListNode(n1);
		ListNode* head2 = new ListNode(n2);
		ListNode* p = head1;
		while(is>>n1){
			ListNode* temp = new ListNode(n1);
			p->next = temp;
			p = temp;
		}
		p = head2;
		while(ss>>n2){
			ListNode* temp = new ListNode(n2);
			p->next = temp;
			p = temp;
		}
		p = s.mergeTwoLists(head1, head2);
		while(p!=NULL){
			cout<<p->val<<"->";
			p = p->next;
		}
		cout<<endl;
	}
}
