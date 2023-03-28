package ru.wkns37.growlamp.data

import kotlin.math.exp

interface VoltageLuxConverter {

    fun toVolts(lux: Int): Int

    fun toLux(voltage: Int): Int

    fun provideLuxValues(): List<Int>

    class Base : VoltageLuxConverter {

        private val table = listOf(
            5 to 185,
            10 to 361,
            50 to 1407,
            80 to 1925,
            150 to 2702,
            320 to 3572,
            400 to 3787,
            540 to 4042
        )

        override fun toVolts(lux: Int): Int {
            return table.firstOrNull { it.first == lux }?.second ?: (V * (1 - alpha / (R * lux + alpha))).toInt()
        }

        override fun toLux(voltage: Int): Int {
            return table.firstOrNull { it.second == voltage }?.first ?: (alpha * (V / (V - voltage) - 1) / R).toInt()
        }

        override fun provideLuxValues() = table.map { it.first }

        private companion object {
            const val V = 5000.0
            const val R = 1000.0
            const val alpha = 127421.0
        }
    }
}