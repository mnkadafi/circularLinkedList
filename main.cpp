//
//  main.cpp
//  circularLinkedList
//
//  Created by Mochamad Nurkhayal Kadafi on 26/12/19.
//  Copyright © 2019 Mochamad Nurkhayal Kadafi. All rights reserved.
//

#include <iostream>

using namespace std;

struct node{
public:
    string data;
    node *next;

    node(string data){
        this->data = data;
    }

    node(){}
};

node *n,*head,*tail;

void insertBeginning(string data){
    n = new node();
    n->data = data;
    if(head == NULL){
        head = n;
        tail = n;
        tail->next = head;
    }else{
        n->next = head;
        head = n;
        tail->next = head;
    }
}

void insertEnd(string data){
    n = new node();
    n->data = data;
    if(head == NULL){
        head = n;
        tail = n;
        tail->next = head;
    }else{
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }
}

void insertAfter(string data,string target){
    node *helper;
    if(head == NULL){
        n = new node(data);
        n->next = head;
        head = n;
        tail = head;
    }else{
        helper = head;
        while (helper->next!= head && helper->data != target){
            helper = helper->next;
        }

        if(helper == NULL) return;
        if(helper == tail){
            insertEnd(data);
        }else{
            n = new node(data);
            n->next = helper->next;
            helper->next = n;
        }
    }
}

void searching(string target){
    node *helper;
    helper = head;
    bool ketemu = false;

    while(helper->next != head && !ketemu){
        if(helper->data == target){
            ketemu = true;
        }else{
            helper = helper->next;
        }
    }

    if(ketemu) {
        cout<<""<<endl;
        cout<<"Ketemu Baju : "<<helper->data;
    }else if(helper->data == target){
        cout<<""<<endl;
        cout<<"Ketemu Baju : "<<helper->data;
    }else{
        cout<<""<<endl;
        cout<<"Baju tidak ditemukan"<<endl;
    }
}

void traverse(){
    node *tmp;
    tmp = head;
    
    if(tmp != NULL){
        cout<<""<<endl;
        cout<<"Display baju terdiri dari: "<<endl;
        
        do{
            cout<<tmp->data<<endl;
            tmp = tmp->next;
        }while (tmp != head);
        
//        cout<<tmp->data;
    }else{
        cout<<""<<endl;
        cout<<"Display Baju Kosong"<<endl;
    }
}

void display(node *anode){
    cout<<anode->data;
}

void destroy(){
    node* del =head;
    head = nullptr;
    tail = nullptr;
    free(del);
}

void deleteHead(){
    if(head==tail){
        destroy();
        return;
    }

    node *del;
    del = head->next;
    free(head);
    head = del;
    tail->next = head;
}

void deleteTail(){
    if(head==tail){
        destroy();
        return;
    }

    node *del = head;
    while(del->next != tail){
        del = del->next;
    }

    del->next = tail->next;
    tail->next = NULL;
    free(tail);
    tail = del;
}

void deletion(string target){
    node *helper,*del;
    helper = head;
    bool ketemu = false;

    if(target == head->data){
        deleteHead();
    }else if(target == tail->data){
        deleteTail();
    }else{
        while( !ketemu && helper->next != head){
            if(helper->next->data == target ){
                ketemu = true;
            }else{
                helper = helper->next;
            }
        }
        if(ketemu){
            del = helper->next;
            helper->next = del->next;
            del->next = NULL;
            free(del);
        }else{
            cout<<"Baju tidak ditemukan"<<endl;
        }
    }
}


//int main() {
//    insertBeginning(1);
//    insertBeginning(4);
//    insertEnd(5);
//    insertEnd(56);
//    deleteTail();
//    insertEnd(57);
//    insertBeginning(231);
//    deleteHead();
//    insertBeginning(123);
//    insertAfter(555,1);
//    deletion(555);
//    searching(57);
//    traverse();
//}



int main() {
    int pil;
    string dataBaru,data;
    
    do{
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"Toko Baju Anime"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"1. Display Depan"<<endl;
        cout<<"2. Display Belakang"<<endl;
        cout<<"3. Display Kustom"<<endl;
        cout<<"4. Cari Baju"<<endl;
        cout<<"5. Hapus Display Depan"<<endl;
        cout<<"6. Hapus Display Belakang"<<endl;
        cout<<"7. Hapus Display Terpilih"<<endl;
        cout<<"8. Tampil Semua Baju"<<endl;
        cout<<"0. Keluar"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<"Pilih Menu : ";cin>>pil;
        
        switch (pil) {
            case 1:
                cout<<"Display Depan"<<endl;
                cout<<"Nama Baju (Tanpa Spasi)    : ";cin>>dataBaru;
                insertBeginning(dataBaru);
                break;
            case 2:
                cout<<"Display Belakang"<<endl;
                cout<<"Nama Baju (Tanpa Spasi)    : ";cin>>dataBaru;
                insertEnd(dataBaru);
                break;
            case 3:
                cout<<"Pajangan Kustom"<<endl;
                cout<<"Nama Baju                  : ";cin>>dataBaru;
                cout<<"Setelah Nama Baju          : ";cin>>data;
                insertAfter(dataBaru, data);
                break;
            case 4:
                cout<<"Cari Baju                  : ";cin>>dataBaru;
                searching(dataBaru);
                break;
            case 5:
                deleteHead();
                cout<<"Hapus Display Depan Berhasil"<<endl;
                break;
            case 6:
                deleteTail();
                cout<<"Hapus Display Belakang Berhasil"<<endl;
                break;
            case 7:
                traverse();
                cout<<""<<endl;
                cout<<"Hapus Display Baju Tertentu"<<endl;
                cout<<"Nama Baju                  : ";cin>>dataBaru;
                deletion(dataBaru);
                cout<<"Hapus Display "<<dataBaru<<" Berhasil"<<endl;
                break;
            case 8:
                traverse();
                break;
            default:
                break;
        }
    }while (pil != 0);
}


