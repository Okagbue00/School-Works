package com.example.box2021multi;

import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;

import java.util.Optional;

public class BoxController {
    InteractionModel iModel;
    BoxModel model;
    double prevX, prevY;

    private enum State {
        READY, PREPARE_CREATE, DRAGGING
    }

    private State currentState;

    public BoxController() {
        currentState = State.READY;
    }

    public void setInteractionModel(InteractionModel newModel) {
        iModel = newModel;
    }

    public void setModel(BoxModel newModel) {
        model = newModel;
    }

    public void handlePressed(double normX, double normY, MouseEvent event) {
        prevX = normX;
        prevY = normY;

        switch (currentState) {
            case READY -> {
                // context: are we on a box?
                Optional<Box> hit = model.checkHit(normX, normY);
                if (hit.isPresent()) {
                    // side effects:
                    // - set selection
                    iModel.setSelection(hit.get());
                    // move to new state
                    currentState = State.DRAGGING;
                } else {
                    // on background
                    // more context: is the right button pressed?
                    if (event.getButton().equals(MouseButton.SECONDARY)) {
                        // side effects
                        // - none
                        // move to new state
                        currentState = State.PREPARE_CREATE;
                    } else {
                        // on background, left button, so cancel selection
                        // side effects:
                        // - unselect
                        iModel.unselect();
                        currentState = State.READY;
                    }
                }
            }
        }
    }

    public void handleDragged(double normX, double normY, MouseEvent event) {
        double dX = normX - prevX;
        double dY = normY - prevY;
        prevX = normX;
        prevY = normY;

        switch (currentState) {
            case DRAGGING -> {
                // context: none
                // side effects:
                // - move box
                model.moveBox(iModel.selection, dX, dY);
                // stay in this state
            }
            case PREPARE_CREATE -> {
                // context: none
                // side effects: none
                // move to new state
                currentState = State.READY;
            }
        }
    }

    public void handleReleased(double normX, double normY, MouseEvent event) {
        switch (currentState) {
            case DRAGGING -> {
                // context: none
                // side effects: none
                // move to new state
                currentState = State.READY;
            }
            case PREPARE_CREATE -> {
                // context: none
                // side effects
                // - create box
                model.createBox(normX, normY);
                // move to new state
                currentState = State.READY;
            }
        }
    }
}
