package ru.wkns37.growlamp.presentation.ui

import javafx.scene.control.Label
import javafx.scene.control.ToolBar

interface StatusUI {

    fun apply(bar: ToolBar, label: Label)

    abstract class Abstract(private val text: String, private val color: String) : StatusUI {

        override fun apply(bar: ToolBar, label: Label) {
            bar.style = "-fx-background-color: $color;"
            label.text = text
        }
    }

    class Normal(text: String) : Abstract(text, "#0066CC")

    class Error(text: String) : Abstract(text, "#CC6600")
}
