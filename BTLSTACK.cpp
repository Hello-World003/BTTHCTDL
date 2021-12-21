#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

//Khai bao cua truc
struct MatHang
{
    char mahang[10];
    char tenhang[100];
    char nhacungcap[50];
    float dongia;
    int soluong;
};

struct hoadon
{
    char mahoadon[10];
    char ngaylap[11];
    char manhanvien[10];
    char makhachhang[10];
    char tenNV[50];
    char tenKH[50];
    char masanpham[10];
    char tensp[100];
    int soluongmua;
    float giaban;
    float tongtien;
};

struct khachhang
{
    char maKH[10];
    char tenKH[50];
    char gioitinh[5];
    char diachi[100];
    char sdt[11];
};

struct nhanvien
{
    char maNV[10];
    char tenNV[50];
    char gioitinh[5];
    char ngaysinh[12];
    char diachi[100];
    char sdt[11];
    char CMND[15];
};

struct Node
{
    MatHang MH;
    hoadon HD;
    khachhang KH;
    nhanvien NV;
    Node *next;
};

struct Stack
{
    Node *Head;
}STMH,STHD,STKH,STNV;


//Khoi tao danh sach
void Init(Stack &Q)
{
   Q.Head=NULL;

}


//Tao nut cho tung doi tuong
Node *createNodeNV(nhanvien nv)
{
    Node *p=new Node;
    if(p==NULL)
    {
        cout<<"Khong du bo nho";
        return 0;
    }
    else{
        p->NV=nv;
        p->next=NULL;
        return p;
    }
}

Node *createNodeKH(khachhang kh)
{
    Node *p=new Node;
    if(p==NULL)
    {
        cout<<"Khong du bo nho";
        return 0;
    }
    else{
        p->KH=kh;
        p->next=NULL;
        return p;
    }
}

Node *createNodeHD(hoadon hd)
{
    Node *p=new Node;
    if(p==NULL)
    {
        cout<<"Khong du bo nho";
        return 0;
    }
    else{
        p->HD=hd;
        p->next=NULL;
        return p;
    }
}

Node *createNodeMH(MatHang mh)
{
    Node *p=new Node;
    if(p==NULL)
    {
        cout<<"Khong du bo nho";
        return 0;
    }
    else{
        p->MH=mh;
        p->next=NULL;
        return p;
    }
}



//Nhap thong tin cho mot doi tuong chung
void nhapMatHang(MatHang &mh)
{   fflush(stdin);
    while(true)
    {
        cout<<"Nhap ma mat hang:";
        cin.getline(mh.mahang,10);
        Node *p=STMH.Head;
        while(p!=NULL)
        {
            if(strcmp(p->MH.mahang,mh.mahang)==0)
            {
                cout<<"--->Ma hang "<<mh.mahang<<" da ton tai<------"<<endl;
                break;
            }
            p=p->next;
        }
        if(p==NULL)
        {
            break;
        }
    }

    cout<<"\nNhap ten mat hang:";
    cin.getline(mh.tenhang,100);
    cout<<"\nNhap nha cung cap:";
    cin.getline(mh.nhacungcap,50);
    cout<<"\nNhap don gia:";
    cin>>mh.dongia;
    cout<<"\nNhap so luong trong kho:";
    cin>>mh.soluong;
}


void nhapHoaDon(hoadon &hd)
{
    fflush(stdin);
    while(true)
    {
        cout<<"Nhap ma hoa don:";
        cin.getline(hd.mahoadon,10);
        Node *p=STHD.Head;
        while(p!=NULL)
        {
            if(strcmp(p->HD.mahoadon,hd.mahoadon)==0)
            {
                cout<<"---->>Ma hoa don "<<hd.mahoadon<<" da ton tai<<-----"<<endl;
                break;
            }
            p=p->next;
        }
        if(p==NULL)
        {
            break;
        }

    }

    cout<<"\nNhap ngay lap:";
    cin.getline(hd.ngaylap,11);
     while(true)
    {
        cout<<"\nNhap ma nhan vien:";
       cin.getline(hd.manhanvien,10);
        Node *p=STNV.Head;
        while(p!=NULL)
        {
            if(strcmp(p->NV.maNV,hd.manhanvien)==0)
            {
                strcpy(hd.tenNV,p->NV.tenNV);
                break;
            }
            p=p->next;
        }
        if(p!=NULL)
        {
           break;
        }
        else {
             cout<<"Khong tim thay nhan vien co ma "<<hd.manhanvien<<" ";
        }
    }
     while(true)
    {
        cout<<"\nNhap ma khach hang:";
         cin.getline(hd.makhachhang,10);
        Node *p=STKH.Head;
        while(p!=NULL)
        {
            if(strcmp(p->KH.maKH,hd.makhachhang)==0)
            {
                strcpy(hd.tenKH,p->KH.tenKH);
                break;
            }
            p=p->next;
        }
        if(p==NULL)
        {
            cout<<"Khong tim thay khach hang co ma "<<hd.makhachhang<<" ";
        }
        else{
            break;
        }
    }

    while(true)
    {
        cout<<"\nNhap ma san pham:";
        cin.getline(hd.masanpham,10);
        Node *a=STMH.Head;
        while(a!=NULL)
        {
            if(strcmp(a->MH.mahang,hd.masanpham)==0)
            {
                strcpy(hd.tensp,a->MH.tenhang);
                break;
            }
            a=a->next;
        }
        if(a==NULL)
        {
            cout<<"Khong ton tai mat hang co ma "<<hd.masanpham<<" trong kho";
        }
        else{
            break;
        }
    }
   do{
     cout<<"\nNhap so luong mua:";
     cin>>hd.soluongmua;
     bool check=true;
     Node *b=STMH.Head;
     while(b!=NULL)
     {
         if(strcmp(b->MH.mahang,hd.masanpham)==0)
         {
             if(b->MH.soluong<hd.soluongmua)
             {
                 cout<<"So luong mat hang "<<b->MH.tenhang<<" trong kho khong du"<<endl;
                 cout<<"So luong mat hang "<<b->MH.tenhang<<" chi con "<<b->MH.soluong<<endl;
                 check=false;
             }
             else{
                b->MH.soluong=b->MH.soluong-hd.soluongmua;
             }
         }
         b=b->next;
     }
     if(check==true)
     {
         break;
     }
   }while(true);

    cout<<"\nNhap gia ban:";
    cin>>hd.giaban;
    hd.tongtien=hd.soluongmua*hd.giaban;
}

void nhapNhanVien(nhanvien &nv)
{
    fflush(stdin);
    while(true)
    {
        cout<<"Nhap ma nhan vien:";
        cin.getline(nv.maNV,10);
        Node *p=STNV.Head;
        while(p!=NULL)
        {
            if(strcmp(p->NV.maNV,nv.maNV)==0)
            {
                cout<<"---->Ma nhan vien "<<nv.maNV<<" da ton tai<-----"<<endl;
                break;
            }
            p=p->next;
        }
        if(p==NULL)
        {
            break;
        }
    }

    cout<<"\nNhap ten nhan vien:";
    cin.getline(nv.tenNV,50);
    cout<<"\nNhap gioi tinh(nam(1)/nu(0)):";
    int n;
    while(true)
    {
        cin>>n;
        if(n==1)
        {
            char gt[]="Nam";
            strcpy(nv.gioitinh,gt);
            break;
        }
        else if(n==0){
            char gt[]="Nu";
            strcpy(nv.gioitinh,gt);
            break;
        }
        else{
            cout<<"Vui long nhap lai"<<endl;
            cout<<"\nNhap gioi tinh(nam(1)/nu(0)):";
        }
    }
    cin.ignore();
    cout<<"\nNhap ngay sinh:";
    cin.getline(nv.ngaysinh,12);
    cout<<"\nNhap dia chi:";
    cin.getline(nv.diachi,100);
    cout<<"\nNhap so dien thoai:";
    cin.getline(nv.sdt,11);
    cout<<"\nNhap so CMND:";
    cin.getline(nv.CMND,15);
}

