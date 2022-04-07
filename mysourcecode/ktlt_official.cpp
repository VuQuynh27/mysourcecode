#include<iostream>
#include<string>
#include<sstream>
#include<fstream>


using namespace std;


bool KiemTraThongTin(string ThongTin);
bool KiemTraNgay(string date);
string DaoTen(string HoTen);
bool SapXep(string HoTen1, string HoTen2){
return DaoTen(HoTen1) < DaoTen(HoTen2) ? true : false;
};
struct SinhVien;

struct Lop;
void ThemSinhVien();
void InDanhSachMotLop();
void clear();

struct DanhSachLop;
void DocFile();
void Tim();
void ThemLop();
void ThemSinhVienVaoLop();
void CapNhatDiem();
void InDanhSachTatCa();
void LuuFile();
void InTenLop();


struct SinhVien{
    string HoTen;
    string MSSV;
    string NgaySinh;
    string GioiTinh;
    string TenLop;
    string DiemKTLT;
    SinhVien* next;


    SinhVien(string HoTen, string MSSV, string GioiTinh, string NgaySinh, string TenLop, string DiemKTLT){
        this->HoTen = HoTen;
        this->MSSV = MSSV;
        this->GioiTinh = GioiTinh;
        this->NgaySinh = NgaySinh;
        this->TenLop = TenLop;
        this->DiemKTLT = DiemKTLT;
        this->next = nullptr;
    };


    ~SinhVien();
};

struct Lop{
    string TenLop;
    SinhVien* head;
    Lop* next;
    int SoLuong;

    Lop(string TenLop){
        this->TenLop = TenLop;
        this->next = nullptr;
        this->SoLuong = 0;
    }

    ~Lop(){
        this->clear();
    };


    void ThemSinhVien(string HoTen, string MSSV, string GioiTinh,string NgaySinh, string TenLop, string DiemKTLT){
        SinhVien* SinhVienMoi = new SinhVien(HoTen, MSSV, GioiTinh, NgaySinh, TenLop, DiemKTLT);
        if (this->SoLuong == 0){
            this->head = SinhVienMoi;
            this->SoLuong++;
            return;
        }
        SinhVien* curr = this->head;
        if (SapXep(SinhVienMoi->HoTen, curr->HoTen)){
            SinhVienMoi->next = curr;
            this->head = SinhVienMoi;
            this->SoLuong++;
            return;
        }
        while(curr->next){
            SinhVien* nextCurr = curr->next;
            if (SapXep(curr->HoTen, SinhVienMoi->HoTen) && SapXep(SinhVienMoi->HoTen, nextCurr->HoTen)){
                curr->next = SinhVienMoi;
                SinhVienMoi->next = nextCurr;
                this->SoLuong++;
                return;
            }
            curr = curr->next;
        }
        curr->next = SinhVienMoi;
        this->SoLuong++;
    };


    void InDanhSachMotLop(){
        if (this->SoLuong == 0){
            return; 
        };
        SinhVien* curr = this->head;
        while(curr){
            cout << curr->HoTen << " " << curr->MSSV << " " << curr->GioiTinh << " " << curr->NgaySinh << " " << curr->TenLop << " " << curr->DiemKTLT << endl;
            curr = curr->next;
        }
    };

    void clear(){
        SinhVien* curr = this->head;
        SinhVien* nextCurr;
        while(curr){
            nextCurr = curr->next;
            curr->next = nullptr;
            delete curr;
            curr = nextCurr;
        }
        this->head = nullptr;
        this->SoLuong = 0;
    }
};

struct DanhSachLop{
    Lop* head;
    int SoLuong;

    DanhSachLop(){
        this->head = new Lop("");
        this->SoLuong = 0;
        this->DocFile();
    };

    ~DanhSachLop(){
        this->clear();
    }


