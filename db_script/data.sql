-- ����Ա�û���¼��Ϣ��ʼ��
insert into tbl_account_info values("admin", "E1F7A8B1B2B057A4A1A71FE6113421B7941B3006A73138326590CEF8DE19FF7831886F72C97B341EF548E04B0FA16680289109927B2BF2D87E460E0B53ADF583", "admin");


-- �˵���ʼ��
-- �����˵�
insert into tbl_sys_menu values(301,   "ϵͳ����(&X)", 0, 0, null);
insert into tbl_sys_menu values(302,   "��Ʒ����(&S)", 0, 0, null);
insert into tbl_sys_menu values(303,   "������(&K)", 0, 0, null);
insert into tbl_sys_menu values(304,   "��������(&D)", 0, 0, null);
insert into tbl_sys_menu values(305,   "��Ŀ����(&P)", 0, 0, null);


-- ϵͳ����˵���
insert into tbl_sys_menu values(30101, "�û�����",     0, 1, "operator");
insert into tbl_sys_menu values(30102, "��ɫ����",     0, 1, "role");
insert into tbl_sys_menu values(30103, "Ȩ�޹���",     0, 1, "auth");

-- ��Ʒ����˵���
insert into tbl_sys_menu values(30201, "��Ӧ�̹���",   1, 1, "supplier");
insert into tbl_sys_menu values(30202, "��Ʒ����",     1, 1, "product");
insert into tbl_sys_menu values(30203, "��Ʒ��Ϲ���", 1, 1, "prodgroup");

-- ������˵���
insert into tbl_sys_menu values(30301, "������",     2, 1, "purchase");
insert into tbl_sys_menu values(30302, "��ⵥ����",   2, 1, "purchaselist");

-- ��������˵���
insert into tbl_sys_menu values(30401, "�ۻ�����",     3, 1, "order");
insert into tbl_sys_menu values(30402, "�ۻ�������",   3, 1, "orderlist");

-- ��Ŀ����˵���
insert into tbl_sys_menu values(30501, "��Ŀ����",     4, 1, "project");
insert into tbl_sys_menu values(30502, "��Դ����",     4, 1, "resource");
insert into tbl_sys_menu values(30503, "��Ŀ��Դ����", 4, 1, "resofproj");
insert into tbl_sys_menu values(30504, "��ʱ����",     4, 1, "worktime");
insert into tbl_sys_menu values(30505, "��Ŀ�ɱ���",         4, 1, "projcostreport");
insert into tbl_sys_menu values(30506, "��Ŀ��Դʹ�ñ�",     4, 1, "projresreport");


