package ru.wkns37.ktp.lab06;

import javax.swing.*;
import javax.swing.filechooser.FileFilter;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.geom.Rectangle2D;

public class FractalExplorer {
    private final int displaySize;
    private final JImageDisplay display;
    private FractalGenerator fractal;
    private final Rectangle2D.Double range;
    private int rowsRemaining;

    private JComboBox<FractalGenerator> fractalChooser;
    private JButton saveButton;
    private JButton resetButton;

    public FractalExplorer(int displaySize) {
        this.displaySize = displaySize;
        fractal = new Mandelbrot();
        range = new Rectangle2D.Double();
        fractal.getInitialRange(range);
        display = new JImageDisplay(displaySize, displaySize);
    }

    public void createAndShowGUI() {
        display.setLayout(new BorderLayout());
        JFrame frame = new JFrame("Fractal Explorer");
        frame.add(display, BorderLayout.CENTER);
        display.addMouseListener(new MouseHandler());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        fractalChooser = new JComboBox<>(new FractalGenerator[]{new Mandelbrot(), new Tricorn(), new BurningShip()});
        fractalChooser.addActionListener(new ButtonHandler());
        JPanel panel = new JPanel();
        panel.add(new JLabel("Fractal:"));
        panel.add(fractalChooser);
        frame.add(panel, BorderLayout.NORTH);

        saveButton = new JButton("Save");
        JPanel myBottomPanel = new JPanel();
        resetButton = new JButton("Reset");
        resetButton.addActionListener(new ResetHandler());
        myBottomPanel.add(saveButton);
        myBottomPanel.add(resetButton);
        frame.add(myBottomPanel, BorderLayout.SOUTH);
        saveButton.addActionListener(new ButtonHandler());
        frame.pack();
        frame.setVisible(true);
        frame.setResizable(false);
    }

    private void enableUI(boolean val) {
        fractalChooser.setEnabled(val);

        saveButton.setEnabled(val);
        resetButton.setEnabled(val);
    }

    private void drawFractal() {
        enableUI(false);

        for (int y = 0; y < displaySize; y++) {
            new FractalWorker(y).execute();
        }

        display.repaint();
    }

    private class ButtonHandler implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();
            if (e.getSource() instanceof JComboBox) {
                @SuppressWarnings("rawtypes")
                JComboBox source = (JComboBox) e.getSource();
                fractal = (FractalGenerator) source.getSelectedItem();
                assert fractal != null;
                fractal.getInitialRange(range);
                drawFractal();
            } else if (command.equals("Reset")) {
                fractal.getInitialRange(range);
                drawFractal();
            } else if (command.equals("Save")) {
                JFileChooser chooser = new JFileChooser();
                FileFilter filter =
                        new FileNameExtensionFilter("PNG Images", "png");
                chooser.setFileFilter(filter);
                chooser.setAcceptAllFileFilterUsed(false);
                int selection = chooser.showSaveDialog(display);
                if (selection == JFileChooser.APPROVE_OPTION) {
                    java.io.File file = chooser.getSelectedFile();
                    try {
                        javax.imageio.ImageIO.write(display.getImage(), "png", file);
                    } catch (Exception exception) {
                        JOptionPane.showMessageDialog(display,
                                exception.getMessage(), "Cannot Save Image",
                                JOptionPane.ERROR_MESSAGE);
                    }
                }
            }
        }
    }

    private class ResetHandler implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            fractal.getInitialRange(range);
            drawFractal();
        }
    }

    private class MouseHandler extends MouseAdapter {
        @Override
        public void mouseClicked(MouseEvent e) {
            if (rowsRemaining > 0) {
                return;
            }

            int x = e.getX();
            double xCoord = FractalGenerator.getCoord(range.x,
                    range.x + range.width, displaySize, x);
            int y = e.getY();
            double yCoord = FractalGenerator.getCoord(range.y,
                    range.y + range.height, displaySize, y);
            fractal.recenterAndZoomRange(range, xCoord, yCoord, 0.5);
            drawFractal();
        }
    }

    public static void main(String[] args) {
        FractalExplorer explorer = new FractalExplorer(800);
        explorer.createAndShowGUI();
        explorer.drawFractal();
    }

    private class FractalWorker extends SwingWorker<Object, Object> {
        private final int y;
        private int[] pixels;

        public FractalWorker(int y) {
            this.y = y;
        }

        @Override
        protected Object doInBackground() {
            pixels = new int[displaySize];

            double yCoord = FractalGenerator.getCoord(range.y,
                    range.y + range.height, displaySize, y);

            for (int x = 0; x < displaySize; x++) {
                double xCoord = FractalGenerator.getCoord(range.x,
                        range.x + range.width, displaySize, x);
                int iteration = fractal.numIterations(xCoord, yCoord);
                if (iteration == -1) {
                    pixels[x] = 0;
                } else {
                    float hue = 0.7f + (float) iteration / 200f;
                    int rgbColor = Color.HSBtoRGB(hue, 1f, 1f);
                    pixels[x] = rgbColor;
                }
            }

            return null;
        }

        @Override
        protected void done() {
            for (int x = 0; x < displaySize; x++) {
                display.drawPixel(x, y, pixels[x]);
            }

            display.repaint(0, y, displaySize, 1);

            if (rowsRemaining-- < 1) {
                enableUI(true);
            }
        }
    }
}
