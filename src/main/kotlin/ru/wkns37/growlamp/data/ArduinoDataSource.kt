package ru.wkns37.growlamp.data

import java.nio.ByteBuffer
import java.nio.ByteOrder
import kotlin.coroutines.resume
import kotlin.coroutines.resumeWithException
import kotlin.coroutines.suspendCoroutine

interface ArduinoDataSource {

    suspend fun readThresholdVoltage(): Int

    suspend fun setThresholdVoltage(value: Int)

    suspend fun readCurrentVoltage(): Int

    abstract class Abstract : ArduinoDataSource {

        protected suspend fun <T> handle(block: () -> T) = suspendCoroutine {
            try {
                it.resume(block.invoke())
            } catch (e: Exception) {
                it.resumeWithException(e)
            }
        }
    }

    class Base(private val communication: PortCommunication) : Abstract() {

        override suspend fun readThresholdVoltage(): Int = handle {
            communication.write(READ_THRESHOLD_VOLTAGE)
            val result = communication.read(2)
            return@handle ByteBuffer.wrap(result).order(ByteOrder.LITTLE_ENDIAN).short.toInt()
        }

        override suspend fun setThresholdVoltage(value: Int) = handle {
            val buffer = ByteBuffer.allocate(3)
            buffer.order(ByteOrder.LITTLE_ENDIAN)
            buffer.put(SET_THRESHOLD_VOLTAGE)
            buffer.putShort(value.toShort())
            communication.write(buffer.array())
        }

        override suspend fun readCurrentVoltage(): Int = handle {
            communication.write(READ_CURRENT_VOLTAGE)
            val result = communication.read(2)
            return@handle ByteBuffer.wrap(result).order(ByteOrder.LITTLE_ENDIAN).short.toInt()
        }

        private companion object {
            const val READ_THRESHOLD_VOLTAGE = 0x1.toByte()
            const val SET_THRESHOLD_VOLTAGE = 0x2.toByte()
            const val READ_CURRENT_VOLTAGE = 0x3.toByte()
        }
    }
}