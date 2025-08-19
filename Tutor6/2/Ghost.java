public class Ghost {
    private String name;
    private String type;
    private int age;
    private String uniqueId;
    private String description;

    public Ghost(String name, String type, int age, String uniqueId, String description) {
        this.name = name;
        this.type = type;
        this.age = age;
        this.uniqueId = uniqueId;
        this.description = description;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public int getAge() {
        return age;
    }

    public String getUniqueId() {
        return uniqueId;
    }

    public String getDescription() {
        return description;
    }
}
