public class Mobil extends Kendaraan {
    private String supir;

    public Mobil() {
        super();
        this.supir = "XXX";
    }

    public Mobil(int nomor, int tahun_keluaran, String merk, String supir) {
        super(nomor, tahun_keluaran, merk);
        this.supir = supir;
    }

    @Override
    public void printInfo() {
        super.printInfo();
        System.out.println("Kategori: Mobil");
        System.out.println("Nama Supir: " + supir);
    }

    public int biayaSewa(int lamaSewa) {
        return 500000 * lamaSewa;
    }
}