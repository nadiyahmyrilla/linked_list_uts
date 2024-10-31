#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node {
    char nama[50];
    char jenisKelamin;
    struct node *next;
};
typedef struct node node;

// Fungsi yang dideklarasikan
void tambah(node **head);
void hapus(node **head);
void traversePerempuan(node *head);
void traverseLaki(node *head);
void traverseUtama(node *head);
int jumlahMahasiswa = 0;

// Data utama
int main() {
    node *head;
    char pilih;

    head = NULL;
    do {
        system("cls");
        printf("=================//========================\n");
        printf("Masukkan Apa Yang Ingin Tambahkan\n");
        printf("1. Tambah data\n");
        printf("2. Hapus data\n");
        printf("3. Cetak isi list\n");
        printf("4. Cetak isi list berdasarkan jenis kelamin Laki-laki\n");
        printf("5. Cetak isi list berdasarkan jenis kelamin Perempuan\n");
        printf("MASUKKAN PILIHAN (tekan q untuk logout) : ");
        fflush(stdin); 
        scanf(" %c", &pilih); 

        if (pilih == '1')
            tambah(&head);
        else if (pilih == '2')
            hapus(&head);
        else if (pilih == '3'){
            traverseUtama(head);
            getch();
        }
        else if (pilih == '4'){
        	traverseLaki(head);
        	getch();
		}
        else if (pilih == '5'){
        	traversePerempuan(head);
			getch();
		}
    } while (pilih != 'q');

    return 0;
}

void tambah(node **head) {
    char nama[50];
    char jenisKelamin;
    int count = 0;
    node *pList = (node *)malloc(sizeof(node));
    node *temp = *head;
    node *pWalker;

    system("cls");
    printf("Masukkan nama: ");
    fflush(stdin); 
    scanf("%s", nama);
    printf("Masukkan jenis kelamin (l untuk laki-laki || p untuk perempuan): ");
    fflush(stdin); 
    scanf(" %c", &jenisKelamin); // Tambahkan spasi sebelum %c

    if (jenisKelamin == 'l' ||jenisKelamin == 'p') {
        if (jumlahMahasiswa >= 20) {
            printf("Jumlah mahasiswa sudah mencapai batas maksimum 20 orang.\n");
            free(pList);
            return;
        }
		strcpy(pList->nama, nama);
        pList->jenisKelamin = jenisKelamin;

        if (*head == NULL) {
            *head = pList;
            pList->next = *head;
        } else {
            if (jenisKelamin == 'l') {
                pList->next = *head;
                while (temp->next != *head) {
                    temp = temp->next;
                }
                temp->next = pList;
                *head = pList;
            } else {
                while (temp->next != *head) {
                    temp = temp->next;
                }
                temp->next = pList;
                pList->next = *head;
        	}
        	jumlahMahasiswa++;
        	
        	if (strcmp(nama, "cindy") == 0){
                printf("Karena kondisi didalam lingkaran tidak memungkinkan, cindy tidak bergabung dalam api unggun.\n");
                node *prev = NULL;
                pWalker = *head;
                // Cari node cindy untuk menghapusnya
                do {
                    if (pWalker == pList) {
                        if (prev) {
                            prev->next = pWalker->next; // Lewati cindy
                        } else {
                            node *last = *head;
                            while (last->next != *head) {
                                last = last->next;
                            }
                            *head = pWalker->next;
                            last->next = *head;
                        }
                        free(pList); // Hapus cindy
                        getch();
                        }
                    prev = pWalker;
                    pWalker = pWalker->next;
                } while (pWalker != *head);
			}
	        if (strcmp(nama, "irsyad") == 0 || strcmp(nama, "arsyad") == 0) {
                pWalker = *head;
                do {
                    if (strcmp(pWalker->nama, "irsyad") == 0 || strcmp(pWalker->nama, "arsyad") == 0) {
                        if (strcmp(nama, "Irsyad") == 0) {
                            // Tambah "Arsyad" setelah "Iryad"
                            node *pArsyad = (node *)malloc(sizeof(node));
                            strcpy(pArsyad->nama, "arsyad");
                            pArsyad->jenisKelamin = 'l';
                            pArsyad->next = pWalker->next;
                            pWalker->next = pArsyad;
                            return;
                        } else {
                            // Tambah "Iryad" setelah "Arsyad"
                            node *pIryad = (node *)malloc(sizeof(node));
                            strcpy(pIryad->nama, "irsyad");
                            pIryad->jenisKelamin = 'l';
                            pIryad->next = pWalker->next;
                            pWalker->next = pIryad;
                            return;
                        }
                    }
                    pWalker = pWalker->next;
                } while (pWalker != *head);
	        }
		}
    } else {
        printf("Jenis kelamin tidak valid. Gunakan 'l' untuk laki-laki atau 'p' untuk perempuan.\n");
        free(pList);
    }
}

void hapus(node **head) {
    node *pCur, *temp;

    system("cls");
    pCur = *head;
    
	if (*head == NULL) {
        printf("Tidak terdapat mahasiwa atau mahasiswi yang mengikuti camping\n");
        getch();
        return;
    }

    // Jika hanya ada satu node dalam list
    if (pCur->next == *head) {
        free(pCur);
        *head = NULL;
        printf("\nMahasiswa dan mahasiswi telah mundur semua, acara selesai.\n");
        getch();
        return;
    }

    temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = pCur->next;
    *head = pCur->next;
    free(pCur);
    
    jumlahMahasiswa--;
    printf("\nMahasiswa atau siswi telah mundur"); 
    getch();
}

// Menampilkan linked list
void traverseUtama(node *head) {
    node *pWalker;

    system("cls");
    pWalker = head;

    if (head == NULL) {
        printf("Tidak terdapat mahasiwa atau mahasiswi yang mengikuti camping\n");
        return;
    } else {
		printf("Acara camping dimulai, para mahasiswa serta mahasiswi berkumpul untuk merayakan api unggun bersama.\n");
	    do {
	        printf("Atas nama %s, dengan Jenis Kelamin %c sedang bernyayi, dilanjutkan oleh: %s\n", pWalker->nama, pWalker->jenisKelamin, pWalker->next);
	        pWalker = pWalker->next;
	    } while (pWalker != head);
	    printf("Acara camping telah berakhir, para mahasiswa serta mahasiswi kembali ketenda masing-masing");
	}
}

// Tambahkan fungsi untuk menampilkan berdasarkan jenis kelamin
void traverseLaki(node *head) {
    node *pWalker = head;

    system("cls");
    if (head == NULL) {
        printf("Tidak terdapat mahasiwa yang mengikuti camping\n");
        return;
    }
    do {
        if (pWalker->jenisKelamin == 'l') {
            printf("Atas nama %s, dengan Jenis Kelamin %c sedang bernyayi\n", pWalker->nama, pWalker->jenisKelamin);
        }
        pWalker = pWalker->next;
    } while (pWalker != head);
}

void traversePerempuan(node *head) {
    node *pWalker = head;

    system("cls");
    if (head == NULL) {
        printf("Tidak terdapat mahasiwi yang mengikuti camping\n");
        return;
    }
    do {
        if (pWalker->jenisKelamin == 'p') {
            printf("Atas nama %s, dengan Jenis Kelamin %c sedang bernyayi\n",  pWalker->nama, pWalker->jenisKelamin);
        }
        pWalker = pWalker->next;
    } while (pWalker != head);
}

