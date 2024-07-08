#include <iostream>
#include <vector>
using namespace std;

/**
 * @class namateam
 * @brief Merepresentasikan sebuah tim dalam domain esports.
 */
class namateam;

/**
 * @class namasponsor
 * @brief Merepresentasikan seorang sponsor dalam domain esports.
 */
class namasponsor {
public:
    string nama; ///< Nama sponsor
    vector<namateam*> daftar_namateam; ///< Daftar tim yang disponsori oleh sponsor ini

    /**
     * @brief Konstruktor untuk namasponsor.
     * @param pnama Nama sponsor.
     */
    namasponsor(string pnama);

    /**
     * @brief Menambahkan tim ke dalam daftar tim sponsor.
     * @param pnamateam Pointer ke tim yang akan ditambahkan.
     */
    void tambahnamateam(namateam* pnamateam);

    /**
     * @brief Mencetak daftar tim yang disponsori oleh sponsor ini.
     */
    void cetaknamateam();
};

/**
 * @class namateam
 * @brief Merepresentasikan sebuah tim dalam domain esports.
 */
class namateam {
public:
    string nama; ///< Nama tim
    vector<namasponsor*> daftar_namasponsor; ///< Daftar sponsor dari tim ini

    /**
     * @brief Konstruktor untuk namateam.
     * @param pNama Nama tim.
     */
    namateam(string pNama);

    /**
     * @brief Menambahkan sponsor ke dalam daftar sponsor tim.
     * @param pnamasponsor Pointer ke sponsor yang akan ditambahkan.
     */
    void tambahnamasponsor(namasponsor* pnamasponsor);

    /**
     * @brief Mencetak daftar sponsor dari tim ini.
     */
    void cetaknamasponsor();
};

/**
 * @brief Menambahkan tim ke dalam daftar tim sponsor.
 * @param pnamateam Pointer ke tim yang akan ditambahkan.
 */
void namasponsor::tambahnamateam(namateam* pnamateam) {
    daftar_namateam.push_back(pnamateam);
}

/**
 * @brief Mencetak daftar tim yang disponsori oleh sponsor ini.
 */
void namasponsor::cetaknamateam() {
    cout << "Daftar tim dengan sponsor \"" << this->nama << "\":\n";
    for (auto& a : daftar_namateam) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

/**
 * @brief Menambahkan sponsor ke dalam daftar sponsor tim.
 * @param pnamasponsor Pointer ke sponsor yang akan ditambahkan.
 */
void namateam::tambahnamasponsor(namasponsor* pnamasponsor) {
    daftar_namasponsor.push_back(pnamasponsor);
    pnamasponsor->tambahnamateam(this);
}

/**
 * @brief Mencetak daftar sponsor dari tim ini.
 */
void namateam::cetaknamasponsor() {
    cout << "Daftar sponsor dari tim \"" << this->nama << "\":\n";
    for (auto& a : daftar_namasponsor) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

/**
 * @brief Fungsi utama untuk mendemonstrasikan hubungan sponsor dan tim.
 * @return int
 */
int main() {

    // membuat objek nama team
    namateam* varNamateam1 = new namateam("Evos esports"); 
    namateam* varNamateam2 = new namateam("Onic esports");   
    
    // membuat objek nama sponsor
    namasponsor* varNamasponsor1 = new namasponsor("leica");
    namasponsor* varNamasponsor2 = new namasponsor("nike");
    namasponsor* varNamasponsor3 = new namasponsor("samsung");

    // menambahkan sponsor ke tim dan tim ke sponsor
    varNamateam1->tambahnamasponsor(varNamasponsor1);
    varNamateam1->tambahnamasponsor(varNamasponsor3);
    varNamateam2->tambahnamasponsor(varNamasponsor1);
    varNamateam2->tambahnamasponsor(varNamasponsor2);
    varNamateam2->tambahnamasponsor(varNamasponsor3);

    // menghapus objek namasponsor untuk membebaskan memori
    delete varNamasponsor1;
    delete varNamasponsor2;
    delete varNamasponsor3;

    return 0;

}