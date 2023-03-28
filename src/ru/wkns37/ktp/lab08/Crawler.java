package ru.wkns37.ktp.lab08;

import java.net.*;
import java.util.*;
import java.io.*;

public class Crawler {

    public static void main(String[] args) {
        int depth = 0;
        int numThreads = 0;

        if (args.length != 3) {
            System.out.println("usage: java Crawler <URL> <depth> <threads number>");
            System.exit(1);
        } else {
            try {
                depth = Integer.parseInt(args[1]);
                numThreads = Integer.parseInt(args[2]);
            } catch (Exception ignore) {
                System.out.println("usage: java Crawler <URL> <depth> <threads number>");
                System.exit(1);
            }
        }

        URLDepthPair currentDepthPair = new URLDepthPair(args[0], 0);
        URLPool pool = new URLPool(depth);
        pool.put(currentDepthPair);
        int initialActive = Thread.activeCount();

        while (pool.getWaitThreads() != numThreads) {
            if (Thread.activeCount() - initialActive < numThreads) {
                CrawlerTask crawler = new CrawlerTask(pool);
                new Thread(crawler).start();
            } else {
                try {
                    Thread.sleep(100);
                } catch (Exception ignore) {
                }
            }
        }

        for (URLDepthPair urlDepthPair : pool.processedURLs) {
            System.out.println(urlDepthPair);
        }

        System.exit(0);
    }

    public static LinkedList<String> getAllLinks(URLDepthPair myDepthPair) {
        LinkedList<String> URLs = new LinkedList<>();
        Socket sock;
        try {
            sock = new Socket(myDepthPair.getWebHost(), 80);
        } catch (Exception ignore) {
            return URLs;
        }

        try {
            sock.setSoTimeout(3000);
        } catch (Exception ignore) {
            return URLs;
        }

        String docPath = myDepthPair.getDocPath();
        String webHost = myDepthPair.getWebHost();

        OutputStream outStream;

        try {
            outStream = sock.getOutputStream();
        } catch (Exception ignore) {
            return URLs;
        }

        PrintWriter myWriter = new PrintWriter(outStream, true);

        myWriter.println("GET " + docPath + " HTTP/1.1");
        myWriter.println("Host: " + webHost);
        myWriter.println("Connection: close");
        myWriter.println();

        InputStream inStream;

        try {
            inStream = sock.getInputStream();
        } catch (Exception ignore) {
            return URLs;
        }

        InputStreamReader inStreamReader = new InputStreamReader(inStream);
        BufferedReader BuffReader = new BufferedReader(inStreamReader);

        while (true) {
            String line;
            try {
                line = BuffReader.readLine();
            } catch (Exception ignore) {
                return URLs;
            }

            if (line == null)
                break;

            int beginIndex;
            int endIndex;
            int index = 0;

            while (true) {
                String URL_INDICATOR = "a href=\"";
                String END_URL = "\"";
                index = line.indexOf(URL_INDICATOR, index);
                if (index == -1) // No more copies of start in this line
                    break;

                index += URL_INDICATOR.length();
                beginIndex = index;

                endIndex = line.indexOf(END_URL, index);
                index = endIndex;
                if (index == -1)
                    break;

                String newLink = line.substring(beginIndex, endIndex);
                URLs.add(newLink);
            }

        }
        return URLs;
    }
}
