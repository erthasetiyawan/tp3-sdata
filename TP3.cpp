/*
/* Created by : Tim 04
*/

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;


class BST{//Khalida Zahra
	private:
	 //Ertha Dwi S  
	    struct Tree
	    {
			char data;
			Tree *left;
			Tree *right;  
			Tree *parent;  
	    };
	
	    struct Tree *newTreeNode(int data) 
	    {
			Tree *node = new Tree;
			node->data = data;
			node->left = NULL;
			node->right = NULL;
			node->parent = NULL;
		
			return node;
	    }
	
	    struct Tree* insertTreeNode(struct Tree *node, char data)
	    {
			static Tree *p;
			Tree *retNode;
		
			if(node == NULL)  {
			    retNode = newTreeNode(data);
			    retNode->parent = p;
			    return retNode;
			}
			if(data <= node->data ) { 
			    p = node;
			    node->left = insertTreeNode(node->left,data);
			} 
			else {
			    p = node;
			    node->right = insertTreeNode(node->right,data);
			} 
			return node;
	    }
	
	//Ertha Dwi S
	public:
	
	    void clear(struct Tree *node)
	    {
			if(node != NULL) {
			    clear(node->left);
			    clear(node->right);
			    delete node;
			}
	    }
	    
	    /* pencarian dari kiri kemudian ke kanan dengan melakukan pembandingan */
	    bool pencarianData(struct Tree *node, char key)
	    {
	    	while (node != NULL) { 
		        if (key < node->data) 
		            node = node->left; 
		        else if (key > node->data) 
		            node = node->right; 
		        else
		            return true; 
		    } 
		    return false; 
	    	
		}
	
	    /* Kiri ke root kemudian ke kanan */
	    void printTreeInOrder(struct Tree *node) ////Fungsi yang akan menjalankan Proses kunjungan secara InOrder
	    {
			if(node == NULL) return;
		
			printTreeInOrder(node->left);
			cout << node->data << " ";
			printTreeInOrder(node->right);
	    }
	
	    /* kiri ke kanan kemudian ke root */
	    void printTreePostOrder(struct Tree *node)  	////Fungsi yang akan menjalankan Proses kunjungan secara PostOrder
	    {
			if(node == NULL) return;
		
			printTreePostOrder(node->left);
			printTreePostOrder(node->right);
			cout << node->data << " ";
	    }
	
	    /* root kemudian ke kiri ke kanan */
	    void printTreePreOrder(struct Tree *node)	//Fungsi yang akan menjalankan Proses kunjungan secara PreOrder
	    {
			if(node == NULL) return;
		
			cout << node->data << " ";
			printTreePreOrder(node->left);
			printTreePreOrder(node->right);
	    }
	
	    /* kebalikan dari in order */
	    void printTreeReverseOrder(struct Tree *node)
	    {
			if(node == NULL) return;
			if(node->left == NULL && node->right == NULL) {
			    cout << node->data << " ";
			    return;
			}
			
			printTreeReverseOrder(node->right);
			cout << node->data << " ";
			printTreeReverseOrder(node->left);
	    }
	    
	    bool uppercaseAlphabets(char abj) 
		{ 
		  	bool status = false;
		    // uppercase 
		    for (char c = 'A'; c <= 'Z'; ++c) {
		    	if(abj == c) {
					status = true;
				}
			} 
		  
		    return status; 
		} 
	
