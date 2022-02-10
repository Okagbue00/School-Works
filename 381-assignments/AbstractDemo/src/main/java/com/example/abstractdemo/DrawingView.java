package com.example.abstractdemo;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;

public class DrawingView extends StackPane implements DrawingModelSubscriber {
    Canvas myCanvas;
    GraphicsContext gc;
    DrawingModel model;
    InteractionModel iModel;

    public DrawingView() {
        myCanvas = new Canvas(1000, 600);
        gc = myCanvas.getGraphicsContext2D();
        this.getChildren().add(myCanvas);
    }

    public void setModel(DrawingModel newModel) {
        model = newModel;
    }

    public void setInteractionModel(InteractionModel newIModel) {
        iModel = newIModel;
        iModel.setViewSize(myCanvas.getWidth(), myCanvas.getHeight());
    }

    public void setController(DrawingController controller) {
        myCanvas.setOnMousePressed(controller::handlePressed);
    }

    public void draw() {
        gc.clearRect(0, 0, myCanvas.getWidth(), myCanvas.getHeight());
        model.getItems().forEach(item -> {
            switch (item) {
                case RedCircle red -> this.drawRedCircle(red);
                case BlueSquare blue -> this.drawBlueSquare(blue);
                case DrawingItem di -> System.out.println("Error: fell through to DrawingItem");
            }
        });
    }

    private void drawRedCircle(RedCircle red) {
        gc.setFill(Color.RED);
        gc.fillOval(red.left, red.top, red.size, red.size);
    }

    private void drawBlueSquare(BlueSquare blue) {
        gc.setFill(Color.BLUE);
        gc.fillRect(blue.left, blue.top, blue.size, blue.size);
    }

    public void modelChanged() {
        draw();
    }
}
