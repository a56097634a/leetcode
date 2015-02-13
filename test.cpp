/*
 * test.cpp
 *
 *  Created on: Jan 20, 2015
 *      Author: Tianming
 */

#include <cstdio>
#include <iostream>
#include "test.h"
#include <stack>
#include <vector>
#include <map>
#include <iterator>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };




class TwoSum {
	//use hashtable
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> result;
    	unordered_map<int, int> hash;
        if(numbers.empty()) return result;

        for(int i=0; i<numbers.size(); i++){
        	hash.insert(pair<int, int>(numbers.at(i), i));
        	//cout<<hash.at(numbers.at(i));
        	unordered_map<int, int>::iterator it = hash.find(target-numbers.at(i));
        	if(it!=hash.end() && (numbers[i] + it->first) == target && i>it->second){
        		result.push_back(it->second);
        		result.push_back(i);
        		break;
        	}
        }
        return result;
    }
};

class ThreeSum {
	//sort first, then use pointer from both side
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size()<3) return result;
        sort(num.begin(), num.end());
        //int size = num.size();

        auto last = num.end();
        for(auto i=num.begin(); i<last-2; i++){
        	int target = -(*i);
        	auto start=i+1;
        	if(i>num.begin() && *i==*(i-1)) continue;
        	auto end=last-1;
        	while(start<end){
        		int sum=*start+*end;
        		if(sum<target){
        			start++;
        			while(*start<*end && *start==*(start-1)) start++;
        		}
        		else if(sum>target){
        			end--;
        			while(*start<*end && *end==*(end+1)) end--;
        		}
        		else{
        			result.push_back({*i, *start, *end});
        			start++;
        			end--;
        			while(*start<*end && *start==*(start-1) && *end==*(end+1)){
        				start++;
        				end--;
        			}
        		}
        	}
        }

        return result;
    }
};

class FourSum{
	//combination 3 sum and hash table
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if(num.size()<4) return result;
        sort(num.begin(), num.end());
        unordered_map<int, vector<int>> hash;
        auto last=num.end();
        for(auto i=num.begin(); i!=last-3; i++){

        }
    }
};

class StringToInt{
	//input case: empty/null, out of boarder, begin with other character, special: "+","-","+-"
public:
    int atoi(const char *str) {
        if(str==NULL || !*str) return 0;
        int result=0;
        int i=0;
        bool positive=true;
        bool setFlag=false;
        while(str[i]!='\0'){
        	if(str[i]==32){
        		if(setFlag){
        			break;
        		}
        		i++;
        	}
        	else if(str[i]==43){
        		if(setFlag){
        			return 0;
        		}
        		positive=true;
        		i++;
        		setFlag=true;
        	}
        	else if(str[i]==45){
        		if(setFlag){
        			return 0;
        		}
        		positive=false;
        		i++;
        		setFlag=true;
        	}
        	else if(str[i]>=48 && str[i]<=57){
        		setFlag=true;
        		int dig=0;
        		switch(str[i]){
        		case 48:
        			dig=0;
        			break;
        		case 49:
        			dig=1;
        			break;
        		case 50:
        			dig=2;
        			break;
        		case 51:
        			dig=3;
        			break;
        		case 52:
        			dig=4;
        			break;
        		case 53:
        			dig=5;
        			break;
        		case 54:
        			dig=6;
        			break;
        		case 55:
        			dig=7;
        			break;
        		case 56:
        			dig=8;
        			break;
        		case 57:
        			dig=9;
        			break;
        		}
        		long int temp=result*10+dig;
        		long int test=(temp-dig)/10;
        		if(!positive && test!=result){
        			return INT_MIN;
        		}
        		else if(positive && test!=result){
        			return INT_MAX;
        		}
        		else{
        			result=(int)temp;
        			i++;
        		}
        	}
        	else{
        		break;
        	}
        }
        if(positive){
        	return result;
        }
        else{
        	return -result;
        }
    }
};

