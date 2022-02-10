module com.example.box2021multi {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.graphics;


    opens com.example.box2021multi to javafx.fxml;
    exports com.example.box2021multi;
}