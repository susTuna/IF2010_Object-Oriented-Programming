class NPC extends Unit implements Interactable {
    private String dialogue = "Hello there!";

    public NPC() {
        super("NPC1", 100);
        this.dialogue = "Hello there!";
    }

    public NPC(String name, int health, String dialogue) {
        super(name, health);
        this.dialogue = dialogue;
    }

    //setter & getter
    public String getDialogue() { return this.dialogue; }

    public void setDialogue(String dialogue) { this.dialogue = dialogue; }

    //implements interact
    public void interact() {
        System.out.println(dialogue);
    }

    //override
    public String toString() {
        return (this.getName() + " [Health: " + this.getHealth() + ", Dialogue: " + this.getDialogue() + "]");
    }
}