    void DocFile(){
        ifstream File;
        File.open("dssv.txt");
        if(File.is_open()){
            string record;
            while(getline(File, record)){
                string HoTen, MSSV, GioiTinh, NgaySinh, TenLop;
                int n[5]{0};
                string DiemKTLT = "";
                int index = 0;

                for (int i=0;i<record.length();i++){
                    if (record[i] == ','){
                        n[index] = i;
                        index++;
                    }
                }

                if (n[4] == 0){
                    n[4] = record.length();
                }else{
                    DiemKTLT = record.substr(n[4]+1, record.length() - n[4] - 1).c_str();
                }

                HoTen = record.substr(0, n[0]);
                MSSV = record.substr(n[0]+1, n[1] - n[0] - 1);
                GioiTinh = record.substr(n[1]+1, n[2] - n[1] - 1);
                NgaySinh = record.substr(n[2]+1, n[3] - n[2] - 1);
                TenLop = record.substr(n[3]+1, n[4] - n[3] - 1);

                this->ThemSinhVienVaoLop(HoTen, MSSV, GioiTinh, NgaySinh, TenLop, DiemKTLT);
            }
            File.close();
        }
    }



    void ThemSinhVienVaoLop(string HoTen, string MSSV, string GioiTinh,string NgaySinh, string TenLop, string DiemKTLT){
        if(this->TonTaiLop(TenLop)){
            this->Tim(TenLop)->ThemSinhVien(HoTen, MSSV, GioiTinh, NgaySinh, TenLop, DiemKTLT);
        }
		else{
            this->ThemLop(TenLop);
            this->Tim(TenLop)->ThemSinhVien(HoTen, MSSV, GioiTinh, NgaySinh, TenLop, DiemKTLT);
        }
    }

    void ThemLop(string TenLop){
        if (this->SoLuong == 0){
            Lop* curr = this->head;
            curr->TenLop = TenLop;
            this->SoLuong++;
            return;
        }
        Lop* LopMoi = new Lop(TenLop);
        Lop* curr = this->head;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = LopMoi;
        this->SoLuong++;
        return;
    };



    void CapNhatDiem(){
        if (this->SoLuong == 0){
            return;
        }
        int SoLuongSV = 0;
        Lop* curr = this->head;
        while(curr){
            SinhVien* currSV = curr->head;
            while(currSV){
                if (currSV->DiemKTLT == ""){
                    SoLuongSV++;
                    cout << currSV->HoTen << " " << currSV->MSSV << " " << currSV->GioiTinh << " " << currSV->NgaySinh << " " << currSV->TenLop << " " << currSV->DiemKTLT << endl;
                    cout << "Nhap vao diem KTLT: ";
                    getline(cin, currSV->DiemKTLT);
                }
                currSV = currSV->next;
            }
            curr = curr->next;
        };
        if (SoLuongSV == 0){
            cout << "Tat ca sinh vien da co diem." << endl << endl;
        }
        return;
    }


    bool TonTaiLop(string TenLop){
        if (this->SoLuong == 0){
            return false;
        }
        Lop* curr = this->head;
        while(curr){
            if (curr->TenLop == TenLop){
                return true;
            }
            curr = curr->next;
        }
        return false;
    }


