public class Bus extends Kendaraan {
    private int kapasitas;

    public Bus() {
        super();
        this.kapasitas = 0;
    }
    public Bus(int nomor, int tahun_keluaran, String merk, int kapasitas) {
        super(nomor, tahun_keluaran, merk);
        this.kapasitas = kapasitas;
    }

    @Override
    public void printInfo() {
        super.printInfo();
        System.out.println("Kategori: Bus");
        System.out.println("Kapasitas: " + kapasitas);
    }

    public int biayaSewa(int lamaSewa) {
        return 1000000 * lamaSewa;
    }
}