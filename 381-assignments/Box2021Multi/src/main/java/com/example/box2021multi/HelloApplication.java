package com.example.box2021multi;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) {
        HBox root = new HBox();

        // MVC
        BoxView view = new BoxView(700,700);

        BoxModel model = new BoxModel();
        BoxController controller = new BoxController();
        InteractionModel iModel = new InteractionModel();

        view.setModel(model);
        view.setController(controller);
        view.setInteractionModel(iModel);
        controller.setInteractionModel(iModel);
        controller.setModel(model);

        model.addSubscriber(view);
        iModel.addSubscriber(view);

        root.getChildren().addAll(view);

        model.createBox(0.1,0.2);
        model.createBox(0.4,0.3);


        stage.setTitle("BoxDemo");
        stage.setScene(new Scene(root));
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}