void nhapKhachHang(khachhang &kh)
{
    fflush(stdin);
    while(true)
    {
        cout<<"\nNhap ma khach hang:";
        cin.getline(kh.maKH,10);
        Node *p=STKH.Head;
        while(p!=NULL)
        {
            if(strcmp(p->KH.maKH,kh.maKH)==0)
            {
                cout<<"---->Ma khach hang "<<kh.maKH<<" da ton tai<------"<<endl;
                break;
            }
            p=p->next;
        }
        if(p==NULL)
        {
            break;
        }
    }

    cout<<"\nNhap ten khach hang:";
    cin.getline(kh.tenKH,50);
    cout<<"\nNhap gioi tinh(nam(1)/nu(0)):";
    int n;
    while(true)
    {
        cin>>n;
        if(n==1)
        {
            char gt[]="Nam";
            strcpy(kh.gioitinh,gt);
            break;
        }
        else if(n==0){
            char gt[]="Nu";
            strcpy(kh.gioitinh,gt);
            break;
        }
        else{
            cout<<"Vui long nhap lai"<<endl;
            cout<<"\nNhap gioi tinh(nam(1)/nu(0)):";
        }
    }
    cin.ignore();
    cout<<"\nNhap dia chi:";
    cin.getline(kh.diachi,100);
    cout<<"\nNhap so dien thoai:";
    cin.getline(kh.sdt,11);
}




//Hien thong tin mot doi tuong

void titleMH()
{
    cout<<setw(10)<<"Ma hang"<<setw(30)<<"Ten hang"<<setw(30)<<"nha cung cap"<<setw(12)<<"Don gia"<<setw(10)<<"so luong"<<endl;
}
                /*Hoa don in theo chieu doc*/
void titleKH()
{
    cout<<setw(10)<<"Ma KH"<<setw(30)<<"Ten KH"<<setw(11)<<"Gioi tinh"<<setw(30)<<"Dia chi"<<setw(11)<<"SDT"<<endl;
}
void titleNV()
{
    cout<<setw(10)<<"Ma NV"<<setw(30)<<"Ten NV"<<setw(5)<<"GT"<<setw(12)<<"Ngay sinh"<<setw(25)<<"Dia chi"<<setw(12)<<"SDT"<<setw(15)<<"CMND"<<endl;
}

void outputMH(MatHang mh)
{

    cout<<setw(10)<<mh.mahang;
    cout<<setw(30)<<mh.tenhang;
    cout<<setw(30)<<mh.nhacungcap;
    cout<<setw(12)<<(int)mh.dongia;
    cout<<setw(10)<<mh.soluong<<endl;
}

void outputHD(hoadon hd)
{
    cout<<"Ma HD:"<<hd.mahoadon<<endl;
    cout<<"Ngay lap:"<<hd.ngaylap<<endl;
    cout<<"Ma NV:"<<hd.manhanvien<<"\t Ho ten NV:"<<hd.tenNV<<endl;
    cout<<"Ma KH:"<<hd.makhachhang<<"\tHo ten KH:"<<hd.tenKH<<endl;
    cout<<"Ma san pham:"<<hd.masanpham<<"\t Ten san pham:"<<hd.tensp<<endl;
    cout<<"So luong:"<<hd.soluongmua<<endl;
    cout<<"Don gia:"<<(int)hd.giaban<<endl;
    cout<<"Tong tien:"<<(int)hd.tongtien<<endl;
}

void outputKH(khachhang kh)
{

     cout<<setw(10)<<kh.maKH<<setw(30)<<kh.tenKH<<setw(11)<<kh.gioitinh<<setw(30)<<kh.diachi<<setw(11)<<kh.sdt<<endl;

}

void outputNV(nhanvien nv)
{
  cout<<setw(10)<<nv.maNV<<setw(30)<<nv.tenNV<<setw(5)<<nv.gioitinh<<setw(12)<<nv.ngaysinh<<setw(25)<<nv.diachi<<setw(12)<<nv.sdt<<setw(15)<<nv.CMND<<endl;
}

//Them thong tin mot nut vao danh sach

int PushMH(Stack &STMH,MatHang mh)
{
    Node *p=new Node;
    if(p==NULL)
    {
        cout<<"Khong them duoc"<<endl;
        return 0;
    }
    else{
        p->MH=mh;
        p->next=STMH.Head;
        STMH.Head=p;
        return 1;
    }
}

int PushHD(Stack &STHD,hoadon hd)
{
    Node *p=new Node;
    if(p==NULL)
    {
        cout<<"Khong them duoc"<<endl;
        return 0;
    }
    else{
        p->HD=hd;
        p->next=STHD.Head;
        STHD.Head=p;
        return 1;
    }
}

int PushKH(Stack &STKH,khachhang kh)
{
    Node *p=new Node;
    if(p==NULL)
    {
        cout<<"Khong them duoc"<<endl;
        return 0;
    }
    else{
        p->KH=kh;
        p->next=STKH.Head;
        STKH.Head=p;
        return 1;
    }
}

int PushNV(Stack &STNV, nhanvien nv)
{
    Node *p=new Node;
    if(p==NULL)
    {
        cout<<"Khong them duoc"<<endl;
        return 0;
    }
    else{
        p->NV=nv;
        p->next=STNV.Head;
        STNV.Head=p;
        return 1;
    }
}

//Lay tung phan tu ra khoi stack
MatHang PopMH(Stack &STMH)
{
    if(STMH.Head==NULL)
    {
        cout<<"Stack rong"<<endl;
    }
    else{
        Node *p=STMH.Head;
        MatHang a=p->MH;
        STMH.Head=STMH.Head->next;
        delete(p);
        p=NULL;
        return a;
    }
}

hoadon PopHD(Stack &STHD)
{
    if(STHD.Head==NULL)
    {
        cout<<"Stack rong"<<endl;
    }
    else{
        Node *p=STHD.Head;
        hoadon a=p->HD;
        STHD.Head=STHD.Head->next;
        delete(p);
        p=NULL;
        return a;
    }
}

khachhang PopKH(Stack &STKH)
{
    if(STKH.Head==NULL)
    {
        cout<<"Stack rong"<<endl;
    }
    else{
        Node *p=STKH.Head;
        khachhang a=p->KH;
        STKH.Head=STKH.Head->next;
        delete(p);
        p=NULL;
        return a;
    }
}

nhanvien PopNV(Stack &STNV)
{
    if(STNV.Head==NULL)
    {
        cout<<"Stack rong"<<endl;
    }
    else{
        Node *p=STNV.Head;
        nhanvien a=p->NV;
        STNV.Head=STNV.Head->next;
        delete(p);
        p=NULL;
        return a;
    }
}

