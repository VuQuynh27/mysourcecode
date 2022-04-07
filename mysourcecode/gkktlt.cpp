#ifndef MODULES
#define MODULES

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

class Student{
public:
    string name;
    string ID;
    string birth;
    string sex;
    string className;
    string mark;
    Student* next;

    /* Ham khoi tao doi tuong student */
    Student(string name, string ID, string sex, string birth, string className, string mark){
        this->name = name;
        this->ID = ID;
        this->sex = sex;
        this->birth = birth;
        this->className = className;
        this->mark = mark;
        this->next = nullptr;
    };

    /* Ham giai phong vung nho duoc su dung boi con tro */
    ~Student(){};
};

class Class{
public:
    string className;
    Student* head;
    Class* next;
    int count;

    /* Ham khoi tao doi tuong class */
    Class(string className){
        this->className = className;
        this->next = nullptr;
        this->count = 0;
    }
    /* Ham giai phong vung nho duoc su dung boi con tro */
    ~Class(){};

    /* Ham dung de them student moi vao mot class (su dung doi voi classList chua ton tai class nay) */
    void addStudent(string name, string ID, string sex,string birth, string className, string mark){
        Student* newStu = new Student(name, ID, sex, birth, className, mark);
        if (this->count == 0){
            this->head = newStu;
            this->count++;
            return;
        }
        Student* curr = this->head;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = newStu;
        this->count++;
    };

    /* Ham dung de in tat ca student cua mot class */
    void print(){
        if (this->count == 0){
            return; 
        };
        Student* curr = this->head;
        while(curr){
            cout << curr->name << " " << curr->ID << " " << curr->sex << " " << curr->birth << " " << curr->className << " " << curr->mark << endl;
            curr = curr->next;
        }
    };
};

class ClassList{
public:
    Class* head;
    int count;

    ClassList(){
        this->head = nullptr;
        this->count = 0;
    };

    /* Ham dung de them mot class chua ton tai vao classList */
    Class* addClass(string className){
        Class* newClass = new Class(className);
        if (this->count == 0){
            this->head = newClass;
            this->count++;
            return newClass;
        }
        Class* curr = this->head;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = newClass;
        this->count++;
        return newClass;
    };

    /* Ham dung de them mot student vao class (su dung khi classList da ton tai class nay) */
    void addStudent(string name, string ID, string sex,string birth, string className, string mark){
        if(this->isExistClassName(className)){
            this->find(className)->addStudent(name, ID, sex, birth, className, mark);
        }else{
            this->addClass(className)->addStudent(name, ID, sex, birth, className, mark);
        }
        this->saveData();
    }

