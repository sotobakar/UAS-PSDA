//Patrick Santino
//NIM 1910512012 Kelas A PSDA
//pet.santino@gmail.com
//Dosen Pak Solihin
//Tugas Pengganti UAS PSDA
//Saya berjanji mengerjakan secara Jujur tanpa menyontek Orang lain dan seluruh source code tidak berasal dari pekerjaan orang lain
//Apabila ada yang sama murni kebetulan mungkin karna cara penulisan
#include<iostream>
#include<string>
using namespace std;
struct Node
{
	Node*left,*right;
	int val;
	Node(int val):left(NULL),right(NULL),val(val){}
};
class BinaryTree
{

	Node* root;
	int count;
	void inorder(Node* r)
	{
		if(r==NULL) return;
		else
		{
			inorder(r->left);
			cout << r->val<<endl;
			inorder(r->right);
		}		
	}
	void preorder(Node* r)
	{
		if(r==NULL) return;
		else {
			cout << r->val<<endl;
			preorder(r->left);
			preorder(r->right);
		}
	}
	void postorder(Node* r)
	{
		if(r==NULL) return;
		else {
			postorder(r->left);
			postorder(r->right);
			cout << r->val<<endl;
		}
	}
public:
	BinaryTree():root(NULL),count(0){}
	void insert(int item)
	{
		Node*  current;
		Node*  trailing;
		Node* data = new Node(item);
		if(root==NULL)
			root = data;
		else
		{
			current = root;
			while (current!=NULL)
			{
				trailing=current;
				if(item < current->val)
				{
					current = current->left;
				}
				else
				{
					current = current->right;
				}
			}
			if(item < trailing->val)
				trailing->left = data;
			else
				trailing->right = data;
			count++;
		}
	}
	int getCount() const
	{
		return count;
	}
	void inOrder()
	{
		inorder(root);
	}
	void preOrder()
	{
		preorder(root);
	}
	void postOrder()
	{
		postorder(root);
	}
	int getMax() 
	{
		Node* ptr = root;
		while (ptr->right!=NULL)
		{
			ptr = ptr->right;
		}
		return ptr->val;
	}
	int getMin()
	{
		Node* ptr = root;
		while (ptr->left!=NULL)
		{
			ptr = ptr->left;
		}
		return ptr->val;
	}
	void removeNode(Node* &p)
	{
		Node *current,*trailing,*temp;
		if(p==NULL) cerr << "Can not remove from empty tree (1)"<<endl;
		else if(p->left == NULL && p->right==NULL){
			temp = p;
			p=NULL;
			delete temp;
			cout << "Case 1: Tidak memiliki anak"<<endl;
		}
		else if(p->left==NULL){
			temp = p;
			p = p->right;
			delete temp;
			cout << "Case 2a: Tidak ada Anak Kiri"<<endl;
		}
		else if(p->right==NULL){
			temp = p;
			p = p->left;
			delete temp;
			cout << "Case 2b: Tidak ada Anak Kanan"<<endl;
		}

		else {
			cout << "Case 3: Memiliki 2 Anak"<<endl;
			current = p->left;
			trailing = NULL;
			while (current->right != NULL)
			{
				trailing=current;
				current = current->right;
			}
			p->val = current->val;
			if(trailing==NULL)
				p->left = current->left;
			else
				trailing->right = current->left;
			delete current;
		}
	
	}
	void remove(int item)
	{
		Node* current,*trailCurrent;
		bool found = false;
		if(root == NULL) cout << "No cookie for you"<<endl;
		else {
			current=root;
			while(current != NULL && !found){
				if(current->val == item)
					found = true;
				else {
					trailCurrent=current;
					if(item < current->val)
						current = current->left;
					else
						current = current->right;
				}
			}
			if(current==NULL)
				cout << "Node to be deleted is not in tree"<<endl;
			else if(found)
			{
				if(current==root)
					removeNode(root);
				else if(item < trailCurrent->val)
					removeNode(trailCurrent->left);
				else removeNode(trailCurrent->right);
			}
		}//else block ends
	}
	
	void find(int item)
	{
		Node* current,*trailCurrent;
		bool found = false;
		if(root == NULL) cout << "ROOT NOT FOUND!"<<endl;
		else {
			current=root;
			while(current != NULL && !found){
				if(current->val == item)
					found = true;
				else {
					trailCurrent=current;
					cout<<trailCurrent->val<<" -> ";
					if(item < current->val)
						current = current->left;
					else
						current = current->right;
				}
			}
			if(current==NULL)
				cout << "\nNode TIDAK DITEMUKAN"<<endl;
			else if(found)
				cout << item;
				cout << "\nNode "<<item<<" DITEMUKAN"<<endl;	
		}//else block ends
	}
	
	void deltree(Node** r)
	{
	    if (*r!=NULL)
	    {
	        deltree(&(*r)->left);
	        deltree(&(*r)->right);
	        delete(*r);
	        *r=NULL;
	    }
	}
	
	void reset(){
		deltree(&root);
	}

};
int main()
{
	BinaryTree bt;
	
	while (true)
	{
		int choice;
		int val;
		cout << "1) For adding   a new Node"<<endl;
		cout << "2) For removing a node"<<endl;
		cout << "3) Cetak Inorder "<<endl;
		cout << "4) Cetak Preorder "<<endl;
		cout << "5) Cetak Postorder "<<endl;
		cout << "6) Pencarian Bilangan "<<endl;
		cout << "7) Cetak Bilangan Terbesar "<<endl;
		cout << "8) Cetak Bilangan Terkecil "<<endl;
		cout << "9) Reset BST "<<endl;
		cout << "0) QUIT "<<endl;
		cin>>choice;
		if(choice==1||choice==2||choice==6){
			cout << "Masukkan Angka : ";cin>>val;
		}
		if (choice==1) bt.insert(val);
		else if(choice==2) bt.remove(val);
		else if(choice==3) bt.inOrder();
		else if(choice==4) bt.preOrder();
		else if(choice==5) bt.postOrder();
		else if(choice==6) bt.find(val);
		else if(choice==7){
			cout << "Bilangan Terbesar pada Pohon adalah : "<< bt.getMax()<<endl;		
		}else if(choice==8){
			cout << "Bilangan Terkecil pada Pohon adalah : "<<bt.getMin()<<endl;
		}else if(choice==9) bt.reset();
		else if(choice==0) break;
	}
	return 0;
}
