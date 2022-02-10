module com.example.abstractdemo {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.graphics;


    opens com.example.abstractdemo to javafx.fxml;
    exports com.example.abstractdemo;
}