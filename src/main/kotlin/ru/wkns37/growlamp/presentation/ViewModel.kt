package ru.wkns37.growlamp.presentation

import javafx.collections.FXCollections
import javafx.scene.control.CheckBox
import javafx.scene.control.ChoiceBox
import kotlinx.coroutines.delay
import kotlinx.coroutines.isActive
import ru.wkns37.growlamp.core.Dispatchers
import ru.wkns37.growlamp.core.Logger
import ru.wkns37.growlamp.data.ArduinoDataSource
import ru.wkns37.growlamp.data.PortEngine
import ru.wkns37.growlamp.data.VoltageLuxConverter
import ru.wkns37.growlamp.presentation.ui.*

class ViewModel(
    private val dispatchers: Dispatchers,
    private val dataSource: ArduinoDataSource,
    private val engine: PortEngine,
    private val converter: VoltageLuxConverter,
    private val log: Logger
) : BaseViewModel() {

    fun initialize() {
        show(TopPaneUI.Disabled)
        show(LeftPaneUI.Disabled)
        show(RightPaneUI.Disabled)
        show(StatusUI.Normal("Loading COM ports"))
        val ports = FXCollections.observableList(engine.serialPortNames())
        show(TopPaneUI.Base(ports))
        show(StatusUI.Normal("Ready"))
    }

    fun connect(portName: String?) {
        log.d("Connect button clicked")
        try {
            show(StatusUI.Normal("Connecting to $portName"))
            engine.connectToPort(portName)
            log.i("Connected to $portName")
            show(TopPaneUI.Disabled)
            show(StatusUI.Normal("Connected"))

            fetchInfo()
            startTelemetry()
        } catch (e: Exception) {
            log.e("connect(): ${e.message!!}")
            show(StatusUI.Error(e.message!!))
        }
    }

    private fun fetchInfo() {
        show(StatusUI.Normal("Loading"))
        dispatchers.launchBackground {
            try {
                val voltage = dataSource.readThresholdVoltage()
                val threshold = if (voltage == 0) 0 else converter.toLux(voltage)
                log.i("Read threshold {voltage: $voltage, lux: $threshold}")
                dispatchers.changeToUI {
                    show(LeftPaneUI.Base(threshold, converter.provideLuxValues()))
                    show(StatusUI.Normal("Loaded"))
                }
            } catch (e: Exception) {
                log.e("fetchInfo(): ${e.message!!}")
                dispatchers.changeToUI {
                    show(StatusUI.Error(e.message!!))
                }
            }
        }
    }

    private fun startTelemetry() {
        show(StatusUI.Normal("Starting telemetry"))
        val measurements = ArrayDeque<Pair<Long, Int>>()
        dispatchers.launchBackground {
            try {
                val data = fetchTelemetryData()
                log.i("LDR telemetry {lux: ${data.second}}")
                measurements.add(data)
                dispatchers.changeToUI {
                    show(StatusUI.Normal("Started telemetry"))
                    show(RightPaneUI.Base(measurements))
                }
            } catch (e: Exception) {
                log.e("startTelemetry(): ${e.message!!}")
                dispatchers.changeToUI {
                    show(StatusUI.Error(e.message!!))
                }

                return@launchBackground
            }

            while (isActive) {
                delay(3000)

                try {
                    if (measurements.size == 10) {
                        measurements.removeFirst()
                    }

                    val data = fetchTelemetryData()
                    log.i("LDR telemetry {lux: ${data.second}}")
                    measurements.add(data)
                    dispatchers.changeToUI {
                        show(RightPaneUI.Base(measurements))
                    }
                } catch (e: Exception) {
                    log.e("startTelemetry(): ${e.message!!}")
                    dispatchers.changeToUI {
                        show(StatusUI.Error(e.message!!))
                    }
                }
            }
        }
    }

    private suspend fun fetchTelemetryData(): Pair<Long, Int> {
        val threshold = dataSource.readCurrentVoltage()
        val time = System.currentTimeMillis()
        val value = converter.toLux(threshold)
        return time to value
    }

    fun apply(powerCheckBox: CheckBox, thresholdChoiceBox: ChoiceBox<Int>) {
        log.d("Apply button clicked")
        if (powerCheckBox.isSelected && thresholdChoiceBox.value == null) {
            show(StatusUI.Error("Threshold value must be chosen"))
            return
        }

        show(StatusUI.Normal("Applying"))
        dispatchers.launchBackground {
            try {
                val power = powerCheckBox.isSelected
                val voltage = if (power) converter.toVolts(thresholdChoiceBox.value!!) else 0
                log.i("Applying state {power: $power, voltage: $voltage}")
                dataSource.setThresholdVoltage(voltage)
                dispatchers.changeToUI {
                    show(StatusUI.Normal("Applied"))
                }
            } catch (e: Exception) {
                log.e("apply(): ${e.message!!}")
                dispatchers.changeToUI {
                    show(StatusUI.Error(e.message!!))
                }
            }
        }
    }
}