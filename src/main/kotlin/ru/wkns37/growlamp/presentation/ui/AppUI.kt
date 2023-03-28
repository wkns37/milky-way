package ru.wkns37.growlamp.presentation.ui

data class AppUI(
    val top: TopPaneUI? = null,
    val left: LeftPaneUI? = null,
    val right: RightPaneUI? = null,
    val status: StatusUI? = null
)