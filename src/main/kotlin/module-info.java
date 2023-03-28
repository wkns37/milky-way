module ru.wkns37.growlamp {
    requires javafx.controls;
    requires javafx.fxml;
    requires kotlin.stdlib;
    requires com.fazecast.jSerialComm;
    requires kotlinx.coroutines.core.jvm;


    opens ru.wkns37.growlamp.presentation to javafx.fxml;
    exports ru.wkns37.growlamp;
}