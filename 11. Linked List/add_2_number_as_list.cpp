#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* addTwoNumbers(ListNode* A, ListNode* B) {

	if(!A) return B;
	if(!B) return A;

	int carry = 0;
	ListNode* head = NULL;
	ListNode* last = head;
	
	while(A and B){
		int sum = A->val + B->val + carry;
		carry = sum/10;
		
		ListNode* t = new ListNode(sum%10);
		
		if(head == NULL) {
			head = t; last = head;
		}
		else {
			last->next = t;
			last = last->next;
		}

		A = A->next;
		B = B->next;
	}

	while(A){
		int sum = A->val + carry;
		carry = sum/10;

		ListNode* t = new ListNode(sum%10);

		last->next = t;
		last = last->next;
		
		A = A->next;
	}

	while(B){
		int sum = B->val + carry;

		carry = sum/10;
		
		ListNode* t = new ListNode(sum%10);

		last->next = t;
		last = last->next;

		B = B->next;
	}

	if(carry != 0){
		ListNode* t = new ListNode(carry);
	    last->next = t;
	}

	return head;
}
