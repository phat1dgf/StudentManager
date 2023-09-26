#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct sinhVien
{
    string hoTen;
    int Tuoi;
    double Diem;
    string MSSV;
};

class Node
{
public:
    struct sinhVien sinhvien;
    Node *next;
    Node *pre;
    Node()
    {
        next = NULL;
        pre = NULL;
    }
};

class danhSachSV
{
public:
    struct Node node;
    Node *head;
    danhSachSV()
    {
        head = NULL;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }

    double setDiem(double diem)
    {
        while (diem < 0 || diem > 10)
        {
            cout << "Khong hop le" << endl;
            cout << "Nhap lai diem: " << endl;
            cin >> diem;
        }
        return diem;
    }

    int setTuoi(int tuoi)
    {
        while (tuoi < 18 || tuoi > 60)
        {
            cout << "Khong hop le" << endl;
            cout << "Nhap lai tuoi: " << endl;
            cin >> tuoi;
        }
        return tuoi;
    }

    // them
    void add(string hoten, int tuoi, double diem, string mssv)
    {
        if (isEmpty())
        {
            Node *newSinhVien = new Node();
            newSinhVien->sinhvien.hoTen = hoten;
            newSinhVien->sinhvien.Diem = setDiem(diem);
            newSinhVien->sinhvien.Tuoi = setTuoi(tuoi);
            newSinhVien->sinhvien.MSSV = mssv;
            head = newSinhVien;
        }
        else
        {
            Node *newSinhVien = new Node();
            newSinhVien->sinhvien.hoTen = hoten;
            newSinhVien->sinhvien.Diem = setDiem(diem);
            newSinhVien->sinhvien.Tuoi = setTuoi(tuoi);
            newSinhVien->sinhvien.MSSV = mssv;
            Node *cur = head;
            while (cur->next != NULL)
            {
                cur = cur->next;
            }
            newSinhVien->pre = cur;
            cur->next = newSinhVien;
        }
    }
    // sua
    void update(string mssv)
    {
        if (isEmpty())
        {
            cout << "Hien tai danh sach sinh vien khong co du lieu" << endl;
        }
        else
        {
            Node *cur = head;
            while (cur != NULL)
            {
                if (mssv == cur->sinhvien.MSSV)
                {
                    int option;
                    do
                    {
                        cout << "1 - Ten" << endl;
                        cout << "2 - Tuoi" << endl;
                        cout << "3 - Diem" << endl;
                        cout << "4 - MSSV" << endl;
                        cout << "0 - Thoat" << endl;
                        cout << "Nhap lua chon: ";
                        cin >> option;
                        switch (option)
                        {
                        case 1:
                        {
                            string ten;
                            cout << "Nhap ten: ";
                            cin >> ten;
                            cur->sinhvien.hoTen = ten;
                            break;
                        }
                        case 2:
                        {
                            int tuoi;
                            cout << "Nhap tuoi: ";
                            cin >> tuoi;
                            cur->sinhvien.Tuoi = tuoi;
                            break;
                        }
                        case 3:
                        {
                            double diem;
                            cout << "Nhap diem: ";
                            cin >> diem;
                            cur->sinhvien.Diem = diem;
                            break;
                        }
                        case 4:
                        {
                            string MSSV;
                            cout << "Nhap MSSV: ";
                            cin >> MSSV;
                            cur->sinhvien.MSSV = MSSV;
                            break;
                        }
                        default:
                            break;
                        }
                    } while (option != 0);
                    break;
                }
                else
                {
                    cur = cur->next;
                }
            }
        }
    }
    // xoa
    void erase(string mssv)
    {
        cout << "0" << endl;
        if (isEmpty())
        {
            cout << "Hien tai danh sach sinh vien khong co du lieu" << endl;
        }
        else
        {
            Node *cur = head;
            while (cur != NULL)
            {
                if (mssv == cur->sinhvien.MSSV && head == cur)
                {
                    head = cur->next;
                    cur->next = NULL;
                    head->pre = NULL;
                    delete cur;
                    cout << "1" << endl;
                    break;
                }
                else if (mssv == cur->sinhvien.MSSV && cur != head && cur->next != NULL)
                {
                    Node *preNode = cur->pre;
                    Node *nextNode = cur->next;
                    preNode->next = nextNode;
                    nextNode->pre = preNode;
                    delete cur;
                    cout << "2" << endl;
                    break;
                }
                else if (mssv == cur->sinhvien.MSSV && cur->next == NULL)
                {
                    Node *preNode = cur->pre;
                    preNode->next = NULL;
                    delete cur;
                    cout << "3" << endl;
                }
                else
                {
                    cur = cur->next;
                }
            }
        }
    }
    // tim
    void search(string textToFind)
    {
        if (isEmpty())
        {
            cout << "Hien tai danh sach sinh vien khong co du lieu" << endl;
        }
        else
        {
            Node *cur = head;
            int stt = 1;
            cout << setw(5) << "STT"
                 << setw(15) << "MSSV"
                 << setw(20) << "Ten"
                 << setw(10) << "Tuoi"
                 << setw(10) << "Diem" << endl;

            // In dòng ngăn cách
            cout << setfill('-') << setw(60) << "-" << endl;
            cout << setfill(' '); // Đặt lại fill character về khoảng trắng
            while (cur->next != NULL)
            {
                if (cur->sinhvien.hoTen.find(textToFind) >= 0 && cur->sinhvien.hoTen.find(textToFind) <= cur->sinhvien.hoTen.length())
                {

                    cout << setw(5) << stt
                         << setw(15) << cur->sinhvien.MSSV
                         << setw(20) << cur->sinhvien.hoTen
                         << setw(10) << cur->sinhvien.Tuoi
                         << setw(10) << cur->sinhvien.Diem << endl;
                    stt++;
                }
                cur = cur->next;
            }
        }
    }
    // in
    void display()
    {

        if (isEmpty())
        {
            cout << "Hien tai danh sach sinh vien khong co du lieu" << endl;
        }
        else
        {
            int stt = 1;
            Node *cur = head;
            // In tiêu đề của bảng
            cout << setw(5) << "STT"
                 << setw(15) << "MSSV"
                 << setw(20) << "Ten"
                 << setw(10) << "Tuoi"
                 << setw(10) << "Diem" << endl;

            // In dòng ngăn cách
            cout << setfill('-') << setw(60) << "-" << endl;
            cout << setfill(' '); // Đặt lại fill character về khoảng trắng
            while (cur != NULL)
            {

                cout << setw(5) << stt
                     << setw(15) << cur->sinhvien.MSSV
                     << setw(20) << cur->sinhvien.hoTen
                     << setw(10) << cur->sinhvien.Tuoi
                     << setw(10) << cur->sinhvien.Diem << endl;
                stt++;
                cur = cur->next;
            }
        }
    }
    // sap xep
    void sapxep()
    {
        cout << "2";
        Node *newHead = NULL;
        Node *nextcur = NULL;

        for (newHead = head; newHead != NULL; newHead = newHead->next)
        {
            for (nextcur = newHead->next; nextcur != NULL; nextcur = nextcur->next)
            {
                if (newHead->sinhvien.Diem > nextcur->sinhvien.Diem)
                {
                    cout << "2";
                    Node *temp = new Node();
                    temp->sinhvien = newHead->sinhvien;
                    newHead->sinhvien = nextcur->sinhvien;
                    nextcur->sinhvien = temp->sinhvien;
                    cout << "1";
                }
            }
        }
        display();
    }
    // thong ke
    void statistic()
    {
        int tongSoSinhVien = 0;
        int sinhVienDuoiTrungBinh = 0;
        int sinhVienTrenTrungBinh = 0;
        int sinhVienGioi = 0;
        double diemTong = 0;
        int tongTuoi = 0;
        Node *cur = head;
        while (cur != NULL)
        {
            tongSoSinhVien++;
            if (cur->sinhvien.Diem < 5)
            {
                sinhVienDuoiTrungBinh++;
            }
            if (cur->sinhvien.Diem >= 5)
            {
                sinhVienTrenTrungBinh++;
            }
            if (cur->sinhvien.Diem >= 8)
            {
                sinhVienGioi++;
            }
            diemTong = diemTong + cur->sinhvien.Diem;
            tongTuoi = tongTuoi + cur->sinhvien.Tuoi;
            cur = cur->next;
        }

        cout << "Tong so sinh vien: " << tongSoSinhVien << endl;
        cout << "So sinh vien duoi trung binh (<5): " << sinhVienDuoiTrungBinh << endl;
        cout << "So sinh vien tren trung binh (>=5): " << sinhVienTrenTrungBinh << endl;
        cout << "So sinh vien loai gioi (>=8): " << sinhVienGioi << endl;
        cout << "Diem trung binh toan bo sinh vien: " << diemTong / tongSoSinhVien << endl;
        cout << "Tuoi trung binh: " << (double)tongTuoi / tongSoSinhVien << endl;
    }
    void save()
    {
        string filename = "C:/Users/Phat/Desktop/QLSV.txt";
        ofstream file(filename);
        if (file.is_open())
        {
            Node *cur = head;
            while (cur != NULL)
            {
                file << cur->sinhvien.hoTen << endl;
                file << cur->sinhvien.MSSV << endl;
                file << cur->sinhvien.Tuoi << endl;
                file << cur->sinhvien.Diem << endl;

                cur = cur->next;
            }
            file.close();
            cout << "Danh sach sinh vien da duoc luu" << filename << endl;
        }
        else
            cout << "Khong the luu danh sach sinh vien" << endl;
    }
};

