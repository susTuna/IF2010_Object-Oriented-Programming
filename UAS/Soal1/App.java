public class App {
  public static void main(String[] args) {
    IHouseBuilder builder = new HouseBuilder();
    House house = builder.withColor("Red")
        .withFloors(2)
        .withRooms(3)
        .withOwner("John Doe")
        .withAddress("Jl. Merdeka No. 1")
        .build();
    System.out.println(house);
    // House{color=Red,floors=2,rooms=3,owner=John Doe,address=Jl. Merdeka No. 1}

    House house2 = builder.withRooms(5).build();
    System.out.println(house2);
    // House{color=Red,floors=2,rooms=5,owner=John Doe,address=Jl. Merdeka No. 1}

    IHouseBuilder builder2 = new HouseBuilder();
    House house3 = builder2.withColor("Blue")
        .withOwner("Jane Doe")
        .withAddress("Jl. Merdeka No. 2")
        .build();
    System.out.println(house3);
    // House{color=Blue,floors=0,rooms=0,owner=Jane Doe,address=Jl. Merdeka No. 2}
  }
}