//Nhap thong tin danh sach cac doi tuong

void inputDSMH(Stack &STMH)
{
    int n;
    cout<<"Nhap so luong mat hang can nhap:";
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        cout<<"\nNhap thong tin mat hang thu "<<i<<":"<<endl;
        MatHang a;
        nhapMatHang(a);
        PushMH(STMH,a);
        cout<<"\n-----------------------------------\n";
    }
}

void inputDSHD(Stack &STHD)
{
    int n;
    cout<<"Nhap so luong hoa don can nhap:";
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        cout<<"\nNhap thong tin hoa don thu "<<i<<":"<<endl;
        hoadon a;
        nhapHoaDon(a);
        PushHD(STHD,a);
        cout<<"\n-------------------------------------\n";
    }
}

void inputDSKH(Stack &STKH)
{
    int n;
    cout<<"\nNhap danh sach khach hang can nhap:";
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap thong tin khach hang thu "<<i<<":"<<endl;
        khachhang a;
        nhapKhachHang(a);
        PushKH(STKH,a);
        cout<<"\n-------------------------------------\n";
    }
}

void inputDSNV(Stack &STNV)
{
    int n;
    cout<<"Nhap so luong nhan vien can nhap:";
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        cout<<"\nNhap thong tin nhan vien thu "<<i<<":"<<endl;
        nhanvien a;
        nhapNhanVien(a);
        PushNV(STNV,a);
        cout<<"\n-----------------------------------\n";
    }
}



//Hien thong tin tung danh sach


void outputDSMH(Stack STMH)
{
    Node *p=STMH.Head;
    titleMH();
    while(p!=NULL)
    {
      outputMH(p->MH);
      p=p->next;
    }
}

void outputDSHD(Stack STHD)
{
    Node *p=STHD.Head;
    while(p!=NULL)
    {
        outputHD(p->HD);
        p=p->next;
        cout<<endl;
    }
}

void outputDSKH(Stack STKH)
{
    Node *p=STKH.Head;
    titleKH();
    while(p!=NULL)
    {
        outputKH(p->KH);
        p=p->next;
    }
}

void outputDSNV(Stack STNV)
{
    Node *p=STNV.Head;
    titleNV();
    while(p!=NULL)
    {
        outputNV(p->NV);
        p=p->next;
    }
}



//Doc file va luu file

void writeFileMH(Stack STMH)
{
    ofstream fo("mathang.txt");
    if(fo.is_open())
    {
        cout<<"Luu file thanh cong"<<endl;
    }
    else{
        cout<<"Luu file khong thanh cong"<<endl;
        return;
    }
    Node *p=STMH.Head;
    while(p!=NULL)
    {
        for(int i=0;i<strlen(p->MH.tenhang);i++)
        {
            if(p->MH.tenhang[i]==' ')
            {
                p->MH.tenhang[i]='_';
            }
        }
        for(int i=0;i<strlen(p->MH.nhacungcap);i++)
        {
            if(p->MH.nhacungcap[i]==' ')
            {
                p->MH.nhacungcap[i]='_';
            }
        }
        fo<<setw(10)<<p->MH.mahang;
        fo<<setw(30)<<p->MH.tenhang;
        fo<<setw(30)<<p->MH.nhacungcap;
        fo<<setw(12)<<p->MH.dongia;
        fo<<setw(10)<<p->MH.soluong<<endl;
        p=p->next;
    }
    fo.close();
}

void readFileMH(Stack &STMH)
{
    if(STMH.Head==NULL)
    {
        ifstream fi("mathang.txt");
        if(!fi.is_open())
        {
            cout<<"Doc file khong thanh cong"<<endl;
            return;

        }
        MatHang a;
        while(fi>>a.mahang>>a.tenhang>>a.nhacungcap
              >>a.dongia>>a.soluong)
        {
            PushMH(STMH,a);
        }
        cout<<"Du lieu sau khi doc file:"<<endl;
        outputDSMH(STMH);
        fi.close();
    }
}


void writeFileKH(Stack STKH)
{
   ofstream fo("khachhang.txt");
   if(fo.is_open())
   {
       cout<<"Luu file thanh cong"<<endl;
   }
   else{
    cout<<"Luu file khong thanh cong"<<endl;
    return ;
   }
   Node *p=STKH.Head;
   while(p!=NULL)
   {
       for(int i=0;i<strlen(p->KH.tenKH);i++)
        {
            if(p->KH.tenKH[i]==' ')
            {
                p->KH.tenKH[i]='_';
            }
        }
         for(int i=0;i<strlen(p->KH.diachi);i++)
        {
            if(p->KH.diachi[i]==' ')
            {
                p->KH.diachi[i]='_';
            }
        }

       fo<<p->KH.maKH<<" ";
       fo<<p->KH.tenKH<<" ";
       fo<<p->KH.gioitinh<<" ";
       fo<<p->KH.diachi<<" ";
       fo<<p->KH.sdt<<endl;
       p=p->next;

   }
   fo.close();
}

void readFileKH(Stack &STKH)
{
    if(STKH.Head==NULL)
    {
        ifstream fi("khachhang.txt");
        if(!fi.is_open())
        {
            cout<<"Doc file khong thanh cong"<<endl;
            return ;
        }
        khachhang a;
        while(fi>>a.maKH>>a.tenKH>>a.gioitinh>>a.diachi
              >>a.sdt)
        {
            PushKH(STKH,a);
        }

        cout<<"Du lieu sau khi doc file:"<<endl;
        outputDSKH(STKH);
        fi.close();
    }
}



void writeFileNV(Stack STNV)
{
    ofstream fo("Nhanvien.txt");
    if(fo.is_open())
    {
        cout<<"Luu file thanh cong"<<endl;
    }
    else{
        cout<<"Luu file khong thanh cong"<<endl;
        return ;
    }
    Node *p=STNV.Head;
    while(p!=NULL)
    {
        for(int i=0;i<strlen(p->NV.tenNV);i++)
        {
            if(p->NV.tenNV[i]==' ')
            {
                p->NV.tenNV[i]='_';
            }
        }
        for(int i=0;i<strlen(p->NV.diachi);i++)
        {
            if(p->NV.diachi[i]==' ')
            {
                p->NV.diachi[i]='_';
            }
        }
        fo<<setw(10)<<p->NV.maNV;
        fo<<setw(30)<<p->NV.tenNV;
        fo<<setw(5)<<p->NV.gioitinh;
        fo<<setw(12)<<p->NV.ngaysinh;
        fo<<setw(25)<<p->NV.diachi;
        fo<<setw(12)<<p->NV.sdt;
        fo<<setw(15)<<p->NV.CMND<<endl;
        p=p->next;
    }
    fo.close();
}

void readFileNV(Stack &STNV)
{
    if(STNV.Head==NULL)
    {
        ifstream fi("Nhanvien.txt");
        if(!fi.is_open())
        {
            cout<<"Doc file khong thanh cong"<<endl;
            return;
        }
        nhanvien a;
        while(fi>>a.maNV>>a.tenNV>>a.gioitinh>>a.ngaysinh>>a.diachi>>a.sdt>>a.CMND)
        {
            PushNV(STNV,a);
        }
        cout<<"Du lieu sau khi doc file:"<<endl;
        outputDSNV(STNV);
        fi.close();
    }
}


