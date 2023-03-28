package ru.wkns37.ktp.lab07;

import java.net.*;
import java.util.*;
import java.io.*;

public class Crawler {

    public static void main(String[] args) {
        int depth = 0;

        if (args.length != 2) {
            System.out.println("usage: java Crawler <URL> <depth>");
            System.exit(1);
        } else {
            try {
                depth = Integer.parseInt(args[1]);
            } catch (Exception ignore) {
                System.out.println("Unable to parse the depth value");
                System.exit(1);
            }
        }

        LinkedList<URLDepthPair> pendingURLs = new LinkedList<>();
        LinkedList<URLDepthPair> processedURLs = new LinkedList<>();
        URLDepthPair currentDepthPair = new URLDepthPair(args[0], 0);
        pendingURLs.add(currentDepthPair);
        ArrayList<String> seenURLs = new ArrayList<>();
        seenURLs.add(currentDepthPair.getURL());

        while (pendingURLs.size() != 0) {
            URLDepthPair depthPair = pendingURLs.pop();
            processedURLs.add(depthPair);
            int myDepth = depthPair.getDepth();
            LinkedList<String> linksList = Crawler.getAllLinks(depthPair);
            if (myDepth < depth) {
                for (String newURL : linksList) {
                    if (!seenURLs.contains(newURL)) {
                        URLDepthPair newDepthPair = new URLDepthPair(newURL, myDepth + 1);
                        pendingURLs.add(newDepthPair);
                        seenURLs.add(newURL);
                    }
                }
            }
        }

        for (URLDepthPair processedURL : processedURLs) {
            System.out.println(processedURL);
        }
    }

    private static LinkedList<String> getAllLinks(URLDepthPair myDepthPair) {
        LinkedList<String> URLs = new LinkedList<>();
        Socket sock;
        try {
            sock = new Socket(myDepthPair.getWebHost(), 80);
        } catch (UnknownHostException e) {
            System.err.println("UnknownHostException: " + e.getMessage());
            return URLs;
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
                if (index == -1) {
                    break;
                }

                String newLink = line.substring(beginIndex, endIndex);
                URLs.add(newLink);
            }

        }

        return URLs;
    }
}
