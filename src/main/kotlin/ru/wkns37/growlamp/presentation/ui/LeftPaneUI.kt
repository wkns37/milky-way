package ru.wkns37.growlamp.presentation.ui

import javafx.collections.FXCollections
import javafx.collections.ObservableList
import javafx.scene.control.CheckBox
import javafx.scene.control.ChoiceBox
import javafx.scene.control.TitledPane

interface LeftPaneUI {

    fun apply(pane: TitledPane, powerCheckBox: CheckBox, thresholdChoiceBox: ChoiceBox<Int>)

    object Disabled : LeftPaneUI {

        override fun apply(pane: TitledPane, powerCheckBox: CheckBox, thresholdChoiceBox: ChoiceBox<Int>) {
            pane.isDisable = true
            powerCheckBox.isDisable = true
            thresholdChoiceBox.isDisable = true
        }
    }

    class Base(private val threshold: Int, private val options: List<Int>) : LeftPaneUI {

        override fun apply(pane: TitledPane, powerCheckBox: CheckBox, thresholdChoiceBox: ChoiceBox<Int>) {
            pane.isDisable = false
            powerCheckBox.apply {
                isDisable = false
                isSelected = threshold > 0
            }
            thresholdChoiceBox.apply {
                isDisable = false
                if (threshold > 0) value = threshold
                items = FXCollections.observableList(options)
            }
        }
    }
}