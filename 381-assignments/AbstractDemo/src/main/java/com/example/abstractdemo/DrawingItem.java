package com.example.abstractdemo;

public abstract class DrawingItem {
    double left, top, size;

    public DrawingItem() {
        left = 0;
        top = 0;
        size = 0;
    }

    public DrawingItem(double newLeft, double newTop, double newSize) {
        left = newLeft;
        top = newTop;
        size = newSize;
    }

    public abstract boolean contains(double x, double y);
}