int main()
{
    danhSachSV QuanLySV;
    int option;
    string ten;
    int tuoi;
    double diem;
    string mssv;
    do
    {
        cout << "Danh sach thao tac:" << endl;
        cout << "1 - In danh sach" << endl;
        cout << "2 - Them" << endl;
        cout << "3 - Sua" << endl;
        cout << "4 - Xoa" << endl;
        cout << "5 - Tim kiem (theo ten)" << endl;
        cout << "6 - Sap xep" << endl;
        cout << "7 - Thong ke" << endl;
        cout << "8 - Sao luu" << endl;
        cout << "9 - Clear man hinh" << endl;
        cout << "0 - Thoat" << endl;
        cout << "Nhap thao tac: ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            QuanLySV.display();
        }
        break;
        case 2:
        {
            cout << "Nhap MSSV: ";
            cin >> mssv;
            cout << endl;
            cout << "Nhap ten: ";
            cin >> ten;
            cout << endl;
            cout << "Nhap tuoi: ";
            cin >> tuoi;
            cout << endl;
            cout << "Nhap diem: ";
            cin >> diem;
            cout << endl;
            QuanLySV.add(ten, tuoi, diem, mssv);
        }
        break;
        case 3:
        {
            cout << "Nhap MSSV: ";
            cin >> mssv;
            QuanLySV.update(mssv);
        }
        break;
        case 4:
        {
            cout << "Nhap MSSV: ";
            cin >> mssv;
            QuanLySV.erase(mssv);
        }
        break;
        case 5:
        {
            cout << "Nhap: ";
            string textToFind;
            cin >> textToFind;
            QuanLySV.search(textToFind);
        }
        break;
        case 6:
        {
            QuanLySV.sapxep();
        }
        break;
        case 7:
        {
            QuanLySV.statistic();
        }
        break;
        case 8:
        {
            QuanLySV.save();
        }
        break;
        case 9:
        {
            system("CLS");
        }
        break;
        default:
            cout << "Chon 1 thao tac ben duoi" << endl;
        }
    } while (option != 0);
    return 0;
}
