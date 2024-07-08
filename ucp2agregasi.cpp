#include <iostream>
#include <vector>
using namespace std;

class team;
class player //membuat class player
{
public:
    string nama;

    player(string pnama) : nama(pnama)
    {
        cout << "nama player \"" << nama << "\" ..\n";
    }

    void tambahteam(team*);
    void cetakteam();
};

class team //membuat class team
{
public:
    string nama;
    vector<player*> daftar_player;
    team(string pNama) : nama(pNama)
    {
        cout << "team \"" << nama << "\" ..\n";
    }

    void tambahplayer(player*);
    void cetakplayer();
};

int main()
{
    //membuat objek team
    team *varteam1 = new team("Evos esports");
    team *varteam2 = new team("Onic Esports");

    //membuat objek player
    player *varplayer1 = new player("Karjo");
    player *varplayer2 = new player("Budi");
    player *varplayer3 = new player("Kirun");
    player *varplayer4 = new player("Cuplis");
    player *varplayer5 = new player("Sule");

    //menambahkan player ke dalam team
    varteam1->tambahplayer(varplayer1);
    varteam1->tambahplayer(varplayer2);
    varteam2->tambahplayer(varplayer3);
    varteam2->tambahplayer(varplayer4);
    varteam2->tambahplayer(varplayer5);

    //mencetak daftar player dalam setiap team 
    varteam1->cetakplayer();
    varteam2->cetakplayer();

    //menghapus objek yang di buat untuk membebaskan memori
    delete varteam1;
    delete varteam2;
    delete varplayer1;
    delete varplayer2;
    delete varplayer3;
    delete varplayer4;
    delete varplayer5;
}
