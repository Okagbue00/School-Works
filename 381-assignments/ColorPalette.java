package sample;

import javafx.scene.paint.Color;



public class ColorPalette {

    private int total = 0;
    public Color currentcolor_red;
    public Color currentcolor_green;
    public Color currentcolor_blue;


    public ColorPalette(){
        currentcolor_red = Color.WHITE;
        currentcolor_green = Color.WHITE;
        currentcolor_blue = Color.WHITE;


    }

    public void addColor(Color c, int x){
        if(!(total != 0 || x != 0)){
            currentcolor_red = c;
            total++;
        }
        else if(!(total != 1 || x != 1)){
            currentcolor_green = c;
            total ++;
        }
        else {
            currentcolor_blue = c;
            total = 0;
        }

    }

    public String toString(){
        return new StringBuilder().append((int) (currentcolor_red.getRed() * 255)).append(",").append((int) (currentcolor_red.getGreen() * 255)).append(",").append((int) (currentcolor_red.getBlue() * 255)).append("\n").append((int) (currentcolor_green.getRed() * 255)).append(",").append((int) (currentcolor_green.getGreen() * 255)).append(",").append((int) (currentcolor_red.getBlue() * 255)).append("\n").append((int) (currentcolor_blue.getRed() * 255)).append(",").append((int) (currentcolor_blue.getGreen() * 255)).append(",").append((int) (currentcolor_blue.getBlue())).toString();

    }
}





