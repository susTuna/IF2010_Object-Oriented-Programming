public class Minibus extends Kendaraan {
    public Minibus() {
        super();
    }

    public Minibus(int nomor, int tahun_keluaran, String merk) {
        super(nomor, tahun_keluaran, merk);
    }

    @Override
    public void printInfo() {
        super.printInfo();
        System.out.println("Kategori: Minibus");
    }

    public int biayaSewa(int lamaSewa) {
        if (lamaSewa > 5) return 500000 + (lamaSewa - 5) * 500000;
        return 500000;
    }

    public int diskon(int lamaSewa) {
        int biayaSewa = biayaSewa(lamaSewa);
        if (lamaSewa > 10) return biayaSewa *= 0.1;
        return 0;
    }
}