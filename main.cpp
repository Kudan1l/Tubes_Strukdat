#include "tubes.h"

int main()
{
    ListKonsum K;
    string nama, alamat;
    infokonsum Konsumen;

    int n, nKonsumen;

    /*

    createListKonsumen(K);

    cout << "Masukan Jumlah Konsumen: ";
    cin >> nKonsumen;
    cout << endl;

    for (int i = 1; i <= nKonsumen; i++) {
        cout << "Data Konsumen" << endl;
        cout << "Nama\t\t: ";
        cin >> Konsumen.nama;
        cout << "ID\t\t: ";
        cin >> Konsumen.id;
        cout << "Alamat\t\t: ";
        cin >> Konsumen.alamat;
        cout << endl;
        insertLastKonsumen(K, createElemenKonsumen(Konsumen));
    }

    showAllKonsumen(K);

    */
    createListKonsumen(K);

    bool cek = true;
    while (cek) {
        mainMenu();
        int pilihan;
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1) {
            cout << "Data Konsumen" << endl;
            cout << "Nama\t\t: ";
            cin >> Konsumen.nama;
            cout << "ID\t\t: ";
            cin >> Konsumen.id;
            cout << "Alamat\t\t: ";
            cin >> Konsumen.alamat;
            cout << endl;
            insertLastKonsumen(K, createElemenKonsumen(Konsumen));
        } else if (pilihan == 2) {
            showAllKonsumen(K);
        } else if (pilihan == 3) {
            cout << "Terima Kasih" << endl;
            cek = false;
        } else {
            cout << "Pilihan tidak tersedia" << endl;
        }
    }
}
