package managers

import utils.EmptyChangeError

class ChangeListManager {
    private val changeList: MutableMap<String, String> = mutableMapOf()
    fun addChange(time: String, change: String) {
        changeList[time] = change
    }
    fun findChange(time: String): String {
        if (!changeList.containsKey(time)) throw EmptyChangeError()
        return changeList[time]!!
    }
    fun getAllChanges(): MutableMap<String, String> {
        return changeList
    }
}