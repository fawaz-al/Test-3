#include <iostream>

using namespace std;

// Deklarasi Single Linked List
struct buku{
    string judul, pengarang;
    int thnTerbit;
    buku *next;
};

buku *head, *tail, *cur, *newNode, *del, *before;

void CreateSingleLinkedList(string judul, string pengarang, int thnTerbit){
    head = new buku();
    head->judul = judul;
    head->pengarang = pengarang;
    head->thnTerbit = thnTerbit;
    head->next = NULL;
    tail = head;
}

void AddFirstSingleLinkedList(string judul, string pengarang, int thnTerbit){
    newNode = new buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->thnTerbit = thnTerbit;
    newNode->next = head;
    head = newNode;
}

void AddLastSingleLinkedList(string judul, string pengarang, int thnTerbit){
    newNode = new buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->thnTerbit = thnTerbit;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void AddMiddleLinkedList(string judul, string pengarang, int thnTerbit, int posisi){
    newNode = new buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->thnTerbit = thnTerbit;
    cur = head;
    int nomor = 1;
    while (nomor < posisi - 1)
    {
        cur = cur->next;
        nomor++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}


void RemoveFirst(){
    del = head;
    head = head->next;
    delete del;
}

void RemoveLast(){
    del = tail;
    cur = head;
    while (cur->next != tail)
    {
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void RemoveMiddle(int posisi){
    int nomor = 1;
    cur = head;
    while (nomor <= posisi)
    {
        if (nomor == posisi-1)
        {
            before = cur;
        }
        if (nomor == posisi)
        {
            del = cur;
        }
        cur = cur->next;
        nomor++;
    }
    before->next = cur;
    delete del;
}

void ChangeFirst(string judul, string pengarang, int thnTerbit){
    head->judul = judul;
    head->pengarang = pengarang;
    head->thnTerbit = thnTerbit;
}

void ChangeLast(string judul, string pengarang, int thnTerbit){
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->thnTerbit = thnTerbit;
}

void ChangeMiddle(string judul, string pengarang, int thnTerbit, int posisi){
    cur = head;
    int nomor = 1;
    while (nomor < posisi)
    {
        cur = cur->next;
        nomor++;
    }
    cur->judul = judul;
    cur->pengarang = pengarang;
    cur->thnTerbit = thnTerbit;
}

void AddMiddleSingleLinkedList(string judul, string pengarang, int thnTerbit, int posisi){
    newNode = new buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->thnTerbit = thnTerbit;
    cur = head;
    int nomor = 1;
    while (nomor < posisi - 1)
    {
        cur = cur->next;
        nomor++;
    }
    
}

void PrintSingleLinkedList(){
    cur = head;
    while (cur != NULL)
    {
        cout << "Judul Buku: " << cur->judul <<endl;
        cout << "Pengarang Buku: " << cur->pengarang <<endl;
        cout << "Tahun Terbit Buku: " << cur->thnTerbit <<endl;
        cur = cur->next;
    }
}

int main(){
    cout << "\n<===== Create Single Linked List =====>\n";
    CreateSingleLinkedList("Tes", "Fulan", 1999);
    PrintSingleLinkedList();
    cout << "\n<===== Add First =====>\n";
    AddFirstSingleLinkedList("Tes_2", "Fulan_2", 2000);
    PrintSingleLinkedList();
    cout << "\n<===== Add Last =====>\n";
    AddLastSingleLinkedList("Tes_3", "Fulan_3", 2001);
    PrintSingleLinkedList();
    cout << "\n<===== Remove First =====>\n";
    RemoveFirst();
    PrintSingleLinkedList();
    cout << "\n<===== Add Last =====>\n";
    AddLastSingleLinkedList("Tes_4", "Fulan_4", 2002);
    PrintSingleLinkedList();
    cout << "\n<===== Remove Last =====>\n";
    RemoveLast();
    PrintSingleLinkedList();
    cout << "\n<===== Change First =====>\n";
    ChangeFirst("Tes_5", "Fulan_5", 2003);
    PrintSingleLinkedList();
    cout << "\n<===== Add Middle =====>\n";
    AddMiddleLinkedList("Tes_6", "Fulan_6", 2004, 2);
    AddMiddleLinkedList("Tes_7", "Fulan_7", 2005, 3);
    PrintSingleLinkedList();
    cout << "\n<===== Remove Middle =====>\n";
    RemoveMiddle(2);
    PrintSingleLinkedList();
    cout << "\n<===== Change Middle =====>\n";
    ChangeMiddle("Tes_8", "Fulan_8", 2006, 2);
    PrintSingleLinkedList();
}