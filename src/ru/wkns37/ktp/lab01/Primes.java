package ru.wkns37.ktp.lab01;

/**
 * This program iterates all the numbers from 0 to 100 inclusively
 * and finds the prime ones.
 */
public class Primes {
    public static void main(String[] args) {
        for (int i = 2; i <= 100; i++) {
            if (isPrime(i)) {
                System.out.println("Found prime: " + i);
            }
        }
    }

    /**
     * Determines whether the number is prime.
     *
     * @param number the number to be tested
     * @return true if the number is prime, false otherwise.
     */
    public static boolean isPrime(final int number) {
        for (int i = 2; i < number; i++) {
            if (number % i == 0) {
                return false;
            }
        }

        return true;
    }
}
