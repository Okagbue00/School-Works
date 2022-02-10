package sample;


import javafx.geometry.Insets;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;


public class ColorSlider extends Pane {

    Slider slider;
    Label label;
    Label labelValue;

    public int getValue() {
        return ((int)slider.getValue());
    }

    public void setValue() {
        labelValue.setText(Integer.toString(getValue()));
    }

    public ColorSlider(String arg) {
        slider = new Slider(0, 255, 50);
        label = new Label(arg);
        labelValue = new Label("50");

        HBox hbox = new HBox(10);
        hbox.setPadding(new Insets(10, 10, 10, 10));
        hbox.getChildren().addAll(label, slider, labelValue);
        this.getChildren().addAll(hbox);


    }


}






