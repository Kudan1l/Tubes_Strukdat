#include "tubes.h"

void createListKonsumen(ListKonsumen &K) {
    first(K) = NULL;
}

void createListProduk(ListProduk &P) {
    first(P) = NULL;
}

// Konsumen
adrKonsumen createKonsumen(infoKonsumen infoK) {
    adrKonsumen K = new elmKonsumen;
    info(K) = infoK;
    next(K) = NULL;
    belanjaan(K) = NULL;
    return K;
}

void addKonsumen(ListKonsumen &K, adrKonsumen addK) {
    adrKonsumen k = first(K);
    if (first(K) == NULL) {
        first(K) = addK;
    } else {
        while (next(k) != NULL) {
            k = next(k);
        }
        next(k) = addK;
    }
}

void hapusKonsumen(ListKonsumen &K, string idKonsumen) {
    adrKonsumen konsumen = first(K);
    adrKonsumen prevKonsumen = NULL;

    while (konsumen != NULL && info(konsumen).id != idKonsumen) {
        prevKonsumen = konsumen;
        konsumen = next(konsumen);
    }

    if (konsumen != NULL) {
        if (prevKonsumen == NULL) {
            first(K) = next(konsumen);
        } else {
            next(prevKonsumen) = next(konsumen);
        }
        delete konsumen;
        cout << "Konsumen dengan ID " << idKonsumen << " telah dihapus dari daftar konsumen." << endl;
    } else {
        cout << "Konsumen dengan ID " << idKonsumen << " tidak ditemukan dalam daftar konsumen." << endl;
    }
}

// Produk
adrProduk createProduk(infoProduk infoP) {
    adrProduk P = new elmProduk;
    info(P) = infoP;
    info(P).profit = 0;
    info(P).terjual = 0;
    next(P) = NULL;
    return P;
}

void addProduk(ListProduk &P, adrProduk addP) {
    adrProduk p = first(P);
    if (first(P) == NULL) {
        first(P) = addP;
    } else {
        while (next(p) != NULL) {
            p = next(p);
        }
        next(p) = addP;
    }
}

void hapusProduk(ListProduk &P, ListKonsumen &K, string jenisProdukDicari) {
    adrProduk produk = first(P);
    adrProduk prevProduk = NULL;

    // Mencari dan menghapus produk dari list produk
    while (produk != NULL && info(produk).jenis != jenisProdukDicari) {
        prevProduk = produk;
        produk = next(produk);
    }

    if (produk != NULL) {
        // Menghapus produk dari list produk
        if (prevProduk == NULL) {
            first(P) = next(produk);
        } else {
            next(prevProduk) = next(produk);
        }
        cout << "Produk dengan jenis " << jenisProdukDicari << " telah dihapus dari daftar produk." << endl;

        // Menghapus referensi produk dari belanjaan konsumen yang sama
        adrKonsumen konsumen = first(K);
        while (konsumen != NULL) {
            adrChildBelanjaan belanjaan = belanjaan(konsumen);
            adrChildBelanjaan prevBelanjaan = NULL;

            while (belanjaan != NULL && connect(belanjaan) != produk) {
                prevBelanjaan = belanjaan;
                belanjaan = next(belanjaan);
            }

            if (belanjaan != NULL) {
                if (prevBelanjaan == NULL) {
                    belanjaan(konsumen) = next(belanjaan);
                } else {
                    next(prevBelanjaan) = next(belanjaan);
                }
                cout << "Produk dengan jenis " << jenisProdukDicari << " telah dihapus dari belanjaan konsumen dengan ID " << info(konsumen).id << "." << endl;
            }
            konsumen = next(konsumen);
        }
    } else {
        cout << "Produk dengan jenis " << jenisProdukDicari << " tidak ditemukan dalam daftar produk." << endl;
    }
}

// Child
void addProdukBeli(ListKonsumen &K, ListProduk &P, string idKonsumen, string jenisProdukDicari, int jumlah) {
    adrKonsumen konsumenDitemukan = cariKonsumen(K, idKonsumen);
    adrProduk produkDibeli = cariProduk(P, jenisProdukDicari);
    if (konsumenDitemukan != NULL) {
        if (produkDibeli != NULL) {
            int totalHarga = jumlah * info(produkDibeli).harga; // Menghitung total harga berdasarkan harga per barang

            adrChildBelanjaan newBeli = new childProduk;
            connect(newBeli) = produkDibeli;
            jBeli(newBeli) = jumlah;
            tHarga(newBeli) = totalHarga;
            next(newBeli) = NULL;

            if (belanjaan(konsumenDitemukan) == NULL) {
                belanjaan(konsumenDitemukan) = newBeli;
            } else {
                adrChildBelanjaan temp = belanjaan(konsumenDitemukan);
                while (next(temp) != NULL) {
                    temp = next(temp);
                }
                next(temp) = newBeli;
            }

            // Update nilai di list produk
            info(produkDibeli).terjual += jumlah; // Menambah jumlah terjual
            info(produkDibeli).stok -= jumlah;   // Mengurangi stok
            info(produkDibeli).profit += totalHarga; // Menambah profit dengan total harga dari barang yang dibeli
            cout << jenisProdukDicari << " berhasil ditambahkan." << endl << endl;
        } else {
            cout << "Produk tidak ditemukan dalam daftar produk." << endl << endl;
        }
    } else {
        cout << "Konsumen tidak ditemukan dalam daftar konsumen." << endl << endl;
    }
}

