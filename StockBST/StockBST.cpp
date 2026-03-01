#include <iostream>
#include <string>
using namespace std;

struct Saham {
    string kode;
    string nama;
};

struct Node {
    Saham data;
    Node* left;
    Node* right;
};

Node* createNode(Saham data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, Saham data) {
    if (root == NULL)
        return createNode(data);

    if (data.kode < root->data.kode)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

Node* search(Node* root, string kode) {
    if (root == NULL || root->data.kode == kode)
        return root;

    if (kode < root->data.kode)
        return search(root->left, kode);

    return search(root->right, kode);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data.kode << " - "
            << root->data.nama << endl;
        inorder(root->right);
    }
}

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, string kode) {
    if (root == NULL) return root;

    if (kode < root->data.kode)
        root->left = deleteNode(root->left, kode);
    else if (kode > root->data.kode)
        root->right = deleteNode(root->right, kode);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.kode);
    }
    return root;
}

int main() {
    Node* root = NULL;
    int pilihan;
    Saham s;
    string kode;

    do {
        cout << "\n===== STOCK DATABASE (BST) =====\n";
        cout << "1. Insert Saham\n";
        cout << "2. Cari Saham\n";
        cout << "3. Tampilkan Inorder\n";
        cout << "4. Hapus Saham\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Kode: ";
            cin >> s.kode;
            cin.ignore();
            cout << "Nama: ";
            getline(cin, s.nama);
            root = insert(root, s);
            break;

        case 2:
            cout << "Kode dicari: ";
            cin >> kode;
            if (search(root, kode))
                cout << "Saham ditemukan.\n";
            else
                cout << "Tidak ditemukan.\n";
            break;

        case 3:
            cout << "\nData Terurut:\n";
            inorder(root);
            break;

        case 4:
            cout << "Kode dihapus: ";
            cin >> kode;
            root = deleteNode(root, kode);
            break;
        }

    } while (pilihan != 0);

    return 0;
}