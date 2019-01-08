#include<iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<ListNode*> v;
		ListNode* p = head;
		while(p!=NULL){
			v.push_back(p);
			p = p->next;
		}
		int size = v.size();
		if(size==n)
			return (head==NULL)?NULL:head->next;
		v[size-n-1]->next = v[size-n-1]->next->next; 
		return head;
    }
};

int main(){
	Solution s;
	string line;
	while(getline(cin,line)){
		istringstream is(line);
		vector<int> v;
		int n, temp;
		cin>>n;
		while(is>>temp){
			v.push_back(temp);
		}
		ListNode* l = new ListNode(v[0]);
		ListNode* p = l;
		for(int i=1; i<v.size(); i++){
			ListNode* l1 = new ListNode(v[i]);
			l->next = l1;
			l = l1;
		}
		p = s.removeNthFromEnd(p, n);
		while(p!=NULL){
			cout<<p->val<<"->"<<endl;
			p = p->next;
		}
	}
}
