#pragma once

// ��� ࠧ�� ����

enum EmployerType {
    PESHKA_NAVALNOGO, //����� ࠡ�⭨�
    TEAMLEAD, //⨬��� (� ���� � ���稭���� �� ����� ࠡ�⭨��)
    DIRECTOR, //�ࠢ���騩 (� ���� � ���稭���� �� ⨬����)
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