    Lop* Tim(string TenLop){
        Lop* curr = this->head;
        while(curr){
            if (curr->TenLop == TenLop){
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }


    void InDanhSachTatCaSV(){
        if (this->SoLuong == 0){
            return;
        }
        string TenLop = "";
        Lop* curr = this->head;
        while(curr){
            if (TenLop != curr->TenLop){
                cout << "********** DANH SACH SINH VIEN LOP " << curr->TenLop << " *********" << endl;
                TenLop = curr->TenLop;
            }
            curr->InDanhSachMotLop();
            cout << endl;
            curr = curr->next;
        }
    }


    void LuuFile(){
        if (this->SoLuong == 0){
            return;
        }
        string DuLieu = "";
        Lop* curr = this->head;
        while(curr){
            SinhVien* currSV = curr->head;
            while(currSV){
                if (curr->next == nullptr && currSV->next == nullptr){
                    if (currSV->DiemKTLT ==""){
                        DuLieu += currSV->HoTen;
                        DuLieu += ",";
                        DuLieu += currSV->MSSV;
                        DuLieu += ",";
                        DuLieu += currSV->GioiTinh;
                        DuLieu += ",";
                        DuLieu += currSV->NgaySinh;
                        DuLieu += ",";
                        DuLieu += currSV->TenLop;
                    }
					else{
                        DuLieu += currSV->HoTen;
                        DuLieu += ",";
                        DuLieu += currSV->MSSV;
                        DuLieu += ",";
                        DuLieu += currSV->GioiTinh;
                        DuLieu += ",";
                        DuLieu += currSV->NgaySinh;
                        DuLieu += ",";
                        DuLieu += currSV->TenLop;
                        DuLieu += ",";
                        DuLieu += currSV->DiemKTLT;
                    }
                }
				else{
                    if (currSV->DiemKTLT ==""){
                        DuLieu += currSV->HoTen;
                        DuLieu += ",";
                        DuLieu += currSV->MSSV;
                        DuLieu += ",";
                        DuLieu += currSV->GioiTinh;
                        DuLieu += ",";
                        DuLieu += currSV->NgaySinh;
                        DuLieu += ",";
                        DuLieu += currSV->TenLop;
                        DuLieu += "\n";
                    }
					else{
                        DuLieu += currSV->HoTen;
                        DuLieu += ",";
                        DuLieu += currSV->MSSV;
                        DuLieu += ",";
                        DuLieu += currSV->GioiTinh;
                        DuLieu += ",";
                        DuLieu += currSV->NgaySinh;
                        DuLieu += ",";
                        DuLieu += currSV->TenLop;
                        DuLieu += ",";
                        DuLieu += currSV->DiemKTLT;
                        DuLieu += "\n";
                    }
                }
                currSV = currSV->next;
            }
            curr = curr->next;
        };

        ofstream File;
        File.open("dssv.txt");
        if (File.is_open()){
            File << DuLieu;
            File.close();
        }
    }

    void InTenLop(){
        Lop* curr = this->head;
        while(curr){
            cout << curr->TenLop << " ";
            curr = curr->next;
        }
    }

    void clear(){
        if (this->SoLuong == 0){
            return;
        }
        Lop* curr = this->head;
        Lop* nextCurr;
        while(curr){
            nextCurr = curr->next;
            curr->next = nullptr;
            curr->clear();
            delete curr;
            curr = nextCurr;
        }
        this->head = nullptr;
        this->SoLuong = 0;
    }
};


bool KiemTraThongTin(string ThongTin){
    if (ThongTin == ""){
        return false;
    }
    return true;
};

bool KiemTraNgay(string date){
    if (date.length() < 10){
        return false;
    }
    if (date.length() != 10){
        return false;
    }
    int n[2]{0};
    int index = 0;
    for (int i=0;i<date.length();i++){
        if (date[i] == '/'){
            n[index] = i;
            index++;
        }
    }
    if (n[0] == 0 || n[1] == 0){
        return false;
    }
    int Ngay = stoi(date.substr(0,2));
    int Thang = stoi(date.substr(3,2));
    int Nam = stoi(date.substr(6,4));

    if (Thang == 1 || Thang == 3 || Thang == 5 || Thang == 7 || Thang == 8 || Thang == 10 || Thang == 12 && Ngay >0 && Ngay<=31){
        return true;
    }
    if(Thang == 4 || Thang == 6 || Thang == 9|| Thang == 11 && Ngay>0 && Ngay<=30){
        return true;
    }
    if (Thang == 2){
        if ((Nam%400 ==0 || (Nam%100 != 0 && Nam%4 == 0)) && Ngay>0 && Ngay<=29){
            return true;
        }
        if (Ngay>=0 && Ngay<=28){
            return true;
        }
        return false;
    }
    return false;
}

string DaoTen(string HoTen){
    int index = 0;
    for (int i=0;i<HoTen.length();i++){
        if (HoTen[i] == ' '){
            index = i;
        }
    }
    string KetQua;
    index == 0 ? KetQua = HoTen : KetQua = HoTen.substr(index+1, HoTen.length() - index - 1) + " " + HoTen.substr(0,index);
    for (int i=0;i<KetQua.length();i++){
        KetQua[i] = tolower(KetQua[i]);
    }
    return KetQua;
}


int main(){
Menu:
	cout << "************MENU****************" << endl;
    cout << "1. Bo sung ho so sinh vien moi" << endl;
    cout << "2. Cap nhat diem KTLT" << endl;
    cout << "3. In danh sach tat ca sinh vien" << endl;
    cout << "Nhap 1,2,3 de chon, an nut bat ki de thoat" << endl;

    char TuyChon;
    cin >> TuyChon;

    while(true){
        if (TuyChon=='1'){
            cin.ignore();
            DanhSachLop* danhSachLop = new DanhSachLop();
            string HoTen, MSSV, GioiTinh, NgaySinh, TenLop, DiemKTLT;
            cout << "***********THONG TIN SINH VIEN MOI***********" << endl;
        HoTen:
            cout << "Ho va ten sinh vien: ";
            getline(cin, HoTen);
            if (!KiemTraThongTin(HoTen)){
                cout << "Thong tin nay khong duoc bo trong!" << endl << endl;
                goto HoTen;
            }
        MSSV:
            cout << "MSSV: ";
            getline(cin, MSSV);
            if (!KiemTraThongTin(MSSV)){
                cout << "Thong tin nay khong duoc bo trong!" << endl << endl;
                goto MSSV;
            }
        GioiTinh:
            cout << "Gioi tinh: ";
            getline(cin, GioiTinh);
            if (!KiemTraThongTin(GioiTinh)){
                cout << "Thong tin nay khong duoc bo trong!" << endl << endl;
                goto GioiTinh;
            }
        NgaySinh:
            cout << "Ngay sinh (dd/mm/yyyy): ";
            getline(cin, NgaySinh);
            if (!KiemTraThongTin(NgaySinh)){
                cout << "Thong tin nay khong duoc bo trong!" << endl << endl;
                goto NgaySinh;
            }
            if (!KiemTraNgay(NgaySinh)){
                cout << "Ngay sinh sai dinh dang, hay nhap lai. " << endl << endl;
                goto NgaySinh;
            }
        TenLop:
            cout << "Ten lop: ";
            getline(cin, TenLop);
            if (!KiemTraThongTin(TenLop)){
                cout << "Thong tin nay khong duoc bo trong!" << endl << endl;
                goto TenLop;
            }
            cout << "Diem KTLT: ";
            getline(cin, DiemKTLT);
            danhSachLop->ThemSinhVienVaoLop(HoTen, MSSV, GioiTinh, NgaySinh, TenLop, DiemKTLT);
            danhSachLop->LuuFile();
            cout << endl << endl;
            goto Menu;
        }
        else if (TuyChon=='2'){
            DanhSachLop* danhSachLop = new DanhSachLop();
            cin.ignore();
            danhSachLop->CapNhatDiem();
            danhSachLop->LuuFile();
            cout << endl << endl;
            goto Menu;
        }
        else if (TuyChon=='3'){
            DanhSachLop* danhSachLop = new DanhSachLop();
            danhSachLop->InDanhSachTatCaSV();
            cout << endl << endl;
            goto Menu;
        }
        
        else{
		cout<< "Ban muon thoat? Nhan Y de thoat. Nhan phim bat ky de tiep tuc chuong trinh!\n";
		cin>> TuyChon;
		if(TuyChon == 'y'|| TuyChon == 'Y')
		break;
		else{
		cout<< "\n";
		goto Menu;
		}
		}
		return 0;
		}
		
    
    return 0;
}
