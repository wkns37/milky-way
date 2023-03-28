package ru.wkns37.growlamp

import javafx.application.Application
import javafx.fxml.FXMLLoader
import javafx.scene.Scene
import javafx.stage.Stage
import kotlinx.coroutines.MainScope
import ru.wkns37.growlamp.core.Dispatchers
import ru.wkns37.growlamp.core.Logger
import ru.wkns37.growlamp.data.ArduinoDataSource
import ru.wkns37.growlamp.data.PortEngine
import ru.wkns37.growlamp.data.VoltageLuxConverter
import ru.wkns37.growlamp.presentation.ViewController
import ru.wkns37.growlamp.presentation.ViewModel

class App : Application() {
    override fun start(stage: Stage) {
        val dispatchers = Dispatchers.Base(MainScope())
        val engine = PortEngine.Base()
        val dataSource = ArduinoDataSource.Base(engine)
        val converter = VoltageLuxConverter.Base()
        val log = Logger.Timed(
            "MMM dd HH:mm:ss.SSS",
            Logger.Standard(),
            Logger.File("log.txt")
        )
        val viewModel = ViewModel(
            dispatchers, dataSource,
            engine, converter, log
        )

        val fxmlLoader = FXMLLoader(javaClass.getResource("layout.fxml"))
        fxmlLoader.setControllerFactory {
            return@setControllerFactory if (it.isAssignableFrom(ViewController::class.java)) {
                ViewController(viewModel)
            } else try {
                it.getDeclaredConstructor().newInstance()
            } catch (e: Exception) {
                throw IllegalStateException(e)
            }
        }

        val scene = Scene(fxmlLoader.load())
        stage.title = "Grow Lamp"
        stage.scene = scene
        stage.show()
    }
}

fun main() {
    Application.launch(App::class.java)
}