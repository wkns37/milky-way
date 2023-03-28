package ru.wkns37.growlamp.data

interface PortCommunication {

    fun read(len: Int): ByteArray

    fun write(data: ByteArray)

    fun write(data: Byte)
}