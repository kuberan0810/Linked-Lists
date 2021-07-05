#include <iostream>
#include <string>
using namespace std;

template <typename T>
void template_sum(T d1, T d2){
	cout<<d1+d2<<endl;
}

template <typename T>
class Node{
	T data;
	Node* next;
	public:
	T get_data(){
		return data;
	}
	Node* get_next(){
		return next;
	}
	void set_data(T Data){
		data = Data;
	}
	void set_link(Node* Next){
		next = Next;
	}
	void replace_by_pos(Node* Head,T data, int pos){
		Node* temp = new Node<T>;
		int LL_length = len(Head);
		if(pos>=LL_length&pos!=0){
			cout<<"Enter Valid position. Only "<<LL_length<<" elements are in list"<<endl;
			return;
		}
		temp = Head->get_next();
		for(int i=0;i<pos;i++){
			temp = temp->get_next();
		}
		temp->set_data(data);
		temp = NULL;
		delete temp;
	}
	void delete_by_pos(Node* Head, int pos){
		Node* temp = new Node<T>;
		Node* prev_temp = new Node<T>;
		int LL_length = len(Head);
		if(pos>=LL_length){
			cout<<"Enter Valid position. Only "<<LL_length<<" elements are in list"<<endl;
			return;
		}
		prev_temp = Head;
		temp = Head->get_next();
		for(int i=0;i<pos;i++){
			if(i==pos-1)
				prev_temp = temp;
			temp = temp->get_next();
		}
		prev_temp->set_link(temp->get_next());
		delete temp;
	}
	void insert_tail(Node* Head, T data){
		Node* new_node = new Node<T>;
		new_node->set_data(data);
		new_node->set_link(NULL);
		Node* temp = new Node<T>;
		temp = Head;
		while(temp->get_next()){
			temp = temp->get_next();
		}
		temp->set_link(new_node);
		temp = NULL;
		delete temp;
	}
	void insert_by_pos(Node* Head, T data, int pos){
		int LL_length = len(Head);
		if(pos>=LL_length&pos!=0){
			cout<<"Enter Valid position. Only "<<LL_length<<" elements are in list"<<endl;
			return;
		}
		Node* temp = new Node<T>;
		Node* curr_node = new Node<T>;
		
		curr_node->set_data(data);
		curr_node->set_link(NULL);		
		temp = Head;
		for(int i=0;i<pos;i++){
			temp = temp->get_next();			
		}
		curr_node->set_link(temp->get_next());
		temp->set_link(curr_node);
		temp = NULL;
		delete temp;
	}
	int len(Node* Head){
		Node* temp = new Node<T>;
		int count =0;
		temp = Head->get_next();
		while(temp){
			count++;
			temp = temp->get_next();			
		}
		delete temp;
		return count;
	}
	void print(Node* Head){
		Node* temp = new Node<T>;
		temp = Head->get_next();
		while(temp){
			cout<<temp->get_data()<<" ";
			temp = temp->get_next();
		}
		cout<<endl;
		delete temp;
	}
};

void template_test(){
	int a = 10;
	int b = 20;
	string A = "Kubera ";
	string B = "Murthi";
	template_sum(a,b);
	template_sum(A,B);
}

void str_lst(){
	string b = "kuber";
	Node<string>* head1 = new Node<string>;
	head1->set_data(b);
	head1->set_link(NULL);
	head1->insert_tail(head1,"Kuber");
	head1->insert_by_pos(head1,"Murthi",0);
	head1->insert_by_pos(head1,"HMIL",1);
	head1->insert_tail(head1,"AM");
	head1->print(head1);
	head1->delete_by_pos(head1,2);
	head1->print(head1);
	head1->replace_by_pos(head1,"PA1",2);
	head1->print(head1);
}
void int_lst(){
	int a = 789;
	Node<int>* head = new Node<int>;
	head->set_data(a);
	head->set_link(NULL);
	head->insert_tail(head,1);
	head->insert_by_pos(head,10,0);
	head->insert_by_pos(head,20,1);
	head->insert_tail(head,5);
	head->print(head);
	head->delete_by_pos(head,2);
	head->print(head);
	head->replace_by_pos(head,65,2);
	head->print(head);
}
void char_lst(){	
	char c = 'A';
	Node<char>* head = new Node<char>;
	head->set_data(c);
	head->set_link(NULL);
	head->insert_tail(head,'X');
	head->insert_by_pos(head,'A',0);
	head->insert_by_pos(head,'B',1);
	head->insert_tail(head,'C');
	head->print(head);
	head->delete_by_pos(head,2);
	head->print(head);
	head->replace_by_pos(head,'D',2);
	head->print(head);
}
int main(){
	int_lst();
	str_lst();
	char_lst();
	return 0;
}
