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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		int size = lists.size();
		if(size==0) return nullptr;
		if(size==1) return lists[0];
		for(int interval = 1; interval<size; interval<<=1)
			for(int i = 0; i<size-interval; i+=interval+1){
				ListNode* l1 = lists[i];
				ListNode* l2 = lists[i+interval];
				ListNode dummy(INT_MIN);
				ListNode* p = &dummy;
				while(l1&&l2){
					if(l1->val<l2->val){
						p->next = l1;
						l1 = l1->next;
					}else{
						p->next = l2;
						l2 = l2->next;
					}
					p = p->next;
				}
				if(l1) p->next = l1;
				if(l2) p->next = l2;
				lists[i]=dummy.next;
			}
		return lists[0];
	}


	/* -- Solution by K
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
		if(list1 == NULL || list2 == NULL)
			return list1 == NULL?list2:list1;
		ListNode dummy(INT_MIN);
		ListNode* p = &dummy;
		while(list1!=NULL && list2!=NULL){
			if(list1->val<list2->val){
				p->next = new ListNode(list1->val);
				list1 = list1->next;
			}else{
				p->next = new ListNode(list2->val);
				list2 = list2->next;
			}
			p = p->next;
		}
		p->next = list1==NULL?list2:list1;
		return dummy.next;
	}

	ListNode* divide(vector<ListNode*>& lists, int start,int end){
		if(start>=end)
			return NULL;
		if(start+1==end)
			return lists[start];
		ListNode* l1;
		ListNode* l2;
		if(start<end-2){
			l1 = divide(lists, start, (end+start)/2);
			l2 = divide(lists, (end+start)/2, end);
		}else{
			l1 = lists[start];
			l2 = lists[start+1];
		}
		return merge2Lists(l1,l2);
	}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
		return divide(lists, 0, lists.size());
    }
	*/
};

int main(){
	Solution solu;
	string str;
	while(getline(cin,str)){
		if(str!="[")
			continue;
		vector<ListNode*> v;
		string s;
		while(getline(cin,s)&&s!="]"){
			string line = "";
			for(auto i : s){
				if(i=='-'||i=='>'||i==',')
					i=' ';
				line += i;
			}
			istringstream is(line);
			ListNode dummy(INT_MIN);
			ListNode* p = &dummy;
			int data;
			while(is>>data){
				ListNode* temp = new ListNode(data);
				p->next = temp;
				p = temp;
			}
			v.push_back(dummy.next);
		}
		ListNode* ans = solu.mergeKLists(v);
		while(ans!=NULL){
			cout<<ans->val<<" ";
			ans = ans->next;
		}
	}
}
