package ru.wkns37.ktp.lab06;

import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;

public class JImageDisplay extends JComponent {
    private final BufferedImage image;

    JImageDisplay(int width, int height) {
        image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        setPreferredSize(new Dimension(width, height));
    }

    /**
     * Paints the specified graphics
     */
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawImage(image, 0, 0, image.getWidth(), image.getHeight(), null);
    }

    /**
     * Returns display's internal buffered image
     */
    public BufferedImage getImage() {
        return image;
    }

    /**
     * Clears display's internal buffered image
     */
    public void clearImage() {

    }

    /**
     * Draws pixel on specified coordinates with color on the display
     */
    public void drawPixel(int x, int y, int rgbColor) {
        image.setRGB(x, y, rgbColor);
    }
}
