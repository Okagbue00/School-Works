package com.example.abstractdemo;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class DrawingModel {
    private ArrayList<DrawingItem> items;
    private ArrayList<DrawingModelSubscriber> subs;

    public DrawingModel() {
        items = new ArrayList<>();
        subs = new ArrayList<>();
    }

    public void addSubscriber(DrawingModelSubscriber aSub) {
        subs.add(aSub);
    }

    private void notifySubscribers() {
        subs.forEach(sub -> sub.modelChanged());
    }

    public void addRedCircle(double left, double top, double size) {
        items.add(new RedCircle(left,top,size));
        notifySubscribers();
    }

    public void addBlueSquare(double left, double top, double size) {
        items.add(new BlueSquare(left,top,size));
        notifySubscribers();
    }

    public List<DrawingItem> getItems() {
        return items;
    }

    public Optional<DrawingItem> getItem(double x, double y) {
        return items.stream().filter(item -> item.contains(x,y)).findFirst();
    }
}
