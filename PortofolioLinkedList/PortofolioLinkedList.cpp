#include <iostream>
#include <string>
using namespace std;

struct Saham {
    string kode;
    string nama;
    double harga;
    int lot;
    double total;
};

struct Node {
    Saham data;
    Node* next;
};

Node* head = NULL;

// ================= TAMBAH =================
void tambahSaham() {
    Node* newNode = new Node();

    cout << "Kode Saham: ";
    cin >> newNode->data.kode;

    cin.ignore();
    cout << "Nama Perusahaan: ";
    getline(cin, newNode->data.nama);

    cout << "Harga Beli: ";
    cin >> newNode->data.harga;

    cout << "Jumlah Lot: ";
    cin >> newNode->data.lot;

    newNode->data.total = newNode->data.harga * newNode->data.lot;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    cout << "Saham berhasil ditambahkan!\n";
}

// ================= TAMPIL =================
void tampilkan() {
    if (head == NULL) {
        cout << "Portofolio kosong.\n";
        return;
    }

    Node* temp = head;
    cout << "\n=== PORTOFOLIO SAHAM ===\n";
    while (temp != NULL) {
        cout << "Kode  : " << temp->data.kode << endl;
        cout << "Nama  : " << temp->data.nama << endl;
        cout << "Total : " << temp->data.total << endl;
        cout << "------------------------\n";
        temp = temp->next;
    }
}

// ================= CARI =================
void cariSaham() {
    string kode;
    cout << "Masukkan kode saham: ";
    cin >> kode;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->data.kode == kode) {
            cout << "Data ditemukan!\n";
            cout << "Nama  : " << temp->data.nama << endl;
            cout << "Total : " << temp->data.total << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Saham tidak ditemukan.\n";
}

// ================= HAPUS =================
void hapusSaham() {
    string kode;
    cout << "Masukkan kode saham yang dihapus: ";
    cin >> kode;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data.kode != kode) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Saham tidak ditemukan.\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Saham berhasil dihapus.\n";
}

// ================= TOTAL =================
void totalPortofolio() {
    double total = 0;
    Node* temp = head;

    while (temp != NULL) {
        total += temp->data.total;
        temp = temp->next;
    }

    cout << "Total nilai portofolio: " << total << endl;
}

// ================= MAIN =================
int main() {
    int pilihan;

    do {
        cout << "\n===== STOCK PORTFOLIO SYSTEM =====\n";
        cout << "1. Tambah Saham\n";
        cout << "2. Tampilkan\n";
        cout << "3. Cari Saham\n";
        cout << "4. Hapus Saham\n";
        cout << "5. Total Portofolio\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: tambahSaham(); break;
        case 2: tampilkan(); break;
        case 3: cariSaham(); break;
        case 4: hapusSaham(); break;
        case 5: totalPortofolio(); break;
        case 0: cout << "Keluar...\n"; break;
        default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}