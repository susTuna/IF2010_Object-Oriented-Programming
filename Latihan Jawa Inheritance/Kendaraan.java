abstract class Kendaraan {
    protected int nomor;
    protected int tahun_keluaran;
    protected String merk;

    public Kendaraan() {
        this.nomor = 0;
        this.tahun_keluaran = 0;
        this.merk = "XXX";
    }

    public Kendaraan(int nomor, int tahun_keluaran, String merk) {
        this.nomor = nomor;
        this.tahun_keluaran = tahun_keluaran;
        this.merk = merk;
    }

    public void printInfo() {
        System.out.println("Nomor Kendaraan: " + nomor);
        System.out.println("Tahun Keluaran: " + tahun_keluaran);
        System.out.println("Merk: " + merk);
    }
    abstract int biayaSewa(int lamaSewa);
}