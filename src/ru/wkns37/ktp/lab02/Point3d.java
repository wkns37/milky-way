package ru.wkns37.ktp.lab02;

import java.util.Objects;

/**
 * The {@code Point3d} class defines a point representing a location in {@code (x,y,z)} coordinate space.
 */
public class Point3d {
    private double x, y, z;

    public Point3d(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    /**
     * Return the X coordinate of this {@code Point3d}
     */
    public double getX() {
        return x;
    }

    /**
     * Sets the X coordinate of this {@code Point3d}
     */
    public void setX(double x) {
        this.x = x;
    }

    /**
     * Return the Y coordinate of this {@code Point3d}
     */
    public double getY() {
        return y;
    }

    /**
     * Sets the Y coordinate of this {@code Point3d}
     */
    public void setY(double y) {
        this.y = y;
    }

    /**
     * Return the Z coordinate of this {@code Point3d}
     */
    public double getZ() {
        return z;
    }

    /**
     * Sets the Z coordinate of this {@code Point3d}
     */
    public void setZ(double z) {
        this.z = z;
    }

    /**
     * Returns the distance between to points
     */
    public double distanceTo(Point3d p) {
        return Math.sqrt(Math.pow(p.x - this.x, 2) +
                Math.pow(p.y - this.y, 2) +
                Math.pow(p.z - this.z, 2));
    }

    /**
     * Returns the area of the triangle based on specified points
     */
    public static double computeArea(Point3d p1, Point3d p2, Point3d p3) {
        double a = p1.distanceTo(p2);
        double b = p2.distanceTo(p3);
        double c = p3.distanceTo(p1);
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point3d point3d = (Point3d) o;
        return Double.compare(point3d.x, x) == 0 && Double.compare(point3d.y, y) == 0 && Double.compare(point3d.z, z) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y, z);
    }
}
