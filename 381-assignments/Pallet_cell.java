package sample;


import javafx.scene.control.ListCell;


public class Pallet_cell extends ListCell<ColorPalette> {

    public void updateItem(ColorPalette item, boolean empty){
        super.updateItem(item, empty);
        PalletView pv = new PalletView(item);
        setGraphic(pv);




    }
}
