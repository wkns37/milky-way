package ru.wkns37.growlamp.presentation.ui

import javafx.collections.FXCollections
import javafx.scene.chart.LineChart
import javafx.scene.chart.XYChart
import javafx.scene.control.TitledPane
import java.time.Instant
import java.time.ZoneId
import java.time.format.DateTimeFormatter

interface RightPaneUI {

    fun apply(pane: TitledPane, chart: LineChart<String, Int>)

    object Disabled : RightPaneUI {

        override fun apply(pane: TitledPane, chart: LineChart<String, Int>) {
            pane.isDisable = true
            chart.isDisable = true
        }
    }

    class Base(private val measurements: List<Pair<Long, Int>>) : RightPaneUI {

        private val format = DateTimeFormatter.ofPattern("HH:mm:ss").withZone(ZoneId.systemDefault())

        override fun apply(pane: TitledPane, chart: LineChart<String, Int>) {
            pane.isDisable = false
            chart.apply {
                isDisable = false
                val convertedList = measurements.map {
                    val time = format.format(Instant.ofEpochMilli(it.first))
                    XYChart.Data(time, it.second)
                }

                val observableList = FXCollections.observableList(convertedList)
                val series = XYChart.Series(observableList)
                data.setAll(series)
            }
        }
    }
}