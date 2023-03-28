package ru.wkns37.growlamp.data

import com.fazecast.jSerialComm.SerialPort
import java.nio.ByteBuffer
import java.nio.ByteOrder

interface PortEngine {

    fun serialPortNames(): List<String>

    fun connectToPort(portName: String?)

    class Base : PortEngine, PortCommunication {

        private var _currentPort: SerialPort? = null
        private val currentPort get() = _currentPort!!

        override fun serialPortNames() =
            SerialPort.getCommPorts().map { it.systemPortName }

        override fun connectToPort(portName: String?) {
            _currentPort = SerialPort.getCommPort(portName)
            currentPort.setComPortTimeouts(SerialPort.TIMEOUT_READ_BLOCKING, 0, 0);
            currentPort.openPort()
        }

        override fun read(len: Int): ByteArray {
            return currentPort.inputStream.readNBytes(len)
        }

        override fun write(data: ByteArray) {
            currentPort.outputStream.write(data)
        }

        override fun write(data: Byte) {
            currentPort.outputStream.write(data.toInt())
        }
    }
}