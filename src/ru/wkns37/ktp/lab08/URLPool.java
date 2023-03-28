package ru.wkns37.ktp.lab08;

import java.util.*;

public class URLPool {
    private final LinkedList<URLDepthPair> pendingURLs;
    public LinkedList<URLDepthPair> processedURLs;
    public int waitingThreads;
    private final int maxDepth;

    public URLPool(int maxDepth) {
        waitingThreads = 0;
        this.maxDepth = maxDepth;
        pendingURLs = new LinkedList<>();
        processedURLs = new LinkedList<>();
    }

    public synchronized int getWaitThreads() {
        return waitingThreads;
    }

    public synchronized void put(URLDepthPair depthPair) {
        if (depthPair.getDepth() <= maxDepth) {
            pendingURLs.addLast(depthPair);
            this.notify();
        }
    }

    public synchronized URLDepthPair get() {
        URLDepthPair myDepthPair;

        if (pendingURLs.size() == 0) {
            waitingThreads++;
            try {
                this.wait();
            } catch (Exception ignore) {
                return null;
            }
        }

        myDepthPair = pendingURLs.removeFirst();
        processedURLs.add(myDepthPair);
        return myDepthPair;
    }
}
