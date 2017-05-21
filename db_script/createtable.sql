create table tbl_account_info(
    account	                 varchar(16)     not null,
    password                 char(128)       not null,
    password_tips            varchar(128)    ,
    PRIMARY KEY (account)    
);

create table tbl_sys_menu (
    menu_id                  integer         not null, -- �˵�ID
    caption                  varchar(128)    not null, -- �˵�����
    parent_pos               integer         not null, -- ���ڵ�λ��
    node_type                integer         not null, -- 0:�����˵���1���˵��2���ָ���
    module                   varchar(20)     ,         -- ��Ӧ���ص�dll
    PRIMARY KEY (menu_id)    
);

create table tbl_employee (
    employee_id              char(8)         not null, -- ����
    account                  varchar(16)     not null, -- �˺�
    employee_name            varchar(128)    not null, -- ����
    sex                      integer         ,         -- �Ա�
    telephone                varchar(15)     ,         -- ����
    mobilephone              varchar(15)     ,         -- �ֻ�
    email                    varchar(128)    ,         -- ����
    qq                       varchar(20)     ,         -- QQ��
    weichat                  varchar(128)    ,         -- ΢�ź�
    homephone                varchar(15)     ,         -- ��ͥ�绰
    emergency_contact        varchar(128)    ,         -- ������ϵ������
    emergency_contact_num    varchar(15)     ,         -- ������ϵ�˺���
    PRIMARY KEY (employee_id)    
);

create unique index idx_tbl_employee_account on tbl_employee (account);
create index idx_tbl_employee_name on tbl_employee (employee_name);

create table tbl_role (
    role_id                  char(8)         not null, -- ��ɫ���
    role_name                varchar(128)    not null, -- ��ɫ����
    parent_id                char(8)         not null, -- ����ɫ���
    role_desc                varchar(1024)   ,         -- ��ɫ����
    PRIMARY KEY (role_id)
);

create table tbl_employee_role (
    employee_id              char(8)         not null, -- ����
    role_id                  char(8)         not null, -- ��ɫ���
    PRIMARY KEY (employee_id, role_id)
);

create table tbl_menu_authority (
    role_id                  char(8)         not null, -- ��ɫ���
    menu_id                  integer         not null, -- �˵�ID
    menu_auth                integer         not null, -- ʹ�ò˵���Ӧ���ܵ�Ȩ�ޣ�0���������˵���1�������˵�
    add_auth                 integer         not null, -- ����Ȩ�ޣ�0����Ȩ�ޣ�1����Ȩ��
    modify_auth              integer         not null, -- �޸�Ȩ�ޣ�0����Ȩ�ޣ�1����Ȩ��
    delete_auth              integer         not null, -- ɾ��Ȩ�ޣ�0����Ȩ�ޣ�1����Ȩ��
    query_auth               integer         not null, -- ��ѯȨ�ޣ�0����Ȩ�ޣ�1����Ȩ��
    import_auth              integer         not null, -- ����Ȩ�ޣ�0����Ȩ�ޣ�1����Ȩ��
    export_auth              integer         not null, -- ����Ȩ�ޣ�0����Ȩ�ޣ�1����Ȩ��
    print_auth               integer         not null, -- ��ӡȨ�ޣ�0����Ȩ�ޣ�1����Ȩ��
    PRIMARY KEY (role_id, menu_id)
);