		void awal()			//Tampilan saat program di Runing
		{	
		
			//Khalida Zahra
			/* Cetak In Order */
			cout<<"||					||TIM 04 : 1900018006	||"<<endl;
			cout<<"||	TUGAS PROYEK STRUKTUR DATA	||	 : 1900018007	||"<<endl;
			cout<<"||					||	 : 1900018022	||"<<endl;
			cout<<"||--------------------------------------------------------------||"<<endl;
			cout<<"||	IMPLEMENTASI BST DALAM MEMBANGUN DAFTAR VOCABULARY	||"<<endl;
			cout<<"||______________________________________________________________||"<<endl;
			cout<<endl;
			
			program:
			
			int status;
			
			cout << "1. Auto Alphabet (A-Z)\n";
			cout << "2. Auto Alphabet (a-z)\n";
			cout << "3. Manual\n";
			cin >> status;
		
			if(status == 1) {
				
				Tree *root = newTreeNode('M');
				for(char c = 'A'; c <= 'Z'; c++) {
					insertTreeNode(root, c);
				}
				
				homess:
				
				cout << "1. Cetak In Order\n";
				cout << "2. Cetak Post Order\n";
				cout << "3. Cetak Pre Order\n";
				cout << "4. Cetak Reverse Order\n";
				cout << "5. Pencarian\n";
				cout << "6. Keluar\n";
				
				int menu;
				
				cout << "Pilih menu : "; cin >> menu;
				
				if(menu == 1) {
					
					cout << "\nin order\n";												
					printTreeInOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;	
					cout<<endl;
					
					goto homess;
					
				} else if (menu == 2) {
					
					/* Cetak Post Order */
					cout<<endl;
					cout << "post order \n";
					printTreePostOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;
					cout << endl;
					
					goto homess;
					
				} else if (menu == 3) {
					
					/* Cetak Pre Order*/
					cout<<endl;
					cout << "pre order \n";
					printTreePreOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;
					cout << endl;
					
					goto homess;
					
				} else if (menu == 4) {
					
					/* Cetak Reverse Order */
					cout<<endl;
					cout << "reverse order \n";
					printTreeReverseOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;
					cout << endl;
					
					goto homess;
					
				} else if (menu == 5) {
					
					char huruf;
					cout << "Masukkan huruf yang ingin dicari : ";
					cin >> huruf;
					bool cari = pencarianData(root, huruf);
					if(cari) 
						cout << "Huruf " << huruf << " Ditemukan!\n" << endl;
					else 
						cout << "Huruf " << huruf << " Tidak Ditemukan!\n" << endl;
					
					goto homess;
					
				} else {
					system("exit");
				}

				system("exit");
				clear(root);
			
			// Daffa Fahreza
			} else if (status == 2) {
				
				Tree *root = newTreeNode('m');
				for(char c = 'a'; c <= 'z'; c++) {
					insertTreeNode(root, c);
				}
				
				homesss:
				
				cout << "1. Cetak In Order\n";
				cout << "2. Cetak Post Order\n";
				cout << "3. Cetak Pre Order\n";
				cout << "4. Cetak Reverse Order\n";
				cout << "5. Pencarian\n";
				cout << "6. Keluar\n";
				
				int menu;
				
				cout << "Pilih menu : "; cin >> menu;
				
				if(menu == 1) {
					
					cout << "\nin order\n";												
					printTreeInOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;	
					cout<<endl;
					
					goto homesss;
					
				} else if (menu == 2) {
					
					/* Cetak Post Order */
					cout<<endl;
					cout << "post order \n";
					printTreePostOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;
					cout << endl;
					
					goto homesss;
					
				} else if (menu == 3) {
					
					/* Cetak Pre Order*/
					cout<<endl;
					cout << "pre order \n";
					printTreePreOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;
					cout << endl;
					
					goto homesss;
					
				} else if (menu == 4) {
					
					/* Cetak Reverse Order */
					cout<<endl;
					cout << "reverse order \n";
					printTreeReverseOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;
					cout << endl;
					
					goto homesss;
					
				} else if (menu == 5) {
					
					char huruf;
					cout << "Masukkan huruf yang ingin dicari : ";
					cin >> huruf;
					bool cari = pencarianData(root, huruf);
					if(cari) 
						cout << "Huruf " << huruf << " Ditemukan!\n" << endl;
					else 
						cout << "Huruf " << huruf << " Tidak Ditemukan!\n" << endl;
					
					goto homesss;
					
				} else {
					system("exit");
				}

				system("exit");
				clear(root);
				
			} else if(status == 3) {
				
				check1:
				char patokan;
				cout << "Masukkan huruf awal : "; cin >> patokan;
				Tree *root = newTreeNode(patokan);
				char pil = 'T';
				char abjad;
				check:
				do{
					cout << "Masukkan huruf abjad antara (A-Z/a-z) : ";
					cin >> abjad;
					bool dupli = pencarianData(root, abjad);
					if(true == dupli) {
						cout << "Huruf " << abjad << " sudah ada!\n";
						goto check;
					}
					insertTreeNode(root, abjad);
					cout << "Ingin input lagi? (Y/T)"; cin >> pil;
				} while(pil == 'Y');
				
				homes:
					
					
				cout << "1. Cetak In Order\n";
				cout << "2. Cetak Post Order\n";
				cout << "3. Cetak Pre Order\n";
				cout << "4. Cetak Reverse Order\n";
				cout << "5. Pencarian\n";
				cout << "6. Keluar\n";
				
				int menu;
				
				cout << "Pilih menu : "; cin >> menu;
				
				if(menu == 1) {
					
					cout << "\nin order\n";												
					printTreeInOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;	
					cout<<endl;
					
					goto homes;
					
				} else if (menu == 2) {
					
					/* Cetak Post Order */
					cout<<endl;
					cout << "post order \n";
					printTreePostOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;
					cout << endl;
					
					goto homes;
					
				} else if (menu == 3) {
					
					/* Cetak Pre Order*/
					cout<<endl;
					cout << "pre order \n";
					printTreePreOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;
					cout << endl;
					
					goto homes;
					
				} else if (menu == 4) {
					
					/* Cetak Reverse Order */
					cout<<endl;
					cout << "reverse order \n";
					printTreeReverseOrder(root);
					cout << endl;
					cout<<"_________________________________________________________________"<<endl;
					cout << endl;
					
					goto homes;
					
				} else if (menu == 5) {
					
					char huruf;
					cout << "Masukkan huruf yang ingin dicari : ";
					cin >> huruf;
					bool cari = pencarianData(root, huruf);
					if(cari) 
						cout << "Huruf " << huruf << " Ditemukan!\n" << endl;
					else 
						cout << "Huruf " << huruf << " Tidak Ditemukan!\n" << endl;
					
					goto homes;
					
				} else {
					system("exit");
				}

				system("exit");
				clear(root);
				
			} else {
				
				system("exit");
				
			}
		
		}
};

//Khalida Zahra
main(){
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	system("color A");
    BST bst;
    bst.awal();
    cin.get();
    return 0;
}
