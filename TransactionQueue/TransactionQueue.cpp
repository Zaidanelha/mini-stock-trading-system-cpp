#include <iostream>
using namespace std;

#define MAX 5

struct Transaksi {
    int id;
    string jenis;
    string kode;
    int lot;
};

struct Queue {
    Transaksi data[MAX];
    int front;
    int rear;
};

Queue q = { {}, -1, -1 };

bool isFull() {
    return (q.rear + 1) % MAX == q.front;
}

bool isEmpty() {
    return q.front == -1;
}

void enqueue() {
    if (isFull()) {
        cout << "Antrian penuh!\n";
        return;
    }

    Transaksi t;
    cout << "ID: "; cin >> t.id;
    cout << "Jenis (Beli/Jual): "; cin >> t.jenis;
    cout << "Kode Saham: "; cin >> t.kode;
    cout << "Jumlah Lot: "; cin >> t.lot;

    if (isEmpty())
        q.front = 0;

    q.rear = (q.rear + 1) % MAX;
    q.data[q.rear] = t;

    cout << "Transaksi masuk ke antrian.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "Transaksi diproses:\n";
    cout << q.data[q.front].id << " - "
        << q.data[q.front].jenis << " - "
        << q.data[q.front].kode << endl;

    if (q.front == q.rear)
        q.front = q.rear = -1;
    else
        q.front = (q.front + 1) % MAX;
}

void display() {
    if (isEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "\n=== ANTRIAN TRANSAKSI ===\n";
    int i = q.front;
    while (true) {
        cout << q.data[i].id << " - "
            << q.data[i].jenis << " - "
            << q.data[i].kode << endl;

        if (i == q.rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n===== TRANSACTION QUEUE =====\n";
        cout << "1. Tambah Transaksi\n";
        cout << "2. Proses Transaksi\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: enqueue(); break;
        case 2: dequeue(); break;
        case 3: display(); break;
        case 0: cout << "Keluar...\n"; break;
        default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}