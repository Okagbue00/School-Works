package sample;


import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.geometry.Pos;

import javafx.scene.Scene;
import javafx.scene.control.Button;

import javafx.scene.control.ListView;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;



public class Main extends Application {


    public Circle circle;
    public Color cr;
    public ColorSlider colorSlider1;
    public ColorSlider colorSlider2;
    public ColorSlider colorSlider3;
    public int x = 0;


    public void setColor() {
        Color color = Color.rgb(colorSlider1.getValue(), colorSlider2.getValue(), colorSlider3.getValue());
        circle.setFill(color);
    }

    PalletView palletView;
    ColorPalette color_palette;

    @Override
    public void start(Stage primaryStage) {


        final double width = 700;
        final double height = 600;


        color_palette = new ColorPalette();

        palletView = new PalletView(color_palette);
//        palletView = new PalletView(color_palette);

        ObservableList<ColorPalette> list = FXCollections.observableArrayList();
        ListView<ColorPalette> list_view = new ListView<>(list);
        list_view.setCellFactory(lis -> new Pallet_cell());


        list_view.setMinHeight(895);
        list_view.setMinWidth(350);



        circle = new Circle(100);
        circle.setFill(Color.rgb(50,50,50));
        Button button = new Button("Add to Palette");
        Button button1 = new Button("Add to List");



        colorSlider1 = new ColorSlider("Red");
        colorSlider2 = new ColorSlider("Green");
        colorSlider3 = new ColorSlider("Blue");



        colorSlider1.slider.valueProperty().addListener(((observableValue, number, t1) -> {
            colorSlider1.setValue();
            setColor();
        }));



        colorSlider2.slider.valueProperty().addListener(((observableValue, number, t1) -> {
            colorSlider2.setValue();
            setColor();
        }));


        colorSlider3.slider.valueProperty().addListener(((observableValue, number, t1) -> {
            colorSlider3.setValue();
            setColor();
        }));


        HBox hbox = new HBox();

        VBox vbox1 = new VBox();
        VBox vbox_2 = new VBox();


        HBox red_hbox = new HBox(10);
        red_hbox.getChildren().add(colorSlider1);
        HBox green_hbox = new HBox(10);
        green_hbox.getChildren().add(colorSlider2);
        HBox blue_hbox = new HBox(10);
        blue_hbox.getChildren().add(colorSlider3);

        red_hbox.setPadding(new Insets(10, 10, 10, 10));
        green_hbox.setPadding(new Insets(10, 10, 10, 10));
        blue_hbox.setPadding(new Insets(10, 10, 10, 10));

        HBox circle_hbox = new HBox(10);
        circle_hbox.setPadding(new Insets(10, 10, 10, 10));
        circle_hbox.getChildren().addAll(palletView);




        button.setOnMouseClicked(e -> {
            cr = Color.rgb(colorSlider1.getValue(),colorSlider2.getValue(),colorSlider3.getValue());
//            color_palette.addColor(cr);
            if (x != 0) {
                if (x==1){
                palletView.circle2.setFill(cr);
                    color_palette.addColor(cr, 1);

                    x = x + 1;
                }
                else{
                palletView.circle3.setFill(cr);
                    color_palette.addColor(cr, 2);

                    x = 0;}
            } else {
            palletView.circle1.setFill(cr);
            color_palette.addColor(cr, 0);
                x = x + 1;}

        });

//        button1.setOnMouseClicked(e -> list.add(color_palette) );

        button1.setOnMouseClicked(e -> {
            ColorPalette cp= new ColorPalette();
            cp.addColor(color_palette.currentcolor_red, 0);
            cp.addColor(color_palette.currentcolor_green, 1);
            cp.addColor(color_palette.currentcolor_blue, 2);

            list_view.getItems().add(cp);

        } );


        hbox.getChildren().addAll(vbox1, vbox_2);
        vbox1.getChildren().addAll(circle, red_hbox, green_hbox, blue_hbox, button, circle_hbox, button1);
        vbox_2.getChildren().addAll(list_view);
        vbox1.setSpacing(20.0);

        vbox1.setAlignment(Pos.CENTER);

        Scene scene = new Scene(hbox, width, height, Color.WHITE);

        primaryStage.setScene(scene);
        primaryStage.show();
    }














    public static void main(String[] args) {
        launch(args);

    }




}