    /* Kiem tra lop cua student da ton tai hay chua */
    bool isExistClassName(string className){
        if (this->count == 0){
            return false;
        }
        Class* curr = this->head;
        while(curr->next){
            if (curr->className == className){
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    /* Tim va tra ve con tro den class co ten trung voi ten lop cua student */
    Class* find(string className){
        Class* curr = this->head;
        while(curr){
            if (curr->className == className){
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    /* In ra tat ca student cua classList (student cua tat ca cac class)*/
    void printAllStudent(){
        if (this->count == 0){
            return;
        }
        Class* curr = this->head;
        while(curr){
            Student* currStu = curr->head;
            while(currStu){
                cout << currStu->name << " " << currStu->ID << " " << currStu->sex << " " << currStu->birth << " " << currStu->className << " " << currStu->mark << endl;
                currStu = currStu->next;
            }
            curr = curr->next;
        }
    }

    /* Ham dung de luu lai thong tin sinh vien vao file */
    void saveData(){
        if (this->count == 0){
            return;
        }
        string fileData = "";
        Class* curr = this->head;
        while(curr){
            Student* currStu = curr->head;
            while(currStu){
                if (curr->next == nullptr && currStu->next == nullptr){
                    if (currStu->mark ==""){
                        fileData += currStu->name + "," + currStu->ID + "," + currStu->sex + "," + currStu->birth + "," + currStu->className;
                    }else{
                        fileData += currStu->name + "," + currStu->ID + "," + currStu->sex + "," + currStu->birth + "," + currStu->className + "," + currStu->mark;
                    }
                }else{
                    if (currStu->mark ==""){
                        fileData += currStu->name + "," + currStu->ID + "," + currStu->sex + "," + currStu->birth + "," + currStu->className + '\n';
                    }else{
                        fileData += currStu->name + "," + currStu->ID + "," + currStu->sex + "," + currStu->birth + "," + currStu->className + "," + currStu->mark + '\n';
                    }
                }
                currStu = currStu->next;
            }
            curr = curr->next;
        };

        ofstream myFile;
        myFile.open("dssv.txt");
        
        if (myFile.is_open()){
            myFile << fileData;
            myFile.close();
        }
    }
};

/* Ham dung de doc du lieu thong tin sinh vien tu file va luu tru duoi dang danh sach lien ket */
ClassList* createClassList(){
    ClassList* classList = new ClassList;

    ifstream myFile;
    myFile.open("dssv.txt");
    if(myFile.is_open()){
        string record;
        while(getline(myFile, record)){
            string name, ID, sex, birth, className;
            string mark = "";
            int indexArr[5]{0};
            int index = 0;

            for (int i=0;i<record.length();i++){
                if (record[i] == ','){
                    indexArr[index] = i;
                    index++;
                }
            }
            if (indexArr[4] == 0){
                indexArr[4] = record.length();
            }else{
                mark = record.substr(indexArr[4]+1, record.length() - indexArr[4] - 1).c_str();
            }

            name = record.substr(0, indexArr[0]);
            ID = record.substr(indexArr[0]+1, indexArr[1] - indexArr[0] - 1);
            sex = record.substr(indexArr[1]+1, indexArr[2] - indexArr[1] - 1);
            birth = record.substr(indexArr[2]+1, indexArr[3] - indexArr[2] - 1);
            className = record.substr(indexArr[3]+1, indexArr[4] - indexArr[3] - 1);

            classList->addStudent(name, ID, sex, birth, className, mark);
        }
        myFile.close();
    }

    return classList;
}

/* Ham dung de cap nhat diem cho cac sinh vien chua co diem */
ClassList* addMark(ClassList* classList){
    if (classList->count == 0){
        return classList;
    }
    Class* curr = classList->head;
    while(curr){
        Student* currStu = curr->head;
        while(currStu){
            if (currStu->mark == ""){
                cout << currStu->name << " " << currStu->ID << " " << currStu->sex << " " << currStu->birth << " " << currStu->className << " " << currStu->mark << endl;
                cout << "Vui long nhap diem so ban can cap nhat: ";
                getline(cin, currStu->mark);
            }
            currStu = currStu->next;
        }
        curr = curr->next;
    };
    classList->saveData();
    return classList;
}

/* Ham kiem tra cac thong tin co ban cua sinh vien bao gom: ten, mssv, gioi tinh, ngay sinh, ten lop co rong hay khong */
bool isValidInfo(string info){
    if (info == ""){
        return false;
    }
    return true;
};

#endif


int main(){
    cout << "*******************CAC CHUC NANG BAN CO THE THUC HIEN*******************" << endl;
    cout << "1. Bo sung ho so sinh vien moi !!!" << endl;
    cout << "2. Cap nhat diem cho sinh vien !!!" << endl;
    cout << "3. In danh sach tat ca sinh vien !!!" << endl;
    cout << "An 1,2,3 de chon cac chuc nang tuong ung, an nut bat ki de thoat chuong trinh !!!" << endl;

    int userSelect;
    cin >> userSelect;
    if (userSelect == 1){
        cin.ignore();
        ClassList* classList = createClassList();
        string name,ID,sex,birth,className, mark;

        cout << "**************THONG TIN SINH VIEN MOI**************" << endl;
    inputName:
        cout << "Ho va ten sinh vien: ";
        getline(cin, name);
        if (!isValidInfo(name)){
            cout << "Thong tin nay khong duoc bo trong !!!" << endl;
            goto inputName;
        }
    inputID:
        cout << "Ma so sinh vien: ";
        getline(cin, ID);
        if (!isValidInfo(ID)){
            cout << "Thong tin nay khong duoc bo trong !!!" << endl;
            goto inputID;
        }
    inputSex:
        cout << "Gioi tinh sinh vien: ";
        getline(cin, sex);
        if (!isValidInfo(sex)){
            cout << "Thong tin nay khong duoc bo trong !!!" << endl;
            goto inputSex;
        }
    inputBirth:
        cout << "Ngay sinh cua sinh vien (dinh dang dd/mm/yyyy): ";
        getline(cin, birth);
        if (!isValidInfo(birth)){
            cout << "Thong tin nay khong duoc bo trong !!!" << endl;
            goto inputBirth;
        }
    inputClassName:
        cout << "Ten lop cua sinh vien: ";
        getline(cin, className);
        if (!isValidInfo(className)){
            cout << "Thong tin nay khong duoc bo trong !!!" << endl;
            goto inputClassName;
        }
        cout << "Diem cua sinh vien (Enter neu chua co diem): ";
        getline(cin, mark);
        classList->addStudent(name, ID, sex, birth, className, mark);
        classList->printAllStudent();
        return 0;
    }
    if (userSelect == 2){
        ClassList* classList = createClassList();
        cin.ignore();
        classList = addMark(classList);
        return 0;
    }
    if (userSelect == 3){
        ClassList* classList = createClassList();
        classList->printAllStudent();
        return 0;
    }
    return 0;
}
