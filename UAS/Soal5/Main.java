import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
  static class Person {
    @JsonField(name = "full_name") private String name;
    @JsonField(serialized = false) private int age;

    private boolean isStudent;
    private String[] hobbies;
    private List<String> friends;
    private Map<String, String> address;

    public Person(String name, int age, boolean isStudent, String[] hobbies, List<String> friends, Map<String, String> address) {
      this.name = name;
      this.age = age;
      this.isStudent = isStudent;
      this.hobbies = hobbies;
      this.friends = friends;
      this.address = address;
    }
  }

  public static void main(String[] args) {
      Person person = new Person(
                        "John Doe", 
                        25, 
                        true, 
                        new String[] {"Reading", "Coding"},                   
                        Arrays.asList("Alice", "Bob", "Charlie"),
                        new HashMap<String, String>() {
                              {
                                put("city", "New York");
                                put("state", "NY");
                              }
                        });

    JsonLoader jsonLoader = new JsonLoader();
    try {
      String json = jsonLoader.serialize(person);   
      System.out.println(json);
    } catch (Exception e) {
      e.printStackTrace();
    }
    // {"full_name":"John Doe","isStudent":true,"hobbies":["Reading","Coding"],"friends":["Alice","Bob","Charlie"],"address":{"city":"New York","state":"NY"}}
  }
}
