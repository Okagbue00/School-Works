package com.example.abstractdemo;

import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;

public class DrawingController {
    DrawingModel model;
    InteractionModel iModel;

    public DrawingController() {
    }

    public void setModel(DrawingModel newModel) {
        model = newModel;
    }

    public void setInteractionModel(InteractionModel newIModel) {
        iModel = newIModel;
    }

    public void handlePressed(MouseEvent event) {
        double size = Math.random() * 100 + 50;
        if (Math.random() > 0.5) {
            model.addBlueSquare(event.getX(), event.getY(), size);
        } else {
            model.addRedCircle(event.getX(), event.getY(), size);
        }
    }

    public void handleKeyPressed(KeyEvent keyEvent) {
        double left = Math.random() * iModel.getViewWidth();
        double top = Math.random() * iModel.getViewHeight();
        double size = Math.random() * 100 + 50;
        switch (keyEvent.getCode()) {
            case B -> model.addBlueSquare(left, top, size);
            case R -> model.addRedCircle(left, top, size);
            default -> System.out.println("Inactive key: " + keyEvent.getCharacter());
        }
    }
}
