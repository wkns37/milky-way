package ru.wkns37.growlamp.core

import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Job
import kotlinx.coroutines.launch
import kotlinx.coroutines.withContext
import kotlin.coroutines.CoroutineContext

interface Dispatchers {

    fun launchUI(block: suspend CoroutineScope.() -> Unit): Job

    fun launchBackground(block: suspend CoroutineScope.() -> Unit): Job

    suspend fun changeToUI(block: suspend CoroutineScope.() -> Unit)

    abstract class Abstract(
        private val scope: CoroutineScope,
        private val ui: CoroutineContext,
        private val background: CoroutineContext
    ) : Dispatchers {

        override fun launchUI(
            block: suspend CoroutineScope.() -> Unit
        ): Job = scope.launch(ui, block = block)

        override fun launchBackground(
            block: suspend CoroutineScope.() -> Unit
        ): Job = scope.launch(background, block = block)

        override suspend fun changeToUI(block: suspend CoroutineScope.() -> Unit) =
            withContext(ui, block)
    }

    class Base(scope: CoroutineScope) : Abstract(
        scope,
        kotlinx.coroutines.Dispatchers.Main,
        kotlinx.coroutines.Dispatchers.IO
    )
}