void writeFileHD(Stack STHD)
{
    ofstream fo("hoadon.txt");
    if(fo.is_open())
    {
        cout<<"Luu file thanh cong"<<endl;
    }
    else{
        cout<<"Luu file khong thanh cong"<<endl;
        return;
    }
    Node *p=STHD.Head;
    while(p!=NULL)
    {
        for(int i=0;i<strlen(p->HD.tenKH);i++)
        {
            if(p->HD.tenKH[i]==' ')
            {
                p->HD.tenKH[i]='_';
            }
        }
        for(int i=0;i<strlen(p->HD.tenNV);i++)
        {
            if(p->HD.tenNV[i]==' ')
            {
                p->HD.tenNV[i]='_';
            }
        }
        for(int i=0;i<strlen(p->HD.tensp);i++)
        {
            if(p->HD.tensp[i]==' ')
            {
                p->HD.tensp[i]='_';
            }
        }
        fo<<p->HD.mahoadon<<endl;
        fo<<p->HD.ngaylap<<endl;
        fo<<p->HD.manhanvien<<endl;
        fo<<p->HD.tenNV<<endl;
        fo<<p->HD.makhachhang<<endl;
        fo<<p->HD.tenKH<<endl;
        fo<<p->HD.masanpham<<endl;
        fo<<p->HD.tensp<<endl;
        fo<<p->HD.soluongmua<<endl;
        fo<<p->HD.giaban<<endl;
        fo<<p->HD.tongtien<<endl<<endl;
        p=p->next;
    }
    fo.close();
    writeFileMH(STMH);
}

void readFileHD(Stack &STHD)
{
    if(STHD.Head==NULL)
    {
        ifstream fi("hoadon.txt");
        if(!fi.is_open())
        {
            cout<<"Doc file khong thanh cong"<<endl;
            return;
        }
        hoadon a;
        while(fi>>a.mahoadon>>a.ngaylap>>a.manhanvien>>a.tenNV>>a.makhachhang
              >>a.tenKH>>a.masanpham>>a.tensp>>a.soluongmua>>a.giaban>>a.tongtien)
        {
            PushHD(STHD,a);
        }
        cout<<"Du lieu sau khi doc file:"<<endl;
        outputDSHD(STHD);
        fi.close();
    }
}



//Xoa du thong tin doi tuong

void deleteMH(Stack &STMH)
{
    char a[11];
    cin.ignore();
    cout<<"Nhap ma mat hang can xoa:";
    cin.getline(a,11);
    Stack k;
    Init(k);
    bool check=false;
    while(STMH.Head!=NULL)
    {
        MatHang mh=PopMH(STMH);
        if(strcmp(mh.mahang,a)==0)
        {
            check=true;
            cout<<"Da xoa mat hang co ma "<<a<<endl;
            break;
        }
        PushMH(k,mh);
    }
    if(check==false)
    {
        cout<<"Khong co mat hang co ma "<<a<<" trong kho"<<endl;
    }
    while(k.Head!=NULL)
    {
        MatHang b=PopMH(k);
        PushMH(STMH,b);
    }
}

void deleteHD(Stack &STHD)
{
    char a[11];
    cin.ignore();
    cout<<"Nhap ma hoa don can xoa:";
    cin.getline(a,11);
    Stack k;
    Init(k);
    bool check=false;
    while(STHD.Head!=NULL)
    {
        hoadon hd=PopHD(STHD);
        if(strcmp(hd.mahoadon,a)==0)
        {
            check=true;
            cout<<"Da xoa hoa don co ma "<<hd.mahoadon<<endl;
            break;
        }
        PushHD(k,hd);
    }
    if(check==false)
    {
        cout<<"Khong co hoa don co ma "<<a<<endl;
    }
    while(k.Head!=NULL)
    {
        hoadon b=PopHD(k);
        PushHD(STHD,b);
    }

}

void deleteKH(Stack &STKH)
{
    char a[11];
    cin.ignore();
    cout<<"Nhap ma khach hang can xoa:";
    cin.getline(a,11);
     Stack k;
     Init(k);
     bool check=false;
    while(STKH.Head!=NULL)
    {
        khachhang kh=PopKH(STKH);
        if(strcmp(kh.maKH,a)==0)
        {
            check=true;
            cout<<"Da xoa khach hang co ma "<<kh.maKH<<endl;
            break;
        }
        PushKH(k,kh);
    }
    if(check==false)
    {
       cout<<"Khong co khach hang co ma "<<a<<endl;
    }
    while(k.Head!=NULL)
    {
        khachhang b=PopKH(k);
        PushKH(STKH,b);
    }
}


void deleteNV(Stack &STNV)
{
    char a[11];
    cin.ignore();
    cout<<"Nhap ma nhan vien can xoa:";
    cin.getline(a,11);
    Stack k;
    Init(k);
     bool check=false;
    while(STNV.Head!=NULL)
    {
        nhanvien nv=PopNV(STNV);
        if(strcmp(nv.maNV,a)==0)
        {
            check=true;
            cout<<"Da xoa nhan vien co ma "<<nv.maNV<<endl;
            break;
        }
        PushNV(k,nv);
    }
    if(check==false)
    {
        cout<<"\nKhong co ma nhan vien can xoa\n"<<endl;
    }
    while(k.Head!=NULL)
    {
        nhanvien b=PopNV(k);
        PushNV(STNV,b);
    }
}


//SAP XEP
void SortMHofTenMH(Stack &STMH)
{
    for(Node *p=STMH.Head;p!=NULL;p=p->next)
    {
        for(Node *q=p->next;q!=NULL;q=q->next)
        {
            if(strcmp(p->MH.tenhang,q->MH.tenhang)>0)
            {
                MatHang a=p->MH;
                p->MH=q->MH;
                q->MH=a;
            }
        }
    }
    outputDSMH(STMH);
}

void SortMHofGia(Stack &STMH)
{
    for(Node *p=STMH.Head;p!=NULL;p=p->next)
    {
        for(Node *q=p->next;q!=NULL;q=q->next)
        {
            if(p->MH.dongia>q->MH.dongia)
            {
                MatHang a=p->MH;
                p->MH=q->MH;
                q->MH=a;
            }
        }
    }
    outputDSMH(STMH);
}

void SortMHofSL(Stack &STMH)
{
     for(Node *p=STMH.Head;p!=NULL;p=p->next)
    {
        for(Node *q=p->next;q!=NULL;q=q->next)
        {
            if(p->MH.soluong>q->MH.soluong)
            {
                MatHang a=p->MH;
                p->MH=q->MH;
                q->MH=a;
            }
        }
    }
    outputDSMH(STMH);
}

    //Tach ten ra khoi ho va ten
char *tachten(char *a)
{    char *ten=new char;
     int countt=-1;

    for(int i=strlen(a)-1;i>=0;i--)
    {
        if(a[i]==' ' || a[i]=='_')
        {
            break;
        }
        countt++;
        ten[countt]=a[i];

    }
    ten[countt+1]=NULL;
    return strrev(ten);
}

