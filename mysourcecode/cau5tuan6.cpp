#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct date
{
    int ngay, thang, nam;
};

istream& operator >> (istream &is, date &d){
cout<< "\nNhap nam sinh: \n";
is>>d.nam;
cout<< "\nNhap thang sinh: \n";
is>>d.thang;
cout<< "\nNhap ngay sinh: \n";
is>>d.ngay;
return is;
	}


ostream& operator << (ostream &os, date &d){
    os<< d.ngay << "/" << d.thang <<"/" <<d.nam;
    return os;
    }

//tao cau truc sinh vien
struct SinhVien
{
    char ten[50];
    int MSSV;
    char gioiTinh[5];
    date ngaySinh;
    char lop[30];
    float diemKTLT;    
};


//tao cau truc danh sach lien ket don
struct Node
{
    SinhVien *data;
    Node *pNext;
};

struct SingleList
{
    Node *pHead;
};


//khoi tao danh sach lien ket don
void KhoiTaoDS(SingleList *&list)
{
    list=new SingleList;
    list->pHead=NULL;
}


//nhap thong tin sinh vien
SinhVien *NhapSinhVien()
{
	date d;
    SinhVien *sv=new SinhVien;
    cout<<"Nhap ho va ten:";
    gets(sv->ten);
    cin.ignore();
    cout<<"Nhap MSSV:";
    cin>>(sv->MSSV);
    cin.ignore();
    cout<<"Nhap gioi tinh:";
    gets(sv->gioiTinh);
    cin.ignore();
	cout<<"Nhap vao ngay sinh: ";
	cin>>(sv->ngaySinh);
    cin.ignore();
    cout<<"Nhap ten lop: ";
    gets(sv->lop);
    cout<<"Nhap diem KTLT: ";
    cin>>(sv->diemKTLT);
    return sv;
}


//tao node sinh vien
Node *CreateNode(SinhVien *sv)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=sv;
        pNode->pNext=NULL;
    }
    else
    {
        cout<<"cap phat bo nho that bai!";
    }
    return pNode;
}


//them node vao cuoi danh sach
void InsertLast(SingleList *&list,SinhVien *sv)
{
    Node *pNode=CreateNode(sv);
    if(list->pHead==NULL)
    {
        list->pHead=pNode;
    }
    else
    {
        Node *pTmp=list->pHead;
         
        while(pTmp->pNext!=NULL)
        {
            pTmp=pTmp->pNext;
        }
        pTmp->pNext=pNode;
    }
}


//hien thi danh sach
void PrintList(SingleList *list)
{
    Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        cout<<"Danh sach rong";
        return;
    }
    while(pTmp!=NULL)
    {
        SinhVien *sv=pTmp->data;
        cout<<(sv->ten)<<"  "<<(sv->MSSV)<<"  "<<(sv->gioiTinh)<<"  "<<(sv->ngaySinh)<<"  "<<(sv->lop)<<"  "<<(sv->diemKTLT);
        pTmp=pTmp->pNext;
    }
}


int main(int argc, char** argv) {
    SingleList *list;
    KhoiTaoDS(list);
    SinhVien *a=NhapSinhVien();
    InsertLast(list,a);
    PrintList(list);

  cout<<"\n---------------------------\n";

}