class MedianTwoSortedArray{
	//assume the input is right
public:
    int midPoint(int min, int max){
    	return (max-min)/2;
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	//special case
    	if(A==NULL && B==NULL) return 0;
        if(!m && !n) return 0;

        if(!m || A==NULL){
        	if(n%2) return B[n/2];
        	else return (B[n/2]+B[n/2-1])/2;
        }
        if(!n || B==NULL){
        	if(m%2) return A[m/2];
        	else return (A[m/2]+A[m/2-1])/2;
        }

        //normal case
        int minA=0, maxA=m-1, minB=0, maxB=n-1;
        int median=(m+n)/2-1;
        while(median!=1){
        	int indexA=midPoint(minA, maxA);
        	int midA=A[indexA];
        	int indexB=midPoint(minB, maxB);
        	int midB=B[indexB];

        	if(indexB==0){
        		return A[indexA];
        	}
        	else if(indexA==0){
        		return B[indexB];
        	}

        	if(midB==midA){
        		return (double)midA;
        	}
        	if(midA<midB){
        		minA=indexA+1;
       		}
        	else if(midA>midB){
        		minB=indexB+1;
        	}
        }
       }


};

class GrayCode{
public:
    vector<int> grayCode(int n) {
    	this->max=exp2(n);
    	this->input=n;
    	this->flag=vector<bool>(max,0);
    	this->result.push_back(0);
    	flag[0]=true;
        if (n==0){
        	return this->result;
        }
        dfs(0, 1);
        return this->result;

    }
private:
    vector<int> result;
    vector<bool> flag;
    int max,input;
    void dfs(int num, int count){
    	//cout<<num<<endl;
    	if(count==max){
    		//cout<<count<<endl;
    		return;
    	}
    	int next;
    	for(int j=0; j<input; j++){
    		if(!(num&(1<<j))){
    			next=num|(1<<j);
    			//cout<<num<<" set "<<j<<" to 1 "<<next<<endl;
    		}
    		else{
    			next=num&(~(1<<j));
    			//cout<<num<<" set "<<j<<" to 0 "<<next<<endl;
    		}
    		if(flag[next]) continue;
    		result.push_back(next);
    		flag[next]=true;
    		break;
    	}
    	dfs(next, count+1);
    }
};

class AddTwoNumbers{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==NULL && l2==NULL){
        	return  new ListNode(0);
        }
        return add(0, l1, l2);
    }
private:

    ListNode * add(int carry, ListNode *l1, ListNode *l2){
    	ListNode * result= new ListNode(1);
    	if(l1==NULL && l2==NULL){
    		if(carry){
    			result->val=1;
    			return result;
    		}
    		else{
    			return NULL;
    		}
    	}
    	else if(l2==NULL){
    		int tmp=l1->val+carry;
    		result->val=tmp%10;
    		int c=tmp/10;
    		result->next=add(c, l1->next, NULL);

    	}
    	else if(l1==NULL){
    		int tmp=l2->val+carry;
    		result->val=tmp%10;
    		int c=tmp/10;
    		result->next=add(c, NULL, l2->next);
    	}
    	else{
    		int tmp=l1->val+l2->val+carry;
    		result->val=tmp%10;
    		int c=tmp/10;
    		result->next=add(c, l1->next, l2->next);
    	}
    }
};

class ReverseInteger{
public:
    int reverse(int x) {
        if(!x || x>INT_MAX || x<INT_MIN){
        	return 0;
        }
        int tmp=abs(x);
        int result=0;
        while(true){
        	if(!tmp){
        		break;
        	}
        	int test=result*10+tmp%10;
        	if((test-tmp%10)/10 != result){
        		return 0;
        	}
        	result=test;
        	tmp=tmp/10;
        }
        if(x>0) return result;
        return -(result);
    }
};

class ContainerWithWater{
public:
    int maxArea(vector<int> &height) {
    	if(height.size()<2) return 0;
    	int tmin=0;
    	int maxArea=0;
    	auto end=height.end()-1;
    	auto start=height.begin();
    	if(*start>=*end) maxArea=*end * (end-start);
    	else maxArea=*start * (end-start);
    	while(start!=end){
    		if(*start>=*end){
    			tmin=*end;
    			int tmp= *end * (end-start);
    			if(tmp>maxArea) maxArea=tmp;
    			//cout<<maxArea<<endl;
    			end--;
    		}
    		else if(*start<*end){
    			tmin=*start;
    			int tmp= *start * (end-start);
    			if(tmp>maxArea) maxArea=tmp;
    			//cout<<maxArea<<endl;
    			start++;
    		}
    	}
    	return maxArea;
    }
};

