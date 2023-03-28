package ru.wkns37.growlamp.presentation.ui

import javafx.collections.ObservableList
import javafx.scene.control.ComboBox
import javafx.scene.layout.Pane

interface TopPaneUI {

    fun apply(pane: Pane, portsComboBox: ComboBox<String>)

    object Disabled : TopPaneUI {

        override fun apply(pane: Pane, portsComboBox: ComboBox<String>) {
            pane.isDisable = true
            portsComboBox.isDisable = true
            portsComboBox.isDisable = true
        }
    }

    class Base(private val portNames: ObservableList<String>) : TopPaneUI {

        override fun apply(pane: Pane, portsComboBox: ComboBox<String>) {
            pane.isDisable = false
            portsComboBox.isDisable = false
            portsComboBox.items = portNames
        }
    }
}