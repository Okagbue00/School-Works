package com.example.abstractdemo;

public class RedCircle extends DrawingItem {
    double cx, cy;

    public RedCircle(double left, double top, double size) {
        super(left,top,size);
        cx = left + size/2;
        cy = top + size/2;
    }
    public boolean contains(double x, double y) {
        return Math.hypot(x-cx,y-cy) <= size/2;
    }
}
