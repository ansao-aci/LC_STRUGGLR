#include<iostream>
#include<memory>

using namespace std;


template <typename T>
struct  ListNode{
    T val;
    shared_ptr<ListNode<T>>  next;
    ListNode(){}
    ListNode(T t) : val(t){}
    ListNode(T t, shared_ptr<ListNode<int>> n): val(t), next(n){}
};


namespace ll {

class Solution{

    public:

    shared_ptr<ListNode<int>>current;

    static void print(shared_ptr<ListNode<int>> head);

    static shared_ptr<ListNode<int>> reverse1(shared_ptr<ListNode<int>> head);
    static shared_ptr<ListNode<int>> reverse2(shared_ptr<ListNode<int>> head);

    shared_ptr<ListNode<int>> delNthLast(shared_ptr<ListNode<int>> head, int n);

    static shared_ptr<ListNode<int>> mergeSorted(shared_ptr<ListNode<int>>l1, shared_ptr<ListNode<int>> l2);

    void printRev(shared_ptr<ListNode<int>>head);

    bool isPalindrome(shared_ptr<ListNode<int>>head);

    bool containsCycle(shared_ptr<ListNode<int>>head);

    size_t cycleSize(shared_ptr<ListNode<int>>head);

    static shared_ptr<ListNode<int>> reverseSublist(shared_ptr<ListNode<int>> head, int start, int finish);

};

    // N  = C->next;
    // Tmp = C->next->next;
    
    // C->next = P;
    // N->next = C;

    // C = Tmp;
    // P = N;


    // 1 > 2 < 3 < 4 < 5  6 
    // 1 > 2 > 5 > 4 > 3 > 6 
    // 
    shared_ptr<ListNode<int>>  Solution::reverseSublist(shared_ptr<ListNode<int>> head, int start, int finish){
        auto dummy_head  = make_shared<ListNode<int>>(ListNode{0, head});
        return dummy_head;
        
    }
    
bool Solution::containsCycle(shared_ptr<ListNode<int>>head){
    if (!head || !head->next) return false;

    shared_ptr<ListNode<int>>slow = head, fast  = head;
    while (fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

/*
  
  1 > 2 > 3 > 4 > 5
          |_______|
             
*/

size_t Solution::cycleSize(shared_ptr<ListNode<int>>head){
    return 8;
}


bool Solution::isPalindrome(shared_ptr<ListNode<int>>head){
        if (!head) return true;
        if (!isPalindrome(head->next)) return false;
        if (current->val != head->val) return false;
        current = current->next;
        return true;
}

void Solution::printRev(shared_ptr<ListNode<int>>head){
    if (!head) return;
    printRev(head->next);
    cout << head->val << " > ";
}


void Solution::print(shared_ptr<ListNode<int>> head){
        while(head){
            cout << " --> " << head->val;
            head = head->next;
        }
        cout << endl;
    }

shared_ptr<ListNode<int>> Solution::reverse1(shared_ptr<ListNode<int>> head){
        if (!head || !head->next) return head;

        shared_ptr<ListNode<int>> node = reverse1(head->next);
        head->next->next  = head;
        head->next = nullptr;
        return node;
    }

shared_ptr<ListNode<int>> Solution::reverse2(shared_ptr<ListNode<int>> head){
        auto P = head;
        P = nullptr;
        auto C = head;
        while(C){
            auto N = C->next;
            C->next = P;
            P = C;
            C = N;
        }
        return P;
    }


 shared_ptr<ListNode<int>> Solution::delNthLast(shared_ptr<ListNode<int>> head, int n){
        auto dummy =  make_shared<ListNode<int>> (ListNode<int>{0,head});

        auto t1 = head; auto t2  = dummy;
        while(n--){
            t1 = t1->next;
        }

        while(t1){
            t1 = t1->next;
            t2 = t2->next;
        }
        
        t2->next = t2->next->next;
        return dummy->next;
    }   


shared_ptr<ListNode<int>>Solution::mergeSorted(shared_ptr<ListNode<int>>l1, shared_ptr<ListNode<int>> l2){
        
        auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0,nullptr});

        auto t1 = dummy_head;
        while(l1 && l2){
            t1->next = l1->val > l2->val ? l2 : l1;  
            if (l1->val < l2->val) l1 = l1->next;
            else l2 = l2->next;
            t1 = t1->next;
        }
        t1->next  =  l1 ? l1: l2;
        return dummy_head->next;
    }


}
/*class Solution
{
public:
    shared_ptr<ListNode<int>> removeNthFromEnd(shared_ptr<ListNode<int>> head, int n)
    {
        shared_ptr<ListNode<int>> t1 = &head, t2 = head;
        for(int i = 1; i < n; ++i)
        {
            t2 = t2->next;
        }
        while(t2->next != NULL)
        {
            t1 = &((*t1)->next);
            t2 = t2->next;
        }
        auto t = (*t1);
        *t1 = (*t1) ->next;
        delete t;
        

        return head;
    }
}; */



/*
use double ptr when: 
1. you want to delete a node in  singly linked list.
2. when you want to free the memory of node pointed by ptr and point ptr to some other node

*/