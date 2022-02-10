package com.example.box2021multi;

import java.util.ArrayList;
import java.util.Optional;

public class BoxModel {
    public ArrayList<Box> boxes;
    ArrayList<BoxModelSubscriber> subscribers;

    public BoxModel() {
        subscribers = new ArrayList<>();
        boxes = new ArrayList<>();
    }

    public void createBox(double left, double top) {
        Box b = new Box(left - 0.05, top-0.05, 0.1, 0.1);
        boxes.add(b);
        notifySubscribers();
    }

    public Optional<Box> checkHit(double x, double y) {
        return boxes.stream().filter(s -> s.contains(x, y)).reduce((first, second) -> second);
    }

    public void moveBox(Box b, double dX, double dY) {
        b.move(dX,dY);
        notifySubscribers();
    }

    public void addSubscriber (BoxModelSubscriber aSub) {
        subscribers.add(aSub);
    }

    private void notifySubscribers() {
        subscribers.forEach(sub -> sub.modelChanged());
    }
}
