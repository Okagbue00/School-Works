package com.example.abstractdemo;

public class BlueSquare extends DrawingItem {
    public BlueSquare(double left, double top, double size) {
        super(left,top,size);
    }
    public boolean contains(double x, double y) {
        return x >= left && x <= left+size && y >= top && y <= top+size;
    }
}