void SortKHofTen(Stack &STKH)
{
    for(Node *p=STKH.Head;p!=NULL;p=p->next)
    {
        for(Node *q=p->next;q!=NULL;q=q->next)
        {
            if(strcmp(tachten(p->KH.tenKH),tachten(q->KH.tenKH))>0)
            {
                khachhang a=p->KH;
                p->KH=q->KH;
                q->KH=a;
            }
        }
    }
    outputDSKH(STKH);
}
void SortKHofMa(Stack &STKH)
{
    for(Node *p=STKH.Head;p!=NULL;p=p->next)
    {
        for(Node *q=p->next;q!=NULL;q=q->next)
        {
            if(strcmp(p->KH.maKH,q->KH.maKH)>0)
            {
                khachhang a=p->KH;
                p->KH=q->KH;
                q->KH=a;
            }
        }
    }
    outputDSKH(STKH);
}

    //Tach thang, nam, ngay
int tachthang(char *a)
{
     char *month=new char;
    int countt=-1;
    int dem=0;
    for(int i=3;i<strlen(a);i++)
    {
        if(a[i]=='/')
        {
            break;
        }
        countt++;
        month[countt]=a[i];

    }
    month[countt+1]=NULL;
    int x=atoi(month);

    return x;
}

int tachngay(char *a)
{   char *day=new char;
    int countt=-1;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='/')
        {
            break;
        }
         countt++;
        day[countt]=a[i];

    }
    day[countt+1]=NULL;
    int x=atoi(day);
    return x;
}

int tachnam(char *a)
{   char *year=new char;
    int countt=0;
    for(int i=strlen(a)-1;i>=0;i--)
    {
        if(a[i]=='/')
        {
            break;
        }

        year[countt]=a[i];
        countt++;
    }
    year=strrev(year);
    int x=atoi(year);
    return x;
}

void SortHDofNgayLap(Stack &STHD)
{
    int dem=0;
    for(Node *p=STHD.Head;p!=NULL;p=p->next)
    {
        if(p->next==NULL)
        {
            p=STHD.Head;
            dem++;
        }
        for(Node *q=p;q!=NULL;q=q->next)
        {
            if(tachnam(p->HD.ngaylap)>tachnam(q->HD.ngaylap))
            {
                hoadon a=p->HD;
                p->HD=q->HD;
                q->HD=a;

            }
            else if(tachnam(p->HD.ngaylap)==tachnam(q->HD.ngaylap))
            {
                if(tachthang(p->HD.ngaylap)>tachthang(q->HD.ngaylap))
                {
                    hoadon a=p->HD;
                    p->HD=q->HD;
                    q->HD=a;
                }
                else if(tachthang(p->HD.ngaylap)==tachthang(q->HD.ngaylap))
                {
                    if(tachngay(p->HD.ngaylap)>tachngay(q->HD.ngaylap))
                    {
                        hoadon a=p->HD;
                        p->HD=q->HD;
                        q->HD=a;
                    }
                }
            }
        }
        if(dem==2)
            {
                break;
            }
    }
    outputDSHD(STHD);
}

void SortHDofMa(Stack &STHD)
{
    for(Node *p=STHD.Head;p!=NULL;p=p->next)
    {
        for(Node *q=p;q!=NULL;q=q->next)
        {
            if(strcmp(p->HD.mahoadon,q->HD.mahoadon)>0)
            {
                hoadon a=p->HD;
                p->HD=q->HD;
                q->HD=a;
            }
        }
    }
    outputDSHD(STHD);
}

void SortNVofTen(Stack &STNV)
{
    for(Node *p=STNV.Head;p!=NULL;p=p->next)
    {
        for(Node *q=p;q!=NULL;q=q->next)
        {
            if(strcmp(tachten(p->NV.tenNV),tachten(q->NV.tenNV))>0)
            {
                nhanvien a=p->NV;
                p->NV=q->NV;
                q->NV=a;
            }
        }
    }
    outputDSNV(STNV);
}

void SortNVofMa(Stack &STNV)
{
    for(Node *p=STNV.Head;p!=NULL;p=p->next)
    {
        for(Node *q=p;q!=NULL;q=q->next)
        {
            if(strcmp(p->NV.maNV,q->NV.maNV)>0)
            {
                nhanvien a=p->NV;
                p->NV=q->NV;
                q->NV=a;
            }
        }
    }
    outputDSNV(STNV);
}


//Tim kiem

int CountNumberofList(Stack &Q)
{
    int dem=0;
    Node *p=Q.Head;
    while(p!=NULL)
    {
        dem++;
        p=p->next;
    }
    return dem;
}

void SearchMHofTen(Stack STMH)
{
    char a[50];
    cout<<"Nhap ten mat hang can tim:";
    cin.getline(a,50);
    Node *p=STMH.Head;
    bool check=false;
    while(p!=NULL)
    {
        if(strcmp(p->MH.tenhang,a)==0)
        {
            titleMH();
            outputMH(p->MH);
            check=true;
        }
        p=p->next;
    }
    if(!check)
    {
        cout<<"Khong tim thay mat hang co ten "<<a<<endl<<endl;
    }

}

void SearchMHofMa(Stack STMH)
{
    char a[50];
    cout<<"Nhap ma mat hang can tim:";
    cin.getline(a,50);
    Node *p=STMH.Head;
    bool check=false;
    while(p!=NULL)
    {
        if(strcmp(p->MH.mahang,a)==0)
        {
            titleMH();
            outputMH(p->MH);
            check=true;
        }
        p=p->next;
    }
    if(!check)
    {
        cout<<"Khong tim thay mat hang co ma "<<a<<endl<<endl;
    }

}

void SearchMHofNCC(Stack &STMH)
{
    char a[50];
    cout<<"Nhap ten nha cung cap can tim:";
    cin.getline(a,50);
    Node *p=STMH.Head;
    bool check=false;
    while(p!=NULL)
    {
        if(strcmp(p->MH.nhacungcap,a)==0)
        {
            titleMH();
            outputMH(p->MH);
            check=true;
        }
        p=p->next;
    }
    if(!check)
    {
        cout<<"Khong tim thay mat hang co nha cung cap "<<a<<endl<<endl;
    }

}



void SearchHDofMaKH(Stack STHD)
{
    char a[20];
    cout<<"Nhap ma khach hang:";
    cin.getline(a,20);
    Node *p=STHD.Head;
    bool check=false;
    while(p!=NULL)
    {
        if(strcmp(p->HD.makhachhang,a)==0)
        {
            check=true;
            outputHD(p->HD);
        }
        p=p->next;
    }
    if(!check)
    {
        cout<<"Khong tim thay khach hang mua hang co ma "<<a<<endl;
    }
}

void SearchHDofMaNV(Stack STHD)
{
    char a[20];
    cout<<"Nhap ma nhan vien:";
    cin.getline(a,20);
    Node *p=STHD.Head;
    bool check=false;
    while(p!=NULL)
    {
        if(strcmp(p->HD.manhanvien,a)==0)
        {
            check=true;
            outputHD(p->HD);
        }
        p=p->next;
    }
    if(!check)
    {
        cout<<"Khong tim thay nhan vien lap hoa don co ma "<<a<<endl;
    }
}

void SearchHDofMaMH(Stack STHD)
{
    char a[20];
    cout<<"Nhap ma mat hang:";
    cin.getline(a,20);
    Node *p=STHD.Head;
    bool check=false;
    while(p!=NULL)
    {
        if(strcmp(p->HD.masanpham,a)==0)
        {
            check=true;
            outputHD(p->HD);
        }
        p=p->next;
    }
    if(!check)
    {
        cout<<"Khong tim thay mat hang duoc mua co ma "<<a<<endl;
    }
}

