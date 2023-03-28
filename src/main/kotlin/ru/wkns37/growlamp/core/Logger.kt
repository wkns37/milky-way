package ru.wkns37.growlamp.core

import java.io.PrintWriter
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.StandardOpenOption.APPEND
import java.nio.file.StandardOpenOption.CREATE
import java.time.LocalDateTime
import java.time.format.DateTimeFormatter
import java.util.*

interface Logger {

    fun log(message: String)

    fun i(message: String)

    fun d(message: String)

    fun e(message: String)

    abstract class Abstract : Logger {

        override fun i(message: String) = log("INFO  - $message")

        override fun d(message: String) = log("DEBUG - $message")

        override fun e(message: String) = log("ERROR - $message")
    }

    class Timed(
        pattern: String,
        private vararg val loggers: Logger
    ) : Abstract() {

        private val formatter = DateTimeFormatter
            .ofPattern(pattern)
            .withLocale(Locale.US)

        override fun log(message: String) {
            val timestamp = LocalDateTime.now().format(formatter)
            loggers.forEach { it.log("$timestamp $message") }
        }
    }

    class Standard : Abstract() {

        override fun log(message: String) {
            println(message)
        }
    }

    class File(private val filename: String) : Abstract() {

        override fun log(message: String) {
            val out = Files.newOutputStream(Path.of(filename), CREATE, APPEND)
            PrintWriter(out).use { it.println(message) }
        }
    }
}