package ru.wkns37.ktp.lab02;

import java.util.Scanner;
import java.util.stream.Stream;

/**
 * This program defines triangle base on user input and returns the area of this triangle
 */
public class Application {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Point3d p1;
        Point3d p2;
        Point3d p3;

        System.out.print("Enter coordinates for the first point (eg. 1 2 3): ");
        int[] coordinates = readIntegers(scanner);
        p1 = new Point3d(coordinates[0], coordinates[1], coordinates[2]);

        System.out.print("Enter coordinates for the second point (eg. 1 2 3): ");
        coordinates = readIntegers(scanner);
        p2 = new Point3d(coordinates[0], coordinates[1], coordinates[2]);

        System.out.print("Enter coordinates for the third point (eg. 1 2 3): ");
        coordinates = readIntegers(scanner);
        p3 = new Point3d(coordinates[0], coordinates[1], coordinates[2]);

        if (pointsAreValid(p1, p2, p3)) {
            double area = Point3d.computeArea(p1, p2, p3);
            System.out.printf("The area of the triangle: %.3f\n", area);
        } else {
            System.out.println("Every triangle point must differ from each other");
        }
    }

    /**
     * Reads user's input as three strings and returns corresponding array of integers
     */
    private static int[] readIntegers(Scanner scanner) {
        String input = scanner.nextLine();
        return Stream.of(input.split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    /**
     * Determines whether the points are different from each other
     * @return true if the points are different, false otherwise
     */
    private static boolean pointsAreValid(Point3d p1, Point3d p2, Point3d p3) {
        return !p1.equals(p2) && !p2.equals(p3) && !p3.equals(p1);
    }
}
