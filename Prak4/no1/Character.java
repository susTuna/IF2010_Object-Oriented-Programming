class Character extends Unit implements Damageable {
    private int score = 0;

    public Character() {
        super("Player1", 100);
        this.score = 0;
    }

    public Character(String name, int health, int score) {
        super(name, health);
        this.score = score;
    }

    //setter & getter
    public int getScore() { return this.score; }

    public void setScore(int score) { this.score = score; }

    //implements Damageable
    public void takeDamage(int damage) {
        int rHP = this.getHealth() - damage;
        if(rHP <= 0) 
        {
            System.out.println(this.getName() + " has been defeated");
            rHP = 0;
        }
        this.setHealth(rHP);
    }

    public void increaseScore(int points) { this.score += points; }

    //override
    public String toString() {
        return (this.getName() + " [Health: " + this.getHealth() + ", Score: " + this.getScore() + "]");
    }
}