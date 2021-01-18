#pragma once

// тута разные енумы

enum ChangeType {
    OPENED_TASK,
    ACTIVATED_TASK,
    RESOLVED_TASK,
    MODIFIED_TASK,
};

enum Selector {
    ID, //поиск задач по ID
    TIME_CREATE, //поиск задач по времени создания изменения
    TIME_CHANGE, //поиск задач по времени последнего изменения
    EMPLOYER, //поиск задач, закреплённых за определённым пользователем (сотрудником команды)
    EMPLOYER_TOUCHED, //поиск задач, в которые пользователь вносил изменения
};

enum TaskState {
    OPEN,
    ACTIVE,
    RESOLVED,
};