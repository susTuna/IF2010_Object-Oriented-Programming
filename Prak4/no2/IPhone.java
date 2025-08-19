public class IPhone extends Device {
    private int batteryLevel;
    
    // Set battery level to 100 on initialization
    public IPhone() {
        super("IPhone");
        this.batteryLevel = 100;
    }
    
    @Override
    // If the battery level is 0, print out "IPhone battery is depleted"
    // If the device is not connected, print out "IPhone is not connected"
    // If the device is connected and the battery level is greater than 0, print out "IPhone is nearby! Distance: *batteryLevel* meters away" 
    // and decrease the battery level by 10
    public void locate() {
        if (this.batteryLevel == 0) System.out.println("IPhone battery is depleted");
        else if (!this.isConnected()) System.out.println("IPhone is not connected");
        else {
            System.out.println("IPhone is nearby! Distance: " + this.batteryLevel + " meters away");
            this.batteryLevel -= 10;
        }
    }
    
    @Override
    // If the battery level is 0, print out "IPhone battery is depleted"
    // If the device is not connected, print out "IPhone is not connected"
    // If the device is connected and the battery level is greater than 0, print out "IPhone: *LOUD BEEPING*"
    // and decrease the battery level by 20
    public void makeSound() {
        if (this.batteryLevel == 0) System.out.println("IPhone battery is depleted");
        else if (!this.isConnected()) System.out.println("IPhone is not connected");
        else {
            System.out.println("IPhone: *LOUD BEEPING*");
            this.batteryLevel -= 20;
        }
    }
    
    // Set the battery level to 100
    // Print out "IPhone charged to 100%"
    public void charge() {
        this.batteryLevel = 100;
        System.out.println("IPhone charged to 100%");
    }
}