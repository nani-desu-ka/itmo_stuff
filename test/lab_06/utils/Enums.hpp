#pragma once

// ��� ࠧ�� ����

enum ChangeType {
    OPENED_TASK,
    ACTIVATED_TASK,
    RESOLVED_TASK,
    MODIFIED_TASK,
};

enum Selector {
    ID, //���� ����� �� ID
    TIME_CREATE, //���� ����� �� �६��� ᮧ����� ���������
    TIME_CHANGE, //���� ����� �� �६��� ��᫥����� ���������
    EMPLOYER, //���� �����, ���९���� �� ��।���� ���짮��⥫�� (���㤭���� �������)
    EMPLOYER_TOUCHED, //���� �����, � ����� ���짮��⥫� ���ᨫ ���������
};

enum TaskState {
    OPEN,
    ACTIVE,
    RESOLVED,
};