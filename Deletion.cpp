/*Program Deletion Mata Kuliah ASD Tugas 3*/
#include <iostream>
using namespace std;

//deklarasi single link list
struct Buku{
	string judul, pengarang;
	int tahun_terbit;
	
	Buku *next;
};

Buku *head, *tail, *cur, *newNode, *del, *after ;

//create single linked list
void createSingleLinkedList(string judul, string pengarang, int tahun_t){
	head = new Buku();
	head->judul = judul;
	head->pengarang = pengarang;
	head->tahun_terbit = tahun_t;
	head->next = NULL;
	tail = head;
}
//insert first single linked list
void insertFirst(string judul, string pengarang, int tahun_t){
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahun_terbit = tahun_t;
	newNode->next = head;
	head = newNode;
}

//insert last single linked list
void insertLast(string judul, string pengarang, int tahun_t){
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahun_terbit = tahun_t;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
}

//insert before/after single linked list
void insertAfter(string judul, string pengarang, int tahun_t, int posisi){
	newNode = new Buku();
	newNode->judul = judul;
	newNode->pengarang = pengarang;
	newNode->tahun_terbit = tahun_t;
	//transfersing
	cur = head;
	int nomor = 1;
	while(nomor < posisi -1){
		cur =  cur->next;
		nomor++;
	}
	
	newNode->next = cur->next;
	cur->next = newNode;

}

//delete first
void deleteFirst(){
	del = head;
	head = head->next;
	delete del;
}

//delete last
void deleteLast(){
	del = tail;
	cur = head;
	while(cur->next != tail){
		cur = cur->next;
	}
	tail = cur;
	tail->next = NULL;
	delete del;
}

//delete after
void deleteAfter(int posisi){
	int nomor = 1;
	cur = head;
	while(nomor <= posisi){
		if(nomor == posisi -1){
			after = cur;
		}
		if(nomor == posisi){
			del = cur;
		}
		del = cur->next;
		nomor++;
	}
	after->next = cur->next->next;
	delete del;
}

//print single linked list
void printSingleLinkedList(){
	cur = head;
	while(cur != NULL){
		cout<<"Judul Buku : "<<cur->judul<<endl;
		cout<<"Pengarang Buku : "<<cur->pengarang<<endl;
		cout<<"Tahun Terbit Buku : "<<cur->tahun_terbit<<endl;
		
		cur = cur->next;
	}
}

int main(){
	
	createSingleLinkedList("Matematika","Ahmad Sutan",2013);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertFirst("Bahasa Indonesia", "Susi Agustian", 2000);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertLast("Sejarah", "Dian Anwar", 1998);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter("Kebumian", "Ratna Harto", 2004, 3);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter("Manusia", "Abimayu", 2014, 4);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteFirst();
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteLast();
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteAfter(3);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	return 0;

}
