#include <iostream>
using namespace std;

class BangunRuang
{
    public:
    float Volume, LuasPer, LuasSel;
    float phi = 3.14285714;
    float rusuk, tinggi, S, jariJari;
    float panjangTotalRusuk;
    int p,l,t, pilih;

    void TampilanAwal()
    { 
    cout << "###### Bangun Ruang ######" << endl;
    cout << "1. Kerucut " << endl;
    cout << "2. Kubus " << endl;
    cout << "3. Balok " << endl;
    cout << "##########################" << endl;
    }

};

class Kerucut : public BangunRuang
{
    public:
    void HitungVolume()
    {
        cout << "\n######   KERUCUT    ######" << endl;
        cout << "\n==== Hitung Volume ====" << endl;
        cout << "Masukan Jari-Jari : ";
        cin >> jariJari;
        cout << "Masukan Tinggi : ";
        cin >> tinggi;
        Volume = 1/(float)3 * phi * jariJari * jariJari * tinggi;
        cout << "Volume Kerucut : " << Volume << " cm3" << endl << endl;
    }

    void HitungLuas()
    {
        cout << "====  Hitung Luas  ====" << endl;
        cout << "Masukan Jari-Jari : ";
        cin >> jariJari;
        cout << "Masukan S : ";
        cin >> S;
        LuasPer = phi * jariJari * (jariJari + S);
        LuasSel = phi * jariJari * S;
        cout << "Luas Permukaan Kerucut : " << LuasPer << " cm2" << endl;
        cout << "Luas Selimut Kerucut   : " << LuasSel << " cm2" << endl;
    }
};


class Kubus : public BangunRuang
{
    public:
    
    float H_luasPer(float S)
    {
        LuasPer = 6 * S * S;
        return (LuasPer);
    }
    float H_volume(float S)
    {
        Volume = S * S * S;
        return (Volume);
    }
    float H_Total(float S)
    {
        panjangTotalRusuk = 12 * S;
        return (panjangTotalRusuk);
    }

    void HitungVolume()
    {
        cout << "\n######   KUBUS    ######" << endl;
        cout << "\n==== Hitung Volume ====" << endl;
        cout << "Masukan Panjang Rusuk Kubus : ";
        cin >> S;
        Volume = H_volume(S);
        panjangTotalRusuk = H_Total(S);

        cout << "Volume kubus = " << Volume << " cm3" << endl;
        cout << "Panjang total rusuk kubus = " << panjangTotalRusuk << " cm" << endl << endl;
    }

    void HitungLuas()
    {
        cout << "====  Hitung Luas  ====" << endl;
        cout << "Masukan Panjang Rusuk Kubus : ";
        cin >> S;
        LuasPer = H_luasPer(S);
        cout << "Luas Permukaan Kubus = " << LuasPer << " cm2" << endl;
        panjangTotalRusuk = H_Total(S);
        cout << "Panjang total rusuk kubus = " << panjangTotalRusuk << " cm" << endl;
    }

};

class Balok : public BangunRuang
{
    public:
    void HitungVolume()
    {
        cout << "\n######   BALOK    ######" << endl;
        cout << "\n==== Hitung Volume ====" << endl;
        cout << "Masukan Panjang : ";
        cin >> p;
        cout << "Masukan Lebar   : ";
        cin >> l;
        cout << "Masukan Tinggi  : ";
        cin >> t;

        Volume = p * l * t;
        cout << "Volume Balok : " << Volume << " cm3" << endl << endl;

    }

    void HitungLuas()
    {
        cout << "====  Hitung Luas  ====" << endl;
        cout << "Masukan Panjang : ";
        cin >> p;
        cout << "Masukan Lebar   : ";
        cin >> l;
        cout << "Masukan Tinggi  : ";
        cin >> t;

        LuasPer = 2* ((p * l) + (p * t) + (l * t));
        cout << "Luas Permukaan : " << LuasPer << " cm2" << endl;

    }
};
class Pemilihan : public BangunRuang
{
    public:
    void Choose() 
    {
    BangunRuang *objek = new BangunRuang;
    objek -> TampilanAwal();
    cout << "Pilih Menu : ";
    cin >> pilih;

        if (pilih == 1)
        {  
        Kerucut *Tampil1 = new Kerucut;
        Tampil1 -> HitungVolume();
        Tampil1 -> HitungLuas();
        }
        else if (pilih == 2)
        {
            Kubus *Tampil2 = new Kubus;
            Tampil2 -> HitungVolume();
            Tampil2 -> HitungLuas();
        }
        else if(pilih == 3)
        {
            Balok *Tampil3 = new Balok;
            Tampil3 -> HitungVolume();
            Tampil3 -> HitungLuas();
        }

    }
    
};

int main()
{
    Pemilihan * show = new Pemilihan;
    show -> Choose();
    return 0;
}