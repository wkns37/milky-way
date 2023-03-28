package ru.wkns37.ktp.lab07;

import java.net.*;

/**
 * A class to represent [URL, depth] pairs for our Crawler.
 */
public class URLDepthPair {
    private final int currentDepth;
    private final String currentURL;

    public URLDepthPair(String URL, int depth) {
        currentDepth = depth;
        currentURL = URL;
    }

    public String getURL() {
        return currentURL;
    }

    public int getDepth() {
        return currentDepth;
    }

    public String getDocPath() {
        try {
            URL url = new URL(currentURL);
            return url.getPath();
        } catch (Exception ignore) {
            return null;
        }
    }

    public String getWebHost() {
        try {
            URL url = new URL(currentURL);
            return url.getHost();
        } catch (Exception ignore) {
            return null;
        }
    }

    @Override
    public String toString() {
        return Integer.toString(currentDepth) + '\t' + currentURL;
    }
}