class LongestCommonPrefix{
public:
    string longestCommonPrefix(vector<string> &strs) {
    	if(strs.empty()) return "";

        string result=*(strs.begin());
        for(int i=0; i<result.size(); i++){
        	//cout<<result[i]<<endl;
        	auto it=strs.begin()+1;
        	while(it!=strs.end()){
        	//cout<<i<<endl;
        	 if((*it)[i]!=result[i]) return result.substr(0, i);
        	 it++;
        	}
        }
        return result;
    }
};

class ValidParenthese{
public:
    bool isValid(string s) {
    	if(s.size()<2) return false;
    	if(s.size()%2) return false;
    	stack<char> stack;
    	for(auto it=s.begin(); it!=s.end();it++){
    		if((*it)=='(' || (*it)=='[' || (*it)=='{'){
    			stack.push(*it);
    		}
    		else{
    			if(stack.size()==0) return false;
    			char tmp=stack.top();
    			//cout<<"tmp: "<<tmp<<endl;
    			if((*it)==')'){
    				if(tmp!='(') return false;
    				stack.pop();
    			}
    			else if((*it)==']'){
    				if(tmp!='[') return false;
    				stack.pop();
    			}
    			else if((*it)=='}'){
    				if(tmp!='{') return false;
    				stack.pop();
    			}
    		}
    	}
    	if(stack.size()!=0) return false;
    	return true;
    }
};

class LongestSubstringWithoutRepeating{
public:
	//a very easy DP problem:
	//for each s[i]:
	//	read the position of last same character and if it bigger than the last start position
	//		update the start position and
	//		keep the max length between each two of them
	//	keep updating the character position due to duplicates;
    int lengthOfLongestSubstring(string s) {
    	if(s.size()<2) return s.size();
    	const int size=256;
    	int hash[size];
    	int result=0;
    	int start=0;

    	fill(hash, hash+size, -1);

    	for(int i=0;i<s.size();i++){
    		if(hash[(int)s[i]]>=start){
    			result=max(i-start, result);
    			start=hash[(int)s[i]]+1;
    		}
    		hash[(int)s[i]]=i;
    	}
    	return max((int)s.size()-start, result);
    }
};

class MergeLists {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	if(lists.empty()) return nullptr;
    	//ListNode *p=lists[0];
    	while(true){
    	//merge 2 lists at once if left one keep that
    	if(lists.size()==1) {
    		if(lists[0]==nullptr) return nullptr;
    		ListNode *p=new ListNode(lists[0]->val);
    		p->next=lists[0]->next;
    		cout<<p->val<<endl;
    		return p;
    	}
    	vector<ListNode *> next;
        for(int i=0;i+1<lists.size();i+=2){
        	if(lists[i]==nullptr && lists[i+1]==nullptr) continue;
        	ListNode *p=mergeTwoLists(lists[i], lists[i+1]);
        	next.push_back(p);
        }
        if(lists.size()%2 && lists[lists.size()-1]!=nullptr){
        	ListNode *p=lists[lists.size()-1];
        	next.push_back(p);
        }
        if(next.empty()){
        	return nullptr;
        }
        else{
        	lists=next;
        }
    	}
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        //if(l1==NULL && l2==NULL) return NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;

        ListNode * result=new ListNode(0);
        if(l1->val<=l2->val){
        	result->val=l1->val;
        	result->next=mergeTwoLists(l1->next,l2);
        }
        else{
        	result->val=l2->val;
        	result->next=mergeTwoLists(l1, l2->next);
        }
        return result;
    }
};

class RemoveDuplicates{
public:
    int removeDuplicates(int A[], int n) {
    	if(n==0) return 0;
    	int rep=A[0];
    	int result=1;
    	int j=1;
    	for(int i=1;i<n;){
    		//cout<<i<<" ";
    		if(A[i]>rep){
    			rep=A[i];
    			//cout<<rep<<endl;
    			i++;
    			j++;
    			result++;
    		}
    		else{
    			if(j==n) break;
    			while(j<n){
    				if(A[j]>rep){
    					//cout<<A[j]<<endl;
    					A[i]=A[j];
    					rep=A[j];
    					i++;
    					j++;
    					result++;
    					break;
    				}
    				j++;
    			}

    		}
    	}
    	return result;
    }
    int removeDuplicates2(int A[], int n){
    	if(n<=2) return n;
    	int rep=A[0];
    	int j=1;
    	int pos=0;
    	int i=1;
    		//cout<<i<<" ";
    	while(i<n){
    		if(A[i]>rep){
        		rep=A[i];
    			pos=i;
        		i++;
        		j++;
    			}
    		else if((A[i]==A[i-1] && i-pos==1)){
    			i++;
    			j++;
    			continue;
    		}
    		else{
    			break;
    		}
    			//cout<<rep<<endl;
    	}
    	cout<<i<<endl;
    	if(i==n) return n;
    	if(i==n-1) return n-1;

    	while(i<n){
    		//cout<<j<<endl;
    		if(j>=n) break;
    		while(j<n){
    			if(A[j]>rep){
    				cout<<i<<"put to"<<A[j]<<endl;
    				A[i]=A[j];
    				rep=A[j];
    					//pos=i;
    				i++;
    				j++;
    				if(j==n) break;
    				if(A[j]==rep){
    					cout<<i<<"put to"<<A[j]<<endl;
    					A[i]=A[j];

    					i++;
    					j++;
    				}
    					//cout<<result<<endl;
    				break;
    			}
    		j++;
    		//i++;
    	}
   	}
   	return i;
   }
};