void hapusChild(ListKonsumen &K, string idKonsumen, string jenisProdukDicari) {
    adrKonsumen konsumen = cariKonsumen(K, idKonsumen);

    if (konsumen != NULL) {
        adrChildBelanjaan belanjaan = belanjaan(konsumen);
        adrChildBelanjaan prevBelanjaan = NULL;

        while (belanjaan != NULL && info(connect(belanjaan)).jenis != jenisProdukDicari) {
            prevBelanjaan = belanjaan;
            belanjaan = next(belanjaan);
        }

        if (belanjaan != NULL) {
            if (prevBelanjaan == NULL) {
                belanjaan(konsumen) = next(belanjaan);
            } else {
                next(prevBelanjaan) = next(belanjaan);
            }
            delete belanjaan;
            cout << "Produk dengan jenis " << jenisProdukDicari << " telah dihapus dari daftar belanjaan konsumen dengan ID " << idKonsumen << "." << endl << endl;;
        } else {
            cout << "Produk dengan jenis " << jenisProdukDicari << " tidak ditemukan dalam daftar belanjaan konsumen dengan ID " << idKonsumen << "." << endl << endl;
        }
    } else {
        cout << "Konsumen dengan ID " << idKonsumen << " tidak ditemukan dalam daftar konsumen." << endl << endl;
    }
}

int hitungChild(ListKonsumen &K, string idKonsumen) {
    adrKonsumen konsumen = first(K);

    while (konsumen != NULL && info(konsumen).id != idKonsumen) {
        konsumen = next(konsumen);
    }

    if (konsumen != NULL) {
        int jumlahChild = 0;
        adrChildBelanjaan belanjaan = belanjaan(konsumen);

        while (belanjaan != NULL) {
            jumlahChild++;
            belanjaan = next(belanjaan);
        }

        cout << "Konsumen dengan ID " << idKonsumen << " memiliki " << jumlahChild << " produk dalam belanjaannya." << endl << endl;
        return jumlahChild;
    } else {
        return 0;
    }
}

// Search
adrKonsumen cariKonsumen(ListKonsumen K, string idKonsumen) {
    adrKonsumen tempKonsumen = first(K);
    while (tempKonsumen != NULL) {
        if (info(tempKonsumen).id == idKonsumen) {
            return tempKonsumen;
        }
        tempKonsumen = next(tempKonsumen);
    }
    return NULL;
}

adrProduk cariProduk(ListProduk P, string jenisProdukDicari) {
    adrProduk temp = first(P);
    while (temp != NULL) {
        if (info(temp).jenis == jenisProdukDicari) {
            return temp;
        }
        temp = next(temp);
    }
    return NULL;
}

void cariChild(ListKonsumen K, string jenisProdukDicari) {
    adrKonsumen infoK = first(K);
    bool cek = true;

    if (infoK != NULL) {
        cout << "Mencari produk " << jenisProdukDicari << " pada setiap konsumen:" << endl;
        while (infoK != NULL) {
            adrChildBelanjaan belanjaan = belanjaan(infoK);
            while (belanjaan != NULL) {
                adrProduk produk = connect(belanjaan);
                if (produk != NULL && info(produk).jenis == jenisProdukDicari) {
                    cek = false;
                    cout << "- Konsumen dengan ID: " << info(infoK).id << endl;
                    cout << "  Nama: " << info(infoK).nama << endl;
                    cout << "  Alamat: " << info(infoK).alamat << endl;
                    cout << "  ID: " << info(infoK).id << endl;
                    cout << "  Jumlah dibeli: " << jBeli(belanjaan) << " pcs" << endl;
                    cout << "  Total Harga: " << tHarga(belanjaan) << endl << endl;
                    break;
                }
                belanjaan = next(belanjaan);
            }
            infoK = next(infoK);
        }

        if (cek) {
            cout << "Produk " << jenisProdukDicari << " tidak ditemukan pada setiap konsumen." << endl << endl;
        }
    } else {
        cout << "Tidak ada konsumen dalam daftar." << endl << endl;
    }
}

