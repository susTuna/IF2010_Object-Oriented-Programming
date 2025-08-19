public class Hoe extends Tools {

    public Hoe(int durability){
        super(durability);
    }

    /**
     * Print dengan format "Menggunakan hoe" dan panggil method parent setelahnya apabila durability cukup. Kurangi durability sebanyak 1. Print "Hoe sudah rusak" apabila durability habis dan tidak bisa dipakai.
     */
    @Override
    public void use(){
        if (durability > 0) {
            System.out.println("Menggunakan hoe");
            durability--;
            super.use();
        } else System.out.println("Hoe sudah rusak");
    }
}
