import java.util.Random;
import java.util.Scanner;

public class NumberGame {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Random r = new Random();

        int number = r.nextInt(100) + 1;
        int guess;

        do {
            System.out.print("Enter your guess: ");
            guess = sc.nextInt();

            if (guess > number) {
                System.out.println("Too High!");
            } else if (guess < number) {
                System.out.println("Too Low!");
            } else {
                System.out.println("Correct Guess!");
            }

        } while (guess != number);

        sc.close();
    }
}