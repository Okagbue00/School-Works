package sample;


import javafx.geometry.Insets;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;


import java.util.Objects;


public class PalletView extends Pane {

   Circle circle1;
   Circle circle2;
   Circle circle3;
   ColorPalette palette;

   public PalletView(ColorPalette colour_palette) {
       HBox hBox = new HBox();
       hBox.setPadding(new Insets(10, 10, 10, 10));
       this.palette = Objects.requireNonNullElseGet(colour_palette,  ColorPalette::new);

       circle1 = new Circle(50,50,50);
       circle1.setFill(palette.currentcolor_red);
       circle1.setStroke(Color.BLACK);

       circle2 = new Circle(50,50,50);
       circle2.setFill(palette.currentcolor_green);
       circle2.setStroke(Color.BLACK);

       circle3 = new Circle(50,50,50);
       circle3.setFill(palette.currentcolor_blue);
       circle3.setStroke(Color.BLACK);

       if (null != palette){
           circle1.setFill(this.palette.currentcolor_red);
           circle2.setFill(this.palette.currentcolor_green);
           circle3.setFill(this.palette.currentcolor_blue);

       }

       hBox.getChildren().addAll(circle1, circle2, circle3);
       this.getChildren().add(hBox);
   }

}
