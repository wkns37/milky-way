package ru.wkns37.ktp.lab03;

import java.util.HashMap;

/**
 * This class stores the basic state necessary for the A* algorithm to compute a
 * path across a map.  This state includes a collection of "open waypoints" and
 * another collection of "closed waypoints."  In addition, this class provides
 * the basic operations that the A* pathfinding algorithm needs to perform its
 * processing.
 **/
public class AStarState {
    /**
     * This is a reference to the map that the A* algorithm is navigating.
     **/
    private final Map2D map;
    private final HashMap<Location, Waypoint> openedWaypoints;
    private final HashMap<Location, Waypoint> closedWaypoints;

    /**
     * Initialize a new state object for the A* pathfinding algorithm to use.
     **/
    public AStarState(Map2D map) {
        if (map == null)
            throw new NullPointerException("map cannot be null");

        this.map = map;
        this.openedWaypoints = new HashMap<>();
        this.closedWaypoints = new HashMap<>();
    }

    /**
     * Returns the map that the A* pathfinder is navigating.
     **/
    public Map2D getMap() {
        return map;
    }

    /**
     * This method scans through all open waypoints, and returns the waypoint
     * with the minimum total cost.  If there are no open waypoints, this method
     * returns <code>null</code>.
     **/
    public Waypoint getMinOpenWaypoint() {
        Waypoint smallest = null;
        for (Waypoint waypoint : openedWaypoints.values()) {
            if (smallest == null) {
                smallest = waypoint;
            }

            if (waypoint.getTotalCost() < smallest.getTotalCost()) {
                smallest = waypoint;
            }
        }

        return smallest;
    }

    /**
     * This method adds a waypoint to (or potentially updates a waypoint already
     * in) the "open waypoints" collection.  If there is not already an open
     * waypoint at the new waypoint's location then the new waypoint is simply
     * added to the collection.  However, if there is already a waypoint at the
     * new waypoint's location, the new waypoint replaces the old one <em>only
     * if</em> the new waypoint's "previous cost" value is less than the current
     * waypoint's "previous cost" value.
     **/
    public void addOpenWaypoint(Waypoint newWP) {
        Waypoint existing = openedWaypoints.get(newWP.getLocation());
        if (existing != null) {
            if (newWP.getPreviousCost() < existing.getPreviousCost()) {
                openedWaypoints.put(newWP.getLocation(), newWP);
            }
        } else {
            openedWaypoints.put(newWP.getLocation(), newWP);
        }
    }


    /**
     * Returns the current number of open waypoints.
     **/
    public int numOpenWaypoints() {
        return openedWaypoints.size();
    }


    /**
     * This method moves the waypoint at the specified location from the
     * open list to the closed list.
     **/
    public void closeWaypoint(Location loc) {
        Waypoint removed = openedWaypoints.remove(loc);
        closedWaypoints.put(loc, removed);
    }

    /**
     * Returns true if the collection of closed waypoints contains a waypoint
     * for the specified location.
     **/
    public boolean isLocationClosed(Location loc) {
        return closedWaypoints.get(loc) != null;
    }
}

