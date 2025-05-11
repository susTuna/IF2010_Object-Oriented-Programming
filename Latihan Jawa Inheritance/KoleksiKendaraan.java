public class KoleksiKendaraan {
    private Kendaraan[] koleksiKendaraan;
    private int size, neff;

    public KoleksiKendaraan() {
        this.size = 0;
        this.neff = 0;
        this.koleksiKendaraan = new Kendaraan[size];
    }

    public KoleksiKendaraan(int size) {
        this.size = size;
        this.neff = 0;
        this.koleksiKendaraan = new Kendaraan[size];
    }

    public void addKendaraan(Kendaraan k) {
        if (this.neff < size) {
            koleksiKendaraan[this.neff] = k;
            this.neff++;
        }
    }

    public void addKendaraan(KoleksiKendaraan k) {
        int k_neff = k.neff;
        if (this.neff + k_neff >= this.size) k_neff = this.size - this.neff;

        for (int i = 0; i < k_neff; ++i) {
            koleksiKendaraan[this.neff] = k.koleksiKendaraan[i];
            this.neff++;
        }
    }

    public void printAll() {
        int j = 0;
        for (Kendaraan i : koleksiKendaraan) {
            System.out.println("Kendaraan ke-" + (++j));
            i.printInfo();
        }
    }

    public static void main(String[] args){
        Bus bus1 = new Bus(123, 2020, "Mercedes", 50);
        Minibus minibus1 = new Minibus(456, 2022, "Toyota");
        Mobil mobil1 = new Mobil(789, 2019, "Honda", "Joni");

        KoleksiKendaraan koleksi = new KoleksiKendaraan(3);
        koleksi.addKendaraan(bus1);
        koleksi.addKendaraan(minibus1);
        koleksi.addKendaraan(mobil1);

        KoleksiKendaraan koleksi2 = new KoleksiKendaraan(4);
        koleksi2.addKendaraan(koleksi);
        koleksi2.addKendaraan(new Bus(321, 2021, "Toyota", 30));
        koleksi2.addKendaraan(new Mobil(654, 2023, "Suzuki", "Budi"));
        
        koleksi.printAll();
        koleksi2.printAll();

        System.out.println("Biaya sewa bus1 untuk 3 hari: " + bus1.biayaSewa(3));
        System.out.println("Biaya sewa minibus1 untuk 4 hari: " + minibus1.biayaSewa(4));
        System.out.println("Biaya sewa minibus1 untuk 12 hari: " + minibus1.biayaSewa(12));
        System.out.println("Diskon untuk minibus1 (12 hari): " + minibus1.diskon(12));
        System.out.println("Biaya sewa mobil1 untuk 5 hari: " + mobil1.biayaSewa(5));
    }
}