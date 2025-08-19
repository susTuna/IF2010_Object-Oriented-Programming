public class Main {
  public static void main(String[] args) {
    GiftChecker checker = new GiftChecker(1, 10);
    MultithreadProgram mtChecker = new MultithreadProgram(checker);
    mtChecker.findCorrectNumber();
    try {
      Thread.sleep(200);
    } catch (InterruptedException e) {
      Thread.currentThread().interrupt();
    }
    System.out.println("Number found: " + mtChecker.foundNumber);
  }
}