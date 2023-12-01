#include<iostream>
#include<iomanip>
using namespace std;
struct ptb {
int info;
ptb* left;
ptb* right;
};
ptb* create_node(int value) {
ptb* NB = new ptb;
NB->info = value;
NB->left = nullptr;
NB->right = nullptr;
return NB;
}
ptb* input(ptb* node, int value) {
if (node == nullptr) { return create_node(value); }
if (value < node->info) { node->left = input(node->left, value); }
else if (value > node->info) { node->right = input(node->right, value); }
else { 
cout << "\n\tInput DITOLAK !!!\n";
cout << "\nNIM " << value << " sudah ada dalam tree !\n\n"; 
}
return node;
}
void preorder(ptb* node) {
if (node != nullptr) {
cout << node->info << " ";
preorder(node->left);
preorder(node->right);
}
}
void inorder(ptb* node) {
if (node != nullptr) {
inorder(node->left);
cout << node->info << " ";
inorder(node->right);
}
}
void postorder(ptb* node) {
if (node != nullptr) {
postorder(node->left);
postorder(node->right);
cout << node->info <<" ";
}
}
int main() {
ptb* tree = nullptr;
int menu,value, banyak;
for (char back='y'; back=='y'; ) {
system ("cls");
cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
cout << "| SELAMAT DATANG DI PROGRAM Binary tree |"<< endl;
cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
cout << "| 1. input |"<< endl;
cout << "| 2. Preorder |"<< endl;
cout << "| 3. Inorder |"<< endl;
cout << "| 4. Postorder |"<< endl;
cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
cout << "| 5. exit |"<< endl;
cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
cout << "pilih : ";
cin>>menu;
switch (menu) {
case 1:
system("cls");
cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
cout << "| MENU INPUT |"<< endl;
cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
cout << "\nMasukan NIM yang akan disimpan\n";
for (char lagi = 'y'; lagi != 'n';)
{
cout << "NIM : "; cin >> value;
tree = input(tree, value);
 cout << "Input lagi ? [y/n] : "; cin >> lagi;
}
break;
case 2:
system("cls");
cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
cout << "| MENU Preorder |"<< endl;
cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
cout << endl;
if (tree != nullptr) {
cout << "Preorder : \n";
preorder(tree);
cout << "\n\n";
}
else cout << "\n\t\tTree KOSONG !!!\n\n";
system("pause"); 
break;
case 3:
system("cls");
cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
cout << "| MENU Inorder |"<< endl;
cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
cout << endl;
if (tree != nullptr) {
cout << "Inorder : \n";
inorder(tree);
cout << "\n\n";
}
else cout << "\n\t\tTree KOSONG !!!\n\n";
system("pause"); 
break;
case 4:
system("cls");
cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
cout << "| MENU Postorder |"<< endl;
cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
cout << endl;
if (tree != nullptr) {
cout << "Postorder : \n";
postorder(tree);
cout << "\n\n";
}
else cout << "\n\t\tTree KOSONG !!!\n\n";
system("pause"); 
break;
}
}
}