void SearchHDofMaHD(Stack STHD)
{
    char a[20];
    cout<<"Nhap ma hoa don:";
    cin.getline(a,20);
    Node *p=STHD.Head;
    bool check=false;
    while(p!=NULL)
    {
        if(strcmp(p->HD.mahoadon,a)==0)
        {
            check=true;
            outputHD(p->HD);
        }
        p=p->next;
    }
    if(!check)
    {
        cout<<"Khong tim hoa don co ma "<<a<<endl;
    }
}

//Hien thi thong tin doanh thu được theo ngày,tháng

void DoanhThuTheoNgay(Stack STHD)
{
    char a[20];
    cout<<"Nhap ngay thang nam:";
    cin.getline(a,20);
    Node *p=STHD.Head;
    bool check=false;
    int total=0;
    while(p!=NULL)
    {
        if(strcmp(p->HD.ngaylap,a)==0)
        {
            check=true;
            total+=p->HD.tongtien;
        }
        p=p->next;
    }
    if(check==false)
    {
        cout<<"khong co hoa don trong ngay "<<a<<endl;
    }
    else{
        cout<<"Doanh thu trong "<<a<<" la:"<<total<<endl;
    }
}

char *tachNamvaThang1(char *a)
{
    char *get=new char;
    int countt=0;
    for(int i=3;i<strlen(a);i++)
    {
        get[countt]=a[i];
        countt++;
    }
    return get;
}

char *tachNamvaThang2(char *a)
{
    char *get=new char;
    int countt=0;
    for(int i=4;i<strlen(a);i++)
    {
        get[countt]=a[i];
        countt++;
    }
    return get;
}

void DoanhThuTheoThang(Stack STHD)
{
    char a[20];
    cout<<"Nhap thang nam:";
    cin.getline(a,20);
    Node *p=STHD.Head;
    bool check=false;
    int total=0;
    while(p!=NULL)
    {
        if((strcmp(tachNamvaThang1(p->HD.ngaylap),a)==0) || (strcmp(tachNamvaThang2(p->HD.ngaylap),a)==0))
        {
            check=true;
            total+=p->HD.tongtien;
        }
        p=p->next;
    }
    if(!check)
    {
        cout<<"Khong co hoa don trong thang "<<a<<endl;
    }
    else{
        cout<<"Danh thu trong "<<a<<" la:"<<total<<endl;
    }
}


//Hien thi san pham duoc mua nhieu nhat
int  CountMaxHDofMaMH(Stack STHD)
{   int maxx=0;
    for(Node *p=STHD.Head;p!=NULL;p=p->next)
    {   int dem=0;
        for(Node *q=p;q!=NULL;q=q->next)
        {
            if(strcmp(p->HD.masanpham,q->HD.masanpham)==0)
            {
                dem++;
            }
        }
        if(dem>maxx)
        {
            maxx=dem;
        }
    }
    return maxx;
}

void SpMuaNhieu(Stack STHD)
{

    char *a=new char;
    cout<<"So luong mat hang duoc mua nhieu nhat la"<<endl;
    for(Node *p=STHD.Head;p!=NULL;p=p->next)
    {   int dem=0;
        for(Node *q=p;q!=NULL;q=q->next)
        {
            if(strcmp(p->HD.masanpham,q->HD.masanpham)==0)
            {
                dem++;
            }

        }
        if(dem==CountMaxHDofMaMH(STHD) && strcmp(a,p->HD.masanpham)!=0)
        {
            cout<<"\t"<<p->HD.tensp<<"\tso lan mua:"<<dem<<endl;
            a=p->HD.masanpham;
        }
    }
}



//Hiển thị tháng bán được nhiều nhất

int demSLMax(Stack STHD,int year)
{   int slmax=0;
    for(int i=1;i<13;i++)
    {
        int demsl=0;
        for(Node *p=STHD.Head;p!=NULL;p=p->next)
        {
            if(i==tachthang(p->HD.ngaylap) && year==tachnam(p->HD.ngaylap))
            {
                demsl++;
            }
        }
        if(demsl>slmax)
        {
            slmax=demsl;
        }
    }
    return slmax;
}

void ThangMuaNhieu(Stack STHD)
{
   int year;
   bool check=true;
   cout<<"Nhap nam can xem:";
   cin>>year;
   cout<<endl;
   cout<<"Thang ban nhieu hang nhat la:"<<endl;
   for(int i=1;i<13;i++)
   {
       int demsl=0;
       int dedoanhthu=0;
       for(Node *p=STHD.Head;p!=NULL;p=p->next)
       {
           if(i==tachthang(p->HD.ngaylap) && year==tachnam(p->HD.ngaylap))
           {
               check=false;
               demsl++;
               dedoanhthu+=p->HD.tongtien;
           }
       }
       if(demsl==demSLMax(STHD,year) && check==false)
       {
           cout<<"Thang "<<i<<" ban duoc "<<demsl<<endl;
           cout<<"Doanh thu "<<dedoanhthu<<endl;
           cout<<endl;
       }
   }
   if(check==true)
   {
       cout<<"Khong co hoa don trong nam "<<year<<endl;
   }


}

//Hien thi danh sach mat hang khong ban duoc
void MHkoBanDuoc(Stack STHD)
{
    cout<<"Danh sach mat hang khong ban duoc"<<endl;
    titleMH();
    for(Node *p=STMH.Head;p!=NULL;p=p->next)
    {
        bool check=true;
        for(Node *q=STHD.Head;q!=NULL;q=q->next)
        {
            if(strcmp(p->MH.mahang,q->HD.masanpham)==0)
            {
                check=false;
            }
        }
        if(check==true)
        {
           outputMH(p->MH);
        }
    }
}


//Danh sach Menu

void menu()
{
    cout<<"1.Mat Hang"<<endl;
    cout<<"2.Hoa Don"<<endl;
    cout<<"3.Khach hang"<<endl;
    cout<<"4.Nhan vien"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"-->Nhap lua chon:";
}
void menuMH()
{
    cout<<"1.Them du lieu mat hang"<<endl;
    cout<<"2.Hien thi danh sach mat hang"<<endl;
    cout<<"3.Ghi file danh sach mat hang"<<endl;
    cout<<"4.Doc file danh sach mat hang"<<endl;
    cout<<"5.Xoa mot mat hang theo ma hang"<<endl;
     cout<<"6.Sap xep mat hang"<<endl;
    cout<<"7.Tim kiem mat hang"<<endl;
    //cout<<""  ->Them cac tinh nang khach;
    cout<<"0.Tro lai"<<endl;
    cout<<"->Vui long chon lua chon:";
}

void menuMHTK()
{
    cout<<"1.TK theo ten"<<endl;
    cout<<"2.TK theo ma"<<endl;
    cout<<"3.TK theo nha cung cap"<<endl;
    cout<<"0.Tro lai"<<endl;
    cout<<"-->Vui long chon lua chon:";
}

void menuMHSX()
{
    cout<<"1.SX theo ten"<<endl;
    cout<<"2.SX theo don gia"<<endl;
    cout<<"3.SX theo so luong"<<endl;
    cout<<"0.Tro lai"<<endl;
    cout<<"->Vui long chon lua chon:";
}


