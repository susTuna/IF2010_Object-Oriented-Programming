abstract class Unit {
    protected String name;
    protected int health;

    public Unit(String name, int health) {
        this.name = name;
        this.health = health;
    }

    //setter and getter
    public String getName() { return this.name; }

    public void setName(String name) { this.name = name; }

    public int getHealth() { return this.health; }

    public void setHealth(int health) { this.health = health; }
    
    public abstract String toString();
}