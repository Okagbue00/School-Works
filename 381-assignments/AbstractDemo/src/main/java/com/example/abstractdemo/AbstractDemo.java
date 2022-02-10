package com.example.abstractdemo;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

import java.io.IOException;

public class AbstractDemo extends Application {
    @Override
    public void start(Stage stage) {
        StackPane root = new StackPane();

        DrawingModel model = new DrawingModel();
        DrawingView view = new DrawingView();
        DrawingController controller = new DrawingController();
        InteractionModel iModel = new InteractionModel();

        model.addSubscriber(view);
        view.setModel(model);
        view.setInteractionModel(iModel);
        view.setController(controller);
        controller.setModel(model);
        controller.setInteractionModel(iModel);

        root.getChildren().add(view);
        Scene scene = new Scene(root);
        scene.setOnKeyPressed(controller::handleKeyPressed);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}