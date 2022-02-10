package com.example.box2021multi;

import java.util.ArrayList;

public class InteractionModel {
    Box selection;
    Box highlight;
    ArrayList<BoxModelSubscriber> subscribers;

    public InteractionModel() {
        subscribers = new ArrayList<>();
        selection = null;
    }

    public void setSelection(Box b) {
        selection = b;
        notifySubscribers();
    }

    public void addSubscriber (BoxModelSubscriber aSub) {
        subscribers.add(aSub);
    }

    private void notifySubscribers() {
        subscribers.forEach(sub -> sub.modelChanged());
    }

    public Box getSelection() {
        return selection;
    }

    public void unselect() {
        selection = null;
        notifySubscribers();
    }

    public void setHighlight(Box whichBox) {
        highlight = whichBox;
        notifySubscribers();
    }

    public void unHighlight() {
        highlight = null;
        notifySubscribers();
    }
}
