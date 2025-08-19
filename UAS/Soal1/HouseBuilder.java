public class HouseBuilder implements IHouseBuilder {
    private String color;
    private int floors;
    private int rooms;
    private String owner;
    private String address;

    public IHouseBuilder withColor(String color) {
    this.color = color;
    return this;
    }

    public IHouseBuilder withFloors(int floors) {
    this.floors = floors;
    return this;
    }

    public IHouseBuilder withRooms(int rooms) {
        this.rooms = rooms;
        return this;
    }

    public IHouseBuilder withOwner(String owner) {
        this.owner = owner;
        return this;
    }

    public IHouseBuilder withAddress(String address) {
        this.address = address;
        return this;
    }

    public House build() {
        return new House(color, floors, rooms, owner, address);
    }
}
