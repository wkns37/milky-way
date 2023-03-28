package ru.wkns37.growlamp.presentation

import ru.wkns37.growlamp.presentation.ui.*

abstract class BaseViewModel {

    var listener: (ui: AppUI) -> Unit = { }

    protected fun show(top: TopPaneUI) {
        listener.invoke(AppUI(top = top))
    }

    protected fun show(left: LeftPaneUI) {
        listener.invoke(AppUI(left = left))
    }

    protected fun show(right: RightPaneUI) {
        listener.invoke(AppUI(right = right))
    }

    protected fun show(status: StatusUI) {
        listener.invoke(AppUI(status = status))
    }
}