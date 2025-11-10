#include <iostream>
using namespace std;

struct DataUser
{
    string nama, username, email, password;
    DataUser *prev;
    DataUser *next;
};

DataUser *head, *tail, *cur, *newNode, *del, *afterNode;

void createDoubleLinkedList(string data[4])
{
    head = new DataUser();
    head->nama = data[0];
    head->username = data[1];
    head->email = data[2];
    head->password = data[3];
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

int countDoubleLinkedList()
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
        return 0;
    }
    else
    {
        cur = head;
        int jumlah = 0;
        while (cur != NULL)
        {
            jumlah++;
            cur = cur->next;
        }
        return jumlah;
    }
}

void addFirst(string data[4])
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        newNode = new DataUser();
        newNode->nama = data[0];
        newNode->username = data[1];
        newNode->email = data[2];
        newNode->password = data[3];
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void addLast(string data[4])
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        newNode = new DataUser();
        newNode->nama = data[0];
        newNode->username = data[1];
        newNode->email = data[2];
        newNode->password = data[3];
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

void addMiddle(string data[4], int posisi)
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {

        if (posisi == 1)
        {
            cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
        }
        else if (posisi < 1 || posisi > countDoubleLinkedList())
        {
            cout << "Posisi diluar jangkauan!!!" << endl;
        }
        else
        {
            newNode = new DataUser();
            newNode->nama = data[0];
            newNode->username = data[1];
            newNode->email = data[2];
            newNode->password = data[3];
            cur = head;
            int nomor = 1;
            while (nomor < posisi - 1)
            {
                cur = cur->next;
                nomor++;
            }
            afterNode = cur->next;
            newNode->prev = cur;
            newNode->next = afterNode;
            cur->next = newNode;
            afterNode->prev = newNode;
        }
    }
}

void removeFirst()
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
}

void removeLast()
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
    }
}

void removeMiddle(int posisi)
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        if (posisi == 1 || posisi == countDoubleLinkedList())
        {
            cout << "Posisi bukan posisi tegah!!" << endl;
        }
        else if (posisi < 1 || posisi > countDoubleLinkedList())
        {
            cout << "Posisi diluar jangkauan!!" << endl;
        }
        else
        {
            int nomor = 1;
            cur = head;
            while (nomor < posisi - 1)
            {
                cur = cur->next;
                nomor++;
            }
            del = cur->next;
            afterNode = del->next;
            cur->next = afterNode;
            afterNode->prev = cur;
            delete del;
        }
    }
}

void printDoubleLinkedList()
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat!!!";
    }
    else
    {
        cout << "\nJumlah Data : " << countDoubleLinkedList() << endl;
        cout << "\n DESKRIPSI DATA" << endl;
        cur = head;
        while (cur != NULL)
        {
            cout << "Nama User : " << cur->nama << endl;
            cout << "Username User : " << cur->username << endl;
            cout << "Email User : " << cur->email << endl;
            cout << "Password User : " << cur->password << "\n"
                 << endl;
            cur = cur->next;
        }
    }
}

int main()
{
    cout << "\n<===== Create Double Linked List =====>\n";
    string newData[4] = {"Ahmad", "ahmadkece", "ahmad@gmail.com", "qwe"};
    createDoubleLinkedList(newData);
    printDoubleLinkedList();
    cout << "\n<===== Add First =====>\n";
    string data2[4] = {"Bambang", "bambangkeren", "bambang@gmail.com", "asd"};
    addFirst(data2);
    printDoubleLinkedList();
    cout << "\n<===== Add Last =====>\n";
    string data3[4] = {"Cecep", "cecepasoy", "cecep@gmail.com", "zxc"};
    string data4[4] = {"Dodi", "dodiashiap", "dodi@gmail.com", "rty"};
    addLast(data3);
    addLast(data4);
    printDoubleLinkedList();
    cout << "\n<===== Remove First =====>\n";
    removeFirst();
    printDoubleLinkedList();
    cout << "\n<===== Remove Last =====>\n";
    removeLast();
    printDoubleLinkedList();
    cout << "\n<===== Add Middle =====>\n";
    string data5[4] = {"Eka", "ekaget", "eka@gmail.com", "fgh"};
    string data6[4] = {"Ghazi", "ghaziaja", "ghazi@gmail.com", "vbn"};
    addMiddle(data5, 2);
    addMiddle(data6, 3);
    printDoubleLinkedList();
    cout << "\n<===== Remove Middle =====>\n";
    removeMiddle(2);
    printDoubleLinkedList();
}
