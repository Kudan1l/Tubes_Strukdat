#include "tubes.h"

int main()
{
    ListKonsumen K;
    ListProduk P;

    adrKonsumen adrK;
    adrProduk adrP;

    infoKonsumen infoK;
    infoProduk infoP;

    bool cek = true;
    int pilihan;

    createListKonsumen(K);
    createListProduk(P);

    while (cek) {
        mainMenu();
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
        case 1:
            cout << "---------- Regis Konsumen ---------" << endl;
            cout << "Data Konsumen" << endl;
            cout << "Nama\t\t: ";
            cin >> infoK.nama;
            cout << "ID\t\t: ";
            cin >> infoK.id;
            cout << "Alamat\t\t: ";
            cin >> infoK.alamat;
            cout << "Konsumen berhasil ditambahkan." << endl << endl;
            addKonsumen(K, createKonsumen(infoK));
            break;
        case 2:
        {
            bool lanjut = true;
            bool cek = false;
            char inputLanjut;
            cout << "---------- Regis Produk -----------" << endl;
            do {
                cout << "Data Produk" << endl;
                cout << "Jenis\t\t: ";
                cin >> infoP.jenis;
                cout << "Harga\t\t: ";
                cin >> infoP.harga;
                cout << "Stock\t\t: ";
                cin >> infoP.stok;
                addProduk(P, createProduk(infoP));
                cout << "Produk berhasil ditambahkan." << endl;

                cout << "Ingin menambahkan produk lagi? (Y/N): ";
                cin >> inputLanjut;
                cout << endl;

                if (inputLanjut == 'N' || inputLanjut == 'n') {
                    lanjut = false;
                } else if (inputLanjut != 'Y' && inputLanjut != 'y') {
                    cout << "Masukan Salah, Harap Ulangi" << endl;
                }
            } while (lanjut);
            break;
        }
        case 3:
        {
            string idKonsumen, jenisProduk;
            int jumlahBeli;
            cout << "--------- Regis Belanjaan ---------" << endl;
            cout << "ID\t\t: ";
            cin >> idKonsumen;
            cout << "Jenis Produk\t: ";
            cin >> jenisProduk;
            cout << "Jumlah(pcs)\t: ";
            cin >> jumlahBeli;
            addProdukBeli(K, P, idKonsumen, jenisProduk, jumlahBeli);
            break;
        }
        case 4:
            showKonsumen(K);
            break;
        case 5:
            showProduk(P);
            break;
        case 6:
        {
            string idKonsumen;
            cout << "---------- Cari Konsumen ----------" << endl;
            cout << "ID\t: ";
            cin >> idKonsumen;
            showOneKonsumen(K, P, idKonsumen);
            break;
        }
        case 7:
        {
            string jenisProduk;
            cout << "----------- Cari Produk -----------" << endl;
            cout << "Jenis Produk\t: ";
            cin >> jenisProduk;
            showOneProduk(P, jenisProduk);
            break;
        }
        case 8:
        {
            string jenisProduk;
            cout << "----------- Cari Child ------------" << endl;
            cout << "Jenis Produk\t: ";
            cin >> jenisProduk;
            cariChild(K, jenisProduk);
            break;
        }
        case 9:
        {
            string idKonsumen;
            cout << "--------- Hapus Konsumen ----------" << endl;
            cout << "ID\t: ";
            cin >> idKonsumen;
            hapusKonsumen(K, idKonsumen);
            break;
        }
        case 10:
        {
            string jenisProduk;
            cout << "------------ Main Menu ------------" << endl;
            cout << "Jenis Produk\t: ";
            cin >> jenisProduk;
            hapusProduk(P, K, jenisProduk);
            break;
        }
        case 11:
        {
            string idKonsumen;
            string jenisProduk;
            cout << "----------- Hapus Child -----------" << endl;
            cout << "Jenis Produk\t: ";
            cin >> jenisProduk;
            cout << "ID\t: ";
            cin >> idKonsumen;
            hapusChild(K, idKonsumen, jenisProduk);
            break;
        }
        case 12:
            cout << "Terima Kasih" << endl << endl;
            cout << "Created by: " << endl;
            cout << "1. Agung Laksono Putra (1303220113)" << endl;
            cout << "2. Ahmad Rohman Nurrohim (1303220156)" << endl << endl;
            cek = false;
            break;
        default:
            cout << "Input Salah" << endl <<endl;
        }
    }
    return 0;
}