void menuKH()
{
    cout<<"1.Them thong tin khach hang"<<endl;
    cout<<"2.Hien thi danh sach khach hang"<<endl;
    cout<<"3.Ghi file danh sach khach hang"<<endl;
    cout<<"4.Doc file dach sach khach hang"<<endl;
    cout<<"5.Xoa mot khach hang theo ma"<<endl;
    cout<<"6.Sap xep khach hang"<<endl;
    //->Them cac tinh nang khac
    cout<<"0.Tro lai"<<endl;
    cout<<"->Vui long chon lua chon:";
}

void menuKHSX()
{
    cout<<"1.SX theo ma"<<endl;
    cout<<"2.SX theo ten"<<endl;
    cout<<"0.Tro lai"<<endl;
    cout<<"-->Vui long chon lua chon:";
}


void menuNV()
{
    cout<<"1.Them thong tin nhan vien"<<endl;
    cout<<"2.Hien thi danh sach nhan vien"<<endl;
    cout<<"3.Ghi file nhan vien"<<endl;
    cout<<"4.Doc file nhan vien"<<endl;
    cout<<"5.Xoa mot nhan vien theo ma"<<endl;
     cout<<"6.Sap xep nhan vien"<<endl;
    //-->Them cac tinh nang khac
    cout<<"0.Tro lai"<<endl;
    cout<<"->Vui long chon lua chon:";
}

void menuSXNV()
{
    cout<<"1.SX theo ten"<<endl;
    cout<<"2.SX theo ma"<<endl;
    cout<<"0.Tro lai"<<endl;
    cout<<"-->Vui long nhap lua chon:";
}


void menuHD()
{
    cout<<"1.Them thong tin hoa don"<<endl;
    cout<<"2.Hien thi danh sach hoa don"<<endl;
    cout<<"3.Ghi file hoa don"<<endl;
    cout<<"4.Doc file hoa don"<<endl;
    cout<<"5.Xoa mot hoa don theo ma"<<endl;
     cout<<"6.Sap xep hoa don"<<endl;
    cout<<"7.Tim kiem hoa don"<<endl;
    cout<<"8.Hien thi doah thu"<<endl;
    cout<<"9.Danh sach mat hang ban nhieu nhat"<<endl;
    cout<<"10.Thang ban duoc nhieu mat hang nhat"<<endl;
    cout<<"11.Hien thi mat hang khong ban duoc"<<endl;
    //->Them cac tinh nang
    cout<<"0.Tro lai"<<endl;
    cout<<"->Vui long nhap lua chon:";
}


void menuHDDT()
{
    cout<<"1.Theo ngay"<<endl;
    cout<<"2.Theo thang"<<endl;
    cout<<"0.Tro lai"<<endl;
    cout<<"-->Vui long chon lua chon:";
}

void menuHDTK()
{
    cout<<"1.TK theo ma khach hang"<<endl;
    cout<<"2.TK theo ma nhan vien"<<endl;
    cout<<"3.TK theo ma mat hang"<<endl;
    cout<<"4.TK theo ma hoa don"<<endl;
    cout<<"0.Tro lai"<<endl;
    cout<<"-->Vui long nhap lua chon:";
}

void menuHDSX()
{
    cout<<"1.SX theo ngay lap"<<endl;
    cout<<"2.SX theo ma hoa don"<<endl;
    cout<<"0.Tro lai"<<endl;
    cout<<"-->Vui long chon lua chon:";
}


