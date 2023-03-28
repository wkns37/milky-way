package ru.wkns37.ktp.lab01;

/**
 * This program gets user's input using command-line arguments as
 * strings and prints whether they are palindromes or not.
 */
public class Palindrome {
    public static void main(String[] args) {
        for (String arg : args) {
            if (isPalindrome(arg)) {
                System.out.printf("'%s' is a palindrome\n", arg);
            } else {
                System.out.printf("'%s' is not a palindrome\n", arg);
            }
        }
    }

    /**
     * Returns the inverted version of the specified string
     *
     * @param str the string to be reversed
     * @return an inverted version of the specified string
     */
    public static String reverseString(final String str) {
        return new StringBuilder(str).reverse().toString();
    }

    /**
     * Returns whether the string is palindrome
     *
     * @param str the string to be tested
     * @return true if the string is palindrome, false otherwise
     */
    public static boolean isPalindrome(final String str) {
        final String reversed = reverseString(str);
        return str.equals(reversed);
    }
}
