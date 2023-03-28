package ru.wkns37.growlamp.presentation

import javafx.fxml.FXML
import javafx.scene.chart.LineChart
import javafx.scene.control.*
import javafx.scene.input.MouseEvent
import javafx.scene.layout.Pane

class ViewController(private val viewModel: ViewModel) {

    @FXML
    private lateinit var topPane: Pane

    @FXML
    private lateinit var leftPane: TitledPane

    @FXML
    private lateinit var rightPane: TitledPane

    @FXML
    private lateinit var portsComboBox: ComboBox<String>

    @FXML
    private lateinit var connectButton: Button

    @FXML
    private lateinit var powerCheckBox: CheckBox

    @FXML
    private lateinit var thresholdChoiceBox: ChoiceBox<Int>

    @FXML
    private lateinit var applyButton: Button

    @FXML
    private lateinit var illuminanceChart: LineChart<String, Int>

    @FXML
    private lateinit var bottomBar: ToolBar

    @FXML
    private lateinit var statusLabel: Label

    @FXML
    fun initialize() {
        viewModel.listener = {
            it.top?.apply(topPane, portsComboBox)
            it.left?.apply(leftPane, powerCheckBox, thresholdChoiceBox)
            it.right?.apply(rightPane, illuminanceChart)
            it.status?.apply(bottomBar, statusLabel)
        }

        connectButton.addEventHandler(MouseEvent.MOUSE_CLICKED) {
            viewModel.connect(portsComboBox.value)
        }

        applyButton.addEventHandler(MouseEvent.MOUSE_CLICKED) {
            viewModel.apply(powerCheckBox, thresholdChoiceBox)
        }

        viewModel.initialize()
    }
}