class BestTimeBuyStock{
public:
	//multiple transactions
    int maxProfitMany(vector<int> &prices) {
        if(prices.size()<2) return 0;
        int result=0;
        for(auto it=prices.begin();it!=(prices.end()-1);it++){
            if(*it<*(it+1)) result+=*(it+1)-*it;
        }
        return result;
    }

    //one transaction
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2) return 0;
        if(prices.size()==2 && prices[0]<prices[1]) return prices[1]-prices[0];
        else if(prices.size()==2) return 0;
        int result=0;
        for(auto it=prices.begin();it!=(prices.end()-1);it++){
        	//cout<<*it<<endl;
            if(*it<*(it+1)){
                //result+=*(it+1)-*(it);
                //cout<<check<<endl;
                //result+=check;
                int check=*(it+1)-*(it);
                if(check>result) result=check;
                auto j=it+1;
                while(j!=(prices.end()-1)){
                	//cout<<check<<endl;
                    check+=*(j+1)-*(j);
                    if(check>result) result=check;
                    if(check<0){
                    	//cout<<"123"<<endl;
                        it=j;
                        break;
                    }
                    j++;
                    it++;
                }
                //if(j==(prices.end()-1)) it=j;
            }
        }
        return result;
    }

    //two transactions
    int maxProfit2(vector<int> &prices) {

    }
};

class SwapNodes{
public:
	//using fake head
	ListNode *swapPairs(ListNode *head) {
	    if (head == NULL || head->next == NULL)
	        return head;

	    ListNode* cur = head->next;
	    ListNode* prev = head;
	    ListNode* pprev = NULL;

	    head = cur;
	    while (prev && cur) {
	        if (pprev) // head case
	            pprev->next = cur;

	        prev->next = cur->next;
	        cur->next = prev;

	        pprev = prev;
	        prev = prev->next;
	        if (prev == NULL) // tail case
	            break;

	        cur = prev->next;

	    }
	    return head;
	}
};

class GenerateParentheses{
public:
    vector<string> generateParenthesis(int n) {

        if(n<1) return result;
        max=n;
        dfs("", 0, 0);
        return result;
    }
private:
    int max;
    vector<string> result;
    void dfs(string s, int l, int r){
    	if(l==max) {
    		result.push_back(s.append(l-r, ')'));
    		return;
    	}
    	dfs(s+'(', l+1, r);
    	if(l>r) dfs(s+')', l, r+1);
    }
};

class isValidBST1{
public:
    bool isValidBST(TreeNode *root) {
        if(root==nullptr) return true;
        vector<int> result;
        travel(result, root);
        cout<<"stop"<<endl;
        for(auto it=result.begin(); it!=result.end()-1; it++){
            if(*(it+1)<=*it) return false;
        }
        return true;
    }
private:
    void travel(vector<int> &result, TreeNode * node){
    	if(node==nullptr) return;
        if(node->left==nullptr && node->right==nullptr){
            result.push_back(node->val);
            return;
        }
        //cout<<"123"<<endl;
        travel(result, node->left);
        cout<<"1"<<endl;
        result.push_back(node->val);
        cout<<"2"<<endl;
        travel(result, node->right);
        cout<<"3"<<endl;
    }
};

