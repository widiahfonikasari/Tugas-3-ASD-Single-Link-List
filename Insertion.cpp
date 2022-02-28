/*Program Insertion Mata Kuliah ASD Tugas 3*/
#include <iostream>
using namespace std;

//deklarasi single link list
struct Buku{
	string judul, pengarang;
	int tahun_terbit;
	
	Buku *next;
};

Buku *head, *tail, *cur, *newNode;

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

//insert after single linked list
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
	
}