// Show
void showKonsumen(ListKonsumen K) {
    adrKonsumen infoK = first(K);
    int i = 1;
    cout << "---------- List Konsumen ----------" << endl;
    if (infoK != NULL) {
        while (infoK != NULL) {
            cout << "* KONSUMEN " << i << endl;
            cout << "Nama\t\t: " << info(infoK).nama << endl;
            cout << "ID\t\t: " << info(infoK).id << endl;
            cout << "Alamat\t\t: " << info(infoK).alamat << endl;

            adrChildBelanjaan belanjaan = belanjaan(infoK);
            if (belanjaan != NULL) {
                cout << "Produk yang Dibeli:" << endl;
                while (belanjaan != NULL) {
                    adrProduk produk = connect(belanjaan);
                    if (produk != NULL) {
                        cout << "- Jenis Produk\t: " << info(produk).jenis << endl;
                        cout << "  Jumlah dibeli\t: " << jBeli(belanjaan) << " pcs" << endl;
                        cout << "  Total Harga\t: " << tHarga(belanjaan) << endl << endl;
                    }
                    belanjaan = next(belanjaan);
                }
            } else {
                cout << "Belum ada produk yang dibeli." << endl << endl;
            }

            infoK = next(infoK);
            cout << endl;
            i++;
        }
    } else {
        cout << "Tidak Ada Konsumen" << endl << endl;
    }
}

void showProduk(ListProduk P) {
    adrProduk infoP = first(P);
    int i = 1;
    cout << "----------- List Produk -----------" << endl;
    if (infoP != NULL) {
        while (infoP != NULL) {
            cout << "* PRODUK " << i << endl;
            cout << "Nama\t: " << info(infoP).jenis << endl;
            cout << "Harga\t: " << info(infoP).harga << endl;
            cout << "Stok\t: " << info(infoP).stok << endl;
            cout << "Terjual\t: " << info(infoP).terjual << endl;
            cout << "Profit\t: " << info(infoP).profit << endl << endl;
            infoP = next(infoP);
            i++;
        }
    } else {
        cout << "Produk tidak tersedia" << endl << endl;
    }
}

void showOneProduk(ListProduk P, string jenisProdukDicari) {
    adrProduk produkDicari = cariProduk(P, jenisProdukDicari);

    if (produkDicari != NULL) {
        cout << "Informasi Produk " << jenisProdukDicari << ":" << endl;
        cout << "Jenis\t: " << info(produkDicari).jenis << endl;
        cout << "Harga\t: " << info(produkDicari).harga << endl;
        cout << "Stok\t: " << info(produkDicari).stok << endl;
        cout << "Terjual\t: " << info(produkDicari).terjual << endl;
        cout << "Profit\t: " << info(produkDicari).profit << endl << endl;

    } else {
        cout << "Produk dengan jenis " << jenisProdukDicari << " tidak ditemukan." << endl << endl;
    }
}

void showOneKonsumen(ListKonsumen K, ListProduk P, string idKonsumen) {
    adrKonsumen konsumen = cariKonsumen(K, idKonsumen);
    int jumlahChild = hitungChild(K, idKonsumen);

    if (konsumen != NULL) {
        cout << "Informasi Konsumen dengan ID " << idKonsumen << ":" << endl;
        cout << "Nama\t: " << info(konsumen).nama << endl;
        cout << "Alamat\t: " << info(konsumen).alamat << endl;
        cout << "ID\t: " << info(konsumen).id << endl << endl;
       // cout << "Jumlah Produk yang Dibeli oleh Konsumen: " << jumlahChild << " produk" << endl << endl;

        cout << "Produk yang Dibeli oleh Konsumen:" << endl;
        adrChildBelanjaan belanjaan = belanjaan(konsumen);

        while (belanjaan != NULL) {
            adrProduk produk = connect(belanjaan);
            if (produk != NULL) {
                cout << "Jenis Produk\t: " << info(produk).jenis << endl;
                cout << "Jumlah dibeli\t: " << jBeli(belanjaan) << " pcs" << endl;
                cout << "Total Harga\t: " << tHarga(belanjaan) << endl << endl;
            }
            belanjaan = next(belanjaan);
        }

    } else {
        cout << "Konsumen dengan ID " << idKonsumen << " tidak ditemukan." << endl << endl;
    }
}

void mainMenu() {
    cout << "------------ Main Menu ------------" << endl;
    cout << "1. Tambah Konsumen" << endl;
    cout << "2. Tambah Produk" << endl;
    cout << "3. Tambah Belanjaan" << endl;
    cout << "4. Tampilkan Konsumen" << endl;
    cout << "5. Tampilkan Produk" << endl;
    cout << "6. Cari Konsumen" << endl;
    cout << "7. Cari Produk" << endl;
    cout << "8. Cari Belanjaan" << endl;
    cout << "9. Hapus Konsumen" << endl;
    cout << "10. Hapus Produk" << endl;
    cout << "11. Hapus Belanjaan" << endl;
    cout << "12. Exit" << endl;
    cout << "Masukan Pilihan: ";
}