int main()
{
    Init(STMH);
    Init(STKH);
    Init(STHD);
    Init(STNV);

    while(true)
    {
        cout<<endl;
        menu();
        int n;
        cin>>n;
        cout<<endl;
        if(n==1)
        {
           while(true)
           {
               menuMH();
               int n1;
               cin>>n1;
               cout<<endl;
               if(n1==1)
               {
                   inputDSMH(STMH);
                   cout<<endl;
               }
               else if(n1==2)
               {
                   if(STMH.Head==NULL)
                   {
                       cout<<"-->Danh sach mat hang trong<--\n"<<endl;
                   }
                   else{
                       outputDSMH(STMH);
                       cout<<endl;
                   }
               }
               else if(n1==3)
               {
                   writeFileMH(STMH);
                   cout<<endl;
               }
               else if(n1==4)
               {
                   readFileMH(STMH);
                   cout<<endl;
               }
               else if(n1==5)
               {
                   if(STMH.Head==NULL)
                   {
                       cout<<"\nDanh sach mat hang trong"<<endl;
                   }
                   else{
                    deleteMH(STMH);
                    cout<<endl;
                   }
               }
               else if(n1==6)
               {
                   if(STMH.Head==NULL)
                   {
                       cout<<"---->Danh sach mat hang trong<-----\n"<<endl;
                   }
                   else{
                       while(true)
                       {   int tl;
                           menuMHSX();
                           cin>>tl;
                           if(tl==1)
                           {
                               SortMHofTenMH(STMH);
                           }
                           else if(tl==2)
                           {
                               SortMHofGia(STMH);
                           }
                           else if(tl==3)
                           {
                               SortMHofSL(STMH);
                           }
                           else if(tl==0)
                           {
                               break;
                           }
                           else{
                            cout<<"Vui long chon lai"<<endl;
                           }
                       }
                   }
               }
               else if(n1==7)
               {
                   if(STMH.Head==NULL)
                   {
                        cout<<"---->Danh sach mat hang trong<-----\n"<<endl;
                   }
                   else{
                       while(true)
                       {   int tl;
                           menuMHTK();
                           cin>>tl;
                           cin.ignore();
                           if(tl==1)
                           {
                               SearchMHofTen(STMH);
                           }
                           else if(tl==2)
                           {
                               SearchMHofMa(STMH);
                           }
                           else if(tl==3)
                           {
                               SearchMHofNCC(STMH);
                           }
                           else if(tl==0)
                           {
                               break;
                           }
                           else{
                            cout<<"Vui long chon lai"<<endl;
                           }
                       }
                   }
               }
               else if(n1==0)
               {
                   break;
               }
               else{
                cout<<"-->Vui long chon lai<----\n"<<endl;
               }
           }
        }
        else if(n==2)
        {
            if(STMH.Head==NULL)
            {
                cout<<"-->Danh sach mat hang trong<--"<<endl;
                cout<<"->Ko the dien thong tin vao hoa don<-\n"<<endl;
            }
            if(STKH.Head==NULL)
            {
                cout<<"-->Danh sach khach hang trong<--"<<endl;
                cout<<"->Ko the dien thong tin vao hoa don<-\n"<<endl;
            }
            if(STNV.Head==NULL)
            {
                cout<<"-->Danh sach nhan vien trong<--"<<endl;
                cout<<"->Ko the dien thong tin vao hoa don<-\n"<<endl;
            }
            else{
                while(true)
                {
                    menuHD();
                    int n2;
                    cin>>n2;
                    cout<<endl;
                    if(n2==1)
                    {
                        inputDSHD(STHD);
                        cout<<endl;
                    }
                    else if(n2==2)
                    {
                        if(STHD.Head==NULL)
                        {
                            cout<<"-->Danh sach hoa don trong<--\n"<<endl;
                        }
                        else{
                            outputDSHD(STHD);
                           cout<<endl;
                        }
                    }
                    else if(n2==3)
                    {
                        writeFileHD(STHD);
                        cout<<endl;

                    }
                    else if(n2==4)
                    {
                        readFileHD(STHD);
                        cout<<endl;
                    }
                    else if(n2==5)
                    {
                        if(STHD.Head==NULL)
                        {
                            cout<<"\nDanh sach hoa don trong\n"<<endl;
                        }
                        else{
                            deleteHD(STHD);
                            cout<<endl;
                        }
                    }
                    else if(n2==6)
                    {
                        if(STHD.Head==NULL)
                        {
                            cout<<"Danh sach hoa don trong"<<endl;
                        }
                        else{
                            while(true)
                            {   int tl;
                                menuHDSX();
                                cin>>tl;
                                if(tl==1)
                                {
                                    SortHDofNgayLap(STHD);
                                }
                                else if(tl==2)
                                {
                                    SortHDofMa(STHD);
                                }
                                else if(tl==0)
                                {
                                    break;
                                }
                                else{
                                    cout<<"Vui long chon lai"<<endl;
                                }
                            }
                        }
                    }
                    else if(n2==7)
                    {
                        if(STHD.Head==NULL)
                        {
                            cout<<"Danh sach hoa don trong"<<endl;
                        }
                        else{
                            while(true)
                                {
                                    int tl;
                                    menuHDTK();
                                    cin>>tl;
                                    cin.ignore();
                                    if(tl==1)
                                    {
                                        SearchHDofMaKH(STHD);
                                        cout<<endl;
                                    }
                                    else if(tl==2)
                                    {
                                        SearchHDofMaNV(STHD);
                                        cout<<endl;
                                    }
                                    else if(tl==3)
                                    {
                                        SearchHDofMaMH(STHD);
                                        cout<<endl;
                                    }
                                    else if(tl==4)
                                    {
                                        SearchHDofMaHD(STHD);
                                        cout<<endl;
                                    }
                                    else if(tl==0)
                                    {
                                        break;
                                    }
                                    else{
                                        cout<<"Vui long chon lai"<<endl;
                                    }
                                }
                                                    }
                    }
                    else if(n2==8)
                    {
                        if(STHD.Head==NULL)
                        {
                            cout<<"Danh sach hoa don trong"<<endl;
                        }
                        else
                        {
                            while(true)
                            {
                                int tl;
                                menuHDDT();
                                cin>>tl;
                                cin.ignore();
                                if(tl==1)
                                {
                                    DoanhThuTheoNgay(STHD);
                                    cout<<endl;
                                }
                                else if(tl==2)
                                {
                                    DoanhThuTheoThang(STHD);
                                    cout<<endl;
                                }
                                else if(tl==0)
                                {
                                    break;
                                }
                                else{
                                    cout<<"vui long nhap lai"<<endl;
                                }
                            }
                        }
                    }
                    else if(n2==9)
                    {
                        if(STHD.Head==NULL)
                        {
                            cout<<"Danh sach hoa don trong"<<endl;
                        }
                        else{
                            SpMuaNhieu(STHD);
                        }
                    }
                    else if(n2==10)
                    {
                        if(STHD.Head==NULL)
                        {
                            cout<<"Danh sach mat hang trong"<<endl;
                        }
                        else{
                            ThangMuaNhieu(STHD);
                            cout<<endl;
                        }
                    }
                    else if(n2==11)
                    {
                        if(STHD.Head==NULL)
                        {
                            cout<<"Danh sach mat hang trong"<<endl;
                        }
                        else{
                            MHkoBanDuoc(STHD);
                            cout<<endl;
                        }
                    }
                    else if(n2==0)
                    {
                        break;
                    }
                    else{
                        cout<<"-->Vui long nhap lai<--\n"<<endl;
                    }
                }
            }
        }
        else if(n==3)
        {
            while(true)
            {
                menuKH();
                int n3;
                cin>>n3;
                if(n3==1)
                {
                    inputDSKH(STKH);
                    cout<<endl;
                }
                else if(n3==2)
                {
                    if(STKH.Head==NULL)
                    {
                        cout<<"-->Danh sach khach hang trong<--\n"<<endl;
                    }
                    else{
                        outputDSKH(STKH);
                        cout<<endl;
                    }
                }
                else if(n3==3)
                {
                    writeFileKH(STKH);
                    cout<<endl;
                }
                else if(n3==4)
                {
                    readFileKH(STKH);
                    cout<<endl;
                }
                else if(n3==5)
                {
                    if(STKH.Head==NULL)
                    {
                        cout<<"\nDanh sach khach hang trong\n"<<endl;
                    }
                    else{
                        deleteKH(STKH);
                        cout<<endl;
                    }
                }
                else if(n3==6)
                {
                    if(STKH.Head==NULL)
                    {
                        cout<<"-->Danh sach khach hang trong<---\n"<<endl;
                    }
                    else{
                        while(true)
                        {
                            int tl;
                            menuKHSX();
                            cin>>tl;
                            if(tl==1)
                            {
                                SortKHofMa(STKH);
                            }
                            else if(tl==2)
                            {
                                SortKHofTen(STKH);
                            }
                            else if(tl==0)
                            {
                                break;
                            }
                            else{
                                cout<<"Vui long chon lai \n"<<endl;
                            }
                        }

                    }
                }
                else if(n3==0)
                {
                    break;
                }
                else{
                    cout<<"-->Vui long chon lai<--\n"<<endl;
                }
            }
        }
        else if(n==4)
        {
             while(true)
             {
                 menuNV();
                 int n4;
                 cin>>n4;
                 cout<<endl;
                 if(n4==1)
                 {
                     inputDSNV(STNV);
                 }
                 else if(n4==2)
                 {
                     if(STNV.Head==NULL)
                     {
                         cout<<"-->Danh sach nhan vien trong<--\n"<<endl;
                     }
                     else{
                        outputDSNV(STNV);
                        cout<<endl;
                     }
                 }
                 else if(n4==3)
                 {
                     writeFileNV(STNV);
                     cout<<endl;
                 }
                 else if(n4==4)
                 {
                     readFileNV(STNV);
                     cout<<endl;
                 }
                 else if(n4==5)
                 {
                     if(STNV.Head==NULL)
                     {
                         cout<<"\nDanh sach nhan vien trong\n"<<endl;
                     }
                     else{
                        deleteNV(STNV);
                        cout<<endl;
                     }
                 }
                  else  if(n4==6)
                 {
                     if(STNV.Head==NULL)
                     {
                         cout<<"Danh sach nhan vien trong"<<endl;
                     }
                     else{
                         while (true)
                         {
                             int tl;
                             menuSXNV();
                             cin>>tl;
                             if(tl==1)
                             {
                                 SortNVofTen(STNV);
                             }
                             else if(tl==2)
                             {
                                 SortNVofMa(STNV);
                             }
                             else if(tl==0)
                             {
                                 break;
                             }
                             else {
                                cout<<"Vui long chon lai"<<endl;
                             }
                         }

                     }
                 }
                 else if(n4==0)
                 {
                     break;
                 }
                 else{
                    cout<<"-->Vui long chon lai<--\n"<<endl;
                 }
             }
        }
        else if(n==0)
        {
            exit(0);
        }
        else{
            cout<<"--->Vui long chon lai<----\n"<<endl;
        }
    }

   return 0;
}