class BinarySearch{
public:
    int search(int A[], int n, int target) {
        if(n==0) return -1;
        int start=0;
        int end=n-1;
        int mid=(start+end)/2;
        while(start<=end){
        	cout<<mid<<endl;
            if(A[mid]==target) return mid;
            if(A[start]<=A[mid]){
                if(A[mid]>target && target>=A[start]) end=mid-1;
                else start=mid+1;
            }
            else{
                if(A[mid]<target && target<=A[end]) start=mid+1;
                else end=mid-1;

            }
            mid=(start+end)/2;
        }
        return -1;
    }
};
void ReverseString(char s[]);
int main(){
printf("Tianming's Tests\n");
//TreeNode *root=new TreeNode(0);
//TreeNode *left=new TreeNode(-1);
//root->left=left;
//isValidBST1 * i= new isValidBST1();
//cout<<i->isValidBST(root)<<endl;
//int A[]= {1,3,5};
//BinarySearch *s=new BinarySearch();
//cout<<s->search(A, 3, 1)<<endl;
//MergeLists * m = new MergeLists();
//RemoveDuplicates * r= new RemoveDuplicates();
//int A[]= {0,0,1,1,2,3,3,4};
//BestTimeBuyStock * b = new BestTimeBuyStock();
//vector<int> B({2,1,2,0,1});
//cout<<b->maxProfit(B)<<endl;
//bool x=false&true;
//cout<<x;
//cout<<r->removeDuplicates2(A, 8)<<endl;
//vector<ListNode *> v;
//v.push_back(new ListNode(2));
//v.push_back({});
//v.push_back(new ListNode(1));
//cout<<123<<endl;
//cout<<m->mergeKLists(v)->val<<endl;
//GenerateParentheses * g = new GenerateParentheses();
//cout<<g->generateParenthesis(1)[0]<<endl;
//LongestSubstringWithoutRepeating * v= new LongestSubstringWithoutRepeating();
//cout<<v->lengthOfLongestSubstring("bbbbbb")<<endl;
//LongestCommonPrefix * l=new LongestCommonPrefix();
//vector<string> * strs= new vector<string>({"abc", "aac"});
//cout<<l->longestCommonPrefix(*strs)<<endl;

//ContainerWithWater * c=new ContainerWithWater();
//vector<int> * h = new vector<int>({4,5,6,1,6,4,1,6,3});
//cout<<c->maxArea(*h)<<endl;
//ReverseInteger * s=new ReverseInteger();
//cout<<s->reverse(1534236469)<<endl;
//s->addTwoNumbers()

//GrayCode * g=new GrayCode();
//vector<int> result = g->grayCode(4);
//for(auto it=result.begin(); it!=result.end(); it++){
//	cout<<*it<<endl;
//}
//MedianTwoSortedArray * s = new MedianTwoSortedArray();
//int a[]={1,3,5,7,8};
//int b[]={-1,0,2,6,9,10};
//cout<<s->findMedianSortedArrays(a,5,b,4)<<endl;

//int nums[] = {-1,0,1,2,-1,-4};
//int nums[]={0,0,-1,0,1};
//vector<int> * num = new vector<int>(nums, nums + sizeof(nums) / sizeof(int));
//const char* str="10522545459";
//string s = "--123a1";
//cout<<stoi(s)<<endl;
//StringToInt * a = new StringToInt();
//cout<<a->atoi(str)<<endl;
//TwoSum * s = new TwoSum();
//s->twoSum(*num, 6);
//ThreeSum * s=new ThreeSum();
//vector<vector<int> > result = s->threeSum(*num);
//vector<int> tmp = result.at(0);
//cout<<tmp[0]<<tmp[1]<<tmp[2]<<endl;
//cout<<result.size()<<endl;
//cout<< s->twoSum(*num, 6).at(0)<<endl;
//cout<< s->twoSum(*num, 6).at(1)<<endl;

//string s="123";
//char * n=new char(s.size()+1);
//copy(s.begin(), s.end(), n);
//n[s.size()]='\0';
//ReverseString(n);
//cout<<n[0]<<endl;

//cout<<c[1]<<endl;
return 0;

}
void ReverseString(char * s){
	if(s[0]=='\0') return;
	int end=0;
	while(s[end]!='\0'){
		//cout<<s[end]<<endl;
		end++;
	}
	end--;
	for(int i=0; i<=end;){
		char tmp=s[i];
		s[i]=s[end];
		s[end]=tmp;
		//cout<<s[i]<<endl;
		i++;
		end--;
	}
	//return s;
}


