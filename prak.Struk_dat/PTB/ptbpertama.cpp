#include <iostream>

using namespace std;

struct ptb{
    string isi;
    ptb *left, *right, *atas;
};

ptb *root,  *newnode, *cur, *bantu, *p, *b;
string letak;

bool ptb_kosong() {
    if(root==NULL)
    return (true);
    else return(false);
}

void buatbaru( string isinya){
    if(root != NULL){
        cout << "Pohon telah dibuat";
    } else {
        root = new ptb();
        root->isi = isinya;

        root->left = NULL;
        root->right = NULL;
        root->atas = NULL;
        cout << "PTB berhasil dibuat";
    }
}

void sisipnode(string isinya){
    if( root == NULL){
        buatbaru(isinya);
    } else {
        cur = root;
        newnode = new ptb();
        newnode->isi = isinya;
        while(cur != NULL && cur->isi!=isinya){
            bantu = cur;
            if(isinya < cur->isi){
                cur = cur->left;
                letak = "left";
            } else if (isinya > cur->isi){
                cur = cur->right;
                letak = "right";
            }
        }
        if(letak == "left"){
           bantu->left = newnode;
        } else if(letak == "right"){
           bantu->right = newnode;
        }
    }
}

void preorder(ptb* akar) {
    if (akar != NULL) {
        cout << "Nilai : " << akar->isi<<endl<<endl;
        preorder(akar->left);
        preorder(akar->right);
    }
}

void inorder(ptb* akar) {
    if (akar != NULL) {
        inorder(akar->left);
        cout << "Nilai : " << akar->isi<<endl<<endl;
        inorder(akar->right);
    }
}

void postorder(ptb* akar) {
    if (akar != NULL) {
        postorder(akar->left);
        postorder(akar->right);
        cout << "Nilai : " << akar->isi<<endl<<endl;
    }
}

void hapus() {
    ptb *temp;
    if(ptb_kosong()){
        cout << "PTB dalam kondisi kosong!" << endl;
        return;
    }
    
    if (p->left == NULL && p->right == NULL) {
        if (b == root && p == root)
            root = NULL;
        else {
            if (p == b->left)
                b->left = NULL;
            else
                b->right = NULL;
        }
        delete p;
    } else if (p->left != NULL && p->right != NULL) {
        temp = p->left;
        b = p;
        while (temp->right != NULL) {
            b = temp;
            temp = temp->right;
        }
        p->isi = temp->isi;
        if (b == p)
            b->left = temp->left;
        else
            b->right = temp->left;
        delete temp;
    } else if (p->left != NULL && p->right == NULL) {
        if (b == p)
            root = p->left;
        else {
            if (p == b->left)
                b->left = p->left;
            else
                b->right = p->left;
        }
        delete p;
    } else if (p->left == NULL && p->right != NULL) {
        if (b == p)
            root = p->right;
        else {
            if (p == b->right)
                b->right = p->right;
            else
                b->left = p->right;
        }
        delete p;
    }
    cout << endl;
    cout << "Data berhasil Dihapus." << endl;
}

void hapusnode(string IH) {
    if (ptb_kosong()){
        cout << "Data dengan nilai " << IH  << " tidak ditemukan dalam PTB." << endl << endl;
    }else {
        b = root;
        p = root;
        while (p != NULL && IH != p->isi) {
            b = p;
            if (IH < p->isi)
                p = b->left;
            else
                p = b->right;
        }
      
    }
    if(p==NULL){
        cout << "Data dengan nilai " << IH  << " tidak ditemukan dalam PTB." << endl << endl;
    }else{
        hapus();
    }
}

void cetak() {
    int pil;
    cout<<"Menu Tampil Data"<<endl;
    cout<<"1. Preorder"<<endl;
    cout<<"2. Inorder"<<endl;
    cout<<"3. Postorder"<<endl;
    cout<<"Pilih metode : "; cin>>pil;
    switch(pil){
        case 1 : cout<<"Menampilkan Data Berdasarkan Preorder : "<<endl; preorder(root); break;
        case 2 : cout<<"Menampilkan Data Berdasarkan Inorder : "<<endl; inorder(root); break;
        case 3 : cout<<"Menampilkan Data Berdasarkan Postorder : "<<endl; postorder(root); break;
        default:cout<<"pilihan salah";
    }
    return;
}

int main(){

    system("cls");
    sisipnode("3");
    sisipnode("1");
    sisipnode("2");
    sisipnode("4");
    system("pause");
    cetak();
    hapusnode("1");
    cetak();

}